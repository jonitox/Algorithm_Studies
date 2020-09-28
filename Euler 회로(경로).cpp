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

vector<vector<int>> adj;
vector<int> indegree, outdegree;

//방향 그래프에 대한 euler 서킷(경로) 찾는 알고리즘 // 무향일 때는 

// 그래프에 euler가 존재하는지 check
bool check_euler() {
	// out: outdegree가 1만큼 더 많은 점의 개수
	// in: indegree가 1만큼 더 많은 점의 개수
	int in = 0, out = 0;
	for (int i = 0; i < 26; i++) {
		int delta = outdegree[i] - indegree[i];
		if (delta > 1 || delta < -1) // 존재 x인 경우
			return false;
		if (delta == 1)	out++;
		if (delta == -1)	 in++;
	}
	return (in == 1 && out == 1) || (in == 0 && out == 0); // (euler 경로 가능) || (euler 서킷 가능)
}

// dfs로 오일러 서킷(경로) 찾기. // circuit에 역순으로 저장된다.
void get_euler(int here, vector<int>& circuit) {
	for (int there = 0; there < 26; there++) {
		while (adj[here][there] > 0) {		// 다중그래프 고려 // 율러 서킷을 하나 찾아서 circuit에 추가한다.
			adj[here][there]--;				// 간선을 지우고
			get_euler(there, circuit);		// 따라간다.
		}
	}
	circuit.push_back(here);
}

// euler 서킷or경로가 존재할때 답안 찾아서 반환.
vector<int> get_circle_or_trail() {
	vector<int> circuit;

	// 트레일로 존재하는경우
	for (int i = 0; i < 26; i++)
		if (outdegree[i] - indegree[i] == 1) { // 시작점은 outdegree = indegree+1인 점으로 고정.
			get_euler(i, circuit);
			return circuit;
		}

	// 서킷인 경우 나가는 선 있는 아무 점에서 시작
	for (int i = 0; i < 26; i++)
		if (outdegree[i]) {
			get_euler(i, circuit);
			return circuit;
		}

	// 위 실패시 빈 벡터 반환. 간선 없는 경우. 이 문제에선 형식상.
	return circuit;
}



bool solve() {
	if (!check_euler) return false;
	
	//존재한다면,
	vector<int> circuit = 
}

int main() {
	cin.sync_with_stdio(false);
	cin.tie(0);
	cout.sync_with_stdio(false);
	cout.tie(0);
	
	return 0;
}