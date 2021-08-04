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
#define mod 1000000007

using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<bool> vb;
typedef vector<long long> vll;
typedef vector<vector<int>> vvi;
typedef pair<int, int> pii;
typedef vector<pii> vpii;

int n;

//카탈란수

// 일반항 c_n = (2n C n)/(n+1) // 복잡도 n. //fac 오버플로주의
int catalan1(int x) {
	vi fac(2*x+1);
	fac[1] = 1;
	for (int i = 2; i <= 2 * x; ++i)
		fac[i] = fac[i - 1] * i;
	return fac[2 * x] / fac[x] / fac[x] / (x + 1);
}

// 점화식 c_n = c_0*c_n-1+ ... + c_n-1*c_0 // 복잡도 n^2
int catalan2(int x) {
	vll ct(x + 1);
	ct[0] = 1;
	for (int i = 1; i <= x; ++i) {
		for (int j = 0; j <= i - 1; ++j) {
			ct[i] += ct[j] * ct[i - 1 - j];
			ct[i] %= 987654321;
		}
	}
	return ct[x];
}

void solve() {
	cin >> n;
	n /= 2;
	cout << catalan2(n)<<"\n";
}

int main() {
	cin.sync_with_stdio(false);
	cin.tie(0);
	cout.sync_with_stdio(false);
	cout.tie(0);
	
	solve();

	return 0;
}