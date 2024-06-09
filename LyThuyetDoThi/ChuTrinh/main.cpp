#include<iostream>
#include<vector>
#include<queue>
#include<stack>
using namespace std;

#define mx 1001

vector<int> adj[mx];
bool visited[mx];
int parent[mx];
int color[mx];
int n, m;


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
// vo huong
bool DFS(int u, int par)
{
	visited[u] = true;
	for (int v : adj[u])
	{
		if (!visited[v])
		{
			if (DFS(v, u))
				return true;
		}
		else if (v != par)
			return true;
	}
	return false;
}

bool BFS(int u)
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
				visited[x] = true;
				parent[x] = v;
			}
			else if (x != parent[v])
				return true;
		}
	}
	return false;
}
// co huong
bool DFS_ch(int u)
{
	color[u] = 1;
	for (int v : adj[u])
	{
		if (color[v] == 0)
		{
			parent[v] = u;
			if (DFS_ch(v)) return true;
		}
		else if (color[u] == 1)
			return false;
	}
	color[u] = 2;
	return false;
}

int main() {
	inp();

	for (int i = 1; i < n; i++)
	{
		if(!visited[i])
			if (BFS(1))
			{
				cout << "yes" << endl;
				return 0;
			}
	}
	cout << "no";
	return 0;
}