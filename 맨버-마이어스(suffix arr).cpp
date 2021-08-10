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

// �ǹ�-���̾

string s;
int len;

// suffix�� t���ڱ������� ������ group�迭�� �̿��ؼ� 2t���� �������� ���ϱ����� �Լ���ü
class COMP {
public:
	int t;
	vector<int>& group; // t�������� ���ĵ� �׷��ȣ // group�迭�� �׻� & (������)�� �Է¹ް� �����Ѵ�.
	COMP(int t,vector<int>& group):t(t),group(group){}

	bool operator()(int a, int b) { // 2*t�������� ���ϴ� ����
		if (group[a] != group[b]) return group[a]<group[b];
		return group[a + t] < group[b + t];
	}
};

void solve() {
	cin >> s;

	len = s.size();
	int t = 1;
	vector<int> perm(len); //suffix arr
	vector<int> group(len + 1); // group��ȣ
	for (int i = 0; i < len; ++i) {
		perm[i] = i;
	}
	for (int i = 0; i < len; ++i) {
		group[i] = s[i];	// t=1�ϋ��� ù ���ڸ� �������� �����ϱ� ����, �� ù���ڸ� �׷� ��ȣ�� �����Ѵ�.(ù ���� ũ���= ������)
	}
	group[len] = -1; // a+t, b+t = n�� ��츦 ���� ����. // �� t���ڰ� ���� ���ڿ� �� ���ڿ��� ��Ȯ�� t������ ���ڿ��� ���������� ���� ���� ������ �Ѵ�.
	
	// t�������� ������ �׷��ȣ�� �̿��ؼ� 2t�������� �����Ѵ�.
	while (t < len) {
		COMP cmp(t, group);
		sort(perm.begin(), perm.end(), cmp); // 2t���� ����
		
		// ������ 2t�� n���� �̻��̶�� ����.
		t *= 2;
		if (t >= len) break;
		
		// ���� �׷��ȣ ����.
		vector<int> ngroup(len+1);
		ngroup[perm[0]] = 0;
		ngroup[len] = -1;
		// 2t���� �������� ���ĵ� suffix arr(perm)�� �տ������� �ΰ��� ���Ͽ�
		for (int i = 1; i < len; ++i) {
			if (cmp(perm[i - 1], perm[i])) // 2*t�������� ��������, �� suffix�� �񱳰� �Ǿ��ٸ�, ���� �ٸ� �׷�(1�� ����)
				ngroup[perm[i]] = ngroup[perm[i - 1]] + 1;
			else
				ngroup[perm[i]] = ngroup[perm[i - 1]]; // �ƴ϶�� ���� ���� �׷��̴�.
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
}