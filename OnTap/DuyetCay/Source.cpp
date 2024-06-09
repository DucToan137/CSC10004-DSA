#include<iostream>
#include<vector>
#include<queue>
#include<stack>

using namespace std;

#define mx 1001

int n, m;
bool visited[mx];
vector<int> adj[mx];

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
	cout << u << " ";
	visited[u] = true;
	for (int x : adj[u])
	{
		if (!visited[u])
			DFS(x);
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
		cout << v << " ";
		for (int x : adj[v])
		{
			if (!visited[x])
			{
				visited[x] = true;
				q.push(x);
			}
		}
	}
}
int main() {

	return 0;
}