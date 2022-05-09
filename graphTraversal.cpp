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
const ll mod = 1e9 + 7,N = 2e5 + 10;
//-------------------------------------------------------------

int h[N], e[N], ne[N], w[N], idx,f[N];
// add an edge u -> v
void add(int u,int v){
	e[idx] = v, ne[idx] = h[u], h[u] = idx++;
}
int ans[N];

void dfs(int cur,int p){
	if(ans[cur]) return;
	ans[cur] = p;
	for(int i = h[cur]; i != -1 ; i = ne[i]){
		dfs(e[i],p);
	}
}

int main(){
	int n,m,u,v;
	scanf("%d%d",&n,&m);
	memset(h,-1,sizeof h);
	memset(ans,0,sizeof ans);
	rep(i,0,m) scanf("%d%d",&u,&v),add(v,u);
	per(i,1,n+1) dfs(i,i);
	rep(i,1,n+1) printf("%d ", ans[i]);
	return 0;
}

