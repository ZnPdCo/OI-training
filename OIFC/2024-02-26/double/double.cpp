#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll N = 2000010;
inline char gc();
template <typename T> inline void read(T &x);
template <typename T, const T p> class modint {
private:
	T v;
public:
	modint() {v = 0;}
	modint(const T &x) {v = x % p;}
	modint operator+(const modint& a) const {return v + a.v >= p ? v + a.v - p : v + a.v;}
	modint operator-(const modint& a) const {return v - a.v < 0 ? v - a.v + p: v - a.v;}
	modint operator*(const modint& a) const {return (1ll * v * a.v % p + p) % p;}
	T operator()(void) const {return v;}
};
using modll = modint<ll, 998244353>;
ll n, m;
bool havem;
struct node {
	ll x, y, c;
} a[N];
struct result {
	modll all, nol, nor;
	ll to;
};
result fun(ll x) {
	modll all_ = 1, nol_ = 1, nor_ = 1, nolr_ = 1;
	vector<result> res;
	result ans;
	ll i = x + 1;
	for(; i <= m && a[i].y <= a[x].y;) {
		result r = fun(i);
		res.push_back(r);
		i = r.to;
	}
	ans.to = i;
	if(res.empty()) {
		ans.all = a[x].c * (a[x].c - 1);
		ans.nol = a[x].c;
		ans.nor = a[x].c;
		return ans;
	}
	for(ll i = 0; i < (ll)res.size(); i++) {
		all_ = all_ * res[i].all; 
		
		if(i == 0) nol_ = nol_ * res[i].nol; 
		else nol_ = nol_ * res[i].all; 
		
		if(i == (ll)res.size() - 1) nor_ = nor_ * res[i].nor; 
		else nor_ = nor_ * res[i].all; 
		
		if(i == 0) nolr_ = nolr_ * res[i].nol; 
		else if(i == (ll)res.size() - 1) nolr_ = nolr_ * res[i].nor; 
		else nolr_ = nolr_ * res[i].all; 
	}
	
	ans.all = all_ + (nol_ + nor_) * a[x].c + nolr_ * a[x].c * (a[x].c - 1);
	ans.nol = nol_ + nolr_ * a[x].c;
	ans.nor = nor_ + nolr_ * a[x].c;
	return ans;
}
int main() {
	freopen("double.in", "r", stdin);
	freopen("double.out", "w", stdout);
	read(n), read(m);
	for(ll i = 1; i <= m; i ++) {
		read(a[i].x), read(a[i].y), read(a[i].c);
		if(a[i].x == 1 && a[i].y == n) havem = 1;
	}
	if(!havem) a[++m].x = 1, a[m].y = n, a[m].c = 0;
	sort(a+1, a+1+m, [](const auto &x, const auto &y) {
		if(x.x != y.x) return x.x < y.x;
		return x.y > y.y;
	});
	printf("%lld", fun(1).all());
	return 0;
}





inline char gc() {
	const int BUF = 1e6;
	static char ch[BUF], *l, *r;
	return (l == r && (r = (l = ch) + fread(ch, 1, BUF, stdin), l == r)) ? EOF : *l++;
}
template <typename T> inline void read(T &x) {
	x = 0; int f = 1; char c = gc();
	for (; !isdigit(c); c = gc()) if (c == '-') f = -f;
	for (; isdigit(c); c = gc()) x = (x << 1) + (x << 3) + (c ^ 48);
	x *= f;
}

