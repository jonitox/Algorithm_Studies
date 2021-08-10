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

using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<bool> vb;
typedef vector<long long> vll;
typedef vector<vector<int>> vvi;
typedef pair<int, int> pii;
typedef vector<pii> vpii;


int n,k;
int tree[100000 * 4];
int lazy[100000 * 4];

// RMQ seg tree with lazy propagation
int init(vi& arr, int node, int l, int r) {
	if (l == r) return tree[node] = l;
	int mid = (l + r) / 2;
	return tree[node] = min(init(arr, 2 * node, l, mid), init(arr, 2 * node + 1, mid + 1, r));
}
// lazy ����
void propagation(int node, int l, int r) {
	// �� ��忡 lazy�� �ִٸ�, ����带 ó���ϰ�, �ڽĳ��鿡 �������ش�.
	if (lazy[node]) {
		tree[node] += lazy[node];
		if (l != r) {
			lazy[2 * node] += lazy[node];
			lazy[2 * node + 1] += lazy[node];
		}
		lazy[node] = 0; // lazy �ʱ�ȭ.
	}
}

int query(int l, int r, int node, int nl, int nr) {
	// �����Լ� ȣ���ҽ�, ����� lazyó��.
	propagation(node, nl, nr);
	if (nr < l || r < nl) return INF;
	if (l <= nl && nr <= r)	return tree[node];
	int mid = (nl + nr) / 2;
	return min(query(l, r, 2 * node, nl, mid), query(l, r, 2 * node + 1, mid + 1, nr));
}

int query(int l, int r) {
	return query(l, r, 1, 0, n - 1);
}

// ���� update // ������ ���update�� �ٸ�.
int update(int l, int r, int val, int node, int nl, int nr) {
	// update�Լ� ȣ���, ����� lazyó��.
	propagation(node, nl, nr);
	// �����Լ��� �����ϰ�, ������ ���� ó���̹Ƿ�, ������ ��尡 ��Ÿ���� �迭�������� �������� update�Ѵ�.
	if (nr < l || r < nl) return tree[node];
	// �������� ��� ��ü�� �����ϸ�,
	if (l <= nl && nr <= r) {
		// ����带 ���� �����ϰ�,
		// �ڽĳ�带 ��������� ȣ�������ʰ�, lazy�� �̿��� �ڽĳ����� ���߿� ó���ص��� �����صд�.
		tree[node] += val;
		if (nl != nr) {
			lazy[2 * node] += val;
			lazy[2 * node + 1] += val;
		}
		return tree[node];
	}
	// ������ ���� ������Ʈ�� nl==nr�� ���ǹ� �����ʿ����. ���� ���ǹ����� ó��.
	int mid = (nl + nr) / 2;
	return tree[node] = min(update(l, r, val, 2 * node, nl, mid), update(l, r, val, 2 * node + 1, mid + 1, nr));
}
int update(int l, int r, int val) {
	return update(l, r, val, 1, 0, n - 1);
}

void solve() {
	cin >> n>>k;
	vi arr(n, 0);
	init(arr, 1, 0, n - 1);
}

int main() {
	cin.sync_with_stdio(false);
	cin.tie(0);
	cout.sync_with_stdio(false);
	cout.tie(0);

	
	
	solve();

	return 0;
}