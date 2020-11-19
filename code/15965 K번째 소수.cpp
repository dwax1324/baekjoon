#include <bits/stdc++.h>

using namespace std;
#define MAX 100000001;
// 소수판정 에라토스테네스의 체

bool arr[1000001];

vector<int> v;
void seive() {
    for (int i = 2; i <= 50000; i++) {
        if (arr[i]) continue;
        v.push_back(i);
        arr[i] = true;
        for (int j = i * 2; j <= 50000; j += i) {
            arr[j] = true;
        }
    }
}

int main() {
    seive();
    int k;
    cin >> k;
    cout << v[k - 1];
}