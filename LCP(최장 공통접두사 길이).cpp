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

//LCP�˰���


// �ǹ�-���̾
class CMP {
};

void getSA(string& s, vector<int>& perm) {
}
void solve() {
	
	cin >> s;
	n = s.size();
	// �ǹ�-���̾�� Suffix Arr�� ���Ѵ�.
	vector<int> perm(n);
	getSA(s, perm);
	
	        
	
	// LCP �˰���
	vector<int> LCP(n); // LCP[i] : perm[i]�� perm[i-1] ���� ���� ���� ���λ����
	vector<int> rank(n); // perm�� ���Լ� // rank[perm[i]] = i // rank[i] : s[i..]�� ���̻� ������ ����
	for (int i = 0; i < n;++i)
		rank[perm[i]] = i;
	int h = 0; // ������ڼ�
	LCP[0] = 0;
	for (int i = 0; i < n; ++i) {
		// s[i..]�� ������ ������ 1�̻��� ��� rank[i] > 0
		// ������ 0��° ���̻�� �� ���� ������ ���ڰ� �����Ƿ� ������� �ʴ´�. // �׻� LCP[0] = 0
		if (rank[i]) {
			int j = perm[rank[i] - 1]; // s[i..]�� Suffix Arr�� ������ s[j..]
			// S.A���� ������ s[i..]�� s[j..]�� ������� ���λ���̸� ����Ѵ�. 
			while (s[i + h] == s[j + h]) h++; // ���� // i+h = s.size()�̸� ���ڿ��� ��. s[s.size()]�� ���ٰ����ϰ� NULL�� ������ִ�. ��, index���� ��� ���ص���.
			LCP[rank[i]] = h;	// LCP ����.
		}
		// h>0�̸� 1�� ���ش�.
		//** �ֳ��ϸ�, for���� ����Ž�� s[i+1..]�� �׻� �ڽŰ� SA���� ������ ���λ���� ����������(lcp)�� h-1 �̻��̱� �����̴�. 
		if (h) h--;  
	}

	// ���⵵ �м�: for������ while���� �ѹ� ���ึ�� h++�ǰ� h�� for�� ��ü���� n��ŭ �����Ҽ� ������, n���� Ŀ���� ����. ��, ���һ�ȯ���� �ִ�o(n)�� ����ǹǷ�
	// ��ü ���⵵ : o(n)

}

int main() {
	cin.sync_with_stdio(false);
	cin.tie(0);
	cout.sync_with_stdio(false);
	cout.tie(0);

	solve();
	return 0;
}