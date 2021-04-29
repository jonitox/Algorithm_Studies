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
#define mod 1000000007

using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<bool> vb;
typedef vector<long long> vll;
typedef vector<vector<int>> vvi;
typedef pair<int, int> pii;
typedef vector<pii> vpii;

// 네트워크 플로우 // min(O(E*F),O(V*E^2))
// 포드풀커슨 or 에드몬드 카프

vi adj[60];
int cap[60][60], flow[60][60];
void solve() {
	int n;
	cin >> n;
	for (int i = 0; i < n; ++i) {
		char a, b;
		int c;
		cin >> a >> b>>c;
		adj[a - 'A'].push_back(b - 'A');
		adj[b - 'A'].push_back(a - 'A');
		cap[a - 'A'][b - 'A'] += c;
		cap[b - 'A'][a - 'A'] += c;
	}
	int src = 0, sink = 'Z'-'A'; 
	// 포드 풀커슨
	int ans = 0;
	// bfs로 흐를수있는 경로를 찾아 유량을 흘러준다(증가경로). // 경로를 못찾을때까지.
	// bfs수행시 잔여용량이 있는 간선들만 이용가능하다. 즉, 잔여용량이 남은 간선들로 source에서 sink까지의 경로를 탐색.
	while (true) {
		// bfs한번 돌릴때 bfs트리상 경로의 parent저장. // 이 값을 이용해 유량을 흘려준다.
		vi pr(60, -1);
		// 0은 source // 큐에 추가
		queue<int> q;
		q.push(0);
		pr[0] = 0; 
		// bfs // 모든 방문가능 노드를 방문하거나, sink까지 경로를 찾을때까지
		while (!q.empty() && pr[sink]==-1) {
			int here = q.front();
			q.pop();
			for (int i : adj[here]) {
				// 아직 방문하지 않았으면서, here로 부터 갈수있는 노드인경우(here-i 사이 잔여용량이 0보다 큰 경우)
				if (pr[i]==-1 && cap[here][i] - flow[here][i] > 0) {
					q.push(i);
					pr[i] = here; // here에서 방문한다.
				}
			}
		}
		// sink까지 경로가 없다면 더이상 sink로 유량을 흐르지 못한다.
		if (pr[sink] == -1)
			break;
		
		// 유량 계산.
		int amt = INF;
		// sink-source사이의 경로에서 최소 잔여용량이 최대로 보낼수있는 유량이 된다.
		for (int i = sink; i != 0; i = pr[i]) {
			amt = min(amt, cap[pr[i]][i] - flow[pr[i]][i]);
		}
		ans += amt; // 최종유량에 더해준다.
		// 유량을 흘려보내준다. 경로의 이용간선들에 유량을 계산해준다.
		for (int i = sink; i != 0; i = pr[i]) {
			flow[pr[i]][i] += amt;
			flow[i][pr[i]] -= amt; // 역방향 유량 계산.
		}
	}
	cout << ans << "\n";
}

int main() {
	cin.sync_with_stdio(false);
	cin.tie(0);
	cout.sync_with_stdio(false);
	cout.tie(0);
	solve();

	return 0;
}