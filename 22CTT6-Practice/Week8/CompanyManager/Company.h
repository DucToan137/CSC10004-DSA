#pragma once
#include<iostream>
#include<fstream>
#include<vector>
#include<string>

using namespace std;


struct Company
{
    string name;
    string profit_tax;
    string address;
};

// doc du lieu tu file
Company ReadCompanyInfo(string companyInfo);
vector<Company> ReadCompanyList(string file_name);

void PrintCompanyList(vector<Company>& companyList);
void CalculateModsArray();

// ham bam
long long HashString(string s);

// tao bang bam
Company* CreateHashTable(vector<Company> list_company);

void Insert(Company* hash_table, Company company);

// tim kiem thong tin cong ti tu bang bam
Company* Search(Company* hash_table, string company_name);

// in theo ket qua tim kiem
void PrintSearchResult(Company* hashTable, string companyName);