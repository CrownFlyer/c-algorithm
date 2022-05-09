#include <bits/stdc++.h>
using namespace std;




typedef long long ll;
const ll mod = 1e9 + 7;

//-------------------------------------------------------------


// 倒叙遍历O(n)
set<int> f;
void dfs(TreeNode *u){
	if(!u) return;
	f.insert(u.val);
	dfs(u.left);
	dfs(u.right);
}

int getNumber(TreeNode* root, vector<vector<int>>& ops){
	f.clear();
	dfs(root);
	reverse(ops.begin(),ops.end());
	int ans = 0;
	for(auto &x :ops){
		int tp = x[0], l = x[1], r = x[2];
		auto it = f.LB(l);
		while(it != f.end() && *it <= r){
			it = f.erase(it);
			ans += tp == 1;
		}
	}
	return ans;
}

// 线段树
const int maxn = 100010 << 2;
int b[maxn];

void add(int p,int tp){
    b[p] = tp;
}

void lazy(int p){
    if(b[p]){
        add(p << 1,b[p]);
        add((p << 1) | 1,b[p]);
        b[p] = 0;
    }
}
// [l,r]:查询的区间，[s,t]:
void update(int s,int t,int l,int r,int tp,int p){
    if(l <= s && t <= r){
        b[p] = tp;
        return;
    }
    lazy(p);
    int m = s + ((t - s) >> 1);
    if(l <= m) update(s,m,l,r,tp,p << 1);
    if(m + 1 <= r) update(m+1,t,l,r,tp,(p << 1) | 1);
}

int ans;
void query(int s,int t,int p){
    if(s == t){
        ans += (b[p] == 2);
        return;
    }
    lazy(p);
    int m = s + ((t - s) >> 1);
    query(s,m,p << 1);
    query(m+1,t,(p << 1) | 1); 
}

int getNumber(TreeNode* root, vector<vector<int>>& ops){
    rep(i,1,maxn) b[i] = 1;
    VI a;
    auto dfs = [&](auto self, auto *u) {
            if (!u) return;
            self(self, u -> left);
            a.PB(u -> val);
            self(self, u -> right);
        };
    dfs(dfs, root);	
    for(auto x:ops){
        int l = LB(all(a),x[1])-a.begin(), r = UB(all(a),x[2]) - a.begin() - 1;
        if( l <= r) update(l,r,0,SZ(a) - 1,x[0] + 1,1),printx();
    }
    ans = 0; query(0,SZ(a)-1,1);
    return ans;
}	

// 并查集
struct DSU{
	VI f,sz;
	DSU(int n):f(n),sz(n, 1) {iota(all(f),0);}
	int find(int x){ 
		while(x!=f[x]) x = f[x] = f[f[x]]; 
		return x;
	}
	bool conn(int x,int y){
		return find(x) == find(y);
	}
	bool merge(int x,int y){
		x = find(x), y = find(y);
		if(x == y) return false;
		sz[x] += sz[y];
		f[y] = x;
		return true;
	}
	int size(int x){return sz[find(x)];}
};

int getNumber(TreeNode* root, vector<vector<int>>& ops){
	VI a;
	auto dfs = [&] (auto self, auto t){
		if(!t) return;
		self(self, t->left);
		a.PB(t->val);
		self(self, t->right);
	};
	dfs(dfs, root);
	int n = a.size();

	DSU g(n + 1);
	int ans = 0;
	reverse(ops.begin(),ops.end());
	// [0,3,5]
	// [1,1,3]
	// [1,2,4]
	for(auto v:ops){
		int t = v[0];
		int l = LB(a.begin(),a.end(),v[1]) - a.begin(), r = LB(a.begin(),a.end(),v[2]) - a.begin() + 1;
		printf("%d %d\n",l, r);
		for(int i = g.find(l);i < r;i = g.find(i)){
			g.merge(i + 1,i);
			if(t) ans++;
		}
	}
	return ans;
}

// mySegmentTree
const int N = 100010;
int a

int main(){
	return 0;
}