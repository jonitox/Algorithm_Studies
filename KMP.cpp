<<<<<<< HEAD
#include <iostream>
#include <string>
#include <cstring>	
#include <vector>
#include <map>
#include <stack>
#include <queue>
#include <algorithm>
#include <typeinfo>
#include <iomanip>
#include <cmath>
#include <limits.h>
#include <set>

#define INF 1000000000
using namespace std;
#define EPS 1e-9

void solve() {
	string H, N;
	cin >> H >> N;
	int n = H.size(), m = N.size();
	vector<int> pi(m, 0);

	// pi����
	for (int i = 1, matched = 0; i < m; ++i) { // begin=1���� Ž��
		 
		while (matched > 0 && N[i] != N[matched])
			matched = pi[matched - 1];
		// ���ڰ� ���ٸ� pi����
		if (N[i] == N[matched]) {
			pi[i] = ++matched;
		}
	}
	//kmp
	vector<int> ans;

	for (int i = 0, matched = 0; i < n; ++i) {
		// ���� ���ڰ� �ٸ��ٸ� �������� ���ɼ� �ִ� �ĺ��� Ž���ϴµ�, i��° ���ڿ� ���� ���ڰ� ���������� �����Լ��� ���󰣴�.
		while (matched > 0 && H[i] != N[matched])
			matched = pi[matched - 1];
		// �� state���� ���ϴ� �� ���ڰ� ���� ��� (�ٸ��� match=0�� ���·� i+1���ڷ� �ѰŰ���.)
		if (H[i] == N[matched]) {
			// match�� 1�����ϰ�
			++matched;
			// �ٴù��ڿ��� ã�� ��� �信 �߰� �� ���� Ž���� ���� ���ɼ� �ִ� �ĺ��� �ٲ���.
			if (matched == m) {
				ans.push_back(i - m+1);
				matched = pi[matched - 1];
			}
		}
	}
	// ���
	cout << ans.size() << "\n";
	for (int i = 0; i < ans.size(); ++i)
		cout << ans[i] + 1 << " ";
}


int main() {
	cin.sync_with_stdio(false);
	cin.tie(0);
	cout.sync_with_stdio(false);
	cout.tie(0);
	
	solve();
		
	
	return 0;
}
=======
#include <iostream>
#include <string>
#include <cstring>	
#include <vector>
#include <map>
#include <stack>
#include <queue>
#include <algorithm>
#include <typeinfo>
#include <iomanip>
#include <cmath>
#include <limits.h>
#include <set>

#define INF 1000000000
using namespace std;
#define EPS 1e-9

void solve() {
	string H, N;
	cin >> H >> N;
	int n = H.size(), m = N.size();
	vector<int> pi(m, 0);

	// pi����
	for (int i = 1, matched = 0; i < m; ++i) { // begin=1���� Ž��
		 
		while (matched > 0 && N[i] != N[matched])
			matched = pi[matched - 1];
		// ���ڰ� ���ٸ� pi����
		if (N[i] == N[matched]) {
			pi[i] = ++matched;
		}
	}
	//kmp
	vector<int> ans;

	for (int i = 0, matched = 0; i < n; ++i) {
		// ���� ���ڰ� �ٸ��ٸ� �������� ���ɼ� �ִ� �ĺ��� Ž���ϴµ�, i��° ���ڿ� ���� ���ڰ� ���������� �����Լ��� ���󰣴�.
		while (matched > 0 && H[i] != N[matched])
			matched = pi[matched - 1];
		// �� state���� ���ϴ� �� ���ڰ� ���� ��� (�ٸ��� match=0�� ���·� i+1���ڷ� �ѰŰ���.)
		if (H[i] == N[matched]) {
			// match�� 1�����ϰ�
			++matched;
			// �ٴù��ڿ��� ã�� ��� �信 �߰� �� ���� Ž���� ���� ���ɼ� �ִ� �ĺ��� �ٲ���.
			if (matched == m) {
				ans.push_back(i - m+1);
				matched = pi[matched - 1];
			}
		}
	}
	// ���
	cout << ans.size() << "\n";
	for (int i = 0; i < ans.size(); ++i)
		cout << ans[i] + 1 << " ";
}


int main() {
	cin.sync_with_stdio(false);
	cin.tie(0);
	cout.sync_with_stdio(false);
	cout.tie(0);
	
	solve();
		
	
	return 0;
}
>>>>>>> bb6e75949a077d02582f893a347fffea74c6bcdf
