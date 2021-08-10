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
// dfs ���д� Ʈ������ backword edge�� cutEdge�� �ɼ� ����.(tree edge�� �̿��� �ٸ� ��ΰ� �׻� �ֱ⶧��.) ��, dfs�����ϸ鼭 ������ tree edge�� cutEdge������ Ȯ���ϸ�ȴ�.
// u-v (parent[here]�� here)�� CutEdge�̷��� (**v���� u���� ������ �����ϰ�) v�� subtree���� �� ���ִ� �ּ� �߰� ������ u �����̴�.
// v�� root�϶��� parent�� �����Ƿ� CutEdge�� ã�� �ʴ´�.
int dfs(int here, bool isRoot) {			// CutVertex�� ���������� here���� �����ִ� �ּҹ߰߼��� ��ȯ. ��, parent[here]-here�� �����ϰ�.  
	discovered[here] = cnt++;
	int ret = discovered[here];

	for (int i = 0; i < adj[here].size(); i++) {
		int there = adj[here][i];
		if (discovered[there] == -1) { // there�� here�� �ڼ� ����϶�
			parent[there] = here;
			int subtree = dfs(there, false);
			ret = min(ret, subtree);
		}
		else if (there != parent[here]) // u-v�� �����ϰ� �����ִ� ���
			ret = min(ret, discovered[there]);
	}
	if (!isRoot&&ret >= discovered[here]) { // here���� �����ִ� �ּ� �߰� ������ parent[here] �����϶�
		int a = here + 1, b = parent[here] + 1;
		if (a > b) swap(a, b);
		cutEdge.push_back(make_pair(a, b)); // cutEdge ����.
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