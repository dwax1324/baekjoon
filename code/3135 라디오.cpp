#include <bits/stdc++.h>

//단순구현
// min(목표-현재 , 즐찾s-목표 +1)

using namespace std;

int main() {
    int a, b;
    cin >> a >> b;
    int n;
    cin >> n;
    vector<int> fvs;

    for (int i = 0; i < n; i++) {
        int k;
        cin >> k;
        fvs.push_back(abs(k - b) + 1);
    }
    fvs.push_back(abs(b - a));
    cout << *min_element(fvs.begin(), fvs.end());
}