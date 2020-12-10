#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define pii pair<int, int>
#define pic pair<int, char>
#define pci pair<int, char>
#define pipii pair<int, pii>
#define pll pair<long, long>
#define tiii tuple<int, int, int>
#define sz(x) (int)(x).size()
#define ff(begin, i, end) for (__typeof(end) i = (begin) - ((begin) > (end)); i != (end) - ((begin) > (end)); i += 1 - 2 * ((begin) > (end)))
#define fastio ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
#define debug freopen("input.txt", "r", stdin), freopen("output.txt", "w", stdout)
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define F first
#define S second
#define error(args...)                           \
    {                                            \
        string _s = #args;                       \
        replace(_s.begin(), _s.end(), ',', ' '); \
        stringstream _ss(_s);                    \
        istream_iterator<string> _it(_ss);       \
        err(_it, args);                          \
        cout << '\n';                            \
    }
void err(istream_iterator<string> it) {}
template <typename T, typename... Args>
void err(istream_iterator<string> it, T a, Args... args) {
    cout << *it << " = " << a << ' ';
    err(++it, args...);
}

/*>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
    구현

    9자리 완탐 ->  시간초과    
    그러니 자리수마다 평균을 구하고, 그 값들을 더해 전체 수의 평균을 구해야 합니다.
    예를 들어 n=2, 십의 자리수 후보가 (6, 8, 9), 일의 자리수 후보가 (0, 3, 8, 9)라고 하면 avg(6,8,9)*10 + avg(0,3,8,9) 이 값이 전체 평균이 됩니다.
<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<*/
string arr[11][5] = {
    {"###",
     "#.#",
     "#.#",
     "#.#",
     "###"},
    {"..#",
     "..#",
     "..#",
     "..#",
     "..#"},
    {
        "###",
        "..#",
        "###",
        "#..",
        "###",
    },
    {"###",
     "..#",
     "###",
     "..#",
     "###"},
    {
        "#.#",
        "#.#",
        "###",
        "..#",
        "..#",
    },
    {
        "###",
        "#..",
        "###",
        "..#",
        "###",
    },
    {
        "###",
        "#..",
        "###",
        "#.#",
        "###",
    },
    {
        "###",
        "..#",
        "..#",
        "..#",
        "..#",
    },
    {
        "###",
        "#.#",
        "###",
        "#.#",
        "###",
    },
    {
        "###",
        "#.#",
        "###",
        "..#",
        "###",
    }

};
vector<vector<double>> ans;
int n;

void solve() {
    cin >> n;
    vector<string> s;
    ff(0, i, 5) {
        string tmp;
        cin >> tmp;
        s.push_back(tmp);
    }

    int t = 0;
    vector<double> temp;
    t = 0;
    for (int i = 0; i < n; i++) {
        temp = {};
        for (int z = 0; z < 10; z++) {
            bool flag = true;
            for (int j = 0; j < 5; j++) {
                if (s[j][t] == '#' && arr[z][j][0] != s[j][t]) flag = false;
                if (s[j][t + 1] == '#' && arr[z][j][1] != s[j][t + 1]) flag = false;
                if (s[j][t + 2] == '#' && arr[z][j][2] != s[j][t + 2]) flag = false;
            }
            if (flag) {
                // error(z);
                temp.push_back(z);
            }
            // error(t);
        }
        t += 4;
        ans.push_back(temp);
    }
    int ret = 1;
    for (auto x : ans) {
        if (!x.size()) ret = 0;
    }
    if (!ret)
        cout << -1;
    else {
        // for (auto x : ans) {
        //     for (auto y : x) {
        //         cout << y << " ";
        //     }
        //     cout << '\n';
        // }
        double ret = 0;
        for (int i = 0; i < n; i++) {
            double sum = 0;
            for (int j = 0; j < ans[i].size(); j++) {
                sum += ans[i][j];
            }
            sum /= double(sz(ans[i]));
            double tp = 1;
            ff(0, z, n - i - 1) {
                tp *= (double)10;
            }
            ret += sum * tp;
            // error(sum);
        }
        cout << fixed << setprecision(10) << ret;
    }
}

auto main() -> int {
    fastio;
    debug;  // ✨✨✨✨✨✨✨✨✨✨✨✨✨✨
    int t = 1;
    // cin >> t;  // ✨✨✨✨✨✨✨✨✨✨✨✨✨✨
    for (int i = 1; i <= t; i++) {
        // cout << "case #" << i << ": ";
        solve();
    }
}

// do you read the problem properly?
// are the number of the input correct?
// are there edge cases?
// how about overflow?
// data structres properly reset between test cases?
// floating points?
// check if fastio is causing the problem
// use feynman algorithm
