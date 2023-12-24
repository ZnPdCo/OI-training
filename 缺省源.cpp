/**
 * @file P4590 [TJOI2018] 游园会.cpp 
 * @tag: #洛谷#dp套dp
 * @author: ZnPdCo
 * @date: 2023-12-23 13:55:50
 * @problem: https://www.luogu.com.cn/problem/P4590
 **/
#include<bits/stdc++.h>
#define debug() cout<<"err "<<__LINE__<<endl,exit(0)
#define F(i,s,t) for(ll i=(s);i<=(t);i++)
#define ll long long
#define N 1010 10010 100010 1000010
#define M 
#define P 998244353
using namespace std;
void outt(){}
template<typename Type,typename... Types>
void outt(const Type& x,const Types&... y){
	cout<<x<<' ';
	outt(y...);
}
void inn(){}
template<typename Type,typename... Types>
void inn(Type& x, Types&... y){
	cin>>x;
	inn(y...);
}
ll n, m, Case=1;
ll a[N][M];
char s[N];
void solve();
int main() {
	inn(Case);
	while(Case--) solve();
}
void solve() {
	inn(n, m);
	for(ll i = 1; i <= n; i++) {
		inn(a[i]);
		for(ll j = 1; j <= m; j++) {
			inn(a[i][j]);
		}
	}
	outt();
}
