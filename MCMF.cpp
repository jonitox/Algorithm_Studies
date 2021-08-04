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

#define INF 1000000000
#define mod ll(43200000000000)
#define MAXN 10010
#define MAXL 200010


// MCMF // �ּҺ�� �ִ� ���� �˰���. // O(V*E*f), ��� O((V+E)*f) (����: SPFA�� ���Ƿ�,)

int n, m;
int cap[202][202], flow[202][202], d[202][202];
vvi adj;

void solve() {
	cin >> n >> m;
	adj.resize(n + m + 2);
	for (int i = 0; i < n; ++i) {
		cin >> cap[2 + m + i][1];
		adj[2 + m + i].push_back(1);
		adj[1].push_back(2 + m + i);
	}
	for (int i = 0; i < m; ++i) {
		cin >> cap[0][2 + i];
		adj[0].push_back(2 + i);
		adj[2 + i].push_back(0);
	}
	for(int i=0; i<m; ++i)
		for (int j = 0; j < n; ++j) {
			int cost;
			cin >> cost;
			d[2 + i][2 + m + j] = cost;
			d[2 + m + j][2 + i] = -cost; // ������ ���� ���. ���� ���.
			cap[2 + i][2 + m + j] = INF;
			adj[2 + i].push_back(2 + m + j);
			adj[2 + m + j].push_back(2 + i);
		}

    int ans = 0;
    // SPFA�� �ִܰ�θ� ã�����ִ� ��ŭ ��� ã��(�ִ� ��������) ������ ������.
    while (true) {
        // 1���� SPFA: ���� �ܿ� �뷮 �������� �ִܰ�θ� ã�� ������ ����.
        vi dis(n + m + 2, INF); vi pr(n + m + 2, -1); vb inQ(n + m + 2, false);
		queue<int> q;
		q.push(0);
		pr[0] = 0; dis[0] = 0; inQ[0] = true;
		while (!q.empty()) {
			int here = q.front();
			q.pop();
			inQ[here] = false;
			for (int i: adj[here]) {
				if (cap[here][i]-flow[here][i]>0 && dis[i] > dis[here] + d[here][i]) {
					dis[i] = dis[here] + d[here][i];
					pr[i] = here;
					if (!inQ[i]) {
						q.push(i);
						inQ[i] = true;
					}
				}
			}
		}
		if (pr[1] == -1) break;  // ��ũ���� ��� ã�����ϸ�(���� �ܿ��뷮�� ���� ������� ������ ����������.) ����.

        int a = INF;
		for (int i = 1; i != 0; i = pr[i]) {
			a = min(a, cap[pr[i]][i] - flow[pr[i]][i]);
		}
		for (int i = 1; i != 0; i = pr[i]) {
			flow[pr[i]][i] += a;
			flow[i][pr[i]] -= a;
			ans += a * d[pr[i]][i]; // ��� ���.
		}
	}


	cout<<ans<<"\n";
}
int main() {
    cin.sync_with_stdio(false);
    cin.tie(0);
    cout.sync_with_stdio(false);
    cout.tie(0);



    solve();

    return 0;
}