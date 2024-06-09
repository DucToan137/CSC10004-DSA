#include<iostream>
#include<vector>
#include<queue>
#include<stack>
using namespace std;

#define mx 1001

int n, m;
bool visited[mx];
vector<int>adj[mx];
int parent[mx];

void inp()
{
	cin >> n >> m;
	for (int i = 0; i < m; i++)
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
	//cout << u << " ";
	visited[u] = true;
	for (int x : adj[u])
	{
		if (!visited[x])
		{
			parent[x] = u;
			DFS(x);
		}
	}
}

void BFS(int u)
{
	queue<int> q;
	q.push(u);
	visited[u] = true;

	while (!q.empty())
	{
		int v = q.front();
		q.pop();
		for (int x : adj[v])
		{
			if (!visited[x])
			{
				q.push(x);
				//cout << x << " ";
				visited[x];
				parent[x] = v;
			}
		}
	}
}
void Path(int s, int t)
{
	memset(parent, 0, sizeof(parent));
	DFS(s);
	if (!visited[t])
	{
		cout << "Khong co duong di" << endl;
	}
	else
	{
		vector<int> path;
		while (t != s)
		{
			path.push_back(t);
			t = parent[t];
		}
		path.push_back(s);
		reverse(begin(path), end(path));
		cout << "Duong di: ";
		for (int x : path)
		{
			cout << x << " ";
		}
	}
}
int main()
{
	inp();
	Path(1, 8);
	return 0;
}
