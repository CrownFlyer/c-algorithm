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
// 堆优化dijkstra O（mlogn）
int h[N], ne[N], e[N], w[N], idx = 0; // 稀疏图用星式链表存储
int dist[N]; // 记录每一个点距离第一个点的距离
int st[N]; // 记录该点的最短距离是否已经确定
int n,m,_u,_v,_w;

void add(int _u,int _v,int _w){
	e[idx] = _v, ne[idx] = h[_u], w[idx] = _w, h[_u] = idx++;
}


int main(){
	scanf("%d%d",&n,&m);
	memset(h,-1,sizeof h);
	rep(i,0,m){
		scanf("%d%d%d",&_u,&_v,&_w);
		add(_u,_v,_w);
	}

	memset(dist,0x3f,sizeof dist);
	dist[1] = 0;
	// 这里为什么存pair，首先小根堆根据距离来的，根据距离记录点，因此用pair来存放另一个点
	priority_queue<PII,vector<PII>,greater<PII>> pq; // 定义小根堆
	pq.push({0,1});
	while(pq.size()){
		PII p = pq.top();
		pq.pop();
		int d = p.fi, ver = p.se;
		if(st[ver]) continue; 
		st[ver] = 1;

		for(int i = h[ver]; ~i; i = ne[i]){
			int j = e[i];
			if(dist[j] > d + w[i]){
				dist[j] = dist[ver] + w[i];
				pq.push({dist[j],j});
			}
		}
	}


	if(dist[n] == 0x3f3f3f3f) puts("-1");
	else printf("%d\n",dist[n]);
	
	return 0;
}

