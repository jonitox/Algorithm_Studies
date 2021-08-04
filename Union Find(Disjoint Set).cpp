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


#define INF 2000000000
using namespace std;
#define MAXN 100000

//////// �����ϰ� �������� ���� //////
int pr[MAXN];
int rk[MAXN];
int find(int u) {
    if (pr[u] == u) return u;
    return pr[u] = find(pr[u]);
}

void merge(int u, int v) {
    u = find(u), v = find(v);
    if (u == v) return;
    if (rk[u] > rk[v]) swap(u, v);
    pr[u] = v;
    if (rk[u] == rk[v]) rk[v]++;
}



/////////////////////////////////////

// ��ȣ��Ÿ�� ����(union-find set)
class disjoint {
public :
	vector<int> parent, rank;	// parent[i]: i�� ���� ������ ��ǥ, rank[i]: i�� ������ ��ǥ�ϋ� ���� Ʈ���� ����
	
	//������
	disjoint(int n):parent(n), rank(n,1){
		for (int i = 0; i < n; ++i)
			parent[i] = i;
	}

	// ���� u�� ���� ������ ��ǥ ���� ��ȯ
	int find(int u) {
		if (u == parent[u])
			return u;
		return parent[u] = find(parent[u]); // Ʈ�� ������ ȿ�� // ����ȭ
	}

	// u�� ���� ���հ� v�� ���� ���� ��ġ�� 
	void merge(int u, int v) {
		u = find(u), v = find(v); // �� ������ ��ǥ�� �ٲ۴�.
		if (u == v) return;
		if (rank[u] > rank[v]) swap(u, v); // �׻� ���̰� ���� Ʈ���� ū�ʿ� ���δ�.
		parent[u] = v;						// Ʈ�� ���̱�
		if (rank[u] == rank[v]) ++rank[v]; // ���� ��ģ �� Ʈ���� ���̰� ���Ҵٸ� ������ Ʈ���� ���̸� +1�Ѵ�.
	}
};


int main() {
	cin.sync_with_stdio(false);
	cin.tie(0);
	cout.sync_with_stdio(false);
	cout.tie(0);


	return 0;
}