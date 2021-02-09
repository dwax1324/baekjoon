// bfs state management
#include <bits/stdc++.h>
using namespace std;

typedef tuple<int, int, int> tii;
int N, M, T;
int mapp[101][101];
bool vis[101][101][2];
int main() {
	cin >> N >> M >> T;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
			cin >> mapp[i][j];
	queue<tii> q;
	q.push({ 0, 0 ,0 });
	vis[0][0][0] = 1;
	int ans;
	bool found = 0;
	for (ans = 0; q.size(); ans++) {
		int qs = q.size();
		for (int i = 0; i < qs; i++) {
			int r, c, gram;
			tie(r, c, gram) = q.front();
			q.pop();
			if (r == N - 1 && c == M - 1) {
				found = true;
				goto bof;
			}
			for (int d = 0; d < 4; d++) {
				int nr = r + "2011"[d] - '1';
				int nc = c + "1102"[d] - '1';
				if (nr < 0 || nc < 0 || nr >= N || nc >= M) continue;
				if (vis[nr][nc][gram] || (gram == 0 && mapp[nr][nc] == 1)) continue;
				if (mapp[nr][nc] == 2 && gram == 0) {
					q.push({ nr,nc,1 });
					vis[nr][nc][1] = 1;
				}
				else {
					q.push({ nr,nc,gram });
					vis[nr][nc][gram] = 1;
				}
			}

		}
	}
bof:
	if (ans <= T && found) cout << ans;
	else cout << "Fail";
}