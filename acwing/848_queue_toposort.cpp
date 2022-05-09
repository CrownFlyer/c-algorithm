#include <bits/stdc++.h>
using namespace std;

#define rep(i,a,n) for(int i = a;i < n; i++)
#define per(i,a,n) for(int i = n - 1;i >= a)
#define PII pair<int,int>
#define VI vector<int>
#define VVI vector<vector<int>>
#define LB lower_bound
#define UB upper_bound
#define PB push_back
#define EB emplace_back
#define fi first
#define se second
#define all(x) (x).begin(), (x).end()
#define SZ(x) ((int)(x).size())


typedef long long ll;
const ll mod = 1e9 + 7,N = 1e5 + 5;
//-------------------------------------------------------------

int h[N << 1], ne[N << 1], e[N << 1],st[N], idx = 0;
int n,m,u,v,ans = N;
int d[N],q[N]; // d表示入度，q表示队列
void add(int u,int v){
	e[idx] = v, ne[idx] = h[u], h[u] = idx++;
}
int main(){
	memset(h,-1,sizeof h);
	scanf("%d%d",&n,&m);
	rep(i,0,m) scanf("%d%d",&u,&v),add(u,v),d[v]++;
	// toposort
	int hh = 0, tt = -1;
	rep(i,1,n+1) if(!d[i]) q[++tt] = i;
	while(hh <= tt){
		int t = q[hh++];
		for(int i = h[t]; ~i; i = ne[i]){
			int j = e[i];
			d[j]--;
			if(!d[j]) q[++tt] = j;
		}
	}

	if(tt == n - 1){ // n个点都入对，表示有效的拓扑排序
		rep(i,0,n) printf("%d ", q[i]);
		printf("\n");
	}else printf("%d\n",-1);
	return 0;
}

