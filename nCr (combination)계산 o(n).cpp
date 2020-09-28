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
#define mod 998244353

using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<bool> vb;
typedef vector<long long> vll;
typedef vector<vector<int>> vvi;
typedef pair<int, int> pii;
typedef vector<pii> vpii;
#define MAXN 300000
int n,k;
ll ans = 0;
ll fac[MAXN], facInv[MAXN]; // factorial과 factorial의 역원(역수) 계산.

// nCk(MOD mod) 구하기 o(n):전처리, o(1):쿼리 
ll mpow(ll x, ll m) {
	if (!m) return 1;
	ll tmp = mpow(x, m / 2);
	tmp = (tmp * tmp) % mod;
	if (m % 2) 
		return (tmp * x)%mod;
	else
		return tmp;
}

void solve() {
	cin >> n>>k;

	// 전처리
	fac[0] = 1;
	for (int i = 1; i <= n; ++i)
		fac[i] = (fac[i - 1] * i) % mod;
	facInv[n] = mpow(fac[n], mod - 2); // mod가 소수인경우, 1/a == a^(mod-2) (MOD mod)
	for (int i = n-1;i >= 0;i--) 
		facInv[i] = (facInv[i + 1] * (i + 1)) % mod;

	
	cout << (((fac[n] * facInv(k))%mod) *facInv(n - k))%mod;
}

int main() {
	cin.sync_with_stdio(false);
	cin.tie(0);
	cout.sync_with_stdio(false);
	cout.tie(0);
	
	solve();
	return 0;
}