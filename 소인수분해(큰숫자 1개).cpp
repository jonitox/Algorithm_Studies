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
//////  #include <bits/stdc++.h>


	using namespace std;
	typedef long long ll;
	typedef vector<int> vi;
	typedef vector<bool> vb;
	typedef vector<long long> vll;
	typedef vector<vector<int>> vvi;
	typedef pair<int, int> pii;
	typedef pair<ll, ll> pll;
	typedef vector<pii> vpii;
	typedef vector<pll> vpll;
		
	#define INF 1000000000
	#define mod 1000000007
	#define MAXN 100001
	
	// p를 소인수분해, O(sqrt(p)+log(p))
	vll cal(int p){
		// p의 소인수는 sqrt(p)보다 큰 것이 최대 한개 존재한다.
		// 만약, sqrt(p)보다 큰 소인수가 한개 존재하더라도,
		// 그 소인수의 지수는 항상 1이다.

		// 따라서 2~sqrt(p)까지 순회하며, p를 나눌수 있는 경우 최대로 나눠주면서 소인수를 모두 구하고,
		// 남은 p값이 1보다 크다면 sqrt(p)보다 큰 가장 큰 소인수이다. 
		ll tmp = p;
		vll ret;
		for(int i=2; i<= sqrt(p); ++i){
			if(tmp%i) continue;
			// tmp를 나눈다면 i는 항상 소수. 그보다 작은 소인수는 모두 나눈 상태이므로.
			while(tmp%i==0){
				tmp /=i;
			}
			ret.push_back(i);
		}
		if(tmp>1)
			ret.push_back(tmp);
		return ret;
	}
	void solve() {
	}

	int main() {
		cin.sync_with_stdio(false);
		cin.tie(0);
		cout.sync_with_stdio(false);
		cout.tie(0);
		int t;
		cin>>t;
		while(t--)
		solve();

		return 0;
	}