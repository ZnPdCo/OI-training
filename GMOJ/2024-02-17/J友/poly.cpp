#include <cstdio>
#include <string>
#include <iostream>
#include <algorithm>
#include <map>
using namespace std;
#define ll long long 
ll n, p, x, y, ans;
const ll dx[4] = {0, 1, 0, -1};
const ll dy[4] = {1, 0, -1, 0};

ll his[10000][2];
string history;
map<string, int> m;

void dfs(ll a, ll b, ll c) {
	if(c > n) {
		if(a == x && b == y) {
			ans++;
			string tmp = history;
			sort(tmp.begin(), tmp.end());
			if(m.find(tmp) == m.end()) m[tmp] = 1;
			else m[tmp] = m[tmp]+1;
//			cout << tmp << endl;
//			for(int i = 1; i < c; i++) {
//				printf("(%lld,%lld)->", his[i][0], his[i][1]);
//			}
//			printf("\b\b  \n");
		}
		return;
	}
	
	for(int i = 0; i < 4; i++) {
		ll xx = a + dx[i];
		ll yy = b + dy[i];
		his[c][0] = xx;
		his[c][1] = yy;
		history.push_back(i+'0');
		dfs(xx, yy, c+1);
		history.pop_back();
	}
}
int main() {
	scanf("%lld %lld %lld %lld", &n, &p, &x, &y);
	dfs(0, 0, 1);
	printf("%lld\n", ans);
	for(auto it : m) {
		cout << it.first << ' ' << it.second << endl;
	}
}
