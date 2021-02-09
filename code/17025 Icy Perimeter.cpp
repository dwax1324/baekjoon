// 2021-02-09
// bfs , size and perimeter of components
#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;
int N;

char mapp[1001][1001];
bool vis[1001][1001];

pii bfs(int a, int b) {
	queue<pii> q;
	vis[a][b] = 1;
	q.push({ a,b });
	int peri = 0, area = 0;
	while (q.size()) {
		int r = q.front().first, c = q.front().second; q.pop();
		area++;
		for (int d = 0; d < 4; d++) {
			int nr = r + "2011"[d] - '1';
			int nc = c + "1102"[d] - '1';
			if (nr < 0 || nc < 0 || nr >= N || nc >= N) {
				peri++; continue;
			}
			if (mapp[nr][nc] == '.') peri++;
		}
		for (int d = 0; d < 4; d++) {
			int nr = r + "2011"[d] - '1';
			int nc = c + "1102"[d] - '1';
			if (nr < 0 || nc < 0 || nr >= N || nc >= N) continue;
			if (vis[nr][nc] || mapp[nr][nc] != '#') continue;
			q.push({ nr,nc });
			vis[nr][nc] = 1;
		}
	}
	return { area,peri };
}

int main() {
	cin >> N;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			cin >> mapp[i][j];
	vector<pii> ans;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			if (mapp[i][j] == '#' && !vis[i][j]) {
				ans.push_back(bfs(i, j));
			}
	sort(ans.begin(), ans.end(), [](pii a, pii b) {
		if (a.first == b.first) return a.second < b.second;
		return a.first > b.first;
		});
	cout << ans[0].first << " " << ans[0].second;
}
