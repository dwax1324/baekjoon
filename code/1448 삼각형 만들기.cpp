#include <bits/stdc++.h>
using namespace std;

// 그리디 수학

// 정렬뒤 붙어있는 세개씩 값을 가져와 비교하면 된다.
// 가장 큰값을 찾으려면 a(최댓값) > b+c 조건을 만족하면서 큰값을 찾아야하는데
// 위조건을 만족하면서  a,b,c사이의 차이가 가작 적으면서 큰값을 골라야한다.
// 그래서 정렬한뒤 붙어있는 세값만 비교해주면 된다.

// 정렬되어있어서 값을 다시 비교할 필요가 없늗네
// 생각없이 코딩하면 아래처럼된다

int main() {
    int n;
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n;
    vector<int> v;
    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        v.push_back(a);
    }
    sort(v.begin(), v.end());
    int ans = 0;
    for (int i = 0; i < n - 2; i++) {
        vector<int> temp(3);
        temp[0] = v[i];
        temp[1] = v[i + 1];
        temp[2] = v[i + 2];
        sort(temp.begin(), temp.end());
        if (temp[2] < temp[1] + temp[0]) {
            ans = max(temp[0] + temp[1] + temp[2], ans);
        }
    }
    cout << (ans ? ans : -1);
}