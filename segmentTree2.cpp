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
int a[N];
ll f[N << 2], v[N << 2];
//-------------------------------------------------------------
// 区间修改 区间查询
inline void build(int p,int l, int r){
	v[p] = 0;
	if(l == r){
		f[p] = a[l];
		return;
	}
	int m = (l + r) >> 1;
	build(p << 1,l, m);
	build(p << 1 | 1, m + 1, r);
	f[p] = f[p << 1] + f[p << 1 | 1];
}

inline void insert(int p,int l,int r,int x,int y,ll k){
	if(l == x && r == y){
		v[p] += k;
		return;
	}
	f[p] += (y - x + 1) * k;
	int m = (l + r) >> 1;
	if(y <= m) insert(p << 1,l,m,x,y,k);
	else if(x > m) insert(p << 1 | 1,m + 1,r,x,y,k);
	else insert(p << 1,l,m,x,m,k),insert(p << 1 | 1,m + 1,r,m+1,y,k);
}

ll calc(int p,int l,int r,int x,int y,ll k){
	k += v[p];
	if(l == x && r == y){
		return k * (r - l + 1) + f[p];
	}
	int m = (l + r) >> 1;
	if(y <= m) return calc(p << 1,l,m,x,y,k);
	else if(x > m) return calc(p << 1 | 1,m + 1,r,x,y,k);
	else return calc(p << 1,l,m,x,m,k) + calc(p << 1 | 1,m + 1,r,m + 1,y,k);
}
int main(){
	int n,m;
	scanf("%d%d",&n,&m);
	rep(i,1,n+1) scanf("%d",&a[i]);
	build(1,1,n);
	rep(i,1,m + 1){
		int t;
		scanf("%d",&t);
		if(t == 1){
			int x,y;
			ll k;
			scanf("%d%d%lld",&x,&y,&k);
			insert(1,1,n,x,y,k);
		}else{
			int x,y;
			scanf("%d%d",&x,&y);
			printf("%lld\n",calc(1,1,n,x,y,0L));
		}
	}
	return 0;
}

