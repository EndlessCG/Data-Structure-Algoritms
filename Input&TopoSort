#include <iostream>
#include <stack>
#include <iomanip>
#include <algorithm>
using namespace std;
struct edge {
	int sp, ep;
	edge* ne;
	edge() :sp(-1), ep(-1),ne(NULL) {};
	edge(int sp, int ep, edge* ne) :ep(ep), sp(sp), ne(ne) {};
};
int main()
{
	int m, n;//m edges, n vertices.
	int i, j;
	int s, e;
	edge* ptr;
	cin >> m >> n;
	stack<int> st;
	int* indegree = new int[n + 1];
	edge** es = new edge * [n + 1];
	for (i = 1; i < n + 1; i++) {
		indegree[i] = 0;
	}
	for (i = 1; i < n + 1; i++) {
		es[i] = NULL;
	}
	//input edges
	for (i = 0; i < m; i++) {
		cin >> s >> e;
		edge* newe = new edge(s, e, NULL);
		ptr = es[s];
		if (ptr) {
			for (; ptr->ne; ptr = ptr->ne);
			ptr->ne = newe;
		}
		else {
			es[s] = newe;
		}
		//init indegree
		indegree[e]++;
	}
	//init stack
	for (i = 1; i < n + 1; i++) {
		if (indegree[i] == 0)st.push(i);
	}
	//main loop
	while (!st.empty()) {
		int p = st.top();
		st.pop();
		cout << p << endl;
		for (ptr = es[p]; ptr; ptr = ptr->ne) {
			if((--indegree[ptr->ep]) == 0)st.push(ptr->ep);
		}
	}
}
