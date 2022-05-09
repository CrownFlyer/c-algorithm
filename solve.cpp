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
// prim 
// 存储图 存储各点到生成树的距离 节点是否加入生成树 节点的前驱节点
int g[N][N],dist[N],st[N],pre[N];
int n,m;
int u,v,w;

int main(){
	scanf("%d%d",&n,&m);
	rep(i,0,m){
		scanf("%d%d%d",&u,&v,&w);
		g[u][v] = g[v][u] = w;
	}
	memset(dist,0x3f,sizeof dist);
	int ans = 0;
	dist[1] = 0; // 任选一个节点开始生成
	rep(i,0,n){ // 每次循环选出一个点到生成树
		int t = -1; // 每次选出加入生成树的点
		rep(j,1,n+1) if(!st[j] && t == -1 || dist[t] > dist[j])
			t = j;

		st[t] = 1; // 选择该点
		ans += dist[t];
		rep(j,1,n+1){ // 更新生成树外的点到生成树的距离
			if(dist[j] > g[t][j] && !st[j]){
				dist[j] = g[t][j];
				pre[j] = t;
			}
		}
	}
	printf("%d\n",ans);

	return 0;
}

