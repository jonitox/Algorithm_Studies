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
#define mod  1000000007

using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<bool> vb;
typedef vector<long long> vll; 
typedef vector<vector<int>> vvi;
typedef pair<int, int> pii;
typedef vector<pii> vpii;

// ���� ��ü
class edge {
public:
	int t, cap, flow, d;
	edge* rev; // ������ ���� ������
	edge(int t, int cap, int flow, int d):t(t), cap(cap),flow(flow), d(d){
	}
	// ������ �ܿ��뷮 ��ȯ
	int re() {
		return cap - flow;
	}
	// ������ ���� �߰�
	void push(int amt) {
		flow += amt;
		rev->flow -= amt;
	}
};

int n;
vector<edge*> adj[367];

// ���� ���� �� �߰�. //������ ������ ���� �����Ѵ�.
void addEdge(int u, int v, int c, int d) {
	edge* uv = new edge(v, c, 0, d);
	edge* vu = new edge(u, 0, 0, -d);
	uv->rev = vu;
	vu->rev = uv;
	adj[u].push_back(uv);
	adj[v].push_back(vu);
}

// boj 3938
void solve() {
	//�ʱ�ȭ
	for (int i = 0; i < 367; ++i) {
		for (edge* a : adj[i]) 
			delete a;
		adj[i].clear();
	}	

	for (int i = 0; i <= 365; ++i)
		addEdge(i, i + 1, 2, 0);
	for (int i = 0; i < n; ++i) {
		int a, b, c;
		cin >> a >> b >> c;	
		addEdge(a, b+1, 1, -c);
	}

	ll ans = 0;
	//MCMF
	while (true) {
		vi pr(367, -1); vi dis(367, INF); vb inQ(367, false);
		vector<edge*> pe(367,NULL);
		queue<int> q;
		q.push(0);
		pr[0] = 0; dis[0] = 0; inQ[0] = true;
		// SPFA
		while (!q.empty()) {
			int here = q.front();
			q.pop();
			inQ[here] = false;
			for (edge* e : adj[here]) {
				int  there = e->t, d = dis[here] + e->d;
				if (e->re() > 0 && d < dis[there]) {
					dis[there]=d;
					pr[there] = here;
					pe[there] = e;
					if (!inQ[there]) {
						q.push(there);
						inQ[there] = true;
					}
				}
			}
		}
		
		if (pr[366] == -1) break;
		int amt = INF;
		for (int i = 366; i != 0; i = pr[i])
			amt = min(amt, pe[i]->re());
		for (int i = 366; i != 0; i = pr[i]) {
			pe[i]->push(amt);
			ans += pe[i]->d;
		}
	}
	cout << -ans << "\n";
}

int main() {
	cin.sync_with_stdio(false);
	cin.tie(0);
	cout.sync_with_stdio(false);
	cout.tie(0);
	while (true) {
		cin >> n;
		if (n == 0)
			break;
		solve();
	}
	return 0;
}