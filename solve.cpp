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
const ll mod = 1e9 + 7,N = 1e6+10;
//-------------------------------------------------------------
// 双端队列模拟单调栈
// q:双端队列，存放数组下标
// a:存放数组
// hh:队首，tt;队尾
int q[N],a[N],hh, tt;
int n, k;

int main(){
	VI a = {1,2,3,4,5};
	int i = 0;
	for(auto &x : a)
		printf("%d %p %p\n", x,&x,&a[i++]);

	for(auto &x : a)
		x = 6;
	for(auto &x : a)
		printf("%d ",x);
	return 0;
}

