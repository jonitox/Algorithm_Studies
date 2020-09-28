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

// 좌표압축
vi idx; // 입력으로 들어온 값(좌표)들을 모두 저장하여 정렬한 배열.
// 임의의 값의 압축된(대응되는) 좌표 반환
int getIdx(int x) {
	return lower_bound(idx.begin(), idx.end(),x)-idx.begin();
}

void solve() {
	// ex) n개의 1차원 좌표가 들어오고 1차원직선상에서 x~y구간에 있는 점의 개수를 묻는 q개의 쿼리를 묻는 문제라면,
	int n,q;
	cin >> n>>q;
	// 직선에 존재하는 점의 좌표 입력.
	for (int i = 0; i < n; ++i) {
		int a;
		cin >> a;
		idx.push_back(a);
	}
	// 쿼리로 들어올수있는 좌표입력.
	for (int i = 0; i < q; ++i) {
		int x, y;
		cin >> x >> y;
		idx.push_back(x);
		idx.push_back(y);
	}
	// 실제 존재하는 좌표들을 정렬 후 중복제거.
	sort(idx.begin(), idx.end());
	idx.erase(unique(idx.begin(), idx.end()), idx.end());

	//이용방법
	getIdx(30); // 좌표 30에 해당하는 압축좌표 반환
}

int main() {
	cin.sync_with_stdio(false);
	cin.tie(0);
	cout.sync_with_stdio(false);
	cout.tie(0);


	solve();

	return 0;
}