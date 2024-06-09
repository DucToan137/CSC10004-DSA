#pragma once
#include<iostream>
#include<vector>
using namespace std;

void selectionSort(vector<int>& a);

void heapify(vector<int>& arr, int n, int i);
void heapSort(vector<int>& a);

void merge(vector<int>& a, vector<int>& a1, vector<int>& a2);
void mergeSort(vector<int>& a, int m, int n);
void mergeSort(vector<int>& a);

void quickSort(vector<int>& a, int low, int high);
void quickSort(vector<int>& a);

int getMax(vector<int>& a);
void CountingSort(vector<int>& a, int k);
void radixSort(vector<int>& a);