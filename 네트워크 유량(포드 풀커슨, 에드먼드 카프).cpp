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

// ��Ʈ��ũ �÷ο� // min(O(E*F),O(V*E^2))
// ����ǮĿ�� or ������ ī��

vi adj[60];
int cap[60][60], flow[60][60];
void solve() {
	int n;
	cin >> n;
	for (int i = 0; i < n; ++i) {
		char a, b;
		int c;
		cin >> a >> b>>c;
		adj[a - 'A'].push_back(b - 'A');
		adj[b - 'A'].push_back(a - 'A');
		cap[a - 'A'][b - 'A'] += c;
		cap[b - 'A'][a - 'A'] += c;
	}
	int src = 0, sink = 'Z'-'A'; 
	// ���� ǮĿ��
	int ans = 0;
	// bfs�� �带���ִ� ��θ� ã�� ������ �귯�ش�(�������). // ��θ� ��ã��������.
	// bfs����� �ܿ��뷮�� �ִ� �����鸸 �̿밡���ϴ�. ��, �ܿ��뷮�� ���� ������� source���� sink������ ��θ� Ž��.
	while (true) {
		// bfs�ѹ� ������ bfsƮ���� ����� parent����. // �� ���� �̿��� ������ ����ش�.
		vi pr(60, -1);
		// 0�� source // ť�� �߰�
		queue<int> q;
		q.push(0);
		pr[0] = 0; 
		// bfs // ��� �湮���� ��带 �湮�ϰų�, sink���� ��θ� ã��������
		while (!q.empty() && pr[sink]==-1) {
			int here = q.front();
			q.pop();
			for (int i : adj[here]) {
				// ���� �湮���� �ʾ����鼭, here�� ���� �����ִ� ����ΰ��(here-i ���� �ܿ��뷮�� 0���� ū ���)
				if (pr[i]==-1 && cap[here][i] - flow[here][i] > 0) {
					q.push(i);
					pr[i] = here; // here���� �湮�Ѵ�.
				}
			}
		}
		// sink���� ��ΰ� ���ٸ� ���̻� sink�� ������ �帣�� ���Ѵ�.
		if (pr[sink] == -1)
			break;
		
		// ���� ���.
		int amt = INF;
		// sink-source������ ��ο��� �ּ� �ܿ��뷮�� �ִ�� �������ִ� ������ �ȴ�.
		for (int i = sink; i != 0; i = pr[i]) {
			amt = min(amt, cap[pr[i]][i] - flow[pr[i]][i]);
		}
		ans += amt; // ���������� �����ش�.
		// ������ ��������ش�. ����� �̿밣���鿡 ������ ������ش�.
		for (int i = sink; i != 0; i = pr[i]) {
			flow[pr[i]][i] += amt;
			flow[i][pr[i]] -= amt; // ������ ���� ���.
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