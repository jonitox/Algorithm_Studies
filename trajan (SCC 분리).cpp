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

vector<int> discovered(6, -1);
vector<int> sccID(6, -1);
vector<vector<int>> adj;
stack<int> st;
int counter = 0;
int sccCounter = 0;

void make_graph() {
	adj.push_back({ 1,4 });
	adj.push_back({ 2 });
	adj.push_back({ 3 });
	adj.push_back({ 1 });
	adj.push_back({ 5 });
	adj.push_back({ 3,4 });
}


// 방향그래프의 scc계산 // subtree 갓다가 함수 반환 시 자신과 부모 사이 노드를 끊어 scc를 만들수있는지 여부 판단.
// here의 서브트리에서 갈 수 있는 최소 발견 순서 정점 반환 // here보다 이상(사실 here포함이므로 here값)이라면 here가 한 scc의 최초 발견 노드이므로 잘라서 scc에 추가
int scc(int here) {
	int ret = discovered[here] = counter++;
	st.push(here);
	for (int i = 0; i < adj[here].size(); i++) {
		int there = adj[here][i];
		// there가 자손, 트리 간선일때
		if (discovered[there] == -1) {
			ret = min(ret,scc(there));
		}
		// there 가 교차간선이면서 무시해도되는 경우(there가 이미 scc로 묶여서 root로 가지 못하는 경우)를 제외한 
		// scc로 안 묶인 곳(선조로 갈수있는곳)으로의 교차간선 or here에서의 역방향 간선 일경우 (두 경우 모두 아직 there의 scc는 정해지지않음.)
		// here에서 끊지 못하므로(scc불가능) discovered 값 저장
		else if (sccID[there] == -1) 
			ret = min(ret,discovered[there]);
	}

	if (ret == discovered[here]) { // parent[here]-here를 끊어야할떄 <-> here에서 parent[here]로 가는 경로가 없을때(즉,다른 scc에 속함) //새로운 scc발견.
		//스택에서 here까지 꺼내서 SCC로 묶기.
		while (true) {
			int t = st.top();
			sccID[t] = sccCounter;
			st.pop();
			if (t == here) {
				break;
			}
		}
		sccCounter++;
	}
	return ret;
}

vector<int> tarjanSCC() {
	sccID = discovered = vector<int>(adj.size(), -1);
	sccCounter = counter = 0;
	// 한 루트에서 모든 점 탐색 안되더라도 scc는 모든 노드에 실행시 알아서 분리됨.
	// 한 노드에서의 탐색시 발견되지 않은 점은 그 점에서 이 노드(사실, 노드의 트리에 있는 노드들)(이미 scc존재)로 올 순 있어도 가진 못하므로. 
	// 실제 이 점에서 if문 수행시 아무것도 안됨.(그 전 노드는 이미 발견& scc존재)
	for (int i = 0; i < adj.size(); i++)
		if (discovered[i] == -1) scc(i);
	return sccID;
}

int main() {
	cin.sync_with_stdio(false);
	cin.tie(0);
	cout.sync_with_stdio(false);
	cout.tie(0);
	make_graph();
	tarjanSCC();
	for (int i = 0; i < 6; i++)
		cout << sccID[i];
	return 0;
}