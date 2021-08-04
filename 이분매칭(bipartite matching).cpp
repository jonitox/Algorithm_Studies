#include <iostream>
#include <string>
#include <cstring>
#include <list>
#include <vector>
#include <map>
#include <set>
#include <stack>
#include <queue>
#include <algorithm>
#include <typeinfo>
#include <iomanip>
#include <math.h>

#define INF 2000000000
using namespace std;
#define mod 1000000007

// 이분 매칭 // 복잡도 : V*E
int n, m;
int adj[200][200]; // 인접행렬. // 인접리스트로 구현해도된다.
vector<bool> vis;
int amatch[200], bmatch[200]; // amatch는 굳이 필요없다.

// A의 원소 a에서 증가 경로를 탐색한다.
bool dfs(int a) {
	if (vis[a]) return false; // 이미 방문하여 탐색한 점이면 이 점으로부터 경로가 없다.
	vis[a] = true;
	for (int b = 0; b < m; ++b) { // B를 순회하며
		if(adj[a][b]) // 연결된 b의 원소에 대해
			// 아직 match가 없다면 연결 //** 혹은 match가 있다면 대응되는 A원소에서 다시 증가경로를 탐색해본다. = match 재배열
			if (bmatch[b] == -1 || dfs(bmatch[b])) { 
				amatch[a] = b;
				bmatch[b] = a;
				return true;
			}
	}
	return false;
}


void solve() {
	cin >> n >> m;

	//간선 추가
	for (int i = 0; i < n; ++i) {
		int a;
		cin >> a;
		for (int j = 0; j < a; ++j) {
			int b;
			cin >> b;
			adj[i][b - 1] = 1;
		}
	}

	int ans = 0;
	// 이분 매칭
	// match 초기화
	memset(amatch, -1, sizeof(amatch));
	memset(bmatch, -1, sizeof(bmatch));
	for (int i = 0; i < n; ++i) {
		vis = vector<bool>(200, false); // vis배열 초기화 //**매 탐색 출발마다  초기화한다. (재배치를 할수도 있으므로)
		if (dfs(i)) {
			ans++; //매 성공시 매칭 +1
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