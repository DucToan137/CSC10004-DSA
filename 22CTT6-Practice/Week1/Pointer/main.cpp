#include<iostream>
using namespace std;

//I
// 1
void inputArray(int*& a, int n)
{
	cin >> n;
	a = new int[n];
	for (int i = 0; i < n; i++) {
		cout << i + 1 << ": ";
		cin >> a[i];
	}
}
//2
void inputArray2D(int**& a, int nRow, int nCol)
{


	for (int i = 0; i < nRow; i++)
	{
		for (int j = 0; j < nCol; j++)
		{
			cin >> a[i][j];
		}
	}
}
//4
void printArray(const int* a, int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << a[i] << " ";
	}
}
void printArray2D(const int** a, int nRow, int nCol)
{
	for (int i = 0; i < nRow; i++)
	{
		for (int j = 0; j < nCol; j++)
		{
			cout << a[i][j] << " ";
		}
		cout << endl;
	}
}
//5
int findMin(const int* a, int n)
{
	int min = a[0];
	for (int i = 0; i < n; i++)
	{
		if (a[i] < min)
			min = a[i];
	}
	return min;
}
//6
int findMaxModulus(const int* a, int n)
{
	int max = a[0];
	for (int i = 0; i < n; i++)
	{
		if (a[i] * a[i] > max * max)
			max = a[i];
	}
	return max;

}
//7
int countValue(int* a, int n, int key)
{
	int dem = 0;
	for (int i = 0; i < n; i++)
	{
		if (a[i] == key)
			dem++;
	}
	return dem;
}
//8
void StrRev(char* a) {
	int l = 0;
	int length;
	for (length = 0; a[length] != '\0'; length++) {}
	while (l < length) {
		--length;
		char tmp = a[l];
		a[l] = a[length];
		a[length] = tmp;
		++l;
	}
}
//9
void PrettyStr(char* a) {
	for (int i = 0; i < strlen(a); i++) {
		if (i == 0 || (i > 0 && a[i - 1] == ' '))
		{
			if (a[i] >= 'a' && a[i] <= 'z')
				a[i] = a[i] - 32;
		}
		else
		{

			if (a[i] >= 'A' && a[i] <= 'Z') {
				a[i] = a[i] + 32;
			}
		}
	}
}

// III
//1
int sumOfSquares(int n)
{
	if (n == 0)
	{
		return 0;
	}
	else
	{
		return n * n + sumOfSquares(n - 1);
	}
}
//2
int gcd(int a, int b)
{
	if (b == 0)
	{
		return a;
	}
	else
	{
		return (gcd(b, b % a));
	}
}
//3
bool isPaliddrome(int a[], int left, int right)
{
	if (left >= right)
		return 1;
	if (a[left] != a[right])
		return 0;
	else
		return isPaliddrome(a, left + 1, right - 1);
}
//4
int Factorial(int n)
{
	if (n == 0)
	{
		return 1;
	}
	else
	{
		return n * Factorial(n - 1);
	}
}
//5
int countDigit(int a)
{
	if (a < 10) {
		return 1;
	}
	else
	{
		return 1 + countDigit(a / 10);
	}

}
//6
int FiboN(int n)
{
	if (n == 0 || n == 1)
	{
		return 1;
	}
	else
	{
		return FiboN(n - 1) + FiboN(n - 2);
	}
}

int main() {

	return 0;
}