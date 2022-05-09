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
const ll mod = 1e9 + 7,N = 5e5 + 10;
//-------------------------------------------------------------
// 区间修改，区间查询

ll a[N],c1[N],c2[N];
int n,m;
int t,x,y;
ll k;

void add(int p,ll v){
	ll v1 = 1ll * p * v;
	while(p <= n){
		c1[p] += v, c2[p] += v1;
		p += p & -p;
	}
}

void add1(int l,int r,ll v){
	add(l, v), add(r + 1, -v);
}

ll query(ll *c,int p){
	ll ans = 0;
	while(p){
		ans += c[p];
		p -= p & -p;
	}
	return ans;
}

ll query1(int l,int r){
	return (r + 1ll) * query(c1, r) - 1ll * l * query(c1, l - 1) - (query(c2, r) - query(c2, l - 1));
}

// 区间修改，对应差分数组的修改
void init(){
	rep(i,1,n+1){
		c1[i] += a[i] - a[i - 1], c2[i] += i * (a[i] - a[i - 1]);
		int j = i + (i & -i);
		if(j <= n) c1[j] += c1[i], c2[j] += c2[i];
	}
}
int main(){
	scanf("%d%d",&n,&m);
	rep(i,1,n+1) scanf("%lld",&a[i]);
	init();
	rep(i,1,m+1){
		scanf("%d",&t);
		if(t == 1){
			scanf("%d%d%lld",&x,&y,&k);
			add1(x,y,k);
		}else{
			scanf("%d",&x);
			printf("%lld\n", query1(x,x));
		}
	}
	return 0;
}

