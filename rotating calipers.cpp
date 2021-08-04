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

int n;
class vec {
public:
	double x, y;
	vec(double x=0, double y=0):x(x),y(y){}
	
	vec operator -()const {
		return vec(-x, -y);
	}
	bool operator ==(const vec& rhs) const {
		return x == rhs.x && y == rhs.y;
	}

	bool operator <(const vec& rhs) const {
		return x != rhs.x ? x < rhs.x : y < rhs.y;
	}

	vec operator - (const vec& rhs) const {
		return vec(x - rhs.x, y - rhs.y);
	}
	double dot(const vec& rhs) const {
		return x * rhs.x + y * rhs.y;
	}
	double cross(const vec& rhs) const {
		return x * rhs.y - y * rhs.x;
	}
	double norm() {
		return hypot(x, y);
	}
	vec normalize() {
		return vec(x / norm(),y/norm());
	}
};

int ccw(vec a, vec b, vec c) {
	double ret = (b - a).cross(c - a);
	if (ret > 0) return 1;
	else if (ret < 0) return -1;
	else return 0;
}


void solve() {
	cin >> n;
	
	vector<vec> hull;
	for (int i = 0; i < n; ++i) {
		int x, y;
		cin >> x >> y;
		hull.push_back({ x,y });
	}

	// 로테이팅 캘리퍼스
	int m = hull.size();
	vec calipers(0, -1); // 캘리퍼스 초기화 // 왼쪽끝에 끼운 방향을 기준으로 한다.
	// 가장왼쪽끝과 오른쪽끝에 끼우고 시작
	int left = min_element(hull.begin(), hull.end()) - hull.begin();
	int right = max_element(hull.begin(), hull.end()) - hull.begin();
	int a = left, b = right;

	// 각변의 방향벡터 저장
	vector<vec> toNext(m);
	for (int i = 0; i < m; ++i) {
		toNext[i] = (hull[(i + 1) % m] - hull[i]).normalize();
	}
	
	double ret = (hull[left] - hull[right]).norm(); // 반환할 두점 사이거리 최댓값

	// 캘리퍼스를 반바퀴 회전할때까지 돌려본다.
	while (a != right || b != left) {
		// 회전 각도가 더 작은 쪽으로 변에맞춰 돌리기
		double cosA = calipers.dot(toNext[a]); 
		double cosB = -calipers.dot(toNext[b]);
		// 각도가 더 작으면 dot값이 더 크다.
		if (cosA > cosB) {
			calipers = toNext[a];
			a = (a + 1)%m;
		}
		else {
			calipers = -toNext[b];
			b = (b + 1) % m;
		}
		ret = max(ret, (hull[a] - hull[b]).norm());
		
	}
	printf("%.8lf\n", ret);
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

int n;
class vec {
public:
	double x, y;
	vec(double x=0, double y=0):x(x),y(y){}
	
	vec operator -()const {
		return vec(-x, -y);
	}
	bool operator ==(const vec& rhs) const {
		return x == rhs.x && y == rhs.y;
	}

	bool operator <(const vec& rhs) const {
		return x != rhs.x ? x < rhs.x : y < rhs.y;
	}

	vec operator - (const vec& rhs) const {
		return vec(x - rhs.x, y - rhs.y);
	}
	double dot(const vec& rhs) const {
		return x * rhs.x + y * rhs.y;
	}
	double cross(const vec& rhs) const {
		return x * rhs.y - y * rhs.x;
	}
	double norm() {
		return hypot(x, y);
	}
	vec normalize() {
		return vec(x / norm(),y/norm());
	}
};

int ccw(vec a, vec b, vec c) {
	double ret = (b - a).cross(c - a);
	if (ret > 0) return 1;
	else if (ret < 0) return -1;
	else return 0;
}


void solve() {
	cin >> n;
	
	vector<vec> hull;
	for (int i = 0; i < n; ++i) {
		int x, y;
		cin >> x >> y;
		hull.push_back({ x,y });
	}

	// 로테이팅 캘리퍼스
	int m = hull.size();
	vec calipers(0, -1); // 캘리퍼스 초기화 // 왼쪽끝에 끼운 방향을 기준으로 한다.
	// 가장왼쪽끝과 오른쪽끝에 끼우고 시작
	int left = min_element(hull.begin(), hull.end()) - hull.begin();
	int right = max_element(hull.begin(), hull.end()) - hull.begin();
	int a = left, b = right;

	// 각변의 방향벡터 저장
	vector<vec> toNext(m);
	for (int i = 0; i < m; ++i) {
		toNext[i] = (hull[(i + 1) % m] - hull[i]).normalize();
	}
	
	double ret = (hull[left] - hull[right]).norm(); // 반환할 두점 사이거리 최댓값

	// 캘리퍼스를 반바퀴 회전할때까지 돌려본다.
	while (a != right || b != left) {
		// 회전 각도가 더 작은 쪽으로 변에맞춰 돌리기
		double cosA = calipers.dot(toNext[a]); 
		double cosB = -calipers.dot(toNext[b]);
		// 각도가 더 작으면 dot값이 더 크다.
		if (cosA > cosB) {
			calipers = toNext[a];
			a = (a + 1)%m;
		}
		else {
			calipers = -toNext[b];
			b = (b + 1) % m;
		}
		ret = max(ret, (hull[a] - hull[b]).norm());
		
	}
	printf("%.8lf\n", ret);
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
