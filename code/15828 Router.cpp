#include <bits/stdc++.h>

// 큐에 푸쉬하고 팝하면된다.

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    queue<int> q;
    int a;
    while (1) {
        cin >> a;
        if (a == -1) break;
        if (!a)
            q.pop();
        else if (q.size() < n)
            q.push(a);
    }

    if (!q.size())
        cout << "empty";
    else {
        while (q.size()) {
            int cur = q.front();
            q.pop();
            cout << cur << " ";
        }
    }
}