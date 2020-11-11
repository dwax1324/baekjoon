#include <bits/stdc++.h>

// 그리디
// 우선순위 큐를 이용해 점수가 가장 큰 사람을 뽑는다.
// 이미 참가된 사람이면 더이상 뽑지 않는다.

using namespace std;

int main() {
    int n, m, k;
    scanf("%d%d%d", &n, &m, &k);
    priority_queue<pair<double, int>> arr[101];
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            double a;
            int b;
            scanf("%d%lf", &b, &a);
            arr[i].push({a, b});
        }
    }
    double ans = 0;
    vector<int> used;
    int cnt = 0;
    while (1) {
        if (cnt == k) break;
        cnt++;
        double MAX = 0;
        for (int j = 0; j < m; j++) {
            if (arr[j].size())
                MAX = max(MAX, arr[j].top().first);
        }
        for (int j = 0; j < m; j++) {
            if (arr[j].size() && arr[j].top().first == MAX) {
                bool disqualified = false;
                for (int z = 0; z < used.size(); z++) {
                    if (arr[j].top().second == used[z]) disqualified = true;
                }
                if (disqualified) {
                    cnt--;
                    arr[j].pop();
                    break;
                }
                ans += arr[j].top().first;
                used.push_back(arr[j].top().second);
                arr[j].pop();
                break;
            }
        }
    }
    printf("%.1lf", ans);
}