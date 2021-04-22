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

// *** 크루스칼 *** //  O(E*lgE)

int v, e;
int pr[MAXN];
int rk[MAXN];

int find(int u) {
    if (pr[u] == u) return u;
    return pr[u] = find(pr[u]);
}

void merge(int u, int v) {
    u = find(u), v = find(v);
    if (u == v) return;
    if (rk[u] > rk[v]) swap(u, v);
    pr[u] = v;
    if (rk[u] == rk[v]) rk[v]++;
}

void solve() {
    cin >> v >> e;
    ll ans = 0;
    vector<pair<int, pii>> edges; // {가중치,{점1,점2}}
    while (e--) {
        // edge 입력받기.
        int a, b, c;
        cin >> a >> b >> c;
        edges.push_back({ c,{a,b} }); 
    }
    sort(edges.begin(), edges.end()); //정렬

    // edge가중치 낮은순으로 탐색하여 현재까지의 (선택된 edge들의 집합)MST에 현 edge를 추가해도 사이클이 안생긴다면 MST에 edge를 추가한다.(선택한다)
    // UF로 현재 미완성MST상에 서로 연결되어있는 정점들의 관계를 관리한다.
    // 후보가되는 edge의 양끝점이 이미 서로 MST상(이전에 선택한edge목록에 의해) 연결되어있는 상태라면 <-> UF상 같은 집합에 존재한다면,
    // 현 edge 추가시 사이클이 생기므로 선택하지않는다.
        for (int i = 1; i <= v; ++i)
        pr[i] = i;
    for (auto& ee : edges) {
        int a = ee.second.first, b = ee.second.second;
        int c = ee.first;
        if (find(a) == find(b)) continue;
        ans += c;
        merge(a, b);
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