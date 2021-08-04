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
#define mod 100
using namespace std;

int n, m;
vector<vector<int>> adj;
int depth[100000]; // ����� ����
int pr[100000][20]; // pr[i][j]: i�� ����� 2^j��° ���� // pr[i][0]: �θ��� // j�� MAX���� log2(����)�� ������ �ȴ�. N=1e5�̸� �־��� ��쿡�� ���̰� 2^19�� �����ʴ´�.

// LCA�˰���
// o(lgN)�� LCA�� ���Ѵ�.
// M�� ���� �� ���⵵ o(M*lgN)
// pr�迭 index-error�� ����



//dfs�� ��ȸ�ϸ� �� ����� �θ���� ���� ����
void dfs(int here, int d) {
	depth[here] = d;
	for (int there : adj[here]) {
		if (depth[there] != -1) continue;
		pr[there][0] = here; // �θ��� ����
		dfs(there, d+1); // ���
	}
	return;
}



void solve() {
	memset(pr, -1, sizeof(pr));
	memset(depth, -1, sizeof(depth));
	cin >> n;
	adj.resize(n);
	// Ʈ�� �Է�, �׷��� ����
	for (int i = 0; i < n-1; ++i) {
		int a, b;
		cin >> a >> b;
		adj[a - 1].push_back(b - 1);
		adj[b - 1].push_back(a - 1);
	}
	// dfs
	dfs(0,0);


	//** pr[][] ��� // �� ����� 2^j��° ������
	// ������ root�� �Ѿ�� �ʱ�ȭ���� -1�� �����ϵ��� ó����.
	for (int j = 1; j < 20; ++j) {
		for (int i = 0; i < n; ++i) {
			if(pr[i][j-1] != -1)		// index-error ����
				pr[i][j] = pr[pr[i][j - 1]][j - 1]; //** i�� 2^j��° ������ 2^j-1��° ���� ����� 2^j-1��° �����̴�.
		}
	}
	

	// m�� ���� �Է�, m������ LCA ã��.
	cin >> m;
	for (int i = 0; i < m; ++i) {
		int a, b, lca;
		cin >> a >> b;
		a--; b--;
		
		// LCA ã��
		//** a���̰� b���� �̻��̵��� ����.
		if (depth[a] < depth[b]) swap(a, b);

		//** a�� b�� ���̰� ������������ a�� ������ 2^i�� ����ö󰣴�.
		for (int j = 19; j >= 0; --j) {
			if (pr[a][j] == -1) continue; // root�� �Ѿ�� ����
			// a�� 2^i��° ������ b���� ���� ������(depth�� ũ��) ����ö󰣴�.
			if (depth[pr[a][j]] >= depth[b]) {
				a = pr[a][j];
			}
		}

		//** ���̰� ���������� a�� b�� ���ٸ� lca�� ã��. 
		lca = a;

		//** a�� b�� �����ʴٸ�, �� a,b�� �� ������ ���� �ٸ��� subtree�� �ִٸ�,
		if (a != b) {
			//** ����������, ���� ����(LCA)�� ���������� Ʈ���� Ÿ�� �ö󰣴�.
			for (int j = 19; j >= 0; --j) 
				if (pr[a][j] != pr[b][j]) { // ����: a,b���̰� �����Ƿ� ���� �� ������ -1�� ���� ����ȵǹǷ�, index-error ������ص���.
					a = pr[a][j], b = pr[b][j];
				}
			//�� for���� ��ȸ�ϰ���, LCA�� �ٷ� �ر��� ����ö�� ���̹Ƿ�. a(,b)�� �θ� LCA�̴�.
			lca = pr[a][0];
		}
		cout << lca+1 << "\n";
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