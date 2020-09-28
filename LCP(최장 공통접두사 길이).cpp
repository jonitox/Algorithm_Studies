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
int n;
string s;

//LCP알고리즘


// 맨버-마이어스
class CMP {
};

void getSA(string& s, vector<int>& perm) {
}
void solve() {
	
	cin >> s;
	n = s.size();
	// 맨버-마이어스로 Suffix Arr을 구한다.
	vector<int> perm(n);
	getSA(s, perm);
	
	        
	
	// LCP 알고리즘
	vector<int> LCP(n); // LCP[i] : perm[i]와 perm[i-1] 간의 최장 공통 접두사길이
	vector<int> rank(n); // perm의 역함수 // rank[perm[i]] = i // rank[i] : s[i..]의 접미사 사전순 순서
	for (int i = 0; i < n;++i)
		rank[perm[i]] = i;
	int h = 0; // 공통글자수
	LCP[0] = 0;
	for (int i = 0; i < n; ++i) {
		// s[i..]의 사전순 순서가 1이상인 경우 rank[i] > 0
		// 사전순 0번째 접미사는 그 이전 사전순 문자가 없으므로 계산하지 않는다. // 항상 LCP[0] = 0
		if (rank[i]) {
			int j = perm[rank[i] - 1]; // s[i..]와 Suffix Arr상 인접한 s[j..]
			// S.A에서 인접한 s[i..]와 s[j..]의 최장공통 접두사길이를 계산한다. 
			while (s[i + h] == s[j + h]) h++; // 참고 // i+h = s.size()이면 문자열의 끝. s[s.size()]는 접근가능하고 NULL이 저장되있다. 즉, index에러 고려 안해도됨.
			LCP[rank[i]] = h;	// LCP 저장.
		}
		// h>0이면 1을 빼준다.
		//** 왜냐하면, for문의 다음탐색 s[i+1..]은 항상 자신과 SA에서 인접한 접두사와의 최장공통길이(lcp)가 h-1 이상이기 때문이다. 
		if (h) h--;  
	}

	// 복잡도 분석: for문내의 while문은 한번 실행마다 h++되고 h는 for문 전체에서 n만큼 감소할수 있으며, n보다 커질수 없다. 즉, 분할상환으로 최대o(n)번 실행되므로
	// 전체 복잡도 : o(n)

}

int main() {
	cin.sync_with_stdio(false);
	cin.tie(0);
	cout.sync_with_stdio(false);
	cout.tie(0);

	solve();
	return 0;
}