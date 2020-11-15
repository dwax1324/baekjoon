#include <bits/stdc++.h>

// 잘 생각해보면 간단한데 자꾸 헷갈린다
// 이것저것 생각하다가 페어만들어서 스택에 넣었는데 사실 그럴 필요도 없다.

using namespace std;

int main() {
    string s;
    cin >> s;
    stack<pair<char, int> > stk;
    int i = -1;

    while (1) {
        if (i == s.size()) break;
        i++;
        if (s[i] == ')') {
            int SUM = 0;
            while (stk.top().first != '(') {
                SUM += stk.top().second;
                stk.pop();
            }
            stk.pop();
            stk.push(make_pair('X', SUM));
        } else if (s[i] == 'H') {
            stk.push(make_pair('X', 1));
        } else if (s[i] == 'C') {
            stk.push(make_pair('X', 12));
        } else if (s[i] == 'O') {
            stk.push(make_pair('X', 16));
        } else if (s[i] <= '9' && s[i] >= '2') {
            int k = stk.top().second;
            stk.pop();
            stk.push(make_pair('X', (s[i] - '0') * k));
        } else {
            stk.push(make_pair('(', 0));
        }
    }
    int ans = 0;
    while (stk.size()) {
        ans += stk.top().second;
        stk.pop();
    }
    cout << ans;
}