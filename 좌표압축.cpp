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

// ��ǥ����
vi idx; // �Է����� ���� ��(��ǥ)���� ��� �����Ͽ� ������ �迭.
// ������ ���� �����(�����Ǵ�) ��ǥ ��ȯ
int getIdx(int x) {
	return lower_bound(idx.begin(), idx.end(),x)-idx.begin();
}

void solve() {
	// ex) n���� 1���� ��ǥ�� ������ 1���������󿡼� x~y������ �ִ� ���� ������ ���� q���� ������ ���� �������,
	int n,q;
	cin >> n>>q;
	// ������ �����ϴ� ���� ��ǥ �Է�.
	for (int i = 0; i < n; ++i) {
		int a;
		cin >> a;
		idx.push_back(a);
	}
	// ������ ���ü��ִ� ��ǥ�Է�.
	for (int i = 0; i < q; ++i) {
		int x, y;
		cin >> x >> y;
		idx.push_back(x);
		idx.push_back(y);
	}
	// ���� �����ϴ� ��ǥ���� ���� �� �ߺ�����.
	sort(idx.begin(), idx.end());
	idx.erase(unique(idx.begin(), idx.end()), idx.end());

	//�̿���
	getIdx(30); // ��ǥ 30�� �ش��ϴ� ������ǥ ��ȯ
}

int main() {
	cin.sync_with_stdio(false);
	cin.tie(0);
	cout.sync_with_stdio(false);
	cout.tie(0);


	solve();

	return 0;
}