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

//////// 간단하게 전역으로 구현 //////
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

// 상호배타적 집합(union-find set)
class disjoint {
public :
	vector<int> parent, rank;	// parent[i]: i가 속한 집합의 대표, rank[i]: i가 집합의 대표일떄 집합 트리의 높이
	
	//생성자
	disjoint(int n):parent(n), rank(n,1){
		for (int i = 0; i < n; ++i)
			parent[i] = i;
	}

	// 원소 u가 속한 집합의 대표 원소 반환
	int find(int u) {
		if (u == parent[u])
			return u;
		return parent[u] = find(parent[u]); // 트리 재정렬 효과 // 최적화
	}

	// u가 속한 집합과 v가 속한 집합 합치기 
	void merge(int u, int v) {
		u = find(u), v = find(v); // 각 집합의 대표로 바꾼다.
		if (u == v) return;
		if (rank[u] > rank[v]) swap(u, v); // 항상 높이가 작은 트리를 큰쪽에 붙인다.
		parent[u] = v;						// 트리 붙이기
		if (rank[u] == rank[v]) ++rank[v]; // 만약 합친 두 트리의 높이가 같았다면 합쳐진 트리의 높이를 +1한다.
	}
};


int main() {
	cin.sync_with_stdio(false);
	cin.tie(0);
	cout.sync_with_stdio(false);
	cout.tie(0);


	return 0;
}