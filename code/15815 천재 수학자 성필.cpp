#include <bits/stdc++.h>

// 30분 정도 헤맴
// 받는 즉시 연산자 계산해줘야한다.
// 후위표기식이지만 꼭 끝에 연산자가 전부 몰려있다는 보장이 없다.
// 저장해뒀다가 한꺼번에 출력해서 10번정도틀림
using namespace std;

int main() {
    string s;
    cin >> s;
    stack<int> numStk;
    vector<char> ops;
    for (int i = 0; i < s.size(); i++) {
        if (s[i] >= '0' && s[i] <= '9') {
            numStk.push(s[i] - '0');
        } else {
            int cur = numStk.top();
            numStk.pop();
            int cur2 = numStk.top();
            numStk.pop();
            if (s[i] == '+') {
                numStk.push(cur + cur2);
            } else if (s[i] == '-') {
                numStk.push(cur2 - cur);
            } else if (s[i] == '/') {
                numStk.push(cur2 / cur);
            } else if (s[i] == '*') {
                numStk.push(cur * cur2);
            }
        }
    }

    cout << numStk.top();
}