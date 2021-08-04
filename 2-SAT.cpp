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

// �ڻ���� �˰���
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

	// �ڻ����. scc���� //** Ÿ���� �ᵵ ����.
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

	// 2sat �������翩�� Ȯ��. // �� ������ �� ���(�������, !���)�� ���� scc�� �ƴ϶�� ���� �׻� ����.
	bool tag = true;
	for (int i = 0; i < 2 * v; ++i)
		if (sccID[i] == sccID[nott(i)])
			tag = false;


	// 2sat �������� ���� ���. (tag�� true�� ���)
	vpii order;
	vi ret(v, -1); // �������� ��ȯ��
	// sccID������ ��������. //** ��, �ڻ���ִ� sccID�� �������ļ�, Ÿ���� �������� �������� ������(reverse�ʿ�, -sccID[i]������ ����).
	for (int i = 0; i < 2*v; ++i)
		order.push_back({ sccID[i],i });
	sort(order.begin(), order.end());
	
	// SCC �������ļ����� false����. (���� scc�� ���� �ڵ������� ���� ������ �����ȴ�.) 
	// �̹� �տ� ��忡 ���� ���� ��ȯ���� ����� ��� ����. ex) A�� �����Ϸ��µ� !A�� �ռ����� �־ A�� true�� ������.
	//** 2*i�� i�� ������ ������� 2*i+1�� i�������� !���� ������ ���.
	for (int i = 0; i < 2*v; i++) {
		int vertex = order[i].second;
		int val = vertex / 2; // val: ������ index(A0, A1,A2...)
		if (ret[val] != -1) continue; // �̹� ��ȯ���� ����� ��� ����
		int istrue = (vertex % 2 == 0); // �����ϴ� �� ��尡 !A ��: istrue =0 A��: istrue=1;
		ret[val] = !istrue; // A�Ǵ� !A�� ������ �ǵ��� A bool�� ����
	}
	//** nott�� �̿��Ͽ� i������� !��尡 i+5000�� �ǵ��� ������ ���.
	for (int i = 0; i < 10001; ++i) {
		int vertex = order[i].second;
		int isTrue = 0;       // ������ ��������� ���.
		if (vertex >= 5000) { // !����� ���.
			isTrue = 1;
			vertex -= 5000; // ���� index�� ����.
		}
		if (ret[vertex] != -1) continue; // �ش� ������ �̹� �����ߴٸ� ����.
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

// �ڻ���� �˰���
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

	// �ڻ����. scc���� //** Ÿ���� �ᵵ ����.
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

	// 2sat �������翩�� Ȯ��. // �� ������ �� ���(�������, !���)�� ���� scc�� �ƴ϶�� ���� �׻� ����.
	bool tag = true;
	for (int i = 0; i < 2 * v; ++i)
		if (sccID[i] == sccID[nott(i)])
			tag = false;


	// 2sat �������� ���� ���. (tag�� true�� ���)
	vpii order;
	vi ret(v, -1); // �������� ��ȯ��
	// sccID������ ��������. //** ��, �ڻ���ִ� sccID�� �������ļ�, Ÿ���� �������� �������� ������(reverse�ʿ�, -sccID[i]������ ����).
	for (int i = 0; i < 2*v; ++i)
		order.push_back({ sccID[i],i });
	sort(order.begin(), order.end());
	
	// SCC �������ļ����� false����. (���� scc�� ���� �ڵ������� ���� ������ �����ȴ�.) 
	// �̹� �տ� ��忡 ���� ���� ��ȯ���� ����� ��� ����. ex) A�� �����Ϸ��µ� !A�� �ռ����� �־ A�� true�� ������.
	//** 2*i�� i�� ������ ������� 2*i+1�� i�������� !���� ������ ���.
	for (int i = 0; i < 2*v; i++) {
		int vertex = order[i].second;
		int val = vertex / 2; // val: ������ index(A0, A1,A2...)
		if (ret[val] != -1) continue; // �̹� ��ȯ���� ����� ��� ����
		int istrue = (vertex % 2 == 0); // �����ϴ� �� ��尡 !A ��: istrue =0 A��: istrue=1;
		ret[val] = !istrue; // A�Ǵ� !A�� ������ �ǵ��� A bool�� ����
	}
	//** nott�� �̿��Ͽ� i������� !��尡 i+5000�� �ǵ��� ������ ���.
	for (int i = 0; i < 10001; ++i) {
		int vertex = order[i].second;
		int isTrue = 0;       // ������ ��������� ���.
		if (vertex >= 5000) { // !����� ���.
			isTrue = 1;
			vertex -= 5000; // ���� index�� ����.
		}
		if (ret[vertex] != -1) continue; // �ش� ������ �̹� �����ߴٸ� ����.
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