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
const ll mod = 1e9 + 7,N = 5e5 + 1;
int a[N],f[N << 2];
//-------------------------------------------------------------

// 单点修改，区间查询

inline void build(int p,int l,int r){
	if(l == r){
		f[p] += a[l];
		return;
	}
	int m = (l + r) >> 1;
	build(p << 1, l, m);
	build(p << 1 | 1,m + 1, r);
	f[p] = f[p << 1] + f[p << 1 | 1];
}

inline void add(int p,int l,int r,int x,int y){
	f[p] += y;
	if(l == r) 
		return;
	int m = (l + r) >> 1;
	if(x <= m) 
		add(p << 1,l, m, x, y);
	else 
		add(p << 1 | 1, m + 1, r, x, y);
}


int calc(int p,int l,int r,int s,int t){
	if(l == s && r == t)
		return f[p];
	int m = (l + r) >> 1;
	if(t <= m) return calc(p << 1,l, m, s ,t);
	else if(s > m) return calc(p << 1 | 1,m + 1, r, s, t);
	return calc(p << 1,l, m, s ,m) + calc(p << 1 | 1,m + 1, r, m + 1, t);
}

int main(){
	int n,m;
	scanf("%d%d",&n,&m);
	memset(f,0,sizeof f);
	rep(i,1,n+1) scanf("%d",&a[i]);
	build(1,1,n);
	rep(i,1,m+1){
		int t,x,y;
		scanf("%d%d%d",&t,&x,&y);
		if(t == 1)
			add(1,1,n,x,y);
		else 
			printf("%d\n", calc(1,1,n,x,y));
	}
	return 0;
}

