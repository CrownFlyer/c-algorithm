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
int n,u,v,ans = N;

void add(int u,int v){
	e[idx] = v, ne[idx] = h[u], h[u] = idx++;
}

int dfs(int u){
	st[u] = 1; // 标记已访问
	int res = 0; // 去除u后到最大节点数
	int sum = 1; // 包含u到树的节点数

	for(int i = h[u]; ~i; i = ne[i]){
		int j = e[i];
		if(!st[j]){
			int s = dfs(j);
			res = max(res, s);
			sum += s;
		}
	}

	res = max(res, n - sum);
	ans = min(ans, res);
	return sum;
}
int main(){
	memset(h,-1,sizeof h);
	memset(st,0,sizeof st);
	scanf("%d",&n);
	rep(i,0,n - 1) scanf("%d%d",&u,&v),add(u,v),add(v,u);
	dfs(1);
	printf("%d\n",ans);
	return 0;
}

