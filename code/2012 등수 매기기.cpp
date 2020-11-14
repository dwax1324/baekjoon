#include <bits/stdc++.h>

// 그리디

// 푸는데 시간 좀 걸림
// 생각해낼 알고리즘이라 할만한 것이 없는 것이 함정
// 등수와 예상등수를 차례대로 빼주면 됨
// 왜?? 몰라
// 그리디 너무 어려워
// 직관적으로 그럴거 같긴한데 증명을 못하겠어~

// 자료형 주의

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> v(n + 1);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }
    long long sum = 0;
    sort(v.begin(), v.end());
    for (int i = 1; i <= n; i++) {
        sum += abs((long long)v[i] - (long long)(i));
    }
    cout << sum;
}