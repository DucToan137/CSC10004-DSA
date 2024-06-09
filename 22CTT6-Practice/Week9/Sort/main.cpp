#include<iostream>
#include<vector>
#include<sstream>
#include"Sort.h"
#include"Data.h"


using namespace std;



vector<int>DocFile(const string& file_name)
{
    vector<int> kq;
    ifstream inFile(file_name);
    if (!inFile.is_open())
    {
        cout << "Khong the mo file";
    }
    string line;
    getline(inFile, line);

    std::istringstream stream(line);
    int so;

    while (stream >> so) {
        kq.push_back(so);
    }

    inFile.close();
    return kq;
}

void ThaoTacDem(vector<int>& a)
{
    heapSort(a);
    quickSort(a);
    mergeSort(a);
    radixSort(a);
    selectionSort(a);
}


int main() {
    //NgauNhien("NgauNhien.txt");
    //TangDan("TangDan.txt");
    //GiamDan("GiamDan.txt");
    //DulieuCoThuTu("DuLieuThuTu.txt");

    vector<int> NN = DocFile("NgauNhien.txt");
    vector<int> TT = DocFile("DuLieuThuTu.txt");
    vector<int> TD = DocFile("TangDan.txt");
    vector<int> GD = DocFile("GiamDan.txt");

    vector<int> NN1(NN.begin(), NN.begin() + 1000);
    vector<int> NN2(NN.begin(), NN.begin() + 5000);
    vector<int> NN3(NN.begin(), NN.begin() + 10000);
    vector<int> NN4(NN.begin(), NN.begin() + 100000);

    vector<int> TT1(TT.begin(), TT.begin() + 1000);
    vector<int> TT2(TT.begin(), TT.begin() + 5000);
    vector<int> TT3(TT.begin(), TT.begin() + 10000);
    vector<int> TT4(TT.begin(), TT.begin() + 100000);

    vector<int> TD1(TD.begin(), TD.begin() + 1000);
    vector<int> TD2(TD.begin(), TD.begin() + 5000);
    vector<int> TD3(TD.begin(), TD.begin() + 10000);
    vector<int> TD4(TD.begin(), TD.begin() + 100000);

    vector<int> GD1(GD.begin(), GD.begin() + 1000);
    vector<int> GD2(GD.begin(), GD.begin() + 5000);
    vector<int> GD3(GD.begin(), GD.begin() + 10000);
    vector<int> GD4(GD.begin(), GD.begin() + 100000);



    cout << "#Du lieu sap xep ngau nhien" << endl;
    cout << "Du lieu co kich thuoc 1000" << endl;
    ThaoTacDem(NN1);
    cout << "Du lieu co kich thuoc 5000" << endl;
    ThaoTacDem(NN2);
    cout << "Du lieu co kich thuoc 10000" << endl;
    ThaoTacDem(NN3);
    cout << "Du lieu co kich thuoc 100000" << endl;
    ThaoTacDem(NN4);
    cout << "Du lieu co kich thuoc 1000000" << endl;
    ThaoTacDem(NN);


    cout << "#Du lieu co thu tu gan nhu tang dan" << endl;
    cout << "Du lieu co kich thuoc 1000" << endl;
    ThaoTacDem(TT1);
    cout << "Du lieu co kich thuoc 5000" << endl;
    ThaoTacDem(TT2);
    cout << "Du lieu co kich thuoc 10000" << endl;
    ThaoTacDem(TT3);
    cout << "Du lieu co kich thuoc 100000" << endl;
    ThaoTacDem(TT4);
    cout << "Du lieu co kich thuoc 1000000" << endl;
    ThaoTacDem(TT);


    cout << "#Du lieu co thu tu tang dan" << endl;
    cout << "Du lieu co kich thuoc 1000" << endl;
    ThaoTacDem(TD1);
    cout << "Du lieu co kich thuoc 5000" << endl;
    ThaoTacDem(TD2);
    cout << "Du lieu co kich thuoc 10000" << endl;
    ThaoTacDem(TD3);
    cout << "Du lieu co kich thuoc 100000" << endl;
    ThaoTacDem(TD4);
    cout << "Du lieu co kich thuoc 1000000" << endl;
    ThaoTacDem(TD);


    cout << "#Du lieu co thu tu giam dan" << endl;
    cout << "Du lieu co kich thuoc 1000" << endl;
    ThaoTacDem(GD1);
    cout << "Du lieu co kich thuoc 5000" << endl;
    ThaoTacDem(GD2);
    cout << "Du lieu co kich thuoc 10000" << endl;
    ThaoTacDem(GD3);
    cout << "Du lieu co kich thuoc 100000" << endl;
    ThaoTacDem(GD4);
    cout << "Du lieu co kich thuoc 1000000" << endl;
    ThaoTacDem(GD);

    return 0;
}