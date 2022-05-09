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
const ll mod = 1e9 + 7,N = 5e2 + 10;
//-------------------------------------------------------------

int g[N][N]; // 稠密图用邻接矩阵
int dist[N]; // 记录每一个点距离第一个点的距离
int st[N]; // 记录该点的最短距离是否已经确定
int n,m,u,v,w;
int main(){
	scanf("%d%d",&n,&m);
	memset(g,0x3f,sizeof g);
	rep(i,0,m){
		scanf("%d%d%d",&u,&v,&w);
		g[u][v] = min(g[u][v],w);
	}

	memset(dist,0x3f,sizeof dist);
	dist[1] = 0;
	rep(i,0,n){
		int t = -1; // t存储当前访问的点
		rep(j,1,n+1) if(!st[j] && (t == -1 || dist[t] > dist[j])) t = j;
		st[t] = 1;
		rep(j,1,n+1) dist[j] = min(dist[j], dist[t] + g[t][j]);
	}

	if(dist[n] == 0x3f3f3f3f) puts("-1");
	else printf("%d\n",dist[n]);
	
	return 0;
}

