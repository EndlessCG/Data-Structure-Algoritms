#include <iostream>
#include <iomanip>
#include <algorithm>
#define INF 999999999
using namespace std;
struct edge {
	int p1, p2;
	int w;
	edge(int p1, int p2, int w) :p1(p1), p2(p2), w(w) {};
	edge() {};
};
int main()
{
	int i, j, m, n;
	cin >> m >> n;
	int* dist = new int[n + 1];
	bool* inGraph = new bool[n + 1];
	int* path = new int[n + 1];
	for (i = 0; i <= n; i++) {
		dist[i] = INF;
		inGraph[i] = false;
	}
	edge* es = new edge[m];
	for (j = 0; j < m; j++) {
		cin >> es[j].p1 >> es[j].p2 >> es[j].w;
	}
	dist[1] = 0;
	for (i = 0; i < n; i++) {
		int min = INF;
		int minj;
		for (j = 1; j <= n; j++) {
			if (!inGraph[j] && dist[j] < min) {
				min = dist[j];
				minj = j;
			}
		}
		inGraph[minj] = true;
		if(minj != 1)cout << minj << ' ' << path[minj] << endl;
		for (j = 0; j < m; j++) {
			if (es[j].p1 == minj && !inGraph[es[j].p2] && es[j].w < dist[es[j].p2]) {
				dist[es[j].p2] = es[j].w;
				path[es[j].p2] = minj;//Difference with Dijkstra: here dist is set to "distance to graph" not"distance to origin".
			}
			if (es[j].p2 == minj && !inGraph[es[j].p1] && es[j].w < dist[es[j].p1]) {
				dist[es[j].p1] = es[j].w;
				path[es[j].p1] = minj;
			}
		}
	}

}
