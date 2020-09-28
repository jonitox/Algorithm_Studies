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
#define mod 100
using namespace std;

int n, m;
vector<vector<int>> adj;
int depth[100000]; // 노드의 깊이
int pr[100000][20]; // pr[i][j]: i번 노드의 2^j번째 조상 // pr[i][0]: 부모노드 // j의 MAX값은 log2(노드수)로 잡으면 된다. N=1e5이면 최악의 경우에도 높이가 2^19을 넘지않는다.

// LCA알고리즘
// o(lgN)에 LCA를 구한다.
// M개 쿼리 총 복잡도 o(M*lgN)
// pr배열 index-error에 주의



//dfs로 순회하며 각 노드의 부모노드와 깊이 저장
void dfs(int here, int d) {
	depth[here] = d;
	for (int there : adj[here]) {
		if (depth[there] != -1) continue;
		pr[there][0] = here; // 부모노드 저장
		dfs(there, d+1); // 재귀
	}
	return;
}



void solve() {
	memset(pr, -1, sizeof(pr));
	memset(depth, -1, sizeof(depth));
	cin >> n;
	adj.resize(n);
	// 트리 입력, 그래프 생성
	for (int i = 0; i < n-1; ++i) {
		int a, b;
		cin >> a >> b;
		adj[a - 1].push_back(b - 1);
		adj[b - 1].push_back(a - 1);
	}
	// dfs
	dfs(0,0);


	//** pr[][] 계산 // 각 노드의 2^j번째 조상노드
	// 조상이 root를 넘어가면 초기화값인 -1로 저장하도록 처리함.
	for (int j = 1; j < 20; ++j) {
		for (int i = 0; i < n; ++i) {
			if(pr[i][j-1] != -1)		// index-error 방지
				pr[i][j] = pr[pr[i][j - 1]][j - 1]; //** i의 2^j번째 조상은 2^j-1번째 조상 노드의 2^j-1번째 조상이다.
		}
	}
	

	// m개 쿼리 입력, m개쌍의 LCA 찾기.
	cin >> m;
	for (int i = 0; i < m; ++i) {
		int a, b, lca;
		cin >> a >> b;
		a--; b--;
		
		// LCA 찾기
		//** a깊이가 b깊이 이상이도록 강제.
		if (depth[a] < depth[b]) swap(a, b);

		//** a와 b의 높이가 같아질때까지 a의 조상을 2^i씩 따라올라간다.
		for (int j = 19; j >= 0; --j) {
			if (pr[a][j] == -1) continue; // root를 넘어가면 무시
			// a의 2^i번째 조상이 b보다 낮게 있으면(depth가 크면) 따라올라간다.
			if (depth[pr[a][j]] >= depth[b]) {
				a = pr[a][j];
			}
		}

		//** 높이가 같아졌을떄 a와 b가 같다면 lca를 찾음. 
		lca = a;

		//** a와 b가 같지않다면, 즉 a,b가 한 조상의 서로 다른쪽 subtree에 있다면,
		if (a != b) {
			//** 마찬가지로, 같은 조상(LCA)을 만날때까지 트리를 타고 올라간다.
			for (int j = 19; j >= 0; --j) 
				if (pr[a][j] != pr[b][j]) { // 참고: a,b높이가 같으므로 둘의 각 조상이 -1인 경우는 실행안되므로, index-error 고려안해도됨.
					a = pr[a][j], b = pr[b][j];
				}
			//위 for문을 순회하고나면, LCA의 바로 밑까지 따라올라온 것이므로. a(,b)의 부모가 LCA이다.
			lca = pr[a][0];
		}
		cout << lca+1 << "\n";
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