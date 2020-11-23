#include <bits/stdc++.h>

using namespace std;

// 그리디
// 패턴찾기
// 모두 동일한 패턴으로 통일시킨다.
// 앞에서부터 A..B...Z

string neutralize(string a) {
    int cnt = 0;
    for (int i = 0; i < a.size(); i++) {
        if (a[i] >= 65 && a[i] <= 90) continue;
        char temp = a[i];
        for (int j = i; j < a.size(); j++) {
            if (a[j] == temp) a[j] = 65 + cnt;
        }
        cnt++;
    }
    return a;
}

int main() {
    int n;
    cin >> n;
    vector<string> v(n);

    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }
    int cnt = 0;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (neutralize(v[i]) == neutralize(v[j])) {
                cnt++;
            }
        }
    }
    cout << cnt;
}