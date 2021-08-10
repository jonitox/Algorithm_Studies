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

// �������� �������� �־��� ������ �����ϱ� ���� ���Լ���ü
class CMP {
public:
	vec p; // ������
	CMP(vec p):p(p){}
	bool operator () (vec a, vec b) {
		if (ccw(p, a, b) != 0) return ccw(p, a, b) > 0; // �ݽð�� ����
		return (p - a).norm() < (p - b).norm();			// ������ ���ٸ� �Ÿ��� ����� ������ ����
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

	// �׶���-��ĵ
	// ������ ã�� : pts[0]
	swap(pts[0], *min_element(pts.begin(), pts.end()));
	// �������� �߽����� ���������� �ݽð�� ����
	sort(pts.begin() + 1, pts.end(), CMP(pts[0]));

	vector<vec> hull; // ���ϲ���
	// �������� ù��°���� �߰��ϰ�
	hull.push_back(pts[0]);
	hull.push_back(pts[1]);
	// ���������� ��ȸ
	for (int i = 2; i < n; ++i) {
		// ������ ���� ���ο� ���� �ݽð踦 �̷��� �ʴ´ٸ� ������ ���� �����Ѵ�.
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

