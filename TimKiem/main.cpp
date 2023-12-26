#include<iostream>
using namespace std;

int binarySearch(int arr[], int l, int r, int x) 
{
    while (l <= r) {
        int m = l + (r - l) / 2;

        if (arr[m] == x)
            return m;
        if (arr[m] < x)
            l = m + 1;
        else
            r = m - 1;
    }
    return -1;
}

double Sqrt(double x) 
{
    if (x < 0.0)
        return -1;

    if (x == 0.0 || x== 1.0) 
        return x;

    double left = 0.0, right = x;

    while (left < right) 
    {
        double mid = left + (right - left) / 2;

        if (mid <= x / mid) 
            left = mid + 1;
        else 
            right = mid;
    }

    return left - 1.0;
}

void binarySearch(int a[],int n,int x)
{
    int tmp = binarySearch(a, 0, n - 1, x);
    if (tmp == -1)
        cout << "Phan tu " << x << " khong co trong mang" << endl;
    else
        cout << "Phan tu " << x << " co trong mang" << endl;
}

int main() {
    int a[7] = { 1,3,4,7,9,15,25 };

    int b = 15;
    int c = 16;
    int d = 25;
    int e = 1;

    binarySearch(a, 7, b);
    binarySearch(a, 7, c);
    binarySearch(a, 7, d);
    binarySearch(a, 7, e);
        

	return 0;
}