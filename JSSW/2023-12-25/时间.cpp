/**
 * @file 时间.cpp 
 * @tag: #JSSW#模拟 
 * @author: ZnPdCo
 * @date: 2023-12-25 13:21:53
 * @problem: https://jsswoj.com/oj/#main/show/2970
 **/
#include<cstdio>
#define ll long long
char s[100];
ll h, m;
int main() {
	scanf("%s", s+1);
	h = (s[1]-'0')*10+(s[2]-'0');
	m = (s[4]-'0')*10+(s[5]-'0');
	m += 30;
	h += 3;
	if(m >= 60) {
		h += m/60;
		m %= 60;
	}
	if(h >= 24) {
		h %= 24;
	}
	printf("%02lld:%02lld", h, m);
	return 0;
} 
