#include <iostream>
#include <string>
#include <cstring>
#include <list>
#include <vector>
#include <map>
#include <set>
#include <stack>
#include <queue>
#include <algorithm>
#include <typeinfo>
#include <iomanip>


#define INF 2000000000
using namespace std;

vector<int> discovered(8, -1);
vector<bool> isCutVertex(8, false);
vector<vector<int>> adj;
int counter = 0;

void make_graph() {
	adj.push_back({ 1 });
	adj.push_back({ 0, 2, 3 });
	adj.push_back({ 1,3,5 });
	adj.push_back({ 1,2,4,5 });
	adj.push_back({ 3 });
	adj.push_back({ 2,3,6,7 });
	adj.push_back({ 5 });
	adj.push_back({ 7 });
}


//find CutVertex
// here �� CutVertex�̷��� here�� child�� subtree���� �� �� �ִ� �ּ� �߰� ������ here �̻��� subtree�� �����Ѵ�.
// here�� root�϶� CutVertex�̷��� child ���� 2 �̻��̴�.
int findCutVertex(int here, bool isroot) {
	discovered[here] = counter++;
	int ret = discovered[here];			// here�� ������ �߰߰���.
	int children = 0;
	for (int i = 0; i < adj[here].size(); i++) {
		int there = adj[here][i];
		if (discovered[there] == -1) { // there�� here�� �ڼ� ����� ���
			children++;
			int subtree = findCutVertex(there, false);
			ret = min(ret, subtree);
			if (!isroot && subtree >= discovered[here]) // there�� subtree���� ���� �ִ� �ּҹ߰߼����� here�̻��϶�  
				isCutVertex[here] = true;
		}
		else // here->there�� backword Edge�϶�
			ret = min(ret, discovered[there]);
	}
	if (isroot) isCutVertex[here] = (children >= 2); // root�� cutVertex�� ���� �ڼ� ��尡 2�� �̻��� ���.
	return ret;
}



int main() {
	cin.sync_with_stdio(false);
	cin.tie(0);
	cout.sync_with_stdio(false);
	cout.tie(0);
	make_graph();
	for (int i = 0; i < adj.size(); i++) {
		if (discovered[i] == -1)
			findCutVertex(i, true);
	}
	for (int i = 0; i < isCutVertex.size(); i++)
		cout << isCutVertex[i];
	return 0;
}