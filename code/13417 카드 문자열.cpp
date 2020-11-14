#include <bits/stdc++.h>

// 그리디 , 덱

// 항상 작거나 같은걸 앞에다푸쉬해주고 나머지는 뒤에다 푸쉬
// 조합탐색으로 풀려다가 당연히 시간초과 ㅠㅠ
using namespace std;

int main() {
    int T;
    cin >> T;
    while (T--) {
        deque<char> deq;
        int n;
        cin >> n;
        vector<char> v;
        char pivot;
        for (int i = 0; i < n; i++) {
            char a;
            cin >> a;
            if (i == 0) {
                pivot = a;
                deq.push_back(a);
            } else
                v.push_back(a);
        }

        for (int i = 0; i < v.size(); i++) {
            if (v[i] <= deq[0]) {
                deq.push_front(v[i]);
            } else {
                deq.push_back(v[i]);
            }
        }
        for (auto x : deq) {
            cout << x;
        }
        cout << '\n';
    }
}