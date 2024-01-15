#include <iostream>
#include <string>
#include <vector>
using namespace std;

#define rep(i, n) for (int i = 0; i < int(n); i++)

int main() {
	string N;
	cin >> N;
	long long ans = 0;
	for (int s = 1; s <= 9 * 14; s++) {
		vector dp(N.size() + 1, vector(s + 1, vector(s, vector(2, 0LL))));
		dp[0][0][0][1] = 1;
		rep(d, N.size())
			rep(i, s + 1)
				rep(j, s)
					rep(f, 2)
						rep(t, 10) {
			if (i + t > s) continue;
			if (f and N[d] - '0' < t) continue;
			dp[d + 1][i + t][(j * 10 + t) % s][f and N[d] - '0' == t] += dp[d][i][j][f];
		}
		ans += dp[N.size()][s][0][0] + dp[N.size()][s][0][1];
	}
	cout << ans << endl;
}

