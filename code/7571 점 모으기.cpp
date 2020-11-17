#include <bits/stdc++.h>

using namespace std;

// 스위핑?
// 한쪽에서 다른쪽으로 훑는다
// 뜻이 광범위하게 사용된다.
// 문제가 어려워질수록 꽤 어려워지는 기법이라한다.

// n=10000 이기 때문에 배열을 만들면 1억짜리 배열이 된다.
// bfs로 풀려고 했으나 이걸 보고 포기.

// 각 점마다 모든점과의 위치를 파악하면 되겠다싶었는데
// 10^5 *10^6 으로 포기

// 그냥 최소거리니까 점이 제일 많이 모이는 곳을 선택하면 되겠다 싶었는데
// 아무리 생각해도 잘 모르겠어서 구글링했더니
// 정답은 중앙값이었다.
// 평균값인가? 하고있었는데 수학적 자질이 부족한가보다.

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, m;
    cin >> n >> m;

    vector<int> v;
    vector<int> v2;
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        v.push_back(a);
        v2.push_back(b);
    }
    sort(v.begin(), v.end());
    sort(v2.begin(), v2.end());

    int y = v[v.size() / 2];
    int x = v2[v2.size() / 2];

    int ans = 0;
    for (int i = 0; i < v.size(); i++) {
        ans += abs(y - v[i]);
        ans += abs(x - v2[i]);
    }
    cout << ans;
}