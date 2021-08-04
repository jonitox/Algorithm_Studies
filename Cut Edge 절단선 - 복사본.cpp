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
#include <limits.h>

#define INF 1000000000
#define mod 100
using namespace std;
vector<vector<int>> adj;
vector<int> discovered, parent;
vector<pair<int, int>> cutEdge;
int v, e, cnt = 0;

void makeGraph() {
	cin >> v >> e;

	discovered = vector<int>(v, -1);
	adj = vector<vector<int>>(v);
	parent = vector<int>(v);
	int a, b;
	for (int i = 0; i < e; i++) {
		cin >> a >> b;
		adj[a - 1].push_back(b - 1);
		adj[b - 1].push_back(a - 1);
	}
	return;
}

// find CutEdge 
// dfs 스패닝 트리에서 backword edge는 cutEdge가 될수 없다.(tree edge를 이용한 다른 경로가 항상 있기때문.) 즉, dfs수행하면서 지나온 tree edge가 cutEdge인지만 확인하면된다.
// u-v (parent[here]와 here)가 CutEdge이려면 (**v에서 u로의 간선을 제외하고) v의 subtree에서 갈 수있는 최소 발견 순서가 u 이후이다.
// v가 root일때는 parent가 없으므로 CutEdge를 찾지 않는다.
int dfs(int here, bool isRoot) {			// CutVertex와 마찬가지로 here에서 갈수있는 최소발견순서 반환. 단, parent[here]-here를 제외하고.  
	discovered[here] = cnt++;
	int ret = discovered[here];

	for (int i = 0; i < adj[here].size(); i++) {
		int there = adj[here][i];
		if (discovered[there] == -1) { // there가 here의 자손 노드일때
			parent[there] = here;
			int subtree = dfs(there, false);
			ret = min(ret, subtree);
		}
		else if (there != parent[here]) // u-v를 제외하고 갈수있는 노드
			ret = min(ret, discovered[there]);
	}
	if (!isRoot&&ret >= discovered[here]) { // here에서 갈수있는 최소 발견 순서가 parent[here] 이후일때
		int a = here + 1, b = parent[here] + 1;
		if (a > b) swap(a, b);
		cutEdge.push_back(make_pair(a, b)); // cutEdge 저장.
	}


	return ret;
}


int main() {
	cin.sync_with_stdio(false);
	cin.tie(0);
	cout.sync_with_stdio(false);
	cout.tie(0);

	makeGraph();
	for (int i = 0; i < v; i++) {
		if (discovered[i] == -1) {
			parent[i] = i;
			dfs(i, true);
		}
	}
	cout << (int)cutEdge.size() << "\n";
	sort(cutEdge.begin(), cutEdge.end());
	for (int i = 0; i < cutEdge.size(); i++)
		cout << cutEdge[i].first << " " << cutEdge[i].second << "\n";
	return 0;
}