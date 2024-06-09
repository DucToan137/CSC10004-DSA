#include<iostream>
#include<queue>
#include<vector>

using namespace std;
using ll = long long;
#define mx 100001

int m, n, s, t;
vector<pair<int, int>> adj[mx];
int pre[mx];

const int INF = 1e9;
void inp()
{
	cin >> n >> m >> s >> t;
	for (int i = 0; i < m; i++)
	{
		int x, y, w;
		cin >> x >> y >> w;
		adj[x].push_back({ y,w });
		//adj[y].push_back({ x,w });
	}
}

void Dijkstra(int s,int t)
{
	vector<ll>d(n + 1, INF);
	//vector<bool>visited(n + 1, false);
	// neu dung mang visted thi thay if(kc > d[u]) bang 2 dong duoi

	d[s] = 0;
	pre[s] = s;

	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> Q;
	Q.push({ 0,s });
	while (!Q.empty())
	{
		pair<int, int> top = Q.top();
		Q.pop();
		int u = top.second;
		int kc = top.first;
		if (kc > d[u]) continue; // dong nay hoac la 2 dong duoi

		//if (visited[u]) continue;
		//visited[u] = true;

		for (pair<int,int> it : adj[u])
		{
			int v = it.first;
			int w = it.second;
			if (d[v] > d[u] + w)
			{
				d[v] = d[u] + w;
				Q.push({ d[v],v });
				pre[v] = u;
			}
		}
	}
	// neu muon tra duong di
	cout << d[t] << endl;
	vector<int>path;
	while (1)
	{
		path.push_back(t);
		if (t == s) break;
		t = pre[t];
	}
	reverse(begin(path), end(path));
	for (int x : path)
		cout << x << " ";
	//

	// in ra khoang cach ngan nhat toi cac dinh
	/*for (int i = 1; i <= n; i++) {
		cout << d[i] << ' ';
	}*/
}

int main()
{
	inp();
	Dijkstra(s,t);
	return 0;
}