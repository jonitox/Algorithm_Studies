<<<<<<< HEAD
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

// 일반 유클리드
// 서로소 여부(혹은 둘중 하나가 1) 찾을땐 확장 말고 일반 유클리드를 사용하자.
int gcd(int a, int b) {
	if (b == 0) return a;
	return gcd(b, a%b);
}

// 확장 유클리드 호제법 // a,b>1일때만 입력으로 들어온다 가정하자.
pair<int, pii> extended_gcd(int a, int b) {
    if (a < b)	swap(a, b);
    // gcd(a,b) = gcd(r0,r1) 으로 바꾸고, gcd(r0,r1) = gcd(r1,r0%r1) =gcd(r1,r2) ..라고 정의할때, 최종 gcd(r,0)이 될때까지 반복한다.(r= gcd(a,b))
    // ri = si*a+t8Ib
    int r0 = a, r1 = b;
	int s0 = 1, s1 = 0;
	int t0 = 0, t1 = 1;
	
	while (1) {
		int q = r0 / r1; // q = r(i-1)/r(i)로 정의
		int r = r0 % r1; // r(i) = r(i-2)%r(i-1)
		r0 = r1;
		r1 = r;
		if (r1 == 0)
			break;
		int s = s0 - s1 * q; // s(i) = s(i-2) - q(i)*s(i-1) 가 성립
		int t = t0 - t1 * q; // t(i) = t(i-2) - q(i)*t(i-1) 가 성립
		s0 = s1; s1 = s;
		t0 = t1; t1 = t;
	}
	return { r0,{s1,t1} }; // r0(=gcd(a,b)) = s1*a + t1*b를 반환.
    // a의 mod b에 대한 역원 구할시(a^-1이 존재한다면), s1이 a의 곱역원. // 그 이유는, 1 = gcd(a,b)  = a*s+b*t에서 a*s=1(mod b)
    // s가 만약 음수라면 +b해주면 0~b-1의 값(mod 값)으로 찾을수 있다.
}
void solve() {
	int a, b;
	cin >> a >> b;
	auto k = extended_gcd(a, b);
	cout << k.first << k.second.first << k.second.second;
}

int main() {
	cin.sync_with_stdio(false);
	cin.tie(0);
	cout.sync_with_stdio(false);
	cout.tie(0);
	while (1)
		solve();

	return 0;
=======
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

// 일반 유클리드
// 서로소 여부(혹은 둘중 하나가 1) 찾을땐 확장 말고 일반 유클리드를 사용하자.
int gcd(int a, int b) {
	if (b == 0) return a;
	return gcd(b, a%b);
}

// 확장 유클리드 호제법 // a,b>1일때만 입력으로 들어온다 가정하자.
pair<int, pii> extended_gcd(int a, int b) {
    if (a < b)	swap(a, b);
    // gcd(a,b) = gcd(r0,r1) 으로 바꾸고, gcd(r0,r1) = gcd(r1,r0%r1) =gcd(r1,r2) ..라고 정의할때, 최종 gcd(r,0)이 될때까지 반복한다.(r= gcd(a,b))
    // ri = si*a+t8Ib
    int r0 = a, r1 = b;
	int s0 = 1, s1 = 0;
	int t0 = 0, t1 = 1;
	
	while (1) {
		int q = r0 / r1; // q = r(i-1)/r(i)로 정의
		int r = r0 % r1; // r(i) = r(i-2)%r(i-1)
		r0 = r1;
		r1 = r;
		if (r1 == 0)
			break;
		int s = s0 - s1 * q; // s(i) = s(i-2) - q(i)*s(i-1) 가 성립
		int t = t0 - t1 * q; // t(i) = t(i-2) - q(i)*t(i-1) 가 성립
		s0 = s1; s1 = s;
		t0 = t1; t1 = t;
	}
	return { r0,{s1,t1} }; // r0(=gcd(a,b)) = s1*a + t1*b를 반환.
    // a의 mod b에 대한 역원 구할시(a^-1이 존재한다면), s1이 a의 곱역원. // 그 이유는, 1 = gcd(a,b)  = a*s+b*t에서 a*s=1(mod b)
    // s가 만약 음수라면 +b해주면 0~b-1의 값(mod 값)으로 찾을수 있다.
}
void solve() {
	int a, b;
	cin >> a >> b;
	auto k = extended_gcd(a, b);
	cout << k.first << k.second.first << k.second.second;
}

int main() {
	cin.sync_with_stdio(false);
	cin.tie(0);
	cout.sync_with_stdio(false);
	cout.tie(0);
	while (1)
		solve();

	return 0;
>>>>>>> bb6e75949a077d02582f893a347fffea74c6bcdf
}