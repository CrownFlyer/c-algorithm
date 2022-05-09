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
const ll mod = 1e9 + 7,N = 2e2 + 10;
//-------------------------------------------------------------
// floyd:O(n^3)
int f[N][N];

int n,m,k;
int u,v,w;
int x,y;

int main(){
	memset(f,0x3f,sizeof f);
	scanf("%d%d%d",&n,&m,&k);
	rep(i,0,m){
		scanf("%d%d%d",&u,&v,&w);
		// 有可能有重边
		f[u][v] = min(f[u][v],w);
	}
	rep(i,1,n+1) f[i][i] = 0;
	rep(k,1,n + 1)
		rep(i,1,n + 1)
			rep(j,1,n + 1)
				f[i][j] = min(f[i][j],f[i][k] + f[k][j]);
	rep(i,0,k){
		scanf("%d%d",&x,&y);
		if(f[x][y] > 0x3f3f3f3f / 2) puts("impossible");
		else printf("%d\n", f[x][y]);
	}
	return 0;
}

