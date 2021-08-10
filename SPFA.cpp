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

using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<bool> vb;
typedef vector<long long> vll;
typedef vector<vector<int>> vvi;
typedef pair<int, int> pii;
typedef vector<pii> vpii;

// SPFA �˰����� // O(VE), ��� O(E)
// ����ġ�׷����� �� ��忡�� ������ ���ܱ��� �ִܰ�� ���.
// ���� ���� ���� ����. // ���� ����Ŭ �Ǻ� ����.
// ���ͽ�Ʈ��� �Ȱ���. ��, pq�� �ƴ� queue�� ����ϸ�, update�Ǿ ť�� ���� ��쿡�� �߰��Ѵٴ°͸� �ٸ�.
int n, m;
vector<vpii> adj;
vi dis;
vi cycle; // �ش� ������ updateȽ��.(**ť�� �߰��� Ƚ��) // n�� �̻� update�ȴٸ� ��尡 ��������Ŭ ���� �����Ѵ�. //��������Ŭ �Ǻ� ����.
vb inQ; // ť�� �ش������� �ִ��� ����. // update�� ��尡 ť�� �̹� �ִٸ� �ߺ����� �߰������ʱ� ����. 
void solve() {
	cin >> n >> m;
	adj.resize(n);
	for (int i = 0; i < m; ++i) {
		int a, b, c;
		cin >> a >> b >> c;
		adj[a-1].push_back({ b - 1,c });
	}


	dis = vi(n, INF), cycle = vi(n,0), inQ = vb(n, false); //�ʱ�ȭ
	queue<int> q;
	q.push(0); // �������� 0
	dis[0] = 0; inQ[0] = true; cycle[0]++;
	// update�� �Ͼ������������ �ݺ��Ѵ�.
	while (!q.empty()) {
		int here = q.front();
		q.pop();
		inQ[here] = false; //ť���� ����.
        // here�� ������ִ� ���鿡 ���� ���Ű������� Ȯ��.
        // (here������ �Ÿ��� update�Ǿ ť�� ����־���, ���� �̿� ����� �ٸ��������� �Ÿ��� updaste�Ҽ��ִ��� Ȯ���Ѵ�.)
            for (auto i : adj[here]) {
			int there = i.first;
			int cost = i.second;
			// update�� ������ ��츸
			if (dis[there] <= dis[here] + cost) continue; 
			// update
			dis[there] = dis[here] + cost;
			// ť�� ���ٸ� ť�� �߰��Ѵ�. // there�κ��� ����� �ٸ��������� �Ÿ��� �ٽ� �����ϱ� �����̴�.
            // ť�� �̹� �ִٸ� �ٽ� �־��� �ʿ�� ����.
			if (!inQ[there]) {
				cycle[there]++; // there�� update�� Ƚ��+1 //**��Ȯ����, ť���߰��� Ƚ��. 
				if (cycle[there] >= n) {
					cout << -1 << "\n"; // ���� ����Ŭ�� ����! // ��� �� �Լ� ����.
					return;
				}
				q.push(there);
				inQ[there] = true;
			}
		}
	}
	for (int i = 1; i < n; ++i)
		cout << dis[i] << "\n";
}

int main() {
	cin.sync_with_stdio(false);
	cin.tie(0);
	cout.sync_with_stdio(false);
	cout.tie(0);
	
	solve();

	return 0;
}