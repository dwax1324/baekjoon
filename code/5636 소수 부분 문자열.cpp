#include <bits/stdc++.h>

using namespace std;

// substr써서 하나하나 비교하다가 멘붕
// substr은 pos 부터 n개의 문자를 반환한다.
// 구간인줄알고 엄청헤맷다..

// file에 써가면서까지 비교했늗네
// 인덱스가 1이되면서 자릿수가 하나씩 더늘어남
// 사실 find함수쓰면 쉽게풀린다.
// 멘탈바사삭

bool vi[100001];
vector<int> v;
void seive() {
    for (int i = 2; i < 100001; i++) {
        if (vi[i]) continue;
        v.push_back(i);
        vi[i] = true;
        for (int j = i * 2; j < 100001; j += i) {
            vi[j] = true;
        }
    }
}

int main() {
    string n;
    ofstream fout;
    // fout.open("a.txt");
    seive();
    int t;
    while (1) {
        cin >> n;
        if (n == "0") return 0;
        for (int i = 0; i < 10; i++) {
            // cout << v[i] << " ";
        }
        int cnt = 0;
        int ans = 0;
        for (int i = 0; i < n.size(); i++) {
            for (int j = 0; j < v.size(); j++) {
                if (n.find(to_string(v[j])) != string::npos) {
                    ans = max(ans, v[j]);
                }
            }
        }
        cout << ans << '\n';
    }
}
