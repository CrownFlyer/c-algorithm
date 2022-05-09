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
const ll mod = 1e9 + 7,N = 5e2 + 10, M = 1e4 + 10;
//-------------------------------------------------------------
int n,m,k;
struct Edge{
	int u;
	int v;
	int w;
} e[M];

// bellman-forward
int dist[N], back[N];

int main(){
	scanf("%d%d%d",&n,&m,&k);
	rep(i,0,m){
		int _u,_v,_w;
		scanf("%d%d%d",&_u,&_v,&_w);
		e[i] = {_u,_v,_w};
	}
	memset(dist,0x3f,sizeof dist);
	dist[1] = 0;
	rep(i,0,k){
		// memcpy(dst,src,len)
		memcpy(back,dist,sizeof dist);
		rep(j,0,m){ // 遍历所有边	
			int u = e[j].u, v = e[j].v, w = e[j].w;
			// 使用back：避免更新完一条边，立马更新另一条边，防止串联更新
			dist[v] = min(dist[v], back[u] + w);
		}
	}

	if(dist[n] > 0x3f3f3f3f / 2) puts("impossible");
	else printf("%d\n", dist[n]);
	return 0;
}

