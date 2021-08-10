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
#include <math.h>

#define INF 2000000000
using namespace std;
#define mod 1000000007

// �̺� ��Ī // ���⵵ : V*E
int n, m;
int adj[200][200]; // �������. // ��������Ʈ�� �����ص��ȴ�.
vector<bool> vis;
int amatch[200], bmatch[200]; // amatch�� ���� �ʿ����.

// A�� ���� a���� ���� ��θ� Ž���Ѵ�.
bool dfs(int a) {
	if (vis[a]) return false; // �̹� �湮�Ͽ� Ž���� ���̸� �� �����κ��� ��ΰ� ����.
	vis[a] = true;
	for (int b = 0; b < m; ++b) { // B�� ��ȸ�ϸ�
		if(adj[a][b]) // ����� b�� ���ҿ� ����
			// ���� match�� ���ٸ� ���� //** Ȥ�� match�� �ִٸ� �����Ǵ� A���ҿ��� �ٽ� ������θ� Ž���غ���. = match ��迭
			if (bmatch[b] == -1 || dfs(bmatch[b])) { 
				amatch[a] = b;
				bmatch[b] = a;
				return true;
			}
	}
	return false;
}


void solve() {
	cin >> n >> m;

	//���� �߰�
	for (int i = 0; i < n; ++i) {
		int a;
		cin >> a;
		for (int j = 0; j < a; ++j) {
			int b;
			cin >> b;
			adj[i][b - 1] = 1;
		}
	}

	int ans = 0;
	// �̺� ��Ī
	// match �ʱ�ȭ
	memset(amatch, -1, sizeof(amatch));
	memset(bmatch, -1, sizeof(bmatch));
	for (int i = 0; i < n; ++i) {
		vis = vector<bool>(200, false); // vis�迭 �ʱ�ȭ //**�� Ž�� ��߸���  �ʱ�ȭ�Ѵ�. (���ġ�� �Ҽ��� �����Ƿ�)
		if (dfs(i)) {
			ans++; //�� ������ ��Ī +1
		}
	}
	cout << ans << "\n";
}

int main() {
	cin.sync_with_stdio(false);
	cin.tie(0);
	cout.sync_with_stdio(false);
	cout.tie(0);

	solve();

	return 0;
}