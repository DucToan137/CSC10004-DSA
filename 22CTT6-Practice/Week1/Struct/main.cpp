#include<iostream>
using namespace std;


struct fraction {
	int num;
	int denom;
};

float UCLN(float x, float y)
{
	while (x != y)
	{
		if (x > y)
			x -= y;
		else
			y -= x;
	}
	return x;
}
fraction RutGon(fraction& a)
{
	float gcd = UCLN(a.num, a.denom);
	a.num = a.num / gcd;
	a.denom = a.denom / gcd;
	return a;
}


fraction Tong(fraction a, fraction b)
{
	fraction kq;
	kq.num = a.num * b.denom + a.denom * b.num;
	kq.denom = a.denom * b.denom;
	RutGon(kq);
	return kq;
}

fraction Hieu(fraction a, fraction b)
{
	fraction kq;
	kq.num = a.num * b.denom - a.denom * b.num;
	kq.denom = a.denom + b.denom;
	RutGon(kq);
	return kq;
}

fraction Tich(fraction a, fraction b)
{
	fraction kq;
	kq.num = a.num * b.num;
	kq.denom = a.denom * b.denom;
	RutGon(kq);
	return kq;
}

fraction Thuong(fraction a, fraction b)
{
	fraction kq;
	kq.num = a.num * b.denom;
	kq.denom = a.denom * b.num;
	RutGon(kq);
	return kq;
}

void Nhap(fraction& a)
{
	cin >> a.num >> a.denom;
}

void Xuat(fraction& a)
{
	cout << a.num << "/" << a.denom << endl;
}


//////////////////////////////////////////////////////////////


struct Time {
	int hrs;
	int mins;
	int secs;
};

void xuat(Time& a)
{
	if (a.hrs == 0 || a.hrs < 10)
	{
		if (a.mins == 0 || a.mins < 10)
		{
			if (a.secs == 0 || a.secs < 10)
			{
				cout << "0" << a.hrs << ":0" << a.mins << ":0" << a.secs << endl;
				return;
			}
			cout << "0" << a.hrs << ":0" << a.mins << ":" << a.secs << endl;
			return;
		}
		else
		{
			if (a.secs == 0 || a.secs < 10)
			{
				cout << "0" << a.hrs << ":" << a.mins << ":0" << a.secs << endl;
				return;
			}
			cout << "0" << a.hrs << ":" << a.mins << ":" << a.secs << endl;
			return;
		}

	}
	cout << a.hrs << ":" << a.mins << ":" << a.secs << endl;

}

void xuli(Time& a, Time& b)
{
	Time kq;
	kq.secs = a.secs + b.secs;
	kq.mins = a.mins + b.mins;
	kq.hrs = a.hrs + b.hrs;
	if (kq.secs >= 60)
	{
		if (kq.secs == 60)
		{
			kq.mins++;
			kq.secs = 0;
		}
		else
		{
			kq.mins++;
			kq.secs = kq.secs - 60;
		}
	}
	if (kq.mins >= 60)
	{
		if (kq.mins == 60)
		{
			kq.hrs++;
			kq.mins = 0;
		}
		else
		{
			kq.hrs++;
			kq.mins = kq.mins - 60;
		}
	}
	xuat(kq);
}




int main() {


	return 0;
}