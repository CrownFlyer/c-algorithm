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
const ll mod = 1e9 + 7,N = 5e2+10, M = 1e5 + 10;
//-------------------------------------------------------------
// 匈牙利算法求二分图最大匹配
bool st[N]; // 某一轮模拟匹配中尚未被匹配
int match[N]; // 

int h[N],e[M],ne[M],idx = 0;
void add(int u,int v){
	e[idx] = v, ne[idx] = h[u], h[u] = idx++;
}
int u,v;
int n1,n2,m;


void init(){
	memset(h,-1,sizeof h);
}

bool find(int u){
	// 遍历可以匹配的边
	for(int i = h[u]; ~i; i = ne[i]){
		int j = e[i];
		if(!st[j]){
			st[j] = true;
			// 如果u匹配的边的另一个点未匹配或其可以匹配其他的边，则配对成功
			if(!match[j] || find(j)){
				match[j] = u;
				return true; 
			}
		}
	}
	return false; // 一个都没有匹配上
}
int main(){
	init();
	scanf("%d%d%d",&n1,&n2,&m);
	rep(i,0,m){
		scanf("%d%d",&u,&v);
		add(u,v);
	}

	int ans = 0;
	rep(i,1,n1+1){
		memset(st,false,sizeof(st));
		if(find(i)) ans++;
	}

	printf("%d\n", ans);
	

	return 0;
}

