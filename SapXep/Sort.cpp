#include<iostream>
#include"./Sort.h"

using namespace std;



// Selection Sort
void selectionSort(vector<int>& a)
{
	int i, j, min;
	for (i = 0; i < a.size() - 1; i++)
	{
		min = i;
		for (j = i + 1; j < a.size(); j++)
			if (a[j] < a[min])
				min = j;
		swap(a[min], a[i]);
	}
}


 //Heap Sort
void heapify(vector<int>& arr, int n, int i)
{
    int largest = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2;

    if (l < n && arr[l] > arr[largest])
        largest = l;

    if (r < n && arr[r] > arr[largest])
        largest = r;

    if (largest != i) {
        swap(arr[i], arr[largest]);
        heapify(arr, n, largest);
    }
}

void heapSort(vector<int>& arr)
{
    int n = arr.size();

    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);

    for (int i = n - 1; i > 0; i--) 
    {
        swap(arr[0], arr[i]);
        heapify(arr, i, 0);
    }
}


// Merge Sort
void merge(vector<int>& a, vector<int>& a1, vector<int>& a2) 
{
    int pos = 0, pos1 = 0, pos2 = 0;
    int n1 = a1.size();
    int n2 = a2.size();

    while (pos1 < n1 && pos2 < n2)
        if (a1[pos1] < a2[pos2])
            a[pos++] = a1[pos1++];
        else
            a[pos++] = a2[pos2++];
    while (pos1 < n1) a[pos++] = a1[pos1++];
    while (pos2 < n2) a[pos++] = a2[pos2++];
}

void mergeSort(vector<int>& a, int m, int n) 
{
    int n = n - m + 1;
    if (n <= 1) return;
    int half = n / 2;

    vector<int> a1(a.begin() + m, a.begin() + m + half);
    vector<int> a2(a.begin() + m + half, a.begin() + n + 1);

    mergeSort(a1, 0, half - 1);
    mergeSort(a2, 0, n - half - 1);
    merge(a, a1, a2);
}

void mergeSort(vector<int>& a) 
{
    int n = a.size();
    mergeSort(a, 0, n - 1);
}


// Quick Sort
void quickSort(vector<int>& a, int low, int high) 
{
    int i = low;
    int j = high;
    int pivot = a[(i + j) / 2];
    int tmp;

    while (i <= j) {
        while (a[i] < pivot) i++;
        while (a[j] > pivot) j--;
        if (i <= j) {
            swap(a[i], a[j]);
            i++;
            j--;
        }
    }
    if (j > low) quickSort(a, low, j);
    if (i < high) quickSort(a, i, high);
}


void quickSort(vector<int>& a)
{
    quickSort(a, 0, a.size() - 1);
}


// Radix Sort
int getMax(vector<int>& a)
{
    int max = a[0];
    for (int i = 1; i < a.size(); i++) {
        if (a[i] > max) {
            max = a[i];
        }
    }
    return max;
}

void CountingSort(vector<int>& a, int k)
{
    const int size = a.size();
    vector<int> output(size);
    vector<int> count(10, 0);

    for (int i = 0; i < size; i++) {
        count[(a[i] / k) % 10]++;
    }

    for (int i = 1; i < 10; i++) {
        count[i] += count[i - 1];
    }

    for (int i = size - 1; i >= 0; i--) {
        output[count[(a[i] / k) % 10] - 1] = a[i];
        count[(a[i] / k) % 10]--;
    }

    for (int i = 0; i < size; i++) {
        a[i] = output[i];
    }
}

void radixSort(vector<int>& a)
{
    int m = getMax(a);
    for (int k = 1; m / k > 0; k *= 10) {
        CountingSort(a, k);
    }
}