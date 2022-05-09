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
// 单点修改 区间查询
ll a[N],c[N];
int n,m;
int t,x,y;

void add(int p,ll v){
	while(p < N){
		c[p] += v;
		p += p & -p;
	}
}

ll query(int p){
	int ans = 0;
	while(p){
		ans += c[p];
		p -= p & -p;
	}
	return ans;
}

void init(){
	rep(i,1,n+1){
		c[i] += a[i];
		int j = i + (i & -i);
		if(j <= n) c[j] += c[i];
	}
}
int main(){
	scanf("%d%d",&n,&m);
	rep(i,1,n+1) scanf("%lld",&a[i]);
	init();
	rep(i,1,m+1){
		scanf("%d%d%d",&t,&x,&y);
		if(t == 1){
			add(x,y);
		}else{
			printf("%lld\n", query(y) - query(x - 1));
		}
	}
	return 0;
}

