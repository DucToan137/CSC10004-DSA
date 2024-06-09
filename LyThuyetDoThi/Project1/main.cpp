#include<iostream>
#include<stack>
#include<queue>
#include<vector>
#include<string>
#include<sstream>
using namespace std;


int a[1000][1000];
vector<int>adj[1000];
vector<pair<int, int>> edge;
bool visited[1000];
int parent[1000];

// #1 Danh sach canh sang ma tran ke
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
		{
			cout << a[i][j] << " ";
		}
		cout << endl;
	}
}

// #2 Danh canh sang danh sach ke
void DS_canhDS_ke(int n, int m)
{
	cin >> n >> m;
	for (int i = 0; i < m; i++)
	{
		int x, y;
		cin >> x >> y;

		adj[x].push_back(y);
		adj[y].push_back(x);

	}

	for (int i = 1; i <= n; i++)
	{
		cout << i << ": ";
		for (int so : adj[i])
		{
			cout << so << " ";
		}
		cout << endl;
	}
}

// #3 Ma tran ke sang danh sach canh
void MT_keDS_canh(int n)
{
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			cin >> a[i][j];
		}
	}

	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			if (a[i][j] && i < j)
				edge.push_back({ i,j });
		}
	}

	for (auto x : edge)
		cout << x.first << " " << x.second << endl;
}

// #4 Ma tran ke sang danh sach ke
void MT_keDS_ke(int n)
{
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			cin >> a[i][j];
		}
	}

	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			if (a[i][j])
				adj[i].push_back(j);
		}
	}
	for (int i = 1; i <= n; i++)
	{
		cout << i << ": ";
		for (int x : adj[i])
			cout << x << " ";
		cout << endl;
	}
}

// #5 Danh sach ke sang ma tran ke
void DS_keMT_ke(int n)
{
	cin >> n;
	cin.ignore();
	for (int i = 1; i <= n; i++)
	{
		string s;
		getline(cin, s);

		string num;

		stringstream ss(s);
		while (ss >> num)
		{
			a[i][stoi(num)] = 1;
		}
	}

	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			cout << a[i][j] << " ";
		}
		cout << endl;
	}
}

// #6 Danh sach ke sang danh sach canh
void DS_keDS_canh(int n)
{
	cin >> n;
	cin.ignore();
	for (int i = 1; i <= n; i++)
	{
		string s, num;
		getline(cin, s);

		stringstream ss(s);
		while (ss >> num)
		{
			if (i < stoi(num))
				edge.push_back({ i,stoi(num) });
		}
	}

	for (auto x : edge)
		cout << x.first << " " << x.second << endl;
}


void inp(int n,int m)
{
	//int m, n;
	cin >> n >> m;
	for (int i = 0; i < m; i++)
	{
		int x, y;
		cin >> x >> y;
		adj[x].push_back(y);
		adj[y].push_back(x); // neu do thi co huong thi khong co dong nay
	}
	memset(visited, false, sizeof(visited));
}

// Duyet theo chieu sau (de quy)
void DFS(int u)
{
	//cout << u << " ";
	visited[u] = true;
	for (int x : adj[u])
	{
		if (!visited[x])
		{
			// Ghi nhan cha cua x la u
			parent[x] = u;
			DFS(x);
		}
	}
}

// Duyet theo chieu rong
void BFS(int u)
{
	queue<int> q;
	q.push(u);
	visited[u] = true;

	while (!q.empty())
	{
		int v = q.front();
		q.pop();
		cout << v << " ";

		for (int x : adj[v])
		{
			if (!visited[x])
			{
				q.push(x);
				visited[x] = true;
			}
		}
	}
}

// Duyet theo chieu sau (stack)
void DFS1(int u)
{
	stack<int> s;
	s.push(u);
	visited[u] = true;
	cout << u << " ";

	while (!s.empty())
	{
		
		int v = s.top();
		s.pop();
		for (int x : adj[v])
		{
			if (!visited[x])
			{
				s.push(x);
				cout << x << " ";
				visited[x] = true;
			}
		}
	}
}

// Dem so thanh phan lien thong
void ConnectedComponent(int n)
{
	int cnt = 0;
	memset(visited, false, sizeof(visited));
	for (int i = 1; i <= n; i++)
	{
		if (!visited[i])
		{
			++cnt;
			cout << "Cac dinh thuoc thanh phan lien thong thu " << cnt << ": ";
			DFS(i);
			cout << endl;
		}
	}
	cout << "So thanh phan lien thong cua do thi: " << cnt << endl;
	if (cnt == 1)
		cout << "Do thi lien thong" << endl;
	else
		cout << "Do thi khong lien thong" << endl;
}

// Tim duong di giua 2 dỉnh
void Path(int s, int t)
{
	memset(visited, false, sizeof(visited));
	memset(parent, 0, sizeof(parent));
	DFS(s);

	if (!visited[t])
		cout << "Khong co duong di" << endl;
	else
	{
		// Truy vet duong di
		vector<int> path;
		while (t != s)
		{
			path.push_back(t);
			// Lan nguoc lai
			t = parent[t];

		}
		path.push_back(s);
		reverse(path.begin(), path.end());
		for (int x : path)
			cout << x << " ";
	}
}

int main() {

	int a = 0;
	int b = 0;
	int n = 0;
	int m = 0;
	cin >> n >> m;
	//DFS(1);
	for (int i = 0; i < m; i++)
	{
		int x, y;
		cin >> x >> y;
		adj[x].push_back(y);
		adj[y].push_back(x);
	}

	//ConnectedComponent(n);
	//MT_keDS_canh(a);
	//DFS1(1);
	cin >> a >> b;
	Path(a, b);

	return 0;
}