/**
 * @file 儒略日.cpp 
 * @tag: #GMOJ#大模拟
 * @author: ZnPdCo
 * @date: 2024-01-16 19:53:25
 * @problem: https://gmoj.net/senior/#main/show/6855
 **/
#include <cstdio>
#include <cmath>
#define ll long long
ll month[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
struct Date {
	ll y, m, d;
	void next() {
		d++;
		if((y <= 1582 && y % 4 == 0) || (y > 1582 && y % 4 == 0 && (y % 100 !=0 || y % 400 == 0))){
			if(m != 2) {
				if(d > month[m]) {
					d = 1;
					m++;
				}
			} else {
				if(d > 29) {
					d = 1;
					m++;
				}
			}
		} else {
			if(d > month[m]) {
				d = 1;
				m++;
			}
		}
		if(m > 12) {
			y++;
			m = 1;
		}
		if(y == 1582 && m == 10 && d == 5) d = 15;
	}
	void show() {
		printf("%lld %lld ", d, m);
		if(y <= 0) printf("%lld BC\n", -y+1);
		else printf("%lld\n", y);
	}
};
ll GetRun(ll year) {
	// 计算经过了多少个闰年
	
	ll res = (year + 4712 + 3) / 4;
	
	if(year >= 1600) {
		res += (year - 1600 + 399) / 400 - (year - 1600 + 99) / 100;
	}	
	
	return res;
}
inline ll GetDay(ll year) {
	// 计算经过了多少天
	ll day = 365 * (year + 4712) + GetRun(year);
	if(year > 1582) day -= 10;
	return day;
}
int main() {
	freopen("julian.in", "r", stdin);
	freopen("julian.out", "w", stdout);
	ll q;
	scanf("%lld", &q);
	while(q--) {
		ll d;
		scanf("%lld", &d);
		
		ll l = -4712, r = 1e9+1;
		Date ans;
		while(l <= r) {
			ll mid = (l+r)>>1;
			if(GetDay(mid) <= d) {
				l = mid+1;
				ans.y = mid;
			} else {
				r = mid-1;
			}
		}
		
		d -= GetDay(ans.y);
		
		ans.m = ans.d = 1;
		
		while(d--) ans.next();
		
		ans.show();
	}
}
