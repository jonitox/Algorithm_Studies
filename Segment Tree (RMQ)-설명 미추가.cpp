#include <iostream>
#include <string>
#include <cstring>
#include <list>
#include <vector>
#include <stack>
#include <queue>
#include <algorithm>
#include <typeinfo>
#include <iomanip>
#include <map>
#include <set>
#define INF 2000000000
using namespace std;

// 세그먼트 트리
class RMQ {
public:
	int n;
	vector<int> rangeMin;
	RMQ(vector<int>& arr){
		n = arr.size();
		rangeMin.resize(4 * n);
		init(arr, 0, n - 1, 1);
	}

	int init(vector<int>&arr, int left, int right, int node) {
		if (left == right) return rangeMin[node]=left;
		int mid = (left + right) / 2;
		return rangeMin[node] = min(init(arr, left, mid, 2 * node), init(arr, mid+1, right, 2 * node + 1));
	}

	int query(int left, int right, int node, int nodeL, int nodeR) {
		if (right < nodeL || nodeR < left) return INF;
		if (left <= nodeL && nodeR <= right) return rangeMin[node];
		int mid = (nodeL + nodeR) / 2;
		return min(query(left, right, 2 * node, nodeL, mid), query(left, right, 2 * node + 1, mid+1, nodeR));
	}
	int query(int left, int right) {
		return query(left, right, 1,0, n - 1);
	}
	
	int update(int index, int new_val, int node, int nodeL, int nodeR) {
		if (index < nodeL || nodeR < index) return rangeMin[node];
		if(nodeL == nodeR) return rangeMin[node] = new_val;
		int mid = (nodeL + nodeR) / 2;
		return rangeMin[node] = min(update(index, new_val, 2 * node, nodeL, mid), update(index, new_val, 2 * node + 1, mid + 1, nodeR);
	}
	int update(int index, int new_val) {
		return update(index, new_val, 1, 0, n - 1);
	}
};

void solve() {
	
}



int main() {
	cin.sync_with_stdio(false);
	cin.tie(0);
	cout.sync_with_stdio(false);
	cout.tie(0);
	
	
	int c;
	cin >> c;
	for (int i = 0; i < c;++i)
		solve();
	return 0;
}