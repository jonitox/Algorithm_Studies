<<<<<<< HEAD
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

// 맨버-마이어스

string s;
int len;

// suffix를 t글자기준으로 정렬한 group배열을 이용해서 2t글자 기준으로 비교하기위한 함수객체
class COMP {
public:
	int t;
	vector<int>& group; // t기준으로 정렬된 그룹번호 // group배열은 항상 & (참조자)로 입력받고 저장한다.
	COMP(int t,vector<int>& group):t(t),group(group){}

	bool operator()(int a, int b) { // 2*t기준으로 비교하는 비교자
		if (group[a] != group[b]) return group[a]<group[b];
		return group[a + t] < group[b + t];
	}
};

void solve() {
	cin >> s;

	len = s.size();
	int t = 1;
	vector<int> perm(len); //suffix arr
	vector<int> group(len + 1); // group번호
	for (int i = 0; i < len; ++i) {
		perm[i] = i;
	}
	for (int i = 0; i < len; ++i) {
		group[i] = s[i];	// t=1일떄는 첫 글자를 기준으로 정렬하기 위해, 각 첫글자를 그룹 번호로 저장한다.(첫 글자 크기순= 사전순)
	}
	group[len] = -1; // a+t, b+t = n인 경우를 위해 저장. // 앞 t글자가 같은 문자열 중 문자열이 정확히 t글자인 문자열이 사전순으로 가장 먼저 오도록 한다.
	
	// t기준으로 정렬한 그룹번호를 이용해서 2t기준으로 정렬한다.
	while (t < len) {
		COMP cmp(t, group);
		sort(perm.begin(), perm.end(), cmp); // 2t기준 정렬
		
		// 기준인 2t가 n글자 이상이라면 종료.
		t *= 2;
		if (t >= len) break;
		
		// 다음 그룹번호 배정.
		vector<int> ngroup(len+1);
		ngroup[perm[0]] = 0;
		ngroup[len] = -1;
		// 2t글자 기준으로 정렬된 suffix arr(perm)의 앞에서부터 두개씩 비교하여
		for (int i = 1; i < len; ++i) {
			if (cmp(perm[i - 1], perm[i])) // 2*t기준으로 비교했을때, 두 suffix가 비교가 되었다면, 서로 다른 그룹(1을 더함)
				ngroup[perm[i]] = ngroup[perm[i - 1]] + 1;
			else
				ngroup[perm[i]] = ngroup[perm[i - 1]]; // 아니라면 서로 같은 그룹이다.
		}
		group = ngroup;
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

// 맨버-마이어스

string s;
int len;

// suffix를 t글자기준으로 정렬한 group배열을 이용해서 2t글자 기준으로 비교하기위한 함수객체
class COMP {
public:
	int t;
	vector<int>& group; // t기준으로 정렬된 그룹번호 // group배열은 항상 & (참조자)로 입력받고 저장한다.
	COMP(int t,vector<int>& group):t(t),group(group){}

	bool operator()(int a, int b) { // 2*t기준으로 비교하는 비교자
		if (group[a] != group[b]) return group[a]<group[b];
		return group[a + t] < group[b + t];
	}
};

void solve() {
	cin >> s;

	len = s.size();
	int t = 1;
	vector<int> perm(len); //suffix arr
	vector<int> group(len + 1); // group번호
	for (int i = 0; i < len; ++i) {
		perm[i] = i;
	}
	for (int i = 0; i < len; ++i) {
		group[i] = s[i];	// t=1일떄는 첫 글자를 기준으로 정렬하기 위해, 각 첫글자를 그룹 번호로 저장한다.(첫 글자 크기순= 사전순)
	}
	group[len] = -1; // a+t, b+t = n인 경우를 위해 저장. // 앞 t글자가 같은 문자열 중 문자열이 정확히 t글자인 문자열이 사전순으로 가장 먼저 오도록 한다.
	
	// t기준으로 정렬한 그룹번호를 이용해서 2t기준으로 정렬한다.
	while (t < len) {
		COMP cmp(t, group);
		sort(perm.begin(), perm.end(), cmp); // 2t기준 정렬
		
		// 기준인 2t가 n글자 이상이라면 종료.
		t *= 2;
		if (t >= len) break;
		
		// 다음 그룹번호 배정.
		vector<int> ngroup(len+1);
		ngroup[perm[0]] = 0;
		ngroup[len] = -1;
		// 2t글자 기준으로 정렬된 suffix arr(perm)의 앞에서부터 두개씩 비교하여
		for (int i = 1; i < len; ++i) {
			if (cmp(perm[i - 1], perm[i])) // 2*t기준으로 비교했을때, 두 suffix가 비교가 되었다면, 서로 다른 그룹(1을 더함)
				ngroup[perm[i]] = ngroup[perm[i - 1]] + 1;
			else
				ngroup[perm[i]] = ngroup[perm[i - 1]]; // 아니라면 서로 같은 그룹이다.
		}
		group = ngroup;
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