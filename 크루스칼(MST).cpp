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

// *** ũ�罺Į *** //  O(E*lgE)

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
    vector<pair<int, pii>> edges; // {����ġ,{��1,��2}}
    while (e--) {
        // edge �Է¹ޱ�.
        int a, b, c;
        cin >> a >> b >> c;
        edges.push_back({ c,{a,b} }); 
    }
    sort(edges.begin(), edges.end()); //����

    // edge����ġ ���������� Ž���Ͽ� ��������� (���õ� edge���� ����)MST�� �� edge�� �߰��ص� ����Ŭ�� �Ȼ���ٸ� MST�� edge�� �߰��Ѵ�.(�����Ѵ�)
    // UF�� ���� �̿ϼ�MST�� ���� ����Ǿ��ִ� �������� ���踦 �����Ѵ�.
    // �ĺ����Ǵ� edge�� �糡���� �̹� ���� MST��(������ ������edge��Ͽ� ����) ����Ǿ��ִ� ���¶�� <-> UF�� ���� ���տ� �����Ѵٸ�,
    // �� edge �߰��� ����Ŭ�� ����Ƿ� ���������ʴ´�.
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