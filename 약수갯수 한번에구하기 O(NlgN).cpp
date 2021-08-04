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

#define INF 2'000'000'000
#define mod 998244353
#define EPSILON 1e-9
#define MAXN 1000001


// 1,2,..,n �� ���� ������ ����� ������ �ѹ��� ���ϱ�. �뷫 o(n*log(n)) 

int n;
int cnt[MAXN];
// cnt[i] : i�� ����� ����
void solve() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        for (int j = i; j <= n; j = j + i) {
            cnt[j]++; // i�� ����� ��� j�� ��������� 1 �߰�.
        }
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