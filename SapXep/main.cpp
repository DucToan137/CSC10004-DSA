#include<iostream>
#include<vector>
#include<sstream>
#include<chrono>
#include<time.h>
#include"./Sort.h"
#include"./Data.h"


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

void TG(vector<int> &a)
{
    auto begin = chrono::high_resolution_clock::now();
    heapSort(a);
    auto end = chrono::high_resolution_clock::now();
    auto duration = chrono::duration_cast<chrono::milliseconds>(end - begin);
    cout << "HeapSort: " << duration.count() << " miliseconds" << endl;

    auto begin1 = chrono::high_resolution_clock::now();
    quickSort(a);
    auto end1 = chrono::high_resolution_clock::now();
    auto duration1 = chrono::duration_cast<chrono::milliseconds>(end1 - begin1);
    cout << "QuickSort: " << duration1.count() << " miliseconds" << endl;

    auto begin2 = chrono::high_resolution_clock::now();
    mergeSort(a);
    auto end2 = chrono::high_resolution_clock::now();
    auto duration2 = chrono::duration_cast<chrono::milliseconds>(end2 - begin2);
    cout << "MergeSort: " << duration2.count() << " miliseconds" << endl;

    auto begin3 = chrono::high_resolution_clock::now();
    radixSort(a);
    auto end3 = chrono::high_resolution_clock::now();
    auto duration3 = chrono::duration_cast<chrono::milliseconds>(end3 - begin3);
    cout << "RadixSort: " << duration3.count() << " miliseconds" << endl;

    auto begin4 = chrono::high_resolution_clock::now();
    selectionSort(a);
    auto end4 = chrono::high_resolution_clock::now();
    auto duration4 = chrono::duration_cast<chrono::milliseconds>(end4 - begin4);
    cout << "SelectionSort: " << duration4.count() << " miliseconds" << endl;
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

    

    /*cout << "#Du lieu sap xep ngau nhien" << endl;
    cout << "Du lieu co kich thuoc 1000" << endl;
    TG(NN1);
    cout << "Du lieu co kich thuoc 5000" << endl;
    TG(NN2);
    cout << "Du lieu co kich thuoc 10000" << endl;
    TG(NN3);
    cout << "Du lieu co kich thuoc 100000" << endl;
    TG(NN4);
    cout << "Du lieu co kich thuoc 1000000" << endl;
    TG(NN);
    

    cout << "#Du lieu co thu tu gan nhu tang dan" << endl;
    cout << "Du lieu co kich thuoc 1000" << endl;
    TG(TT1);
    cout << "Du lieu co kich thuoc 5000" << endl;
    TG(TT2);
    cout << "Du lieu co kich thuoc 10000" << endl;
    TG(TT3);
    cout << "Du lieu co kich thuoc 100000" << endl;
    TG(TT4);
    cout << "Du lieu co kich thuoc 1000000" << endl;
    TG(TT);


    cout << "#Du lieu co thu tu tang dan" << endl;
    cout << "Du lieu co kich thuoc 1000" << endl;
    TG(TD1);
    cout << "Du lieu co kich thuoc 5000" << endl;
    TG(TD2);
    cout << "Du lieu co kich thuoc 10000" << endl;
    TG(TD3);
    cout << "Du lieu co kich thuoc 100000" << endl;
    TG(TD4);
    cout << "Du lieu co kich thuoc 1000000" << endl;
    TG(TD);*/


    cout << "#Du lieu co thu tu giam dan" << endl;
    cout << "Du lieu co kich thuoc 1000" << endl;
    TG(GD1);
    cout << "Du lieu co kich thuoc 5000" << endl;
    TG(GD2);
    cout << "Du lieu co kich thuoc 10000" << endl;
    TG(GD3);
    cout << "Du lieu co kich thuoc 100000" << endl;
    TG(GD4);
    cout << "Du lieu co kich thuoc 1000000" << endl;
    TG(GD);



	return 0;
}