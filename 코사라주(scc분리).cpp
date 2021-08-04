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

// �ڻ���� �˰���
//�Ϲ� dfs
void dfs(int here) {
	vis[here] = true;
	for (auto there : adj[here]) {
		if (!vis[there]) {
			dfs(there);
		}
	}
	st.push(here); // ��������� stack�� �߰�. //** pop�� scc���� �������� ������ ���湮.
}
// ������ dfs
void dfs2(int here) {
	vis[here] = true;
	// scc����.
	sccID[here] = sccCnt;
	scc[sccCnt].push_back(here);
	// �� ��忡�� ���������� �����ִ� ���� ���� ���� scc�� �ִ�. ��ͷ� ȣ��
	for (auto i : radj[here])
		if (!vis[i])
			dfs2(i);
}
void solve() {
	cin >> v >> e;
	memset(vis, false, sizeof(vis));
	memset(sccID, -1, sizeof(sccID));
	for (int i = 0; i < e; ++i) {
		int a, b;
		cin >> a >> b;
		adj[a].push_back(b);
		radj[b].push_back(a); // ���� ������ ������ ������ �����д�.
	}
	// dfs
	for (int i = 1; i <= v; ++i) {
		if (!vis[i])
			dfs(i);
	}
	// stack���� pop�ϸ� ������dfs2����
	memset(vis, false, sizeof(vis));
	while (!st.empty()) {
		int here = st.top();
		st.pop();
		if (vis[here]) continue; // ���� ����� �̹� �湮�� ���̸� ����.(�ٸ� ����� dfs2������ scc�� ������ ���)
		// dfs2�� scc�� �ϳ� ã�´�.
		dfs2(here);
		//scc���� ����
		sccCnt++;   	}



	// boj 2150
	cout << sccCnt << "\n";
	vpii minE(sccCnt);
	for (int i = 0; i < sccCnt;++i) {
		sort(scc[i].begin(), scc[i].end());
		minE[i] = { scc[i][0], i };
	}
	sort(minE.begin(), minE.end());
	for (int i = 0; i < sccCnt;++i) {
		for (auto j : scc[minE[i].second])
			cout << j << " ";
		cout << -1 << "\n";
	}
}

int main() {	
	cin.sync_with_stdio(false);
	cin.tie(0);
	cout.sync_with_stdio(false);
	cout.tie(0);

		solve();

	return 0;
}