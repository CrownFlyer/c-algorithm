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
ll a[N],k;
int t,x,y,MOD;
struct node{
	ll v,mul,add;
}st[N << 2];
//-------------------------------------------------------------
// 区间修改（加乘） 区间查询
inline void build(int p,int l,int r){
	st[p].mul = 1;
	st[p].add = 0;
	if(l == r){
		st[p].v = a[l];
	}else{
		int m = (l + r) >> 1;
		build(p << 1,l,m);
		build(p << 1 | 1,m + 1, r);
		st[p].v = st[p << 1].v + st[p << 1 | 1].v;
	}
	st[p].v %= MOD;
}

void pushdown(int p,int l,int r){
	int m = (l + r) >> 1;
	// 维护儿子的值
	st[p << 1].v = ( st[p << 1].v * st[p].mul + st[p].add * (m - l + 1) ) % MOD;
	st[p << 1 | 1].v = ( st[p << 1 | 1].v * st[p].mul + st[p].add * (r - m) ) % MOD;

	// 维护lazytag
	st[p << 1].mul = ( st[p << 1].mul * st[p].mul ) % MOD;
	st[p << 1 | 1].mul = ( st[p << 1 | 1].mul * st[p].mul ) % MOD;
	st[p << 1].add = ( st[p << 1].add * st[p].mul + st[p].add ) % MOD;
	st[p << 1 | 1].add = ( st[p << 1 | 1].add * st[p].mul + st[p].add ) % MOD;

	// 父节点lazytag初始化
	st[p].mul = 1;
	st[p].add = 0;
}

// update
void ud1(int p,int l,int r,int s,int t,ll k){
	if(t < l || s > r)
		return;
	if(s <= l && r <= t){
		st[p].v = (st[p].v * k) % MOD;
		st[p].mul = (st[p].mul * k) %MOD;
		st[p].add = (st[p].add * k) %MOD;
		return;
	}

	// 假如给出的区间与本区间有交集，但也有不交叉的部分
	// 先传递lazytag
	pushdown(p,l,r);
	int m = (l + r) >> 1;
	ud1(p << 1,l,m,s,t,k);
	ud1(p << 1 | 1,m + 1,r,s,t,k);
	st[p].v = ( st[p << 1].v + st[p << 1 | 1].v ) % MOD;
}

void ud2(int p,int l,int r,int s,int t,ll k){
	if(t < l || s > r)
		return;
	if(s <= l && r <= t){
		st[p].add = ( st[p].add + k ) %MOD;
		st[p].v = ( st[p].v + (r - l + 1) * k ) % MOD;
		return;
	}

	// 假如给出的区间与本区间有交集，但也有不交叉的部分
	// 先传递lazytag
	pushdown(p,l,r);
	int m = (l + r) >> 1;
	ud2(p << 1,l,m,s,t,k);
	ud2(p << 1 | 1,m + 1,r,s,t,k);
	st[p].v = ( st[p << 1].v + st[p << 1 | 1].v ) % MOD;
}


ll query(int p,int l,int r,int s,int t){
	if(t < l || s > r)
		return 0L;
	if(s <= l && r <= t)
		return st[p].v;

	pushdown(p,l,r);
	int m = (l + r) / 2;
	return ( query(p << 1,l,m,s,t) + query(p << 1 | 1,m+1,r,s,t) ) % MOD;
}

int main(){
	int n,m;
	scanf("%d%d%d",&n,&m,&MOD);
	rep(i,1,n+1) scanf("%lld",&a[i]);
	build(1,1,n);
	rep(i,1,m+1){
		scanf("%d",&t);
		if(t == 1){
			scanf("%d%d%lld",&x,&y,&k);
			ud1(1,1,n,x,y,k);
		}
		else if(t == 2){
			scanf("%d%d%lld",&x,&y,&k);
			ud2(1,1,n,x,y,k);
		}else{
			scanf("%d%d",&x,&y);
			printf("%lld\n",query(1,1,n,x,y));
		}
	}
	return 0;
}

