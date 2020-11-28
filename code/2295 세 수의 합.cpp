#include <bits/stdc++.h>
//////////////////////////////////////////////
#define ll long long
#define ull unsigned long long
#define pii pair<int, int>
#define ppii pair<int, pii>
#define fr(i, num1, num2) for (int i = num1; i < num2; i++)
#define rfr(i, num1, num2) for (int i = num1 - 1; i >= num2; i--)
#define F first
#define S second
using namespace std;
void fastio();
void DEBUG();
///////////////////////////////////////////////
/*
    최적화문제
    정말 나이브하게 푼다면 n**4의 시간복잡도를 갖는다
    
    큰 수부터 차례대로 검사해봐야하기 떄문에
    일단 O(n) 은 불가피하고,
    두 수의 합의 배열을 따로 만들어서 
    반복문 하나를 더 돌며 이분탐색을 시킨다.
    배열에 중복된 값인지 확인하는 정보들을 넣어놓고 판별한다.

*/
///////////////////////////////////////////////

void preprocess() {
}

map<int, int> m;
vector<int> v;
vector<ppii> v2;

bool bs(int a, int b) {
    int l = 0;
    int r = v2.size() - 1;

    while (l <= r) {
        int mid = (l + r) / 2;
        if (v2[mid].F == a) {
            return true;
        } else if (v2[mid].F > a) {
            r = mid - 1;
        } else {
            l = mid + 1;
        }
    }
    return false;
}
void solve() {
    int n;
    cin >> n;
    fr(i, 0, n) {
        int a;
        cin >> a;
        v.push_back(a);
    }
    sort(v.begin(), v.end());
    fr(i, 0, n) {
        fr(j, i, n) {
            v2.push_back({v[i] + v[j], {v[i], v[j]}});
        }
    }
    sort(v2.begin(), v2.end());

    rfr(i, n, 0) {
        rfr(j, i, 0) {
            if (bs(v[i] - v[j], v[j])) {
                cout << v[i];
                exit(0);
            }
        }
    }
}
int main() {
    fastio();
    preprocess();
    DEBUG();
    int t;
    t = 1;
    // cin >> t;
    for (int i = 1; i <= t; i++) {
        // cout << "case #" << t << ": ";
        solve();
    }
}

///////////////////////////////////////////////
void fastio() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

void DEBUG() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
}