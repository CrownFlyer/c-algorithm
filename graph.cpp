const int N = 100010;
int h[N], e[N], ne[N], w[N], idx;

// add an edge u -> v
void add(int u,int v){
	e[idx] = v, ne[idx] = h[u], h[u] = idx++;
}
void add(int u,int v,int _w){
	e[idx] = v,w[idx] = _w, ne[idx] = h[u], h[u] = idx++;
}


// 初始化
idx = 0;
memset(h,-1,sizeof h);

// 记录访问记录
bool vis[N];
memset(vis,false,sizeof vis);

// 树与图的遍历
// dfs
int dfs(int u){
	vis[u] = true;
	for(int i = h[u];i != -1;i = ne[i]){
		int nxt = e[i];
		if(!vis[nxt]) dfs(nxt);
	}
}

// bfs
queue<int> q;
vis[1] = true;
q.push(1);
while(q.size()){
	int cur = q.front();
	q.pop();
	for(int i = h[cur];i != -1;i = ne[i]){
		int nxt = e[i];
		if(!vis[nxt]) vis[nxt] = true,q.push(nxt);
	}
}

// The shortest path
int dist[N]; 
bool st[N]; // 存储每个点的最短距离是否已确定
// dijkstra
int dijkstra(){
	memset(dist,0x3f,sizeof dist);
	memset(st,false,sizeof st);
	priority_queue<PII,vector<PII>,greater<PII>> hp;
	hp.push({0,1});
	while(hp.size()){
		auto t = hp.top();
		hp.pop();
		int d = t.fi, cur = t.se;
		if(st[cur]) continue;
		st[cur] = true;

		for(int i = h[cur]; i != -1; i = ne[i]){
			int nxt = e[i];
			if(dist[nxt] > d + w[i]){
				dist[nxt] = d + w[i];
				hp.push({dist[nxt],nxt});
			}
		}
	}
	return dist[n] == 0x3f3f3f3f ? -1 : dist[n];
}
