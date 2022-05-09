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
// spfa:平均情况下O(m)，最坏O(nm)
int h[N],e[N],w[N],ne[N],idx = 0;
int _u,_v,_w;
void add(int u,int v,int _w){
	e[idx] = v, w[idx] = _w, ne[idx] = h[u], h[u] = idx++;
}

int n,m,dist[N],st[N];

int main(){
	memset(h,-1,sizeof h);
	memset(dist,0x3f,sizeof dist);
	memset(st,0,sizeof st);
	scanf("%d%d",&n,&m);
	rep(i,0,m){
		scanf("%d%d%d",&_u,&_v,&_w);
		add(_u,_v,_w);
	}
	
	queue<PII> q;

	dist[1] = 0;
	// 更新只会涉及跟更新相关的点
	q.push({0,1});
	st[1] = 1;
	while(q.size()){
		PII cur = q.front();
		q.pop();
		int t = cur.se;
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
	// 这里是==是因为此时只选择了更新的边进行更新，没有像bellman-ford选择所有的边进行更新
	// 就不会选择dist[i]这样的点来进行更新，所以不会对dist[i]加上一个负数
	if(dist[n] == 0x3f3f3f3f) puts("impossible");
	else printf("%d\n", dist[n]);
	return 0;
}

