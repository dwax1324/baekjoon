#include <bits/stdc++.h>

using namespace std;

// 조합 탐색

// 중복 조합

int n;
vector<int> v = {1, 5, 10, 50};
set<int> SET;
int arr[1001];
int vi[1001];

void go(int depth, int k, int start) {
    if (depth == n) {
        SET.insert(k);
        return;
    }

    for (int i = start; i < 4; i++) {
        go(depth + 1, k += v[i], i);
        k -= v[i];
    }
}

int main() {
    cin >> n;
    go(0, {}, 0);
    cout << SET.size();
}