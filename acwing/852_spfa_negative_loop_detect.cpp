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
const ll mod = 1e9 + 7,N = 1e5 + 10;
//-------------------------------------------------------------
// spfa判断负环:O(nm)
int h[N],e[N],w[N],ne[N],idx = 0;
int _u,_v,_w;
void add(int u,int v,int _w){
	e[idx] = v, w[idx] = _w, ne[idx] = h[u], h[u] = idx++;
}

int n,m,dist[N],st[N],cnt[N];

int main(){
	memset(h,-1,sizeof h);
	memset(dist,0x3f,sizeof dist);
	memset(st,0,sizeof st);
	memset(cnt,0,sizeof cnt);
	scanf("%d%d",&n,&m);
	rep(i,0,m){
		scanf("%d%d%d",&_u,&_v,&_w);
		add(_u,_v,_w);
	}
	// spfa,更新只会涉及跟更新相关的点
	// 判断负环将每个点入队，且dist的初值不重要 ，只要会更新n次，即表示有负环
	queue<PII> q;
    rep(i,1,n+1){
        q.push({0,i});
        st[i] = 1;
    }
	bool ans = false;
	while(q.size() && !ans){
		int t = q.front().se;
		q.pop();
		cnt[t]++;
		if(cnt[t] == n) ans = true; 
		st[t] = 0; // 从队列中取出后置零表示还可入队
		for(int i = h[t]; ~i;i = ne[i]){
			int j = e[i];
			if(dist[j] > dist[t] + w[i]){
				dist[j] = dist[t] + w[i];
				if(!st[j]){
					st[j] = 1;
					q.push({dist[j],j});
				}
			}
		}
	}

	if(ans) puts("Yes");
	else puts("No");
	return 0;
}

