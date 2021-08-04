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

	// pi생성
	for (int i = 1, matched = 0; i < m; ++i) { // begin=1부터 탐색
		 
		while (matched > 0 && N[i] != N[matched])
			matched = pi[matched - 1];
		// 문자가 같다면 pi갱신
		if (N[i] == N[matched]) {
			pi[i] = ++matched;
		}
	}
	//kmp
	vector<int> ans;

	for (int i = 0, matched = 0; i < n; ++i) {
		// 비교한 문자가 다르다면 다음으로 가능성 있는 후보를 탐색하는데, i번째 글자와 다음 글자가 맞을때까지 실패함수를 따라간다.
		while (matched > 0 && H[i] != N[matched])
			matched = pi[matched - 1];
		// 현 state에서 비교하는 두 문자가 같은 경우 (다르면 match=0인 상태로 i+1글자로 넘거간다.)
		if (H[i] == N[matched]) {
			// match를 1증가하고
			++matched;
			// 바늘문자열을 찾은 경우 답에 추가 후 다음 탐색을 위해 가능성 있는 후보로 바꿔줌.
			if (matched == m) {
				ans.push_back(i - m+1);
				matched = pi[matched - 1];
			}
		}
	}
	// 출력
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

	// pi생성
	for (int i = 1, matched = 0; i < m; ++i) { // begin=1부터 탐색
		 
		while (matched > 0 && N[i] != N[matched])
			matched = pi[matched - 1];
		// 문자가 같다면 pi갱신
		if (N[i] == N[matched]) {
			pi[i] = ++matched;
		}
	}
	//kmp
	vector<int> ans;

	for (int i = 0, matched = 0; i < n; ++i) {
		// 비교한 문자가 다르다면 다음으로 가능성 있는 후보를 탐색하는데, i번째 글자와 다음 글자가 맞을때까지 실패함수를 따라간다.
		while (matched > 0 && H[i] != N[matched])
			matched = pi[matched - 1];
		// 현 state에서 비교하는 두 문자가 같은 경우 (다르면 match=0인 상태로 i+1글자로 넘거간다.)
		if (H[i] == N[matched]) {
			// match를 1증가하고
			++matched;
			// 바늘문자열을 찾은 경우 답에 추가 후 다음 탐색을 위해 가능성 있는 후보로 바꿔줌.
			if (matched == m) {
				ans.push_back(i - m+1);
				matched = pi[matched - 1];
			}
		}
	}
	// 출력
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
