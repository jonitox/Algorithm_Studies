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

// ��������
int n,M;
vi arr;

void solve() {
	cin >> n>>M;
	arr.resize(n);
	for(int i=0; i<n; ++i)
		cin >> arr[i];
	int sum = 0, lo = 0, hi = 0; // [lo,hi)�� ���� sum�� ����.
	int ans = 0;
	while (1) {
		if (sum >= M) sum -= arr[lo++]; // sum>=M�� ���
		else if (hi == n) break;			// sum<M�̰� hi==n�� ���
		else sum += arr[hi++];			// sum<M�̰� �� ���� ���� ���� ���
		if (sum == M) ans++; // �������� sumȮ��.
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