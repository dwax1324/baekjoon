#include <bits/stdc++.h>

using namespace std;

// 시도1 조합탐색 불가 *n -> 80

// 시도2 그리디
// 문자열을 입력받고 오른쪽 끝에서부터 왼쪽으로 탐색을 시작
// 만약 지나온 길 뒤로 자신보다 큰 값이 있으면 스왑
// 스왑한 지점을 기점으로 문자열 끝까지 정렬
// 최솟값 찾음!/ 찾지못하였다면 biggest출력

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int T;
    cin >> T;
    while (T--) {
        string k;
        cin >> k;
        bool flag = false;
        for (int i = k.size() - 1; i >= 0; i--) {
            vector<pair<int, int>> v;
            for (int j = i; j < k.size(); j++) {
                if (k[j] - '0' > k[i] - '0') {
                    v.push_back({k[j], j});
                    flag = true;
                }
            }
            if (flag) {
                sort(v.begin(), v.end());
                swap(k[i], k[v[0].second]);
                sort(k.begin() + i + 1, k.end());
                break;
            }
        }
        if (!flag) {
            cout << "BIGGEST\n";
        } else {
            cout << k << '\n';
        }
    }
}