#include <bits/stdc++.h>

// 단순구현
// 공백과 태그안의 문자는 그대로 놔두고
// 단어만 들어오면 뒤집어서 출력한다.

#define MAX 1001001
using namespace std;

char arr[MAX];
int main() {
    for (int i = 0; i < MAX; i++) {
        arr[i] = '@';
    }
    scanf(" %[^\n]s", arr);
    int SIZE = 0;
    for (int i = 0; i < MAX; i++) {
        if (arr[i] == '@') {
            SIZE = i;
            break;
        }
    }

    int i = 0;
    string s = "";
    while (1) {
        if (i == SIZE) {
            if (s.size()) {
                reverse(s.begin(), s.end());
                cout << s;
            }
            break;
        }
        if (arr[i] == '<') {
            if (s.size()) {
                reverse(s.begin(), s.end());
                cout << s;
                s = "";
            }
            while (1) {
                cout << arr[i];
                i++;
                if (arr[i] == '>') {
                    cout << arr[i];
                    break;
                }
            }
        }
        if (arr[i] == ' ') {
            if (s.size()) {
                reverse(s.begin(), s.end());
                cout << s;
                s = "";
            }
            cout << ' ';
        }
        if ((arr[i] <= '9' && arr[i] >= '0') || (arr[i] >= 'a' && arr[i] <= 'z')) {
            s += arr[i];
        }
        i++;
    }
}