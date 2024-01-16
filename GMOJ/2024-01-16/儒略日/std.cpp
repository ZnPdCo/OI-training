#include<bits/stdc++.h>

using namespace std;
typedef long long ll;

inline int read(){
	int x=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9')x=(x<<3)+(x<<1)+ch-'0',ch=getchar();
	return x*f;
}
inline ll readll(){
	ll x=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9')x=(x<<3)+(x<<1)+ch-'0',ch=getchar();
	return x*f;
}

const int dom[]={0,31,28,31,30,31,30,31,31,30,31,30,31};
int y=-4737,m=1,d=1;
int isRUN(int y){
	if(y<=0){
		y=-y;
		return y%4==1;
	}
	if(y<=1582)return y%4==0;
	return (y%400==0)||((y%4==0)&&(y%100!=0));
}
void getnxtday(){
	d++;
	if(y==1582&&m==10&&d==5)d=15;
	if(d>dom[m]+(m==2&&isRUN(y)))m++,d=1;
	if(m>12)y++,m=1;
}
ll checkday(int x){
	ll day=1ll*(x+4712)*365;
	if(x>1582)day-=10;
	day+=1ll*(x+4712+3)/4;
	if(x>=1600){
		x-=1601;
		day-=(ll)x/100ll;
		day+=(ll)x/400ll;
	}
	return day;
}
int main(){
	int T;
	T=read(); 
	while(T--){
		y=0;m=d=1;
		ll n=readll();
		int l=-4712,r=1e9+1;
		while(l<=r){
			int mid=(l+r)/2;
			if(checkday(mid)<=n){
				y=mid;
				l=mid+1;
			}else r=mid-1;
		}
		n-=checkday(y);
		if(y<=0)y--;
		while(n--)getnxtday();
		printf("%d %d ",d,m);
		if(y<=0)printf("%d BC\n",-y);
		else printf("%d\n",y);
	}
	return 0;
}

