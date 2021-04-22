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
#define MAXN 100010

int n, q;
ll arr[MAXN];
ll tree[MAXN * 4];

// seg tree // 부분합 쿼리. 
ll init(int nd, int st, int en) {
    if (st == en) return tree[nd] = arr[st];
    int mid = (st + en) / 2;
    return tree[nd] = init(2 * nd, st, mid) + init(2 * nd + 1, mid + 1, en);
}
ll query(int nd, int st, int en, int l, int r) {
    if (r < st || en < l) return 0;
    if (l <= st && en <= r) return tree[nd];
    int mid = (st + en) / 2;
    return query(2 * nd, st, mid, l, r) + query(2 * nd + 1, mid + 1, en, l, r);
}
ll query(int l, int r) {
    return query(1, 0, n - 1, l, r);
}
void update(int idx, int val, int nd, int st, int en) {
    if (idx < st || en < idx) return;
    if (st == en) {
        tree[nd] = val;
        return;
    }

    int mid = (st + en) / 2;
    update(idx, val, 2 * nd, st, mid);
    update(idx, val, 2 * nd + 1, mid + 1, en);
    tree[nd] = tree[2 * nd] + tree[2 * nd + 1];
}

void update(int idx, int val) {
    update(idx, val, 1, 0, n - 1);
}

void solve() {
    cin >> n >> q;
    for (int i = 0; i < n; ++i)
        cin >> arr[i];
    init(1, 0, n - 1);
    while (q--) {
        int x, y, a, b;

        cin >> x >> y >> a >> b;
        cout << query(x - 1, y - 1) << "\n";
        update(a - 1, b);
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