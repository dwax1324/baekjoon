#include <bits/stdc++.h>

// 구현

// 확률계산
// 20-2 ->   내가 이길 가짓수 / 전체 가짓수(18C2)
using namespace std;

vector<pair<int, int>> combs;
vector<int> v;

int cnt = 0;
void go(int x, vector<int> vx, int start) {
    if (x == 2) {
        combs.push_back({vx[0], vx[1]});
        return;
    }
    for (int i = start; i < v.size(); i++) {
        vx.push_back(v[i]);
        go(x + 1, vx, i + 1);
        vx.pop_back();
    }
}

int main() {
    int a, b;
    cin >> a >> b;
    for (int i = 1; i <= 10; i++) {
        if (i != a)
            v.push_back(i);
    }
    for (int i = 1; i <= 10; i++) {
        if (i != b)
            v.push_back(i);
    }
    // cout << v.size();
    go(0, {}, 0);
    double cnt = 0;
    if (a == b) {
        for (int i = 0; i < 153; i++) {
            if (combs[i].first != combs[i].second) cnt++;
            if (combs[i].first == combs[i].second && combs[i].first < a) cnt++;
        }
    } else {
        int k = (a + b) % 10;
        for (int i = 0; i < 153; i++) {
            if ((combs[i].first != combs[i].second) && (combs[i].first + combs[i].second) % 10 < k) cnt++;
        }
    }
    printf("%.3lf", cnt / combs.size());
}