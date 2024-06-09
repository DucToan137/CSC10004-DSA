#include<iostream>
#include"Company.h"

using namespace std;

const int HashLength = 20;
const int P = 31;
const int m = 1000000009;
const int HashTableSize = 200;
const char kitu = '|';
long long s[HashLength];


// 1.Doc du lieu tu file txt
Company ReadCompanyInfo(string companyInfo)
{
    int n = companyInfo.size();
    int gach1 = 0;
    while (gach1 < n && companyInfo[gach1] != kitu)
        gach1++;

    int gach2 = gach1 + 1;
    while (gach2 < n && companyInfo[gach2] != kitu)
        gach2++;

    Company company;
    company.name = companyInfo.substr(0, gach1);
    company.profit_tax = companyInfo.substr(gach1 + 1, gach2 - gach1 - 1);
    company.address = companyInfo.substr(gach2 + 1, n - gach2 - 1);

    return company;
}

vector<Company> ReadCompanyList(string file_name)
{
    vector<Company> companyList;
    ifstream fin;
    fin.open(file_name);
    if (fin.is_open()) {
        string line;

        getline(fin, line);

        while (!fin.eof())
        {
            getline(fin, line);
            Company company = ReadCompanyInfo(line);
            companyList.push_back(company);
        }

        fin.close();
    }
    else
    {
        cout << "Cannot open file" << endl;
    }

    return companyList;
}

void PrintCompanyList(vector<Company>& companyList)
{
    for (Company company : companyList)
    {
        cout << company.name << " | " << company.profit_tax << " | " << company.address << endl;
    }
}

void CalculateModsArray()
{
    s[0] = 1;
    for (int i = 1; i < HashLength; i++)
        s[i] = (s[i - 1] * P) % m;
}

// 2. Ham bam chuoi
long long HashString(string s)
{
    if (s.size() >= HashLength)
        s = s.substr(s.size() - HashLength, HashLength);

    long long key = 0;
    for (int i = 0; i < s.size(); i++) {
        key += s[i] * (int)s[i];
        key = key % m;
    }

    return key;
}

// 3. Ham tao bang bam tu danh sach cong ti, kich thuoc 200
Company* CreateHashTable(vector<Company> list_company)
{
    Company* hashTable = new Company[HashTableSize];
    for (int i = 0; i < HashTableSize; i++)
        hashTable[i].name = "NULL";

    bool isFull = false;
    for (int i = 0; i < list_company.size(); i++) {
        if (isFull)
            break;

        long long key = HashString(list_company[i].name);
        int tmp1 = key % HashTableSize;

        int tmp = tmp1;
        while (hashTable[tmp1].name != "NULL") {
            tmp1++;

            if (tmp1 == HashTableSize)
                tmp1 = 0;

            if (tmp1 == tmp) {
                isFull = true;
                break;
            }
        }

        if (!isFull) {
            hashTable[tmp1] = list_company[i];
        }
    }

    return hashTable;
}

// 4. Them thong tin 1 cong ti vao bang bam
void Insert(Company* hash_table, Company company)
{
    bool isFull = false;
    long long key = HashString(company.name);
    int tmp1 = key % HashTableSize;

    int tmp = tmp1;
    while (hash_table[tmp1].name != "NULL") {
        tmp1 = (tmp1 + 1) % HashTableSize;

        if (tmp1 == tmp) {
            isFull = true;
            break;
        }
    }

    if (!isFull) {
        hash_table[tmp1] = company;
    }
}

// 5. Tim kiem thong tin cua 1 cong ti trong bang bam thong qua ten cong ti
Company* Search(Company* hash_table, string company_name)
{
    int key = HashString(company_name);
    int tmp1 = key % HashTableSize;

    int probingCount = 0;
    while (hash_table[tmp1].name != "NULL")
    {
        if ((hash_table[tmp1].name).compare(company_name) == 0)
            return &(hash_table[tmp1]);
        else {
            probingCount++;
            tmp1 = (tmp1 + 1) % HashTableSize;

            if (probingCount == HashTableSize)
                return NULL;
        }
    }

    return NULL;
}

void PrintSearchResult(Company* hashTable, string companyName)
{
    Company* company = Search(hashTable, companyName);
    if (company == NULL)
        cout << "Khong tim thay " << companyName << endl;
    else
        cout << "Ten cong ty: " << company->name << "\nMST: " << company->profit_tax << "\nDia chi: " << company->address << endl;
}