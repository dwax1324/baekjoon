#include <bits/stdc++.h>

// 요세푸스문제
// 메모리가 겨우 4메가?
// 푸는데 오래걸렸다.
// 연산 과정중에 temp만들어서 사용하면 메모리초과난다 ㅡㅡ;

// 모든 연산에서 첫번째 요소는 없애고 시작하기 때문에
// 오른쪽으로 가야될 경우 -1을 해준다

using namespace std;

int main() {
    int n;
    cin >> n;
    deque<pair<int, int>> deq(n);
    for (int i = 0; i < n; i++) {
        cin >> deq[i].first;
        deq[i].second = i + 1;
    }

    while (deq.size()) {
        // for (int i = 0; i < deq.size(); i++) {
        //     cout << deq[i].first << " ";
        // }
        // cout << '\n';
        pair<int, int> nxt = deq.front();
        int rotate = nxt.first;
        cout << nxt.second << " ";
        deq.pop_front();
        // if (nxt.second == -1) cout << "@@";
        if (rotate > 0) {
            for (int i = 0; i < abs(rotate) - 1; i++) {
                deq.push_back(deq[0]);
                deq.pop_front();
            }
        } else {
            for (int i = 0; i < abs(rotate); i++) {
                deq.push_front(deq[deq.size() - 1]);
                deq.pop_back();
            }
        }
    }
}
