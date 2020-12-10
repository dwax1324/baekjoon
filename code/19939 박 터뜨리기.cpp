#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define pii pair<int, int>
#define pic pair<int, char>
#define pci pair<int, char>
#define pipii pair<int, pii>
#define pll pair<long, long>
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
    규칙을 찾는 문제였다.

 

규칙만 찾는다면 구현은 금방 하는 문제이지만 규칙 찾기가 쉽지 않았다.

 

 

 

우선 공을 가장 적게 분배해준다. 1)

 

k = 3이라면

 

1 2 3  <- 이런 식으로

 

1부터 k까지의 누적합이 n보다 크다면 불가능한 경우다. 2)

 

 

 

가능한 경우,

 

두 가지의 경우로 나뉜다.

 

ex. 6 3

- 1 2 3

 

ex. 9 3

- 2 3 4

 

ex. 10 4

- 1 2 3 4

 

위의 세 예시처럼 연속적인 수들로 담을 수 있는 경우와

 

ex. 7 3

- 1 2 4

 

ex. 11 3

- 2 4 5

 

ex. 11 4

- 1 2 3 5

 

위의 예시처럼 연속적이지 못한 수들로 담을 수 있는 경우

 

이렇게 두 가지로 나뉜다.

 

 

 

전자의 경우 k-1이 정답이고 3)

 

후자의 경우 k가 정답이 된다. 4)

 

라는 규칙을 찾아볼 수 있다.
https://korean-otter.tistory.com/entry/%EB%B0%B1%EC%A4%80-19939-%EB%B0%95-%ED%84%B0%EB%9C%A8%EB%A6%AC%EA%B8%B0-2020-%EC%A0%95%EC%98%AC-%EC%B4%88%EB%93%B1%EB%B6%80-1%EB%B2%88
<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<*/

void solve() {
    int n, k;
    cin >> n >> k;
    int t;
    int st = 1;
    ff(2, i, k + 1) {
        st += i;
    }
    n -= st;

    if (n < 0)
        cout << -1;
    else if (n % k == 0)
        cout << k - 1;
    else if (n % k != 0)
        cout << k;
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
