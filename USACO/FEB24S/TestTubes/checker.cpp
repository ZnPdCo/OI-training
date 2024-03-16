#include <cstdio>
#include <testlib.h>
#define ll long long
#define N 100010
using namespace std;
ll t;
ll s[4][2*N];
ll k[4];
void mov(ll x, ll y) {
	if(k[x] == 0) quitf(_wa, "Not enough!.");
	if(k[x] && k[y] && s[x][k[x]] == s[y][k[y]]) k[x]--;
	else s[y][++k[y]] = s[x][k[x]--];
}
int main(int argc, char *argv[]) {
	registerTestlibCmd(argc, argv);
	t = inf.readLong();
	for(ll _ = 1; _ <= t; _ ++) {
		ll n = inf.readLong(), p = inf.readLong();
		string s1 = inf.readToken(), s2 = inf.readToken();
		k[1] = k[2] = k[3] = 0;
		for(ll i = 0; i < n; i++) {
			if(s1[i] == '1') {
				if(s[1][k[1]] != 1) s[1][++ k[1]] = 1;
			}
			if(s1[i] == '2') {
				if(s[1][k[1]] != 2) s[1][++ k[1]] = 2;
			}
			if(s2[i] == '1') {
				if(s[2][k[2]] != 1) s[2][++ k[2]] = 1;
			}
			if(s2[i] == '2') {
				if(s[2][k[2]] != 2) s[2][++ k[2]] = 2;
			}
		}
		if(p == 1) {
			ll Out = ouf.readLong(), Ans = ans.readLong();
			if(Out != Ans) {
				quitf(_wa, "In test %lld, expected %lld, found %lld.", _, Ans, Out);
			}
		} else if(p == 2) {
			ll Out = ouf.readLong(), Ans = ans.readLong();
			for(ll i = 1; i <= Out; i++) {
				ll x = ouf.readLong(), y = ouf.readLong();
				mov(x, y);
			}
			if(k[1] != 1 || k[2] != 1 || k[3] != 0) {
				quitf(_wa, "Ans wrong.");
			}
			for(ll i = 1; i <= Ans; i++) {
				ll x = ans.readLong(), y = ans.readLong();
			}
		}else if(p == 3) {
			ll Out = ouf.readLong(), Ans = ans.readLong();
			if(Out != Ans) {
				quitf(_wa, "In test %lld, expected %lld, found %lld.", _, Ans, Out);
			}
			for(ll i = 1; i <= Out; i++) {
				ll x = ouf.readLong(), y = ouf.readLong();
				mov(x, y);
			}
			if(k[1] != 1 || k[2] != 1 || k[3] != 0) {
				quitf(_wa, "Ans wrong.");
			}
			for(ll i = 1; i <= Ans; i++) {
				ll x = ans.readLong(), y = ans.readLong();
			}
		}
	}
	quitf(_ok, "All right! owo");
	return 0;
}
