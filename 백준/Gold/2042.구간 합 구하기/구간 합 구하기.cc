#include <bits/stdc++.h>
#include <cmath>
#include <limits.h>
#define endl '\n'
using namespace std;
using ll = long long;

int N, M, K; // M: update, K: summation
vector<ll> arr; // 숫자 입력 배열
vector<ll> tree;

void Update() {
    return;
}

ll Init(int node, int start, int end) {
    if (start == end) {
        return tree[node] = arr[start];
    }
    return tree[node] = Init(node * 2, start, (start + end) / 2) + Init(node * 2 + 1, (start + end) / 2 + 1, end);
}

ll Sum(int left, int right, int node, int start, int end) {
    if (left > end || right < start) {
        return 0;
    }

    if (left <= start && right >= end) {
        return tree[node];
    }

    return Sum(left, right, node * 2, start, (start + end) / 2)  + Sum(left, right, node * 2 + 1, (start + end) / 2 + 1, end);
}

void Update(int node, int start, int end, int idx, ll diff) {
    if (idx < start || idx > end) {
        return;
    }

    tree[node] += diff;

    if (start != end){
        Update(node * 2, start, (start + end) / 2, idx, diff);
        Update(node * 2 + 1, (start + end) / 2 + 1, end, idx, diff);
    } // 리프 노드가 아니면
}

void Input() {
    ll a, b, c;
	int h;

    cin >> N >> M >> K;
	arr.resize(N);
	h = (int)ceil(log2(N));
	tree.resize(1 << (h + 1));
    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }
    Init(1, 0, N - 1);
	while (M || K) {
		cin >> a >> b >> c;
		
		if (a == 1) {//update
			Update(1, 0, N - 1, b - 1, c - arr[b - 1]);
			arr[b - 1] = c; // 중요한 부분, 값을 Update해주면 원본 입력 배열에서도 반영을 해야한다.
			M--;
		}
		
		if (a == 2) {//print summation
			cout << Sum(b - 1, c - 1, 1, 0, N - 1) << endl;
			K--;
		}
	}   
}

void Solve() {
    Input();
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    //freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    Solve();
    return 0;
}
