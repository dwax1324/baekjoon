#include <bits/stdc++.h>

using namespace std;

int main() {
	int n; cin >> n;
	bool odd = false, even = false;
	for (int i = 1; i <= 100; i++) {
		int SUM = 0;
		for (int j = i; j < i + n; j++) {
			SUM += j;
		}
		if (SUM % 2) odd = true;
		else even = true;
	}
	if (odd && even) cout << "Either";
	else if (odd) cout << "Odd";
	else cout << "Even";

}