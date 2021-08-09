#include <iostream>
#include <string>
#include <cstring>
#include <set>
#include <vector>
#include <map>
#include <stack>
#include <queue>
#include <algorithm>
#include <typeinfo>
#include <iomanip>
#include <cmath>
#include <cstdio>
//////  #include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<bool> vb;
typedef vector<long long> vll;
typedef vector<vector<int>> vvi;
typedef vector<vector<long long>> vvll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<pii> vpii;
typedef vector<pll> vpll;
typedef vector<vector<pii>> vvpii;

#define pb push_back
#define INF 1'000'000'000
#define mod 998244353
#define EPSILON 1e-9
#define MAXN 100010

int dis[501][501];
char bd[501][501];
int dx[4] = { 0,1,0,-1 };
int dy[4] = { 1,0,-1,0 };
int h, w;


// 01 BFS // 노드의 레벨이 최대 1차이나는 노드들만 방문큐에 저장되어있는 BFS
// 다익스트라+BFS와 비슷, 하지만 구현방법은 더 간단.
// 복잡도도 BFS와 같은 O(V+E)
// deque이용.

// 문제는 ATcoder beginner contest 213 #E https://atcoder.jp/contests/abc213/tasks/abc213_e
void solve() {

	cin >> h >> w;
	for (int i = 0; i < h; ++i)
		for (int j = 0; j < w; ++j) {
			cin >> bd[i][j];
			dis[i][j] = INF;
		}
	deque<pii> q;
	q.push_front({ 0,0 }); // 시작점.
	dis[0][0] = 0;
	// BFS와 같이 큐가 빌때까지 front를 하나씩 pop
	while (!q.empty()) {
		auto here = q.front();
		q.pop_front();
		// 미방분이면서 가중치가 0이면(같은 레벨이면) 큐의 앞쪽에 추가.
		for (int i = 0; i < 4; ++i) {
			int x = here.first + dx[i];
			int y = here.second + dy[i];
			if (x >= 0 && x < h && y >= 0 && y < w && bd[x][y]=='.'&& dis[x][y] > dis[here.first][here.second]) {
				dis[x][y] = dis[here.first][here.second];
				q.push_front({ x,y });
			}
		}
		// 미방분이면서 가중치가 1(즉, 연결되어있다면)이면 큐의 뒤쪽에 추가.
		for (int i = 0; i < 5; ++i)
			for (int j = 0; j < 5; ++j) {
				if (i == 0 && j == 0) continue;
				if (i == 0 && j == 4) continue;
				if (i == 4 && j == 0)  continue;
				if (i == 4 && j == 4) continue;
				int x = here.first + (i - 2);
				int y = here.second + (j - 2);
				if (x >= 0 && x < h && y >= 0 && y < w && dis[x][y] > dis[here.first][here.second]+1) {
					dis[x][y] = dis[here.first][here.second] + 1;
					q.push_back({ x,y });
				}
			}
	}
	cout << dis[h - 1][w - 1] << "\n";
}

int main()
{
	cin.sync_with_stdio(false);
	cin.tie(0);
	cout.sync_with_stdio(false);
	cout.tie(0);

	solve();

	return 0;
}
