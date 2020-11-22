#include <bits/stdc++.h>
using namespace std;

// 구현
// 말 그대로 구현문제

vector<string> v;
void clockwise(int a) {
    string k = v[a];
    for (int i = 1; i < k.size(); i++) {
        k[i] = v[a][i - 1];
    }
    k[0] = v[a][v[a].size() - 1];
    v[a] = k;
}
void antiClockwise(int a) {
    string k = v[a];
    for (int i = k.size() - 2; i >= 0; i--) {
        k[i] = v[a][i + 1];
    }
    k[k.size() - 1] = v[a][0];
    v[a] = k;
}

bool vi[10];
int main() {
    int n;
    n = 4;
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        v.push_back(s);
    }

    int t;
    scanf("%d", &t);
    while (t--) {
        int a, b;
        scanf("%d%d", &a, &b);
        fill(vi, vi + 10, 0);
        a--;
        int cnt = 0;
        int waiting[1001] = {
            0,
        };
        for (int i = a; i > 0; i--) {
            if (v[i][6] != v[i - 1][2]) {
                if (b == -1) {
                    if (cnt % 2 == 0) {
                        waiting[i - 1] = 1;
                    } else {
                        waiting[i - 1] = -1;
                    }
                    cnt++;
                } else if (b == 1) {
                    if (cnt % 2 == 0) {
                        waiting[i - 1] = -1;
                    } else {
                        waiting[i - 1] = 1;
                    }
                    cnt++;
                }
            } else {
                break;
            }
        }
        cnt = 0;
        for (int i = a; i < v.size() - 1; i++) {
            if (v[i][2] != v[i + 1][6]) {
                if (b == -1) {
                    if (cnt % 2 == 0) {
                        waiting[i + 1] = 1;
                    } else {
                        waiting[i + 1] = -1;
                    }
                    cnt++;
                } else if (b == 1) {
                    if (cnt % 2 == 0) {
                        waiting[i + 1] = -1;
                    } else {
                        waiting[i + 1] = 1;
                    }
                    cnt++;
                }
            } else {
                break;
            }
        }
        waiting[a] = b;

        // for (int i = 0; i < n; i++) {
        //     printf("%d", waiting[i]);
        // }
        // printf("\n");

        for (int i = 0; i < n; i++) {
            if (waiting[i] == 1) {
                clockwise(i);
            } else if (waiting[i] == -1) {
                antiClockwise(i);
            }
        }
        // printf("\n");
    }
    int ans = 0;
    if (v[0][0] == '1') ans += 1;
    if (v[1][0] == '1') ans += 2;
    if (v[2][0] == '1') ans += 4;
    if (v[3][0] == '1') ans += 8;
    printf("%d", ans);
}