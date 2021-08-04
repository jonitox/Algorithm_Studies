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

#define INF 1000000010
#define mod 1000000007
#define MAXN 10010


// 위상정렬 // queue를 이용하는 방법.
int n, m;
vi adj[32001];
int indeg[32001];

void solve() {
	cin >> n >> m;
	for (int i = 0; i < m; ++i) {
		int a, b;
		cin >> a >> b;
		adj[a].push_back(b);
		indeg[b]++;
    }
    // indegre =0 인 점부터 방문하며, 방문한 점은 그래프에서 간선과 함꼐 지운다.
    queue<int> q;
	vi vis(n + 1,false);
	for (int i = 1; i <= n; ++i) {
		if (indeg[i] == 0) {
			q.push(i);
			vis[i] = true;
		}
	}
	
	while (!q.empty()) {
		int a = q.front();
		q.pop();
		cout << a << " ";
		for (int b : adj[a]) {
			indeg[b]--;
			if (indeg[b] == 0 && !vis[b]) {
				q.push(b);
				vis[b] = true;
			}
		}
	}
	for (int i = 1;i <= n; ++i) {
		if (!vis[i])
			cout << i<<" ";
	}
	cout << "\n";
}





int main() {
    cin.sync_with_stdio(false);
    cin.tie(0);
    cout.sync_with_stdio(false);
    cout.tie(0);

    solve();

    return 0;
}