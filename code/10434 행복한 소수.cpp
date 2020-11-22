#include <bits/stdc++.h>

using namespace std;

// 구현 소수판별
// 각 자리를 더해서 1이되는지 확인하는데
// 행복한 수가 아닌 수에대해 반복문을 빠져나오는 기저조건이 뭔지 헷갈려서 고민했다.
// 수의 길이가 1이면 빠져나오는걸로 했었었는데.
// 7이되면 또 49가되기때문에 안된다.

// 결국은 그냥 횟수제한을 두고 풀었다.
// 아마 사이클이 생겨서 빠져나오지 못할것이다.

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    cin >> n;
    while (n--) {
        int a;
        string b;
        cin >> a >> b;
        string coutB = b;
        int k = stoi(b);
        int cnt = 0;
        for (int i = 1; i * i <= k; i++) {
            if (k % i == 0) cnt++;
        }
        if (k == 1 || cnt != 1) {
            cout << a << " " << b << " "
                 << "NO\n";
            continue;
        }
        int C = 0;
        bool flag = false;
        int MAX = 0;
        while (1) {
            if (MAX++ > 10) break;
            int sum = 0;
            for (int i = 0; i < b.size(); i++) {
                sum += (b[i] - '0') * (b[i] - '0');
            }
            b = to_string(sum);
            if (b.size() == 1) {
                if (to_string((b[0] - '0') * (b[0] - '0')).size() > 1) {
                    continue;
                }
                if (b[0] == '1') {
                    flag = true;
                }
                break;
            }
        }
        if (flag) {
            cout << a << " " << coutB << " "
                 << "YES\n";
        } else {
            cout << a << " " << coutB << " "
                 << "NO\n";
        }
    }
}