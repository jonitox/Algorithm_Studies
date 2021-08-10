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

// �Ϲ� ��Ŭ����
// ���μ� ����(Ȥ�� ���� �ϳ��� 1) ã���� Ȯ�� ���� �Ϲ� ��Ŭ���带 �������.
int gcd(int a, int b) {
	if (b == 0) return a;
	return gcd(b, a%b);
}

// Ȯ�� ��Ŭ���� ȣ���� // a,b>1�϶��� �Է����� ���´� ��������.
pair<int, pii> extended_gcd(int a, int b) {
    if (a < b)	swap(a, b);
    // gcd(a,b) = gcd(r0,r1) ���� �ٲٰ�, gcd(r0,r1) = gcd(r1,r0%r1) =gcd(r1,r2) ..��� �����Ҷ�, ���� gcd(r,0)�� �ɶ����� �ݺ��Ѵ�.(r= gcd(a,b))
    // ri = si*a+t8Ib
    int r0 = a, r1 = b;
	int s0 = 1, s1 = 0;
	int t0 = 0, t1 = 1;
	
	while (1) {
		int q = r0 / r1; // q = r(i-1)/r(i)�� ����
		int r = r0 % r1; // r(i) = r(i-2)%r(i-1)
		r0 = r1;
		r1 = r;
		if (r1 == 0)
			break;
		int s = s0 - s1 * q; // s(i) = s(i-2) - q(i)*s(i-1) �� ����
		int t = t0 - t1 * q; // t(i) = t(i-2) - q(i)*t(i-1) �� ����
		s0 = s1; s1 = s;
		t0 = t1; t1 = t;
	}
	return { r0,{s1,t1} }; // r0(=gcd(a,b)) = s1*a + t1*b�� ��ȯ.
    // a�� mod b�� ���� ���� ���ҽ�(a^-1�� �����Ѵٸ�), s1�� a�� ������. // �� ������, 1 = gcd(a,b)  = a*s+b*t���� a*s=1(mod b)
    // s�� ���� ������� +b���ָ� 0~b-1�� ��(mod ��)���� ã���� �ִ�.
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
}