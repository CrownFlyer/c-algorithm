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
const ll mod = 1e9 + 7,N = 1e5+10;
//-------------------------------------------------------------
// 数组模拟单调栈
int stk[N],tt = 0;
int n, x;
int main(){
	scanf("%d",&n);
	while(n--){
		scanf("%d",&x);
		while(tt && stk[tt] > x) tt--;
		if(tt) printf("%d ", stk[tt]);
		else printf("-1 ");
		stk[++tt] = x;

	}
	return 0;
}

