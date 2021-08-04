#include <iostream>
#include <string>
#include <cstring>
#include <set>
#include <vector>
#include <map> 
#include <stack>
#include <queue>
#include <algorithm>
#include <typeinfo>
#include <iomanip>
#include <cmath>
#include <cstdio>
//////  #include <bits/stdc++.h>


using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<bool> vb;
typedef vector<long long> vll;
typedef vector<vector<int>> vvi;
typedef vector<vector<long long>> vvll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<pii> vpii;
typedef vector<pll> vpll;

#define INF 1'000'000'000
#define mod ll(43200000000000)
#define MAXN 100001

// ��Ģ���� ����. stack.

// idx������ ù ������ ��������.
int getOp(string& s, int idx) {
    if (s[idx] == '+')
        return 0;

    else if (s[idx] == '-')
        return 1;

    else if (s[idx] == '*')
        return 2;
    else if (s[idx] == '/')
        return 3;
    else
        return -1;
}

// idx������ ù ���� ��������
int getVal(string& s, int& idx) {
    string ret = "";
    for (; idx < s.size() && '0' <= s[idx] && s[idx] <= '9'; ++idx) {
        ret += s[idx];
    }
    return stoi(ret);
}

// �� ���ڸ� �����ϱ�.
int cal(int x, int y, int op) {
    if (op == 0)
        return x + y;
    else if (op == 1)
        return x - y;
    else if (op == 2)
        return x * y;
    else
        return x / y;
}

void solve() {
    string s;
    cin >> s; // ���� �Է� 
    stack<int> num;
    stack<int> op;

    int idx = 0, i = 0;
    // ����, �����ڸ� ������ �����鼭, 
    while (idx < s.size()) {
        if (i % 2) {
            // �������� ���, ������ stack�� top�� ���� �������� �켱�������� ���������� pop�Ͽ� ������ ó��.
            int o = getOp(s, idx++);
            while (!op.empty() && op.top() >= o) {
                int opr = op.top(); op.pop();
                int n2 = num.top(); num.pop();
                int n1 = num.top(); num.pop();
                num.push(cal(n1, n2, opr)); // �� ������ ����� �ٽ� stack�� �־�θ鼭 ���ʴ�� ���.
            }
            op.push(o); // ���� ������ �߰�.
        }
        else {
            // ������ ���, ���� stack�� push.
            int n = getVal(s, idx);
            num.push(n);
        }
        ++i;
    }
    // ������ stack�� �����ִٸ� ���� ������ ������� ����.
    while (!op.empty()) {
        int opr = op.top(); op.pop();
        int n2 = num.top(); num.pop();
        int n1 = num.top(); num.pop();
        num.push(cal(n1, n2, opr));
    }
    // ���� stack�� ���� �ϳ��� ���Ұ� ���� ��.
    cout << num.top();

}


int main() {
    cin.sync_with_stdio(false);
    cin.tie(0);
    cout.sync_with_stdio(false);
    cout.tie(0);

    solve();


    return 0;
}