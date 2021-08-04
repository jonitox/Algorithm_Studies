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
#define MAXN 20010

int v, e, st;
vpii adj[MAXN];
int dis[MAXN];

// 다익스트라

void solve() {
    cin >> v >> e >> st;
    for (int i = 0; i < e; ++i) {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({ v,w });
    }

    fill(dis, dis + v + 1, INF);

    priority_queue<pii> pq;
    pq.push({ 0,st });
    dis[st] = 0;

    while (!pq.empty()) {
        auto k = pq.top();
        pq.pop();
        int here = k.second;
        int cost = -k.first;
        if (dis[here] < cost) continue;
        for (auto& t : adj[here]) {
            int there = t.first;
            int d = t.second;
            if (dis[there] > cost + d)
            {
                dis[there] = cost + d;
                pq.push({ -(cost + d), there });
            }
        }
    }
    for (int i = 1; i <= v;++i) {
        if (dis[i] == INF) {
            cout << "INF\n";
            continue;
        }
        cout <<dis[i] << "\n";
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