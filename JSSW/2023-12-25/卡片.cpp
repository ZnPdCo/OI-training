/**
 * @file ��Ƭ.cpp 
 * @tag: #JSSW#���� 
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
	 lcm(a,bn)����غ�Ҫ�ߵ�·�� 
	 Aliceһ����a������Ϊ lcm(a, b*n) / a
	 ��Ϊ��ת�ǵ�����һ��������ת�ǵ��·���� lcm(a, b)
	 Ȼ�������ܹ����ٴ�ת�ǵ�  lcm(a, b*n) / lcm(a, b)
	 ����ת�ǵ�λ��������Ϊ0��a-1���������һ�飿��֪���Բ��� 
	 */ 
	printf("%lld", lcm(a, b*n) / a + (a-1) * lcm(a, b*n) / lcm(a, b));
}
