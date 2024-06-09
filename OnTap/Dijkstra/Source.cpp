#include<iostream>
#include<vector>
#include<queue>

using namespace std;
using ll = long long;

#define mx 1001

vector<pair<int, int>> adj[mx];
int m, n, s, t;
int d[mx];
int pre[mx];

void inp()
{
	cin >> n >> m >> s >> t;
	for (int i = 1; i <= m; i++)
	{
		int x, y, w;
		cin >> x >> y >> w;
		adj[x].push_back({ y,w });
		adj[y].push_back({ x,w });
	}
}

void Dijkstra(int s, int t)
{
	vector<ll>d(n + 1, 1e9);
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;
	d[s] = 0;
	pre[s] = s;
	q.push({ 0,s });

	while (!q.empty())
	{
		pair<int, int> top = q.top();
		q.pop();
		int u = top.second;
		int kc = top.first;

		if (kc > d[u]) continue;
		for (auto it : adj[u])
		{
			int v = it.first;
			int w = it.second;
			if (d[v] > d[u] + w)
			{
				d[v] = d[u] + w;
				pre[v] = u;
				q.push({ d[v],v });
			}
		}
	}
	cout << d[t] << endl;
}
int main()
{
	inp();
	Dijkstra(1,5);
	return 0;
}