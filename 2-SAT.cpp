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
#define mod 1000000007

using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<bool> vb;
typedef vector<long long> vll;
typedef vector<vector<int>> vvi;
typedef pair<int, int> pii;
typedef vector<pii> vpii;

int v, e;
vi adj[10001];
vi radj[10001];
int sccID[10001];
vi scc[10001];
bool vis[10001];
stack<int> st;
int sccCnt;

int nott(int x) {
	if (x < 5000) return x + 5000;
	return x - 5000;
}

// 코사라주 알고리즘
void dfs(int here) {
	vis[here] = true;
	for (auto there : adj[here]) {
		if (!vis[there]) {
			dfs(there);
		}
	}
	st.push(here);
}
void dfs2(int here) {
	vis[here] = true;
	sccID[here] = sccCnt;
	scc[sccCnt].push_back(here);
	for (auto i : radj[here])
		if (!vis[i])
			dfs2(i);
}
void solve() {
	cin >> v >> e;
	memset(vis, false, sizeof(vis));
	memset(sccID, -1, sizeof(sccID));

	// 코사라주. scc생성 //** 타잔을 써도 무방.
	for (int i = 0; i < 2*v; ++i) {
		if (!vis[i])
			dfs(i);
	}
	memset(vis, false, sizeof(vis));
	while (!st.empty()) {
		int here = st.top();
		st.pop();
		if (vis[here]) continue; 
		dfs2(here);
		sccCnt++;
	}

	// 2sat 정답존재여부 확인. // 한 변수의 두 노드(기존노드, !노드)가 같은 scc가 아니라면 답은 항상 존재.
	bool tag = true;
	for (int i = 0; i < 2 * v; ++i)
		if (sccID[i] == sccID[nott(i)])
			tag = false;


	// 2sat 변수들의 정답 계산. (tag가 true인 경우)
	vpii order;
	vi ret(v, -1); // 변수들의 반환값
	// sccID순으로 위상정렬. //** 단, 코사라주는 sccID가 위상정렬순, 타잔은 위상정렬 역순으로 배정됨(reverse필요, -sccID[i]순으로 정렬).
	for (int i = 0; i < 2*v; ++i)
		order.push_back({ sccID[i],i });
	sort(order.begin(), order.end());
	
	// SCC 위상정렬순으로 false배정. (같은 scc의 노드는 자동적으로 같은 값으로 배정된다.) 
	// 이미 앞에 노드에 의해 변수 반환값이 저장된 경우 무시. ex) A를 배정하려는데 !A가 앞순서에 있어서 A가 true로 배정됨.
	//** 2*i가 i번 변수의 기존노드 2*i+1이 i번변수의 !노드로 구현한 경우.
	for (int i = 0; i < 2*v; i++) {
		int vertex = order[i].second;
		int val = vertex / 2; // val: 변수의 index(A0, A1,A2...)
		if (ret[val] != -1) continue; // 이미 반환값이 저장된 경우 무시
		int istrue = (vertex % 2 == 0); // 배정하는 현 노드가 !A 꼴: istrue =0 A꼴: istrue=1;
		ret[val] = !istrue; // A또는 !A이 거짓이 되도록 A bool값 저장
	}
	//** nott을 이용하여 i번노드의 !노드가 i+5000이 되도록 구현한 경우.
	for (int i = 0; i < 10001; ++i) {
		int vertex = order[i].second;
		int isTrue = 0;       // 변수의 기존노드인 경우.
		if (vertex >= 5000) { // !노드인 경우.
			isTrue = 1;
			vertex -= 5000; // 변수 index로 변경.
		}
		if (ret[vertex] != -1) continue; // 해당 변수를 이미 배정했다면 무시.
		ret[vertex] = !isTrue;
	}
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
#define mod 1000000007

using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<bool> vb;
typedef vector<long long> vll;
typedef vector<vector<int>> vvi;
typedef pair<int, int> pii;
typedef vector<pii> vpii;

int v, e;
vi adj[10001];
vi radj[10001];
int sccID[10001];
vi scc[10001];
bool vis[10001];
stack<int> st;
int sccCnt;

int nott(int x) {
	if (x < 5000) return x + 5000;
	return x - 5000;
}

// 코사라주 알고리즘
void dfs(int here) {
	vis[here] = true;
	for (auto there : adj[here]) {
		if (!vis[there]) {
			dfs(there);
		}
	}
	st.push(here);
}
void dfs2(int here) {
	vis[here] = true;
	sccID[here] = sccCnt;
	scc[sccCnt].push_back(here);
	for (auto i : radj[here])
		if (!vis[i])
			dfs2(i);
}
void solve() {
	cin >> v >> e;
	memset(vis, false, sizeof(vis));
	memset(sccID, -1, sizeof(sccID));

	// 코사라주. scc생성 //** 타잔을 써도 무방.
	for (int i = 0; i < 2*v; ++i) {
		if (!vis[i])
			dfs(i);
	}
	memset(vis, false, sizeof(vis));
	while (!st.empty()) {
		int here = st.top();
		st.pop();
		if (vis[here]) continue; 
		dfs2(here);
		sccCnt++;
	}

	// 2sat 정답존재여부 확인. // 한 변수의 두 노드(기존노드, !노드)가 같은 scc가 아니라면 답은 항상 존재.
	bool tag = true;
	for (int i = 0; i < 2 * v; ++i)
		if (sccID[i] == sccID[nott(i)])
			tag = false;


	// 2sat 변수들의 정답 계산. (tag가 true인 경우)
	vpii order;
	vi ret(v, -1); // 변수들의 반환값
	// sccID순으로 위상정렬. //** 단, 코사라주는 sccID가 위상정렬순, 타잔은 위상정렬 역순으로 배정됨(reverse필요, -sccID[i]순으로 정렬).
	for (int i = 0; i < 2*v; ++i)
		order.push_back({ sccID[i],i });
	sort(order.begin(), order.end());
	
	// SCC 위상정렬순으로 false배정. (같은 scc의 노드는 자동적으로 같은 값으로 배정된다.) 
	// 이미 앞에 노드에 의해 변수 반환값이 저장된 경우 무시. ex) A를 배정하려는데 !A가 앞순서에 있어서 A가 true로 배정됨.
	//** 2*i가 i번 변수의 기존노드 2*i+1이 i번변수의 !노드로 구현한 경우.
	for (int i = 0; i < 2*v; i++) {
		int vertex = order[i].second;
		int val = vertex / 2; // val: 변수의 index(A0, A1,A2...)
		if (ret[val] != -1) continue; // 이미 반환값이 저장된 경우 무시
		int istrue = (vertex % 2 == 0); // 배정하는 현 노드가 !A 꼴: istrue =0 A꼴: istrue=1;
		ret[val] = !istrue; // A또는 !A이 거짓이 되도록 A bool값 저장
	}
	//** nott을 이용하여 i번노드의 !노드가 i+5000이 되도록 구현한 경우.
	for (int i = 0; i < 10001; ++i) {
		int vertex = order[i].second;
		int isTrue = 0;       // 변수의 기존노드인 경우.
		if (vertex >= 5000) { // !노드인 경우.
			isTrue = 1;
			vertex -= 5000; // 변수 index로 변경.
		}
		if (ret[vertex] != -1) continue; // 해당 변수를 이미 배정했다면 무시.
		ret[vertex] = !isTrue;
	}
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