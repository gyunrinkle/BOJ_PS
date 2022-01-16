#include <bits/stdc++.h>
#include <limits.h>
#define endl '\n'

using namespace std;
const int MAX = 1000000;
int n, m;
int root[MAX + 1];

void InitRoot() {
	for (int i = 0; i <= n; i++) {
		root[i] = i;
	}
}

int Find(int x) {
	if (root[x] == x) return x;
	return root[x] = Find(root[x]);
}

void Union(int x, int y) { // x가 루트 역할, y가 자식 역할
	int root_x, root_y;

	root_x = Find(x);
	root_y = Find(y);
	
	root[root_y] = root_x;
}

void Input() {
	int c, a, b;
	cin >> n >> m;
	InitRoot();
	for (int i = 0; i < m; i++) {
		cin >> c >> a >> b;
		if (c == 0) {
			Union(a, b);
			continue;
		}
		if (c == 1) {
			if (Find(a) == Find(b)) cout << "YES" << endl;
			else cout << "NO" << endl;
			continue;
		}
	}
}

void Solve() {
	Input();	
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	Solve();
	return 0;
}
// 첫째 줄에 n(1 ≤ n ≤ 1,000,000), m(1 ≤ m ≤ 100,000)이 주어진다. 
// m은 입력으로 주어지는 연산의 개수이다. 
// 다음 m개의 줄에는 각각의 연산이 주어진다. 
// 합집합은 0 a b의 형태로 입력이 주어진다. 
// 이는 a가 포함되어 있는 집합과, b가 포함되어 있는 집합을 합친다는 의미이다. 
// 두 원소가 같은 집합에 포함되어 있는지를 확인하는 연산은 1 a b의 형태로 입력이 주어진다. 
// 이는 a와 b가 같은 집합에 포함되어 있는지를 확인하는 연산이다. 
// a와 b는 n 이하의 자연수 또는 0이며 같을 수도 있다.