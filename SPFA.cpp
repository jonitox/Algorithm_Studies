#include <iostream>
#include <string>
#include <cstring>
#include <set>
#include <vector>
#include<map> 
#include <stack>
#include <queue>
#include <algorithm>
#include <typeinfo>
#include <iomanip>
#include <cmath>

#define INF 1000000000

using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<bool> vb;
typedef vector<long long> vll;
typedef vector<vector<int>> vvi;
typedef pair<int, int> pii;
typedef vector<pii> vpii;

// SPFA 알고리즘 // O(VE), 평균 O(E)
// 가중치그래프의 한 노드에서 나머지 노드단까지 최단경로 계산.
// 음수 간선 포함 가능. // 음수 사이클 판별 가능.
// 다익스트라와 똑같다. 단, pq가 아닌 queue를 사용하며, update되어도 큐에 없는 경우에만 추가한다는것만 다름.
int n, m;
vector<vpii> adj;
vi dis;
vi cycle; // 해당 정점의 update횟수.(**큐에 추가한 횟수) // n번 이상 update된다면 노드가 음수사이클 위에 존재한다. //음수사이클 판별 가능.
vb inQ; // 큐에 해당정점이 있는지 저장. // update한 노드가 큐에 이미 있다면 중복에서 추가하지않기 위함. 
void solve() {
	cin >> n >> m;
	adj.resize(n);
	for (int i = 0; i < m; ++i) {
		int a, b, c;
		cin >> a >> b >> c;
		adj[a-1].push_back({ b - 1,c });
	}


	dis = vi(n, INF), cycle = vi(n,0), inQ = vb(n, false); //초기화
	queue<int> q;
	q.push(0); // 기준점이 0
	dis[0] = 0; inQ[0] = true; cycle[0]++;
	// update가 일어나지않을때까지 반복한다.
	while (!q.empty()) {
		int here = q.front();
		q.pop();
		inQ[here] = false; //큐에서 제거.
        // here에 연결되있는 노드들에 대해 갱신가능한지 확인.
        // (here까지의 거리가 update되어서 큐에 들어있었고, 따라서 이에 연결된 다른노드까지의 거리도 updaste할수있는지 확인한다.)
            for (auto i : adj[here]) {
			int there = i.first;
			int cost = i.second;
			// update가 가능한 경우만
			if (dis[there] <= dis[here] + cost) continue; 
			// update
			dis[there] = dis[here] + cost;
			// 큐에 없다면 큐에 추가한다. // there로부터 연결된 다른노드까지의 거리도 다시 갱신하기 위함이다.
            // 큐에 이미 있다면 다시 넣어줄 필요는 없다.
			if (!inQ[there]) {
				cycle[there]++; // there를 update한 횟수+1 //**정확히는, 큐에추가한 횟수. 
				if (cycle[there] >= n) {
					cout << -1 << "\n"; // 음수 사이클이 존재! // 출력 후 함수 종료.
					return;
				}
				q.push(there);
				inQ[there] = true;
			}
		}
	}
	for (int i = 1; i < n; ++i)
		cout << dis[i] << "\n";
}

int main() {
	cin.sync_with_stdio(false);
	cin.tie(0);
	cout.sync_with_stdio(false);
	cout.tie(0);
	
	solve();

	return 0;
}