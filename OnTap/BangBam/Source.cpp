#include <fstream>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

const int HASH_LENGTH = 20;
const int P = 31;
const int MOD = 1000000009;
const int HASH_TABLE_SIZE = 2000;
const char DELIM_CHAR = '|';
const string NO_NAME = "NULL";
long long EXP_OF_P[HASH_LENGTH];

struct Company {
    string name;
    string tax_code;
    string address;
};

// 1. Read the companies’ information from a given file
Company ReadCompanyInfo(string companyInfo) {
    int n = companyInfo.size();
    int delim1 = 0;
    while (delim1 < n && companyInfo[delim1] != DELIM_CHAR)
        delim1++;

    int delim2 = delim1 + 1;
    while (delim2 < n && companyInfo[delim2] != DELIM_CHAR)
        delim2++;

    // cout << "delim1: " << delim1 << " delim2: " << delim2 << endl;

    Company company;
    company.name = companyInfo.substr(0, delim1);
    company.tax_code = companyInfo.substr(delim1 + 1, delim2 - delim1 - 1);
    company.address = companyInfo.substr(delim2 + 1, n - delim2 - 1);

    return company;
}

vector<Company> ReadCompanyList(string file_name) {
    vector<Company> companyList;
    ifstream fin;
    fin.open(file_name);
    if (fin.is_open()) {
        string line;
        // remove the header
        getline(fin, line);

        // read all companies
        while (!fin.eof()) {
            getline(fin, line);
            Company company = ReadCompanyInfo(line);
            companyList.push_back(company);
        }

        fin.close();
    }
    else {
        cout << "Cannot open file" << endl;
    }

    return companyList;
}

void PrintCompanyList(vector<Company>& companyList) {
    for (Company company : companyList) {
        cout << company.name << "|||||" << company.tax_code << "|||||" << company.address << endl;
    }
}

void CalculateModsArray() {
    EXP_OF_P[0] = 1;
    for (int i = 1; i < HASH_LENGTH; i++)
        EXP_OF_P[i] = (EXP_OF_P[i - 1] * P) % MOD;
}

// 2. Hash a string (company name) function
long long Hash(string s) {
    if (s.size() >= HASH_LENGTH)
        s = s.substr(s.size() - HASH_LENGTH, HASH_LENGTH);

    long long key = 0;
    for (int i = 0; i < s.size(); i++) {
        key += EXP_OF_P[i] * (int)s[i];
        key = key % MOD;
    }

    return key;
}

// 3. The function to create a hash table of size 2000, generated from the Companies list
// HASH_TABLE_SIZE = 2000
Company* CreateHashTable(vector<Company> list_company) {
    Company* hashTable = new Company[HASH_TABLE_SIZE];
    for (int i = 0; i < HASH_TABLE_SIZE; i++)
        hashTable[i].name = NO_NAME;

    bool isFull = false;
    for (int i = 0; i < list_company.size(); i++) {
        if (isFull)
            break;

        long long key = Hash(list_company[i].name);
        int index = key % HASH_TABLE_SIZE;

        // Find available index, using linear probing
        int orgIndex = index;
        while (hashTable[index].name != NO_NAME) {
            index++;

            // Circular
            if (index == HASH_TABLE_SIZE)
                index = 0;

            // Hashtable is full, cannot add more
            if (index == orgIndex) {
                isFull = true;
                break;
            }
        }

        // Found available index
        if (!isFull) {
            hashTable[index] = list_company[i];
        }
    }

    return hashTable;
}

// 4. Add the info of one company into an existed hash table
void Insert(Company* hash_table, Company company) {
    bool isFull = false;
    long long key = Hash(company.name);
    int index = key % HASH_TABLE_SIZE;

    // Find available index, using linear probing
    int orgIndex = index;
    while (hash_table[index].name != NO_NAME) {
        index = (index + 1) % HASH_TABLE_SIZE;

        // Hashtable is full
        if (index == orgIndex) {
            isFull = true;
            break;
        }
    }

    // Found available index
    if (!isFull) {
        hash_table[index] = company;
    }
}

// 5. Search for company information by its name:
Company* Search(Company* hash_table, string company_name) {
    int key = Hash(company_name);
    int index = key % HASH_TABLE_SIZE;

    int probingCount = 0;
    while (hash_table[index].name != NO_NAME) {
        // Found
        if ((hash_table[index].name).compare(company_name) == 0)
            return &(hash_table[index]);
        else {
            probingCount++;
            index = (index + 1) % HASH_TABLE_SIZE;

            // Hash table is full, the company not found
            if (probingCount == HASH_TABLE_SIZE)
                return NULL;
        }
    }

    return NULL;
}

void PrintSearchResult(Company* hashTable, string companyName) {
    Company* company = Search(hashTable, companyName);
    if (company == NULL)
        cout << "Khong tim thay " << companyName << endl;
    else
        cout << "Ten cong ty: " << company->name << "\nMST: " << company->tax_code << "\nDia chi: " << company->address << endl;
}

int main() {
    CalculateModsArray();
    vector<Company> companyList = ReadCompanyList("data.txt");
    Company* hashTable = CreateHashTable(companyList);

    string companyName1 = "CONG TY TNHH HANH TRANG PHAT";
    cout << "Tim kiem cong ty: " << companyName1 << endl;
    PrintSearchResult(hashTable, companyName1);

    cout << endl;
    string companyName2 = "CONG TY TNHH THUONG MAI - XUAT NHAP KHAU THANH CONG MOI";
    cout << "Tim kiem cong ty: " << companyName2 << endl;
    PrintSearchResult(hashTable, companyName2);

    cout << endl;
    string companyName3 = "CONG TY TNHH COCACOLA VIET NAM";
    cout << "Tim kiem cong ty: " << companyName3 << endl;
    PrintSearchResult(hashTable, companyName3);
    return 0;
}
