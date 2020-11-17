#include <bits/stdc++.h>

using namespace std;
#define MAX 1000001

// 에라토스테네스의 체,
// 어렵게도 풀었다.
// 배열이용해서 체를 좀더 활용하면 쉽게 풀수 있다.
// 탐색도 절반까지만 하면 된다.
// 효율적이지 않은 코드
// 소수를 벡터에 저장하여 이분탐색하여 풀었다.
bool vi[MAX];
vector<int> v;
void seive() {
    for (int i = 2; i < MAX; i++) {
        if (vi[i]) continue;
        vi[i] = true;
        v.push_back(i);
        for (int j = i * 2; j < MAX; j += i) {
            vi[j] = true;
        }
    }
}

int main() {
    seive();
    int T;
    scanf("%d", &T);
    while (T--) {
        int k, ans = 0;
        scanf("%d", &k);
        set<int> SET;
        bool temp[1000001] = {
            0,
        };
        for (int i = 0; i < v.size(); i++) {
            if (k <= v[i]) break;
            if (temp[v[i]]) continue;
            if (binary_search(v.begin(), v.end(), k - v[i])) {
                ans++;
                temp[k - v[i]] = true;
            }
        }
        printf("%d\n", ans);
    }
}
