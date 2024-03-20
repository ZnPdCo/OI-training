#include <cstdio>
#include <vector>
using namespace std;
#define ll long long
#define N 300010
ll n;
ll p[N];
ll ans[N];
vector<ll> m;
int main() {
	scanf("%lld", &n);
	for(ll i = 1; i <= n; i++) {
		scanf("%lld", &p[i]);
	}
	ans[1] = ans[n] = -1;
	ll big = 0, sml = 0;
	for(ll i = 2; i <= n; i ++) {
		if(p[i] > p[1]) big ++;
		else sml ++;
		if(i % 2 == 1 && big != sml) {
			ans[1] = i;
			break;
		}
	}
	big = 0, sml = 0;
	for(ll i = 2; i <= n; i ++) {
		if(p[n - i + 1] > p[n]) big ++;
		else sml ++;
		if(i % 2 == 1 && big != sml) {
			ans[n] = i;
			break;
		}
	}
	for(ll i = 2; i < n; i++) {
		if(i + 2 <= n && (p[i + 1] > p[i]) == (p[i + 2] > p[i])) ans[i] = 3;
		else if(2 <= i && i + 1 <= n && (p[i + 1] > p[i]) == (p[i - 1] > p[i])) ans[i] = 3;
		else if(3 <= i && (p[i - 1] > p[i]) == (p[i - 2] > p[i])) ans[i] = 3;
		else m.push_back(i);
	}
	for(ll k = 5; k <= n; k += 2) {
		vector<ll> b = m;
		m.clear();
		for(ll i : b) {
			if(i - k + 2 >= 1 && (p[i - k + 2] < p[i]) != (p[i - 1] < p[i])) ans[i] = k;
			else if(i - k + 1 >= 1 && (p[i - k + 1] < p[i]) == (p[i - 1] < p[i])) ans[i] = k;
			else if(i + k - 2 <= n && (p[i + k - 2] < p[i]) != (p[i + 1] < p[i])) ans[i] = k;
			else if(i + k - 1 <= n && (p[i + k - 1] < p[i]) == (p[i + 1] < p[i])) ans[i] = k;
			else m.push_back(i);
		}
	}
	for(ll i : m) {
		ans[i] = -1;
	}
	for(ll i = 1; i <= n; i++) {
		printf("%lld ", ans[i]);
	}
}
