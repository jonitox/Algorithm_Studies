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

#define INF 1'000'000'000
#define mod 1'000'000'007
#define EPSILON 1e-9
#define MAXN 100010


ll gcd(ll a, ll b) {
	if (b == 0) return a;
	return gcd(b, a%b);
}

void solve() {
	
}
int main()
{
	cin.sync_with_stdio(false);
	cin.tie(0);
	cout.sync_with_stdio(false);
	cout.tie(0);

	int t;
	cin >> t;
	while (t--)
		solve();

	return 0;
}
