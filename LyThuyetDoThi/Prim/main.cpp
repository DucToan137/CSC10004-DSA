#include<iostream>
#include<vector>
#include<queue>

using namespace std;

#define mx 10001

int n, m;
vector<pair<int, int>>adj[mx];
bool used[mx];
int parent[mx];
int d[mx];

struct canh {
	int x, y, w;
};

void inp()
{
	cin >> n >> m;
	for (int i = 0; i < m; i++)
	{
		int x, y, w;
		cin >> x >> y >> w;
		adj[x].push_back({ y,w });
		adj[y].push_back({ x,w });
	}
	memset(used, false, sizeof(used));
	for (int i = 1; i <= n; i++)
		d[i] = INT_MAX;
}

void Prim_1(int u)
{
	vector<canh>MST;
	int d = 0;
	used[u] = true;

	while (MST.size() < n - 1)
	{
		int min_w = INT_MAX;
		int X,Y;
		for (int i = 1; i <= n; i++)
		{
			if (used[i]) 
			{
				for (pair<int, int> it : adj[i])
				{
					int j = it.first;
					int trongso = it.second;
					if (!used[j] && trongso < min_w)
					{
						min_w = trongso;
						X = j;
						Y = i;
					}
				}
			}
		}
		MST.push_back({ X,Y,min_w });
		d += min_w;
		used[X] = true;
	}
	cout << d << endl;
	for (canh e : MST)
	{
		cout << e.x << " " << e.y << " " << e.w << endl;
	}
}

void Prim_2(int u)
{
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>>Q;
	vector<canh>MST;
	int res = 0;
	Q.push({ 0,u });
	
	while (!Q.empty())
	{
		pair<int, int> top = Q.top();
		Q.pop();
		int dinh = top.second;
		int trongso = top.first;

		if (used[dinh]) continue;
		res += trongso;
		used[dinh] = true;
		if (u != dinh)
			MST.push_back({ dinh,parent[dinh],trongso });
		for (auto it : adj[dinh])
		{
			int y = it.first, w = it.second;
			if (!used[y] && w < d[y])
			{
				Q.push({ w,y });
				d[y] = w;
				parent[y] = dinh;
			}
		}
	}
	cout << res << endl;
	for (auto it : MST)
	{
		cout << it.x << " " << it.y << " " << it.w << endl;
	}
}

int main() {
	inp();
	Prim_1(1);
	return 0;
}