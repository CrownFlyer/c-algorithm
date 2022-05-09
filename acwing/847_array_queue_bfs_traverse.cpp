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
int n,m,u,v,ans = N;
int d[N],q[N]; // d表示距离编号1的距离，q表示队列
void add(int u,int v){
	e[idx] = v, ne[idx] = h[u], h[u] = idx++;
}
int main(){
	memset(h,-1,sizeof h);
	scanf("%d%d",&n,&m);
	rep(i,0,m) scanf("%d%d",&u,&v),add(u,v);
	memset(d,-1,sizeof d); 
	int hh = 0, tt = 0;
	q[0] = 1, d[1] = 0;
	while(hh <= tt){
		int t = q[hh++];
		for(int i = h[t]; ~i; i = ne[i]){
			int j = e[i];
			if(d[j] == -1){
				d[j] = d[t] + 1;
				q[++tt] = j;
			}
		}
	}
	printf("%d\n",d[n]);
	return 0;
}

