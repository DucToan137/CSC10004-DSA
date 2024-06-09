#include<iostream>
#include<queue>
#include<vector>

using namespace std;

#define mx 1001

int n, m;
vector<int> adj[mx];
bool visited[mx];

void inp()
{
	cin >> n >> m;
	for (int i = 1; i <= m; i++)
	{
		int x, y;
		cin >> x >> y;
		adj[x].push_back(y);
		adj[y].push_back(x);
	}
	memset(visited, false, sizeof(visited));
}

void DFS(int u)
{
	cout << u << " ";
	visited[u] = true;
	for (int x : adj[u])
	{
		if (!visited[x])
			DFS(x);
	}
}

void connectedComponent()
{
	int cnt = 0;
	for (int i = 1; i <= n; i++)
	{
		
		if (!visited[i])
		{
			++cnt;
			cout << "Thanh phan lien thong thu " << cnt << ": ";	
			DFS(i);
			cout << endl;
		}
		
	}
	if (cnt == 1)
		cout << "Do thi lien thong" << endl;
	else
	{
		cout << "Do thi khong lien thong" << endl;
		cout << "So thanh phan lien thong: " << cnt << endl;
	}
}

int main()
{
	inp();
	connectedComponent();
	return 0;
}