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
typedef long long ll;
typedef vector<int> vi;
typedef vector<bool> vb;
typedef vector<long long> vll;
typedef vector<vector<int>> vvi;
typedef pair<int, int> pii;

int n, m;
ll cache[10][100000];


// y앞에 숫자 x를 붙인다.
ll attPre(ll x, ll y, int idx) {
	if (y < 0)
		return -INF;
	ll tmp = y;
	while (tmp || idx > 0) {
		x *= 10; tmp /= 10; idx--;
	}
	return x + y;
}

ll dp(int idx, int k) {
	//기저사례
	if (idx == n)
		return k == 0 ? 0 : -INF;
	// 메모이제이션
	ll& ret = cache[idx][k];
	if (ret != -1)
		return ret;

	ret = -INF;

	// 다음 칸에 11 추가.
	int nk = (k * 100 + 11) % m;
	ret = max(ret, attPre(11, dp(idx + 1, nk), n - idx - 1));


	for (int i = 9; i >= 0; --i) {
		int nk = (k * 10 + i) % m;
		ret = max(ret, attPre(i, dp(idx + 1, nk), n - idx - 1));
	}

	return ret;
}

void solve() {
	cin >> n >> m;
	memset(cache, -1, sizeof(cache));
	cout << dp(0, 0) << "\n";

}

int main() {
	cin.sync_with_stdio(false);
	cin.tie(0);
	cout.sync_with_stdio(false);
	cout.tie(0);

	int t;
	cin >> t;
	for (int i = 0; i < t; ++i)
		solve();
	return 0;
}