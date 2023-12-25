/**
 * @file 石子.cpp 
 * @tag: #JSSW#模拟#思维 
 * @author: ZnPdCo
 * @date: 2023-12-25 13:21:53
 * @problem: https://jsswoj.com/oj/#main/show/2971
 **/
#include <cstdio>
#define ll long long
#define N 1000010
ll n;
ll a[N];
int fun() {
	/*
	 想到一个做法是Alice每次尽量取完偶数（否则Bob会把偶数取为奇数，亏了）
	 否则把奇数取得剩下1（遇到这种情况说明偶数没了，Alice怎么取都会剩下奇数，Bob可以直接拿掉）
	 否则输了
	 然后Bob尽量取偶数（让偶数变成奇数）
	 否则取奇数取完（1Alice取不了）
	 最后取1
	 */
	ll num1=0, numji=0, numou=0;
	for(ll i = 1; i <= n; i++) {
		scanf("%lld", &a[i]);
		if(a[i] == 1) num1++;
		else if(a[i] % 2 == 0) numou++;
		else numji++;
	}
	while(true) {
		// Alice
		if(numou) numou--;
		else if(numji) numji--, num1++;
		else return printf("NO\n") & 0;
		
		
		// Bob
		if(numou) numou--, num1++;
		else if(numji) numji--;
		else if(num1) num1--;
		else return printf("YES\n") & 0;
	}
}
int main() {
	while(scanf("%lld", &n) != EOF) {
		fun();
	}
}
