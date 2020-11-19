#include <bits/stdc++.h>

// 수학
// 근의공식
// 판별식을 통해 허근 중근 걸러내기
// sqrt함수를 쓰기때문에 double써줘야함.
// 정수가아닌 수가 나오면 "둘다틀렸근을" 출력
// 나머지 2의 k승이면 "이수근", 나머지는 "정수근"

using namespace std;

int main() {
    int a, b, c;
    cin >> a >> b >> c;
    if (b * b - (4 * a * c) <= 0)
        cout << "둘다틀렸근";
    else {
        double d = (-(double)b + sqrt(b * b - 4 * a * c)) / (2 * (double)a);
        double e = (-(double)b - sqrt(b * b - 4 * a * c)) / (2 * (double)a);
        if ((int)d != d || (int)e != e) {
            cout << "둘다틀렸근";
            return 0;
        }
        bool h1 = false, h2 = false;
        for (int i = 1; i <= 30; i++) {
            if ((1 << i) == d) {
                h1 = true;
            }
            if ((1 << i) == e) {
                h2 = true;
            }
            if (h1 && h2) break;
        }
        if (h1 && h2)
            cout << "이수근";
        else
            cout << "정수근";
    }
}