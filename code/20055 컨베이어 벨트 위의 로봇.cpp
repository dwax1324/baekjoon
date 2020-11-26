#include <bits/stdc++.h>

using namespace std;

// 구현

// 지문이 이해가 안가서 힘들었다.
// 로봇이 내려간다는게 컨베이어벨트 밑으로 내려가서 다시 첨으로 가는건지
// 아예 땅으로 떨어지는건지
// 설명이 좀 친절하진 않은거같다.
// 아무튼 구현하면됨

vector<pair<int, int>> v;
int n, m;

void move() {
    pair<int, int> temp = v[1];
    pair<int, int> last = v[n * 2];
    for (int i = 2; i <= n * 2; i++) {
        pair<int, int> temp2 = v[i];
        v[i] = temp;
        temp = temp2;
    }
    v[1] = last;
}

int check() {
    int cnt = 0;
    for (int i = 1; i <= n * 2; i++) {
        if (v[i].first == 0) cnt++;
    }
    return cnt;
}
void print() {
    cout << '\n';
    for (int i = 1; i <= n * 2; i++) {
        cout << v[i].first << " ";
    }
    cout << '\n';
    for (int i = 1; i <= n * 2; i++) {
        cout << v[i].second << " ";
    }
    cout << "\n";
}

void moveRobots() {
    for (int i = n - 1; i >= 1; i--) {
        // 현재칸에 로봇이 있다면
        if (v[i].second == 1) {
            // 뒷칸이 내구도가 0이아니고 로봇이 없다면
            // 로봇을 이동시키고 내구도를 감소
            if (v[i + 1].first > 0 && v[i + 1].second == 0) {
                v[i].second = 0;
                v[i + 1].second = 1;
                v[i + 1].first--;
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n >> m;
    v.resize(n * 2 + 1, {0, 0});
    for (int i = 1; i <= n * 2; i++) {
        cin >> v[i].first;
    }
    int cnt = 0;
    while (1) {
        if (check() >= m) break;
        cnt++;
        // n번 위치에 로봇이 있으면 땅에 떨어뜨린다.
        move();
        v[n].second = 0;
        moveRobots();
        v[n].second = 0;
        // 첫번째칸의 내구도가 0이아니며 로봇이 안올려져있다면
        // 로봇을 올리고 내구도를 감소시킨다.
        if (v[1].first > 0 && v[1].second == 0) {
            v[1].second = 1;
            v[1].first--;
        }
        // print();
    }
    cout << cnt;
}