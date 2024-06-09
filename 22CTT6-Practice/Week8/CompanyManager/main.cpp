#include<iostream>
#include"Company.h"

using namespace std;

int main()
{
    CalculateModsArray();
    vector<Company> companyList = ReadCompanyList("MST.txt");
    Company* hashTable = CreateHashTable(companyList);

    PrintCompanyList(companyList);
    cout << endl;

    string companyName1 = "CONG TY CO PHAN PHAN BON BINH DIEN";
    cout << "Tim kiem cong ty: " << companyName1 << endl;
    PrintSearchResult(hashTable, companyName1);

    cout << endl;
    string companyName2 = "CONG TY CO PHAN THUONG MAI BACH HOA XANH";
    cout << "Tim kiem cong ty: " << companyName2 << endl;
    PrintSearchResult(hashTable, companyName2);

    cout << endl;
    string companyName3 = "CONG TY TNHH COCA COLA VIET NAM";
    cout << "Tim kiem cong ty: " << companyName3 << endl;
    PrintSearchResult(hashTable, companyName3);

    return 0;
}
