<<<<<<< HEAD
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
// here 가 CutVertex이려면 here의 child의 subtree에서 갈 수 있는 최소 발견 순서가 here 이상인 subtree가 존재한다.
// here가 root일때 CutVertex이려면 child 수가 2 이상이다.
int findCutVertex(int here, bool isroot) {
	discovered[here] = counter++;
	int ret = discovered[here];			// here은 무조건 발견가능.
	int children = 0;
	for (int i = 0; i < adj[here].size(); i++) {
		int there = adj[here][i];
		if (discovered[there] == -1) { // there가 here의 자손 노드인 경우
			children++;
			int subtree = findCutVertex(there, false);
			ret = min(ret, subtree);
			if (!isroot && subtree >= discovered[here]) // there의 subtree에서 갈수 있는 최소발견순서가 here이상일때  
				isCutVertex[here] = true;
		}
		else // here->there이 backword Edge일때
			ret = min(ret, discovered[there]);
	}
	if (isroot) isCutVertex[here] = (children >= 2); // root가 cutVertex인 경우는 자손 노드가 2개 이상인 경우.
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
=======
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
// here 가 CutVertex이려면 here의 child의 subtree에서 갈 수 있는 최소 발견 순서가 here 이상인 subtree가 존재한다.
// here가 root일때 CutVertex이려면 child 수가 2 이상이다.
int findCutVertex(int here, bool isroot) {
	discovered[here] = counter++;
	int ret = discovered[here];			// here은 무조건 발견가능.
	int children = 0;
	for (int i = 0; i < adj[here].size(); i++) {
		int there = adj[here][i];
		if (discovered[there] == -1) { // there가 here의 자손 노드인 경우
			children++;
			int subtree = findCutVertex(there, false);
			ret = min(ret, subtree);
			if (!isroot && subtree >= discovered[here]) // there의 subtree에서 갈수 있는 최소발견순서가 here이상일때  
				isCutVertex[here] = true;
		}
		else // here->there이 backword Edge일때
			ret = min(ret, discovered[there]);
	}
	if (isroot) isCutVertex[here] = (children >= 2); // root가 cutVertex인 경우는 자손 노드가 2개 이상인 경우.
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
>>>>>>> bb6e75949a077d02582f893a347fffea74c6bcdf
}