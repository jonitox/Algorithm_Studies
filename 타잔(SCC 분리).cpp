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

vector<int> discovered(6, -1);
vector<int> sccID(6, -1);
vector<vector<int>> adj;
stack<int> st;
int counter = 0;
int sccCounter = 0;

void make_graph() {
	adj.push_back({ 1,4 });
	adj.push_back({ 2 });
	adj.push_back({ 3 });
	adj.push_back({ 1 });
	adj.push_back({ 5 });
	adj.push_back({ 3,4 });
}


// ����׷����� scc��� // subtree ���ٰ� �Լ� ��ȯ �� �ڽŰ� �θ� ���� ��带 ���� scc�� ������ִ��� ���� �Ǵ�.
// here�� ����Ʈ������ �� �� �ִ� �ּ� �߰� ���� ���� ��ȯ // here���� �̻�(��� here�����̹Ƿ� here��)�̶�� here�� �� scc�� ���� �߰� ����̹Ƿ� �߶� scc�� �߰�
int scc(int here) {
	int ret = discovered[here] = counter++;
	st.push(here);
	for (int i = 0; i < adj[here].size(); i++) {
		int there = adj[here][i];
		// there�� �ڼ�, Ʈ�� �����϶�
		if (discovered[there] == -1) {
			ret = min(ret,scc(there));
		}
		// there �� ���������̸鼭 �����ص��Ǵ� ���(there�� �̹� scc�� ������ root�� ���� ���ϴ� ���)�� ������ 
		// scc�� �� ���� ��(������ �����ִ°�)������ �������� or here������ ������ ���� �ϰ�� (�� ��� ��� ���� there�� scc�� ������������.)
		// here���� ���� ���ϹǷ�(scc�Ұ���) discovered �� ����
		else if (sccID[there] == -1) 
			ret = min(ret,discovered[there]);
	}

	if (ret == discovered[here]) { // parent[here]-here�� ������ҋ� <-> here���� parent[here]�� ���� ��ΰ� ������(��,�ٸ� scc�� ����) //���ο� scc�߰�.
		//���ÿ��� here���� ������ SCC�� ����.
		while (true) {
			int t = st.top();
			sccID[t] = sccCounter;
			st.pop();
			if (t == here) {
				break;
			}
		}
		sccCounter++;
	}
	return ret;
}

vector<int> tarjanSCC() {
	sccID = discovered = vector<int>(adj.size(), -1);
	sccCounter = counter = 0;
	// �� ��Ʈ���� ��� �� Ž�� �ȵǴ��� scc�� ��� ��忡 ����� �˾Ƽ� �и���.
	// �� ��忡���� Ž���� �߰ߵ��� ���� ���� �� ������ �� ���(���, ����� Ʈ���� �ִ� ����)(�̹� scc����)�� �� �� �־ ���� ���ϹǷ�. 
	// ���� �� ������ if�� ����� �ƹ��͵� �ȵ�.(�� �� ���� �̹� �߰�& scc����)
	for (int i = 0; i < adj.size(); i++)
		if (discovered[i] == -1) scc(i);
	return sccID;
}

int main() {
	cin.sync_with_stdio(false);
	cin.tie(0);
	cout.sync_with_stdio(false);
	cout.tie(0);
	make_graph();
	tarjanSCC();
	for (int i = 0; i < 6; i++)
		cout << sccID[i];
	return 0;
}