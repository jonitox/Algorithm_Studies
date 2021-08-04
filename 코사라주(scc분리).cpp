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

int v, e;
vi adj[10001];
vi radj[10001];
int sccID[10001];
vi scc[10001];
bool vis[10001];
stack<int> st;
int sccCnt;

// 코사라주 알고리즘
//일반 dfs
void dfs(int here) {
	vis[here] = true;
	for (auto there : adj[here]) {
		if (!vis[there]) {
			dfs(there);
		}
	}
	st.push(here); // 종료순으로 stack에 추가. //** pop시 scc기준 위상정렬 순으로 노드방문.
}
// 역방향 dfs
void dfs2(int here) {
	vis[here] = true;
	// scc저장.
	sccID[here] = sccCnt;
	scc[sccCnt].push_back(here);
	// 현 노드에서 역방향으로 갈수있는 노드는 전부 같은 scc에 있다. 재귀로 호출
	for (auto i : radj[here])
		if (!vis[i])
			dfs2(i);
}
void solve() {
	cin >> v >> e;
	memset(vis, false, sizeof(vis));
	memset(sccID, -1, sizeof(sccID));
	for (int i = 0; i < e; ++i) {
		int a, b;
		cin >> a >> b;
		adj[a].push_back(b);
		radj[b].push_back(a); // 기존 간선의 역방향 간선을 만들어둔다.
	}
	// dfs
	for (int i = 1; i <= v; ++i) {
		if (!vis[i])
			dfs(i);
	}
	// stack에서 pop하며 역방향dfs2수행
	memset(vis, false, sizeof(vis));
	while (!st.empty()) {
		int here = st.top();
		st.pop();
		if (vis[here]) continue; // 먼저 종료됬어도 이미 방문한 점이면 무시.(다른 노드의 dfs2에의해 scc가 정해진 노드)
		// dfs2로 scc를 하나 찾는다.
		dfs2(here);
		//scc개수 증가
		sccCnt++;   	}



	// boj 2150
	cout << sccCnt << "\n";
	vpii minE(sccCnt);
	for (int i = 0; i < sccCnt;++i) {
		sort(scc[i].begin(), scc[i].end());
		minE[i] = { scc[i][0], i };
	}
	sort(minE.begin(), minE.end());
	for (int i = 0; i < sccCnt;++i) {
		for (auto j : scc[minE[i].second])
			cout << j << " ";
		cout << -1 << "\n";
	}
}

int main() {	
	cin.sync_with_stdio(false);
	cin.tie(0);
	cout.sync_with_stdio(false);
	cout.tie(0);

		solve();

	return 0;
}