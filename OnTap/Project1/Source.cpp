#pragma warning(disable : 4996)
#include<iostream>
#include<fstream>
#include<vector>
#include<string>
#include<sstream>

using namespace std;
#define _CRT_SECURE_NO_WARNINGS_
#define mx 1001

int n, m;
vector<int> adj[mx];
bool visited[mx];
int a[mx][mx];
vector<pair<int, int>> edge;




//1 DS canh sang ma tran ke
void DS_canhMT_ke(int n, int m)
{
	cin >> n >> m;
	for (int i = 0; i < m; i++)
	{
		int x, y;
		cin >> x >> y;
		a[x][y] = a[y][x] = 1;
	}

	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
			cout << a[i][j] << " ";
		cout << endl;
	}
}

//2 DS canh sang DS ke
void DS_canhDS_ke(int n, int m)
{
	cin >> n >> m;
	for (int i = 1; i <= m; i++)
	{
		int x, y;
		cin >> x >> y;
		adj[x].push_back(y);
		adj[y].push_back(x);
	}

	for (int i = 1; i <= n; i++)
	{
		cout << i << ": ";
		for (int x : adj[i])
			cout << x << " ";
		cout << endl;
	}
}

//3 MT ke sang DS canh
void MT_keDS_canh(int n,int m)
{
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			cin >> a[i][j];
			if (i < j && a[i][j] == 1)
				edge.push_back({ i,j });
		}
	}
	for (auto it : edge)
	{
		cout << it.first << " " << it.second << endl;
	}

}

//4 MT ke sang DS ke
void MT_keDS_ke(int n, int m)
{
	cin >> n >> m;
	for (int i = 1; i < n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			cin >> a[i][j];
			if (i < j && a[i][j]==1)
			{
				adj[i].push_back(j);
				adj[j].push_back(i);
			}
		}
	}

	for (int i = 1; i <= n; i++)
	{
		cout << i << ": ";
		for (int x : adj[i])
		{
			cout << x << " ";
		}
		cout << endl;
	}
}

//5 DS ke sang MT ke
void DS_keMT_ke(int n,int m)
{
	cin >> n >> m;
	cin.ignore();
	for (int i = 1; i <=n; i++)
	{
		
		string s;
		getline(cin, s);

		stringstream ss(s);
		string num;
		while(ss>>num)
		{
			a[i][stoi(num)] = 1;
		}
	}

	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
			cout << a[i][j] << " ";
		cout << endl;
	}
}

//6 DS ke sang DS canh
void DS_keDS_canh(int n, int m)
{
	cin >> n >> m;
	cin.ignore();
	for (int i = 1; i <= n; i++)
	{
		string s, num;
		getline(cin, s);

		stringstream ss(s);
		while (ss >> num)
		{
			if (i < stoi(num))
			{
				edge.push_back({ i,stoi(num) });
			}
		}
	}

	for (auto it : edge)
		cout << it.first << " " << it.second << endl;
}
int main()
{
	
	//freopen("data.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	
	/*ifstream input("data.txt");
	ofstream output("output.txt");

	if (!input.is_open())
		cout << "khong the mo file" << endl;
	else
	{
		cout << "mo file thanh cong" << endl;
		input >> n;
		input >> m;
		for (int i = 0; i < m; i++)
		{
			int x, y;
			input >> x >> y;
			a[x][y] = a[y][x] = 1;
		}
	}

	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
			output << a[i][j] << " ";
		output << endl;
	}*/
	DS_keDS_canh(n,m);
	
	
	
	return 0;
}



























