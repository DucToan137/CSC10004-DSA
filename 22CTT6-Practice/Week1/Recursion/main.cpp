#include<iostream>

using namespace std;


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