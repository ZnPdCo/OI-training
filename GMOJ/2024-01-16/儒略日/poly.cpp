#include <cstdio>
#define ll long long
ll month[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
ll year = -4713;
ll mon = 1;
ll day = 1;
ll run = 1;
int main() {
	freopen("day.csv", "w", stdout);
	for(ll i = 1; i <= 10000000; i++) {
		day++;
		if((year<0 && (year+1)%4==0) || (year > 0 && year%4==0)){
			if(mon != 2) {
				if(day > month[mon]) {
					day = 1;
					mon++;
				}
			} else {
				if(day > 29) {
					day = 1;
					mon++;
				}
			}
		} else {
			if(day > month[mon]) {
				day = 1;
				mon++;
			}
		}
		if(mon > 12) {
			year++;
			if(year == 0) year = 1;
			if((year<0 && (year+1)%4==0) || (year > 0 && year%4==0)) run++;
			
			mon = 1;
		}
//		if(year > -10) {
			printf("%lld,", i);
			printf(",%lld,%lld,%lld\n", year, mon, dayb);
//			printf("%lld\n", year+4713+1);
//		}
	}
}
