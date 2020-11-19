#include <bits/stdc++.h>

using namespace std;

// 그리디

// 길이가 다르면 0
// 길이가 다르면 무조건 8이안들어가는 숫자를 만들 수 있다.

// 길이가 같으면 앞에서부터
// 같은 숫자면 통과, 둘다 8이면 ans++, 다른숫자면 break

int main() {
    string a, b;
    cin >> a >> b;
    int cnt = 0;
    if (a.size() == b.size()) {
        for (int i = 0; i < a.size(); i++) {
            if (a[i] == b[i]) {
                if (a[i] == '8')
                    cnt++;
            } else
                break;
        }
    }
    cout << cnt;
}