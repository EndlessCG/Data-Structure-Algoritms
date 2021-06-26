#include <iostream>
#include <queue>
#include <vector>
#include <iomanip>
#include <algorithm>
using namespace std;
int main()
{
	int n, w;
	int i, j;
	priority_queue<int, vector<int>, greater<int>> q;
	cin >> n;
	for (i = 0; i < n; i++) {
		cin >> w;
		q.push(w);
	}
	while (q.size() != 1) {
		int a = q.top();
		q.pop();
		int b = q.top();
		q.pop();
		cout << a << ' ' << b << ' ';
		q.push(a + b);
	}
	cout << q.top() << endl;
}
