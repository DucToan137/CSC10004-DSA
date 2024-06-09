#include<iostream>
#include<vector>
#include<queue>
#include<stack>
using namespace std;

#define mx 1001

int n, m;
bool visited[mx];
vector<int> adj[mx];
vector<pair<int, int>> edge;
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
	cout << u << " ";
	visited[u] = true;
	for (int i : adj[u])
		if (!visited[i])
			DFS(i);
}

void connectedComponent()
{
	int cnt = 0;
	for (int i = 1; i <= n; i++)
	{
		if (!visited[i]) {
			++cnt;
			cout << "Thanh phan lien thong thu " << i << ": ";
			DFS(i);
			cout << endl;
		}
	}
	cout << "So thanh phan lien thong: " << cnt << endl;
	if (cnt == 1)
		cout << "Do thi lien thong" << endl;
	else
		cout << "Do thi khong lien thong" << endl;
}

int main() {
	inp();
	connectedComponent();
	return 0;
}