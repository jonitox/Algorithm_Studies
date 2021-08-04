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
#define MAXN 10000
using namespace std;

int n;
int arr[MAXN];
int tree[MAXN*4];

// RMQ
int init(int node, int l, int r) {
	if (l == r) return tree[node] = arr[l];
	int mid = (l + r) / 2;
	return tree[node] = min(init(2 * node, l, mid), init(2 * node + 1, mid + 1, r));
}
int query(int left, int right, int node, int nL, int nR){
	if(right< nL || nR<left) return INF;
	if(left<=nL && nR <= right) return tree[node];
	int mid = (nL+nR)/2;
	return min(query(left,right,2*node,nL,mid),query(left,right,2*node+1,mid+1,nR)); 
}
int query(int left, int right){
	return query(left,right,1,0,n-1);
}
void update(int idx, int val, int node, int left,int right){
	if(idx<left || right<idx) return;
	if(left==right){
		tree[node] = val; // val로 바꾸는 경우.
		return;
	}
	int mid = (left+right)/2;
	update(idx,val,2*node, left, mid);
	update(idx,val,2*node+1,mid+1,right);
	tree[node] = min(tree[2*node],tree[2*node+1]);
	return; 
}
void update(int idx, int val){
	update(idx,val,1,0,n-1);
	return;
}

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