#include <bits/stdc++.h>

// 나이브하게 while문으로 점프하는 식으로 구현해도됨
// 구현력부족으로 포기 / for문->포인터->while문쓰려다가
// 좀 더 생각해보니 그냥 매순간의 최솟값 저장해주고 곱해주면 됨
// 자료형 주의

using namespace std;

int main() {
    int n;
    cin >> n;
    unsigned long long sum = 0;

    vector<long long> v;
    vector<long long> v2;
    for (int i = 0; i < n - 1; i++) {
        int a;
        cin >> a;
        v2.push_back(a);
    }
    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        v.push_back(a);
    }

    int cnt = 0;
    long long val = 1 << 30;
    for (int i = 0; i < v.size() - 1; i++) {
        val = min(val, v[i]);
        sum += val * v2[i];
    }
    cout << sum;
}