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
const ll mod = 1e9 + 7,N = 1e5+10;
//-------------------------------------------------------------
// 染色法判定二分图
int h[N<<1],e[N<<1],ne[N<<1],idx = 0;
void add(int u,int v){
	e[idx] = v, ne[idx] = h[u], h[u] = idx++;
}
int u,v;
int n,m;
// 0表示未染色，1表示白色，2表示黑色
int color[N];
// 给点u染色c，返回染色成功与否
bool dfs(int u,int c){
	color[u] = c;
	for(int i = h[u]; ~i; i = ne[i]){
		int j = e[i];
		if(!color[j]){
			if(!dfs(j,3-c)) return false;
		}else if(color[j] == c) return false;
	}
	return true;
}
int main(){
	memset(color,0,sizeof color);
	memset(h,-1,sizeof h);
	scanf("%d%d",&n,&m);
	rep(i,0,m){
		scanf("%d%d",&u,&v);
		add(u,v),add(v,u);
	}

	bool ok = true;
	rep(i,1,n+1){
		if(!color[i] && !dfs(i,1)) ok = false;
	}

	if(ok) puts("Yes");
	else puts("No");
	

	return 0;
}

