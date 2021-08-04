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

// 사칙연산 계산기. stack.

// idx이후의 첫 연산자 가져오기.
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

// idx이후의 첫 숫자 가져오기
int getVal(string& s, int& idx) {
    string ret = "";
    for (; idx < s.size() && '0' <= s[idx] && s[idx] <= '9'; ++idx) {
        ret += s[idx];
    }
    return stoi(ret);
}

// 두 숫자를 연산하기.
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
    cin >> s; // 수식 입력 
    stack<int> num;
    stack<int> op;

    int idx = 0, i = 0;
    // 숫자, 연산자를 번갈아 읽으면서, 
    while (idx < s.size()) {
        if (i % 2) {
            // 연산자인 경우, 연산자 stack의 top이 현재 연산자의 우선순위보다 낮을때까지 pop하여 연산을 처리.
            int o = getOp(s, idx++);
            while (!op.empty() && op.top() >= o) {
                int opr = op.top(); op.pop();
                int n2 = num.top(); num.pop();
                int n1 = num.top(); num.pop();
                num.push(cal(n1, n2, opr)); // 각 연산의 결과를 다시 stack에 넣어두면서 차례대로 계산.
            }
            op.push(o); // 현재 연산자 추가.
        }
        else {
            // 숫자인 경우, 숫자 stack에 push.
            int n = getVal(s, idx);
            num.push(n);
        }
        ++i;
    }
    // 연산자 stack이 남아있다면 남은 연산을 순서대로 연산.
    while (!op.empty()) {
        int opr = op.top(); op.pop();
        int n2 = num.top(); num.pop();
        int n1 = num.top(); num.pop();
        num.push(cal(n1, n2, opr));
    }
    // 숫자 stack에 남은 하나의 원소가 최종 답.
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