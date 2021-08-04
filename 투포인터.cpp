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

// 투포인터
int n,M;
vi arr;

void solve() {
	cin >> n>>M;
	arr.resize(n);
	for(int i=0; i<n; ++i)
		cin >> arr[i];
	int sum = 0, lo = 0, hi = 0; // [lo,hi)의 합을 sum에 저장.
	int ans = 0;
	while (1) {
		if (sum >= M) sum -= arr[lo++]; // sum>=M인 경우
		else if (hi == n) break;			// sum<M이고 hi==n인 경우
		else sum += arr[hi++];			// sum<M이고 더 읽은 수가 남은 경우
		if (sum == M) ans++; // 마지막에 sum확인.
	}
}


int main() {
	cin.sync_with_stdio(false);
	cin.tie(0);
	cout.sync_with_stdio(false);
	cout.tie(0);
	int t;
	cin >> t;
	for(int i=0; i<t; ++i)
		solve();
		
	
	return 0;
}