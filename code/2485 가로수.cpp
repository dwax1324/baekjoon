#include <bits/stdc++.h>

// 입력이 순서대로 들어온다는 보장이 없었는데
// 당연히 그러겠거니 하고  풀어서 틀림 (정렬해줘야함)
// 유클리드호제법 -> 최대공약수를 구한다
// 최대공약수를 구한 뒤에 반복문을 돌며
// ((각 길이) / (최대공약수)) -1 을 해줬는데
// 사실 그냥 전체 길이를 알고 있으니 한 번에
// v[n]-v[0](전체길이) / ((최대공약수)+1) 을 해주면 된다.

using namespace std;

long long go(long long a, long long b) {
    return b ? go(b, a % b) : a;
}

int main() {
    int n;
    cin >> n;
    vector<long long> v;
    vector<long long> v2;
    for (int i = 0; i < n; i++) {
        long long a;
        cin >> a;
        v2.push_back(a);
    }
    sort(v2.begin(), v2.end());
    for (int i = 0; i < v2.size() - 1; i++) {
        v.push_back(v2[i + 1] - v2[i]);
    }

    long long min = go(v[0], v[1]);
    for (int i = 2; i < v.size(); i++) {
        min = go(min, v[i]);
    }
    long long sum = 0;
    for (int i = 0; i < v.size(); i++) {
        sum += (v[i] / min) - 1;
    }
    cout << sum;
}