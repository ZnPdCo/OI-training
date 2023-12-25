/**
 * @file 卡片.cpp 
 * @tag: #JSSW#数论 
 * @author: ZnPdCo
 * @date: 2023-12-25 13:21:53
 * @problem: https://jsswoj.com/oj/#main/show/2972
 **/
#include <cstdio>
#define ll long long
ll gcd(ll a, ll b) {
	if(b == 0) return a;
	return gcd(b, a%b);
}
ll lcm(ll a, ll b) {
	return a*b/gcd(a,b);
}
ll a, m, b, n;
int main() {
	scanf("%lld %lld %lld %lld", &a, &m, &b, &n);
	/*
	 lcm(a,bn)算出重合要走的路程 
	 Alice一次走a长，故为 lcm(a, b*n) / a
	 因为在转角点会多走一步，遇到转角点的路程是 lcm(a, b)
	 然后计算出总共多少次转角点  lcm(a, b*n) / lcm(a, b)
	 对于转角点位置余数不为0的情况都算一遍？不知道对不对 
	 */ 
	printf("%lld", lcm(a, b*n) / a + (lcm(a, b)/b-1) * lcm(a, b*n) / lcm(a, b));
}
