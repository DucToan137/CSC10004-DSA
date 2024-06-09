#include<iostream>
#include<queue>
#include<vector>

using ll = long long;
using namespace std;

#define mx 1001

struct canh {
	int x, y, w;
};


int m, n, s, t;
vector<pair<int, int>>adj[mx];
bool visited[mx];
int pre[mx];
int d[mx];

void inp()
{
	cin >> n >> m >> s >> t;
	for (int i = 0; i < m; i++)
	{
		int x, y, w;
		cin >> x >> y >> w;
		adj[x].push_back({ y,w });
		adj[y].push_back({ x,w });
	}
	memset(visited, false, sizeof(visited));
	//for (int i = 1; i <= n; i++)
		//d[i] = INT_MAX;
}

void Prim_1(int u)
{
	vector<canh>MST;
	visited[u] = true;
	int res = 0;

	while (MST.size() < n - 1)
	{
		int min_w = INT_MAX;
		int X, Y;
		for (int i = 1; i <= n; i++)
		{
			if (visited[i])
			{
				for (auto it : adj[i])
				{
					int j = it.first, trongso = it.second;
					if (!visited[j] && trongso < min_w)
					{
						min_w = trongso;
						X = j; Y = i;
					}
				}
			}
		}
		MST.push_back({ X,Y,min_w });
		res += min_w;
		visited[X] = true;
	}
	cout << res;
}

void Prim_2(int u)
{
	vector<canh>MST;
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>>q;
	int res = 0;
	q.push({ 0,u });
	while (!q.empty())
	{
		pair<int, int>top = q.top();
		q.pop();
		int dinh = top.second;
		int trongso = top.first;
		if (visited[dinh]) continue;
		res += trongso;
		visited[dinh] = true;
		if (u != dinh)
			MST.push_back({ dinh,pre[dinh],trongso });
		for (auto it : adj[dinh])
		{
			int y = it.first;
			int w = it.second;
			if (!visited[y] && d[y] > w)
			{
				d[y] = w;
				pre[y] = dinh;
				q.push({ d[y],y });
			}
		}
	}
	cout << res;
}

void Dijkstra(int s,int t)
{
	vector<ll>d(n + 1, 1e9);
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;
	q.push({ 0,s });

	d[s] = 0;
	pre[s] = 0;

	while (!q.empty())
	{
		pair<int, int>top = q.top();
		q.pop();
		int u = top.second;
		int trongso = top.first;
		
		if (visited[u]) continue;
		visited[u] = true;
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
	for (int i = 1; i <= n; i++)
		cout << d[i] << " ";
}
int main() {
	inp();
	Dijkstra(1,6);
	//Prim_2(2);
	return 0;
}