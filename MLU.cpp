#include <bits/stdc++.h>
using namespace std;

#define rep(i,a,n) for(int i = a;i < n; i++)
#define per(i,a,n) for(int i = n - 1;i >= a;i--)
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
const ll mod = 1e9 + 7,N = 110;
//-------------------------------------------------------------

// 这里一开始开1e9会有3个相加导致溢出，开1e8安全
int INF = 1e8,n,m,u,v,w,ans = INF;
int a[N][N], f[N][N];	// 记录两条线段的权值以及两点之间的最小权值

int main(){
	scanf("%d%d",&n,&m);
	rep(i,1,n+1) rep(j,1,n+1) if(i != j) a[i][j] = INF,f[i][j] = INF;
	rep(i,1,m+1){
		scanf("%d%d%d",&u,&v,&w);
		a[u][v] = w, a[v][u] = w;
		f[u][v] = w, f[v][u] = w;
	}
	rep(k,1,n+1) {
		// 判断最小环
		rep(i,1,k) rep(j,i+1,k) ans = min(ans,f[i][j] + a[i][k] + a[k][j]);
		// 更新权值
		rep(i,1,n+1) rep(j,1,n+1) f[i][j] = min(f[i][j], f[i][k] + f[k][j]),f[j][i] = f[i][j];
	}
	if(ans == INF) 
		printf("No solution.\n");
	else 
		printf("%d\n",ans);
	return 0;
}

