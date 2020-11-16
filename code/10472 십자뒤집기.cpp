#include <bits/stdc++.h>
using namespace std;

// 시도1.
// 3*3으로 수가 적기때문에 충분히 브루트포스로 풀 수 있다고 생각
// bfs로 풀던 중 각 맵의 상태를 표현하는데서 막힘.
// 큐로 이차원배열을 넘겨주자니 뭔가 메모리초과날거 같고..
// 생각에 진전이 없어서 구글링함

// http://joonas-yoon.blogspot.com/2016/03/10472.html 여기를 참고했다.
// 일단 아이디어는 비트마스킹+bfs
// 클릭으로 변할 수 있는 가짓 수를 배열에 저장한다.
// 000 000 000 부터 시작한다.
// vi-> 1<<9 방문 표시를 하며
// xor한 값이  방문된적 없으면 큐에 넣는다.
// 입력받은 배열과 같으면 멈춘다.
// 비트마스킹으로푸는게 신기하다.

int click[9] = {
    416,  //110 100 000
    464,  //111 010 000
    200,  //011 001 000
    308,  //100 110 100
    186,  //010 111 010
    89,   //001 011 001
    38,   //000 100 110
    23,   //000 010 111
    11,   //000 001 011
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int T;
    cin >> T;
    while (T--) {
        char arr[10];
        for (int i = 0; i < 9; i++) {
            cin >> arr[i];
        }
        int k = 0;
        for (int i = 0; i < 9; i++) {
            k |= ((arr[i] == '*') << (8 - i));
        }

        queue<int> q;
        bool vi[1 << 9] = {};
        q.push(0);
        vi[0] = true;
        int dist = 0;

        while (q.size()) {
            bool flag = false;
            int qs = q.size();
            while (qs--) {
                int cur = q.front();
                q.pop();
                if (cur == k) {
                    flag = true;
                    break;
                }
                for (int i = 0; i < 9; i++) {
                    int next = cur ^ click[i];
                    if (!vi[next]) {
                        q.push(next);
                        vi[next] = true;
                    }
                }
            }
            if (flag) break;
            dist++;
        }
        cout << dist << '\n';
    }
}