#include <bits/stdc++.h>

// 이분탐색
// 투포인터

// 부르투프스는 N^3으로 10억이넘어가서 안되지만
// 이분탐색으로는 N^2logN이 된다.
// 두점을 찾고 나머지 한점은 이분탐색으로 찾는다

// 투포인터로 풀면 n^2으로 풀수있다.
// 중앙점 찍어놓고 좌++ 우--

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    int t;
    cin >> t;
    while (t--) {
        cin >> n;
        vector<int> v;
        for (int i = 0; i < n; i++) {
            int a;
            cin >> a;
            v.push_back(a);
        }
        sort(v.begin(), v.end());
        int cnt = 0;
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                int A = v[i];
                int B = v[j];
                if (binary_search(v.begin(), v.end(), B + (B - A))) {
                    cnt++;
                }
            }
        }
        cout << cnt << '\n';
    }
}