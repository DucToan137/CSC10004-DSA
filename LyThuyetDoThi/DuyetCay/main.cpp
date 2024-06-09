#include<iostream>
#include<vector>
#include<queue>
#include<stack>
#include<cstdio>
using namespace std;

int m, n;
vector<pair<int, int>> edge;
int a[1001][1001];
bool visited[1001];
vector<int>adj[1001];
int parent[1001];
int trace[1001];

void inp() {
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

// #1: Deep First Search: DFS (de quy)
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

// #1.2: Deep First Search: DFS (stack)
//void DFS1(int u)
//{
//	stack<int> s;
//	s.push(u);
//	visited[u] = true;
//	cout << u << " ";
//
//	while (!s.empty())
//	{
//
//		int v = s.top();
//		s.pop();
//		for (int x : adj[v])
//		{
//			if (!visited[x])
//			{
//				s.push(x);
//				cout << x << " ";
//				visited[x] = true;
//			}
//		}
//	}
//}

//void DFS1(int startVertex) {
//	// Mảng để theo dõi đỉnh đã được duyệt
//	
//
//	// Ngăn để thực hiện DFS
//	stack<int> s;
//
//	// Bắt đầu từ đỉnh startVertex
//	s.push(startVertex);
//
//	while (!s.empty()) {
//		// Lấy đỉnh hiện tại từ ngăn
//		int currentVertex = s.top();
//		s.pop();
//
//		// Nếu đỉnh chưa được duyệt, in ra và đánh dấu đã duyệt
//		if (!visited[currentVertex]) {
//			cout << currentVertex << " ";
//			visited[currentVertex] = true;
//		}
//
//		// Duyệt các đỉnh kề của đỉnh hiện tại
//		for (int neighbor : adj[currentVertex]) {
//			if (!visited[neighbor]) {
//				s.push(neighbor);
//			}
//		}
//	}
//}
// #2 Breadth First Search
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
	inp();
	
	/*freopen("case.txt", "r", stdin);
	freopen("result.txt", "w", stdout);

	memset(visited, false, sizeof(visited));
	memset(trace, -1, sizeof(trace));
	
	int a, b, c, d;
	cin >> a >> b >> c >> d;
	for (int i = 1; i <= m; i++)
	{
		cin >> a >> b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}*/
	DFS(1);

	/*int re[1001], k = 0;
	if (trace[d] == -1)
	{
		cout << "not found" << endl;
	}
	else
	{
		while (d != c)
		{
			re[++k] = c;
			for (int i = k; i > 0; i--)
			{
				cout << re[i] << " ";
			}
		}
	}*/

	return 0;
}

