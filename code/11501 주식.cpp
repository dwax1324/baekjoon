#include <bits/stdc++.h>

// 그리디

// 뒤에서 부터 탐색해주면서 최댓값을 갱신하면서
// 최댓값보다 작은값을 만나면 그 차를 더해주면 된다.

// 위 방법을 생각못해서 아래처럼 어렵게 풀었다..
// o(n)이 아닌 o(nlongn)? 에 푼거같다.
// 생각만 잘하면 간단한 문제였다 ㅠㅠ

// 1.인덱스+값의 페어로 벡터에 저장한다.
// 2.정렬을 한다.
// 3.최댓값을 팝시킨다.
// 4. 최댓값이 없는 벡터에서 인덱스가 최댓값의 인덱스보다 작은순으로 정렬시킨다.
// 4.앞에서부터 순차적으로 검사하면서 인덱스가 작으면서 값도 작은 값들을 정답에 누적시키고 아니면 인덱스를 저장시키고 break한다.
// 5.마지막 인덱스부터 끝까지 벡터를 자른다.
// 6. 1로 돌아간다.

int K;
using namespace std;

bool cmp(pair<long long, long long>& a, pair<long long, long long>& b) {
    return a.second - K < b.second - K;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        vector<pair<long long, long long>> v;
        for (int i = 0; i < n; i++) {
            int a;
            cin >> a;
            v.push_back({a, i});
        }

        long long sum = 0;
        while (1) {
            if (v.size() == 0) break;
            sort(v.begin(), v.end());
            pair<long long, long long> cur = v.back();
            v.pop_back();
            K = cur.second;
            sort(v.begin(), v.end(), cmp);
            int last;
            for (int i = 0; i < v.size(); i++) {
                last = i;
                if (v[i].first <= cur.first && v[i].second < cur.second) {
                    sum += (cur.first - v[i].first);
                } else {
                    break;
                }
            }
            if (v.size() == 0) break;
            v.assign(v.begin() + last, v.end());
        }
        cout << sum << '\n';
    }
}