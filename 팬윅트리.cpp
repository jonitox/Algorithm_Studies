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

#define MAXN 10000
//����Ʈ��
int n;
int tree[MAXN+1];
	
// 0~pos�� ������ ��ȯ
int sum(int pos) {
	pos++;
	int ret = 0;
	while (pos > 0) {
		ret += tree[pos];
		pos &= pos - 1;
	}
	return ret;
}
// pos�� ������ �� val��ŭ ����(update).
void add(int pos, int val) {
	pos++;
	while (pos <= MAXN) {
		tree[pos] += val;
		pos += pos & (-pos);
	}
}
void solve() {
	
}
int main() {
	cin.sync_with_stdio(false);
	cin.tie(0);
	cout.sync_with_stdio(false);
	cout.tie(0);

	solve();

	return 0;
}