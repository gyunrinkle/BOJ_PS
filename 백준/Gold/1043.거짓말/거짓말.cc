#include <bits/stdc++.h>
using namespace std;
const int MAX = 50;
int N, M, n_promising;
vector<int> people[MAX + 1], party[MAX + 1], promising_people;
bool is_promising[MAX + 1] = {false, };

void Connect(vector<int>& p) {
	for (const auto& person : p) {
		for (const auto& another : p) {
			if (person == another) continue;
			people[person].push_back(another);
		}
	}
}

void Input() {
	int promising_num;// 거짓말을 아는 사람
	int n_attendant, attendant; // 파티 참석 인원, 참석 사람
	cin >> N >> M;
	cin >> n_promising; // 거짓말을 아는 사람의 수
	if (n_promising != 0) {		 
		for (int i = 0; i < n_promising; i++) {
			cin >> promising_num;
			promising_people.push_back(promising_num);
		}
	}
	
	for (int i = 0; i < M; i++) {		
		cin >> n_attendant;
		for (int j = 0; j < n_attendant; j++) {
			cin >> attendant;
			party[i].push_back(attendant);
		}
		Connect(party[i]);
	}
}

void BFS(int start) {
	queue<int> q;
	q.push(start);
	while (!q.empty()) {
		int cur = q.front();
		q.pop();
		if (is_promising[cur] == false) {
			is_promising[cur] = true;
			for (const auto& next : people[cur]) {
				if (is_promising[next] == true) continue;
				q.push(next);
			}
		}
	}
}

void Solve() {
	Input();
	if (n_promising == 0) {
		cout << M << '\n';
	}
	else {
		for (const auto& person : promising_people) {
			BFS(person);
		}
		for (const auto& p : party) {
			for (const auto& person : p) {
				if (is_promising[person] == true) {
					M--;
					break;
				}
			}
		}
		cout << M << '\n';
	}
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	Solve();
	return 0;
}