#include<iostream>
#include<queue>
using namespace std;

void selectionSort(int a[], int n)
{
	for (int i = 0; i < n - 1; i++)
	{
		int min_pos = i;
		for (int j = i + 1; j < n; j++)
		{
			if (a[j] < a[min_pos])
				min_pos = j;
		}
		swap(a[i], a[min_pos]);
	}
}

void bubbleSort(int a[], int n)
{
	for (int i = 0; i < n-1; i++)
	{
		for (int j = 0; j < n-i-1; j++)
			if (a[j] > a[j + 1])
				swap(a[j], a[j + 1]);
	}
}

void merge(int a[], int l, int m, int r)
{
	vector<int>x(a + l, a + m + 1);
	vector<int>y(a + m + 1, a + r + 1);
	int i = 0;
	int j = 0;
	while (i < x.size() && j < y.size())
	{
		if (x[i] <= y[j])
		{
			a[l] = x[i];
			++l; ++i;
		}
		else
		{
			a[l] = y[j];
			++l; ++j;
		}
	}
	while (i < x.size())
	{
		a[l] = x[i];
		++l; ++i;
	}
	while (j < y.size())
	{
		a[l] = y[j];
		++l; ++j;
	}
}

void mergeSort(int a[], int l, int r)
{
	if (l >= r)return;
	int m = (l + r) / 2;
	mergeSort(a, l, m);
	mergeSort(a, m + 1, r);
	merge(a, l, m, r);
}

void heapify(int a[], int n,int i)
{
	int largest = i;
	int left = 2 * i + 1;
	int right = 2 * i + 2;

	if (left<n && a[left]>a[largest])
		largest = left;
	if (right<n && a[right]>a[largest])
		largest = right;

	if (i != largest)
	{
		swap(a[i], a[largest]);
		heapify(a, n, largest);
	}
}

void heapSort(int a[], int n)
{
	for (int i = n / 2 - 1; i >= 0; i--)
		heapify(a, n, i);
	for (int i = n - 1; i >= 0; i--)
	{
		swap(a[0], a[i]);
		heapify(a, i, 0);
	}
}

int getMax(int a[], int n)
{
	int max = a[0];
	for (int i = 0; i < n; i++)
	{
		if (a[i] > max)
			max = a[i];
	}
	return max;
}

void countSort(int a[], int n, int exp)
{
	int output[1001];
	int count[10] = { 0 };

	for (int i = 0; i < n; i++)
		count[(a[i] / exp) % 10]++;

	for (int i = 1; i < 10; i++)
		count[i] += count[i - 1];

	for (int i = n - 1; i >= 0; i--)
	{
		output[count[(a[i] / exp) % 10] - 1] = a[i];
		count[(a[i] / exp) % 10]--;
	}

	for (int i = 0; i < n; i++)
	{
		a[i] = output[i];
	}
}

void radixSort(int a[], int n)
{
	int m = getMax(a, n);
	for (int exp = 1; m / exp > 0; exp *= 10)
		countSort(a, n, exp);
}


int partition_l(int a[], int l, int r)
{
	int p = a[r];
	int i = l - 1;
	for (int j = l; j < r; j++)
	{
		if (a[j] <= p)
		{
			++i;
			swap(a[i], a[j]);
		}
	}
	++i;
	swap(a[i], a[r]);
	return i;
}

void quickSort(int a[], int l, int r)
{
	if (l >= r)return;
	int p = partition_l(a, l, r);
	quickSort(a, l, p - 1);
	quickSort(a, p + 1, r);
}
int partition_h(int a[], int l, int r)
{
	int p = a[(l + r) / 2];
	int i = l - 1;
	int j = r + 1;
	while (1)
	{
		do {
			++i;
		} while (a[i] < p);
		do {
			--j;
		} while (a[j] > p);
		if (i < j)
		{
			swap(a[i], a[j]);
		}
		else
			return j;
	}
}

void quickSort_h(int a[], int l, int r)
{
	if (l >= r)return;
	int p = partition_h(a, l, r);
	quickSort_h(a, l, p);
	quickSort_h(a, p + 1, r);
}


int main()
{
	int a[10] = { 10,9,8,7,6,5,4,3,2,1 };
	quickSort_h(a,0,9);
	for (int i = 0; i < 10; i++)
	{
		cout << a[i] << " ";
	}
	return 0;
}