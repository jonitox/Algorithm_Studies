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

vector<int> discovered(4, -1);
vector<int> finished(4, 0);
vector<vector<int>> adj;
int counter;

void make_graph() {
	adj.push_back({ 1,2,3 });
	adj.push_back({ 2 });
	adj.push_back({ 1 });
	adj.push_back({ 1,2 });
}

void dfs(int here) {
	discovered[here] = counter++;
	for (int i = 0; i < adj[here].size(); i++) {
		int there = adj[here][i];
		cout << "(" << here << "," << there << ") is a ";
		if (discovered[there] < 0) {
			cout << "tree edge\n";
			dfs(there);
		}
		else if (discovered[there] > discovered[here])
			cout << "forward edge\n";
		else if (!finished[there])
			cout << "back edge\n";
		else
			cout << "cross edge\n";
	}
	finished[here] = 1;
}



int main() {
	cin.sync_with_stdio(false);
	cin.tie(0);
	cout.sync_with_stdio(false);
	cout.tie(0);
	counter = 0;
	make_graph();
	dfs(0);
	return 0;
}