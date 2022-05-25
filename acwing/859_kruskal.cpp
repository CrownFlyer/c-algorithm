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
// kruskal O(m + nlongn) 贪心
// 存储图 存储各点到生成树的距离 节点是否加入生成树 节点的前驱节点
struct Edge{
	int u,v,w;
	bool operator < (const Edge &W) const{
		return w < W.w;
	}
}edge[N << 1];
int n,m;
int u,v,w;

// Disjoint-set
int p[N];
int find(int x){
	while(x != p[x]) x = p[x];
	return x;
}
int main(){
	scanf("%d%d",&n,&m);
	rep(i,0,m){
		scanf("%d%d%d",&u,&v,&w);
		edge[i] = {u,v,w};
	}
	sort(edge,edge + m);
	rep(i,1,n+1) p[i] = i;
	int cnt = 1; // 记录生成树的节点数
	int ans = 0; // 记录权值总和
	rep(i,0,m){
		int a = edge[i].u, b = edge[i].v, c = edge[i].w;
		int pa = find(a), pb = find(b);
		if(pa != pb){
			p[a] = pb;
			cnt++;
			ans += c;
		}
	}

	if(cnt < n) printf("impossible\n");
	else printf("%d\n",ans);

	return 0;
}

