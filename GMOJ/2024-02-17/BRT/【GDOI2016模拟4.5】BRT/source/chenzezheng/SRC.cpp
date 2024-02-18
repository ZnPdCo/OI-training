#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std ;

#define N 100000 + 10
#define M 5000000 + 10
typedef long long ll ;

int T[M] , Son[M][2] , tot = 1 ;
ll S1[N] , S2[N] , RE[N] ;
int a[N] ;
int n , m , G , R , L , ret ;

void ADD( int v , int l , int r , int x , int c ) {
	if ( l == x && r == x ) {
		T[v] = min( T[v] , c ) ;
		return ;
	}
	int mid = (l + r) / 2 ;
	if ( x <= mid ) {
		if ( !Son[v][0] ) {
			Son[v][0] = ++ tot ;
			T[tot] = 0x7FFFFFFF ;
		}
		ADD( Son[v][0] , l , mid , x , c ) ;
	} else {
		if ( !Son[v][1] ) {
			Son[v][1] = ++ tot ;
			T[tot] = 0x7FFFFFFF ;
		}
		ADD( Son[v][1] , mid + 1 , r , x , c ) ;
	}
	T[v] = min( T[Son[v][0]] , T[Son[v][1]] ) ;
}

void Search( int v , int l , int r , int x , int y ) {
	if ( !v || x > y ) return ;
	if ( l == x && r == y ) {
		ret = min( ret , T[v] ) ;
		return ;
	}
	int mid = (l + r) / 2 ;
	if ( y <= mid ) Search( Son[v][0] , l , mid , x , y ) ;
	else if ( x > mid ) Search( Son[v][1] , mid + 1 , r , x , y ) ;
	else {
		Search( Son[v][0] , l , mid , x , mid ) ;
		Search( Son[v][1] , mid + 1 , r , mid + 1 , y ) ;
	}
}

int main() {
	scanf( "%d%d%d" , &n , &G , &R ) ;
	L = G + R ;
	memset( T , 63 , sizeof(T) ) ;
	for (int i = 1 ; i <= n + 1 ; i ++ ) {
		scanf( "%d" , &a[i] ) ;
		S1[i] = S1[i-1] + a[i] ;
		S2[i] = (S2[i-1] + a[i]) % L ;
	}
	RE[n] = a[n+1] ;
	if ( n ) ADD( 1 , 0 , L - 1 , S2[n] , n ) ;
	for (int i = n - 1 ; i > 0 ; i -- ) {
		ret = 0x7FFFFFFF ;
		Search( 1 , 0 , L - 1 , G + S2[i] , min( L - 1 + S2[i] , (ll) L - 1 ) ) ;
		Search( 1 , 0 , L - 1 , max( G - L + S2[i] , 0ll ) , S2[i] - 1 ) ;
		if ( ret == 0x7FFFFFFF ) {
			RE[i] = S1[n+1] - S1[i] ;
			ADD( 1 , 0 , L - 1 , S2[i] , i ) ;
			continue ;
		}
		ll Dis = S1[ret] - S1[i] ;
		ll Tim = (Dis / L + ( Dis % L != 0 )) * L ;
		RE[i] = RE[ret] + Tim ;
		ADD( 1 , 0 , L - 1 , S2[i] , i ) ;
	}
	scanf( "%d" , &m ) ;
	for (int i = 1 ; i <= m ; i ++ ) {
		int st , rest ;
		scanf( "%d" , &st ) ;
		rest = st % L ;
		ret = 0x7FFFFFFF ;
		Search( 1 , 0 , L - 1 , max( 0 , G - rest ) , L - rest - 1 ) ;
		Search( 1 , 0 , L - 1 , max( L - rest + 1 , L + G - rest ) , L - 1 ) ;
		if ( ret < 0x7FFFFFFF ) {
			ll Dis = st + S1[ret] ;
			ll Tim = (Dis / L + ( Dis % L != 0 )) * L ;
			printf( "%lld\n" , Tim + RE[ret] ) ;
		}
		else printf( "%lld\n" , S1[n+1] + st ) ;
	}
	return 0 ;
}