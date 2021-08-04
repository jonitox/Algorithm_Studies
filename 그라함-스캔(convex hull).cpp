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
	vec(int x, int y):x(x),y(y){}
	
	bool operator ==(const vec& rhs) const {
		return x == rhs.x && y == rhs.y;
	}
	bool operator <(const vec& rhs) const {
		return x != rhs.x ? x < rhs.x : y < rhs.y;
	}
	vec operator - (const vec& rhs) const {
		return vec(x - rhs.x, y - rhs.y);
	}
	double cross(const vec& rhs) const {
		return x * rhs.y - y * rhs.x;
	}
	double norm() {
		return hypot(x, y);
	}
};

int ccw(vec a, vec b, vec c) {
	double ret = (b - a).cross(c - a);
	if (ret > 0) return 1;
	else if (ret < 0) return -1;
	else return 0;
}

// 기준점을 기준으로 주어진 점들을 정렬하기 위한 비교함수객체
class CMP {
public:
	vec p; // 기준점
	CMP(vec p):p(p){}
	bool operator () (vec a, vec b) {
		if (ccw(p, a, b) != 0) return ccw(p, a, b) > 0; // 반시계로 정렬
		return (p - a).norm() < (p - b).norm();			// 각도가 같다면 거리가 가까운 순으로 정렬
	}
};
void solve() {
	cin >> n;
	vector<vec> pts;
	
	for (int i = 0; i < n; ++i) {
		double x, y;
		cin >> x >> y;
		pts.push_back(vec(x, y));
	}

	// 그라함-스캔
	// 기준점 찾기 : pts[0]
	swap(pts[0], *min_element(pts.begin(), pts.end()));
	// 기준점을 중심으로 나머지점을 반시계로 정렬
	sort(pts.begin() + 1, pts.end(), CMP(pts[0]));

	vector<vec> hull; // 볼록껍질
	// 기준점과 첫번째점을 추가하고
	hull.push_back(pts[0]);
	hull.push_back(pts[1]);
	// 나머지점을 순회
	for (int i = 2; i < n; ++i) {
		// 기존의 점과 새로운 점이 반시계를 이루지 않는다면 기존의 점을 제거한다.
		while (hull.size() >= 2 && ccw(hull[hull.size() - 2], hull.back(), pts[i]) <= 0)
			hull.pop_back();
		hull.push_back(pts[i]);
	}

	cout << hull.size() << "\n";
}


int main() {
	cin.sync_with_stdio(false);
	cin.tie(0);
	cout.sync_with_stdio(false);
	cout.tie(0);
	solve();

	return 0;
}
