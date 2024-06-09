#include<iostream>
#include<vector>
#include<queue>
#include<stack>
using namespace std;

#define mx 1001

char a[mx][mx];
vector<int> adj[mx];
bool visited[mx][mx];
int parent[mx];
int n, m, s, t, u, v;
int dx[4] = { -1,0,0,1 };
int dy[4] = { 0,-1,1,0 };
int d[mx][mx];




void BFS(int i, int j)
{
	queue<pair<int, int>> q;
	q.push({ i,j });
	a[i][j] = 'o';
	cout << i << " " << j << endl;

	while (!q.empty())
	{
		pair<int, int> top = q.front();
		q.pop();

		for (int k = 0; k < 4; k++)
		{
			int i1 = top.first + dx[k];
			int j1 = top.second + dy[k];
			if (i1 >= 1 && i1 <= n && j1 >= 1 && j1 <= n && a[i1][j1] == 'x')
			{
				cout << i1 << " " << j1 << endl;
				q.push({ i1,j1 });
				a[i1][j1] = 'o';
			}
		}
	}
}

void DFS(int i, int j)
{
	cout << i << " " << j << endl;
	visited[i][j] = true;
	 //a[i][j] = 'o';

	for (int k = 0; k < 4; k++)
	{
		int i1 = i + dx[k];
		int j1 = j + dy[k];
		if (i1 >= 1 && i1 <= n && j1 >= 1 && j1 <= n && a[i][j] == 'x' && !visited[i1][j1])
			DFS(i1, j1);
	}
}

void inp()
{
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			cin >> a[i][j];
	memset(visited, false, sizeof(visited));

	int cnt = 0;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			if (a[i][j] == 'x' && !visited[i][j]) // DFS
			//if(a[i][j]=='x')  // BFS (loi)
			{
				cout << "Thanh phan lien thong thu " << cnt + 1 << ": ";
				DFS(i, j);
				++cnt;
			}
		}
	}
	cout << cnt << endl;
}


// Kiem tra duong di giua 2 diem tren luoi
bool DFS_2(int i, int j)
{
	if (a[i][j] == 'B')
		return true;
	a[i][j] = 'x';
	// Duyet cac dinh ke
	for (int k = 0; k < 4; k++)
	{
		int i1 = i + dx[k];
		int j1 = j + dy[k];
		if (i1 >= 1 && i1 <= n && j1 >= 1 && j1 <= n && a[i1][j1] != 'x')
		{
			if (DFS_2(i1, j1))
				return true;
		}
	}
	return false;
}

bool BFS_2(int i, int j)
{
	queue<pair<int, int>> q;
	q.push({ i,j });
	a[i][j] = 'o';

	while (!q.empty())
	{
		pair<int, int>top = q.front();
		q.pop();
		for (int k = 0; k < 4; k++)
		{
			int i1 = top.first + dx[k];
			int j1 = top.second + dy[k];
			if (i1 >= 1 && i1 <= n && j1 >= 1 && j1 <= n && a[i1][j1] != 'x')
			{
				if (a[i1][j1] == 'B')
					return true;
				q.push({ i1,j1 });
				a[i1][j1] = 'o';
			}
		}
	}
	return false;
}

void inp_2()
{
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			cin >> a[i][j];
			if (a[i][j] == 'A')
				s = i; t = j;
		}
	}
	memset(visited, false, sizeof(visited));
	if (BFS_2(s, t))
	{
		cout << "yes" << endl;
	}
	else
		cout << "no" << endl;
}

// Tim duong di ngan nhat giua 2 diem (loi)
void BFS_3(int i, int j)
{
	queue<pair<int, int>>q;
	q.push({ i,j });
	a[i][j] = 'x';
	d[i][j] = 0;

	while (!q.empty())
	{
		pair<int, int> top = q.front();
		q.pop();
		for (int k = 0; k < 4; k++)
		{
			int i1 = top.first + dx[k];
			int j1 = top.second + dy[k];
			if (i1 >= 1 && i1 <= n && j1 >= 1 && j1 <= n && a[i1][j1] != 'x')
			{
				d[i1][j1] = d[top.first][top.second] + 1;
				if (a[i1][j1] == 'B') return;
				q.push({ i1,j1 });
				a[i1][j1] = 'x';
			}
		}
	}
}

void inp_3()
{
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; i++)
		{
			cin >> a[i][j];
			if (a[i][j] == 'A')
			{
				s = i; t = j;
			}
			else if(a[i][j]=='B')
			{
				u = i; v = j;
			}
		}
	}
	memset(visited, false, sizeof(visited));
	BFS(s, t);
	if (!d[u][v])
		cout << "Khong co duong di" << endl;
	else
		cout << d[u][v] << endl;
}

int main() {
	inp_3();

	return 0;
}