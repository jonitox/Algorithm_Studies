<<<<<<< HEAD
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


// euler 경로/회로 존재여부 확인. (방향그래프인경우)
// 무향일때는 조건: 홀수점이 2개 (오일러 경로) 혹은 전부 짝수점(오일러 회로)
bool check_euler() {
	// outdegree: 나가는 간선수
	// indegree: 들어오는 간선수
	int in = 0, out = 0;
	for (int i = 0; i < 26; i++) {
		int delta = outdegree[i] - indegree[i];
		if (delta > 1 || delta < -1) // 불가능
			return false;
		if (delta == 1)	out++;
		if (delta == -1)	 in++;
	}
	return (in == 1 && out == 1) || (in == 0 && out == 0); // 
}

// dfs로 오일러경로 찾기. 이동가능한 간선을 찾을때마다 간선을 지우며 이동.
// 방문 종료시 오일러 경로에 해당정점을 추가하면 완성.
void get_euler(int here, vector<int>& circuit) {
	for (int there = 0; there < 26; there++) {
		while (adj[here][there] > 0) {		
			adj[here][there]--;				
			get_euler(there, circuit);		
		}
	}
	circuit.push_back(here);
}


// 오일러 경로or회로 찾는 함수 // check_euler가 true인 경우.
vector<int> get_circle_or_trail() {
	vector<int> circuit;

	// 회로 찾기
	for (int i = 0; i < 26; i++)
		if (outdegree[i] - indegree[i] == 1) {
			get_euler(i, circuit);
			return circuit;
		}

	// 경로 찾기 // 나가는 간선이 있는 아무곳에서나 dfs하면됨.
	for (int i = 0; i < 26; i++)
		if (outdegree[i]) {
			get_euler(i, circuit);
			return circuit;
		}

	return circuit;
}



bool solve() {
	if (!check_euler) return false;
	
	vector<int> circuit = get_circle_or_trail();
}

int main() {
	cin.sync_with_stdio(false);
	cin.tie(0);
	cout.sync_with_stdio(false);
	cout.tie(0);
	
	return 0;
=======
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


// euler 경로/회로 존재여부 확인. (방향그래프인경우)
// 무향일때는 조건: 홀수점이 2개 (오일러 경로) 혹은 전부 짝수점(오일러 회로)
bool check_euler() {
	// outdegree: 나가는 간선수
	// indegree: 들어오는 간선수
	int in = 0, out = 0;
	for (int i = 0; i < 26; i++) {
		int delta = outdegree[i] - indegree[i];
		if (delta > 1 || delta < -1) // 불가능
			return false;
		if (delta == 1)	out++;
		if (delta == -1)	 in++;
	}
	return (in == 1 && out == 1) || (in == 0 && out == 0); // 
}

// dfs로 오일러경로 찾기. 이동가능한 간선을 찾을때마다 간선을 지우며 이동.
// 방문 종료시 오일러 경로에 해당정점을 추가하면 완성.
void get_euler(int here, vector<int>& circuit) {
	for (int there = 0; there < 26; there++) {
		while (adj[here][there] > 0) {		
			adj[here][there]--;				
			get_euler(there, circuit);		
		}
	}
	circuit.push_back(here);
}


// 오일러 경로or회로 찾는 함수 // check_euler가 true인 경우.
vector<int> get_circle_or_trail() {
	vector<int> circuit;

	// 회로 찾기
	for (int i = 0; i < 26; i++)
		if (outdegree[i] - indegree[i] == 1) {
			get_euler(i, circuit);
			return circuit;
		}

	// 경로 찾기 // 나가는 간선이 있는 아무곳에서나 dfs하면됨.
	for (int i = 0; i < 26; i++)
		if (outdegree[i]) {
			get_euler(i, circuit);
			return circuit;
		}

	return circuit;
}



bool solve() {
	if (!check_euler) return false;
	
	vector<int> circuit = get_circle_or_trail();
}

int main() {
	cin.sync_with_stdio(false);
	cin.tie(0);
	cout.sync_with_stdio(false);
	cout.tie(0);
	
	return 0;
>>>>>>> bb6e75949a077d02582f893a347fffea74c6bcdf
}