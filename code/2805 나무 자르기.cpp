#include <bits/stdc++.h>

// 이분탐색

// 나무를 입력받고 정렬
// 입력받은 나무의 최댓값->r , 0-> l , mid=(r+l)/2;
// mid값의 upperbound보다 큰값은 모두 더해준다 -> sum;
// sum으로 이분탐색

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, k;
    cin >> n >> k;
    vector<int> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }

    sort(v.begin(), v.end());

    int r = v[v.size() - 1] - 1;
    int l = 0;
    int cnt = 0;
    long long mid;
    while (1) {
        if (cnt++ > 35) break;
        mid = ((long long)r + (long long)l) / 2;
        auto idx = upper_bound(v.begin(), v.end(), mid - 1);
        long long sum = 0;
        // cout << mid << " " << *idx << '\n';
        while (idx != v.end()) {
            sum += (long long)*idx - (long long)mid;
            idx++;
        }
        if (sum == k) {
            // cout << cur;
            break;
        } else if (sum < k) {
            r = mid - 1;
        } else {
            l = mid + 1;
        }
        // cout << mid << " ";
    }
    cout << mid;
}