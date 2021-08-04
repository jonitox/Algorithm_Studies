<<<<<<< HEAD
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
// lazy 전파
void propagation(int node, int l, int r) {
	// 현 노드에 lazy가 있다면, 현노드를 처리하고, 자식노드들에 전파해준다.
	if (lazy[node]) {
		tree[node] += lazy[node];
		if (l != r) {
			lazy[2 * node] += lazy[node];
			lazy[2 * node + 1] += lazy[node];
		}
		lazy[node] = 0; // lazy 초기화.
	}
}

int query(int l, int r, int node, int nl, int nr) {
	// 쿼리함수 호출할시, 현노드 lazy처리.
	propagation(node, nl, nr);
	if (nr < l || r < nl) return INF;
	if (l <= nl && nr <= r)	return tree[node];
	int mid = (nl + nr) / 2;
	return min(query(l, r, 2 * node, nl, mid), query(l, r, 2 * node + 1, mid + 1, nr));
}

int query(int l, int r) {
	return query(l, r, 1, 0, n - 1);
}

// 구간 update // 기존의 노드(한 점)update와 다름.
int update(int l, int r, int val, int node, int nl, int nr) {
	// update함수 호출시, 현노드 lazy처리.
	propagation(node, nl, nr);
	// 쿼리함수와 유사하게, 구간에 대한 처리이므로, 구간과 노드가 나타내는 배열구간과의 교집합을 update한다.
	if (nr < l || r < nl) return tree[node];
	// 교집합이 노드 전체를 포함하면,
	if (l <= nl && nr <= r) {
		// 현노드를 직접 갱신하고,
		// 자식노드를 재귀적으로 호출하지않고, lazy를 이용해 자식노드들을 나중에 처리해둠을 명시해둔다.
		tree[node] += val;
		if (nl != nr) {
			lazy[2 * node] += val;
			lazy[2 * node + 1] += val;
		}
		return tree[node];
	}
	// 구간에 대한 업데이트는 nl==nr인 조건문 써줄필요없음. 위의 조건문으로 처리.
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
=======
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
// lazy 전파
void propagation(int node, int l, int r) {
	// 현 노드에 lazy가 있다면, 현노드를 처리하고, 자식노드들에 전파해준다.
	if (lazy[node]) {
		tree[node] += lazy[node];
		if (l != r) {
			lazy[2 * node] += lazy[node];
			lazy[2 * node + 1] += lazy[node];
		}
		lazy[node] = 0; // lazy 초기화.
	}
}

int query(int l, int r, int node, int nl, int nr) {
	// 쿼리함수 호출할시, 현노드 lazy처리.
	propagation(node, nl, nr);
	if (nr < l || r < nl) return INF;
	if (l <= nl && nr <= r)	return tree[node];
	int mid = (nl + nr) / 2;
	return min(query(l, r, 2 * node, nl, mid), query(l, r, 2 * node + 1, mid + 1, nr));
}

int query(int l, int r) {
	return query(l, r, 1, 0, n - 1);
}

// 구간 update // 기존의 노드update와 다름.
int update(int l, int r, int val, int node, int nl, int nr) {
	// update함수 호출시, 현노드 lazy처리.
	propagation(node, nl, nr);
	// 쿼리함수와 유사하게, 구간에 대한 처리이므로, 구간과 노드가 나타내는 배열구간과의 교집합을 update한다.
	if (nr < l || r < nl) return tree[node];
	// 교집합이 노드 전체를 포함하면,
	if (l <= nl && nr <= r) {
		// 현노드를 직접 갱신하고,
		// 자식노드를 재귀적으로 호출하지않고, lazy를 이용해 자식노드들을 나중에 처리해둠을 명시해둔다.
		tree[node] += val;
		if (nl != nr) {
			lazy[2 * node] += val;
			lazy[2 * node + 1] += val;
		}
		return tree[node];
	}
	// 구간에 대한 업데이트는 nl==nr인 조건문 써줄필요없음. 위의 조건문으로 처리.
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
>>>>>>> bb6e75949a077d02582f893a347fffea74c6bcdf
}