#include <bits/stdc++.h>

// 수학
// 서로소의 두수의 곱으로 k를 만들수 있는가?
// k의 약수를 구하고 약수가 최대공약수로 나누어지는지 확인하면 된다..

// 근데 그걸 생각못하고 k의 약수의 약수를 모두 구하고 교집합사용했다.
// 남들은 0ms나오는데 400ms나왔다 ㅋㅋ

// 각 쿼리마다 백만의 벡터를 생성하니까 시간이 오래잡아먹힌다.
// 벡터를 50으로 줄여주니 12ms까지 내려간다.

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cout.tie(NULL);
    cin.tie(NULL);
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        int cnt = 0;
        if (a == 1) {
            cout << 1 << '\n';
            continue;
        }
        for (int i = 1; i * i <= a; i++) {
            if (a % i == 0) {
                int x = i;
                int y = a / i;

                vector<int> v, v2, v3(50);

                for (int j = 1; j * j <= x; j++) {
                    if (x % j == 0) {
                        v.push_back(j);
                        v.push_back(x / j);
                    }
                }
                for (int j = 1; j * j <= y; j++) {
                    if (y % j == 0) {
                        v2.push_back(j);
                        v2.push_back(y / j);
                    }
                }
                sort(v.begin(), v.end());
                sort(v2.begin(), v2.end());
                auto it = set_intersection(v.begin(), v.end(), v2.begin(), v2.end(), v3.begin());
                v3.resize(it - v3.begin());

                if (v3.size() == 1) cnt++;
            }
        }
        cout << cnt << '\n';
    }
}