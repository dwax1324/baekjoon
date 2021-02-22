// date: Sun Feb 21 20:57:03 2021
// author: dwax1324
#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
#define int int64_t
using namespace std;typedef pair<int,int> pii;typedef tuple<int,int,int> tii; typedef long long ll;

// ST_MAX 구간트리 총갯수
const int ST_MAX = 1<<21;
struct segtree{
	// start 트리의 height -1의 마지막 노드
	int start;
	// 트리 배열, 레이지 배열
	int tree[ST_MAX],lazy[ST_MAX];
	segtree(){
		start = ST_MAX/2;
		fill(tree,tree+ST_MAX,0);
		fill(lazy,lazy+ST_MAX,0);
	}
	void construct(){
		// 트리의 height-1의 마지막 노드부터 루트까지
		// 두자식의 합을 자신의 값으로 갖는다.
		for(int i= start-1; i>0; i--)
			tree[i] = tree[i*2] ^ tree[i*2+1];
	}
	void propagate(int node, int ns, int ne){
		// 만약 레이지값이 0이 아니면
		if(lazy[node] != 0){
			// 만약 리프노드가 아니면
			if(node < start){
				// 자식들에게 레이지값을 미룬다.
				lazy[node*2] ^= lazy[node];
				lazy[node*2+1] ^= lazy[node];
			}else
				tree[node] ^= lazy[node];
			lazy[node] =0;
		}
	}

	// update함수
	void add(int s, int e, int k){ add(s,e,k,1,0,start);}
	void add(int s, int e, int k, int node, int ns, int ne){
		// 일단 전파를 한다.
		propagate(node,ns,ne);
		if(e <= ns || ne <= s) return;
		if(s <= ns && ne <= e){
			// 이 값이 구간에 완전히 포함이 되면 lazy값 부여 후 전파
			lazy[node] ^= k;
			propagate(node,ns,ne);
			return;
		}
		// 좌우 값갱신
		int mid = (ns+ne)/2;
		add(s,e,k,node*2,ns,mid);
		add(s,e,k,node*2+1,mid,ne);
		tree[node] = tree[node*2] ^ tree[node*2+1];
	}

	int sum(int s, int e){ return sum(s,e,1,0,start);}
	int sum(int s, int e, int node, int ns, int ne){
		propagate(node, ns, ne);
		if(e <= ns || ne <= s) return 0;
		if(s <= ns && ne <= e) return tree[node];
		int mid = (ns+ne)/2;
		return sum(s,e,node*2,ns,mid)^sum(s,e,node*2+1,mid,ne);
	}
}st;
int32_t main(){ios_base::sync_with_stdio(0);cin.tie(0);
	int N,M;
	cin >> N;
	// 리프노드 값받기 (start + i)
	for(int i=0; i < N; i++) cin >> st.tree[i+st.start];
	st.construct();
	cin >> M;
	for(int i=0; i <M; i++){
		int a,b,c,d;
		cin >> a;
		if(a==1){
			cin >> b >> c >> d;
			if(b>c) swap(b,c);
			st.add(b,c+1,d);
		}else{
			cin >> b >> c;
			if(b>c) swap(b,c);
			cout << st.sum(b,c+1) << '\n';
		}
	}

}


