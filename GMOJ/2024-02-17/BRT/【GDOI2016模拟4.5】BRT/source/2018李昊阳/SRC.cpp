#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
#define N 100005
#define M 100*N
#define ll long long
#define inf 2139062143
int n,q,tot;
ll g,r,R;
ll a[N],sum[N],s1[N],c[N];
struct code{
	int f,g,l,r;
}f[M];
void cmin(int &x,int y){
	x=min(x,y);
	return;
}
void down(int k,int pd){
	if (f[k].g==inf) return;
	cmin(f[k].f,f[k].g);
	if (pd){
		if (!f[k].l){
			f[k].l=++tot;
			f[tot]=f[0];
		}
		cmin(f[f[k].l].g,f[k].g);
		if (!f[k].r){
			f[k].r=++tot;
			f[tot]=f[0];
		}
		cmin(f[f[k].r].g,f[k].g);
	}
	f[k].g=inf;
	return;
}
void change(int k,ll l,ll r,ll x,ll y,int z){
	down(k,l<r);
	if (x<=l && r<=y){
		cmin(f[k].g,z);
		down(k,l<r);
		return;
	}
	int mid=(l+r)/2;	
	if (!(mid<x || y<l)){
		if (!f[k].l){
			f[k].l=++tot;
			f[tot]=f[0];
		}
		change(f[k].l,l,mid,x,y,z);
	}
	if (!(r<x || y<mid+1)){
		if (!f[k].r){
			f[k].r=++tot;
			f[tot]=f[0];
		}
		change(f[k].r,mid+1,r,x,y,z);
	}
	f[k].f=min(f[f[k].l].f,f[f[k].r].f);
	return;
}
int find(int k,ll l,ll r,int x){
	down(k,l<r);
	if (l==r && l==x) return f[k].f;
	ll mid=(l+r)/2;
	if (x<=mid){
		if (!f[k].l) return 0;
		return find(f[k].l,l,mid,x);
	}
	if (!f[k].r) return 0;
	return find(f[k].r,mid+1,r,x);
}
int main(){
	scanf("%d%lld%lld",&n,&g,&r);
	R=g+r,f[0]=(code){inf,inf,0,0};
	for (int i=1;i<=n+1;i++){
		scanf("%lld",&a[i]);
		sum[i]=sum[i-1]+a[i];
		s1[i]=sum[i]%R;
//		printf("%lld ",s1[i]);
	}
//	printf("\n\n");
	if (n>5000){
		tot=1,f[1]=f[0];
		for (int i=n;i>0;i--){
			int stop=find(1,0,R,s1[i]);
			if (stop==inf || !stop) c[i]=sum[n+1]-sum[i];
			else{
				ll dis=sum[stop]-sum[i];
				ll d1=dis%R;
				c[i]=c[stop]+dis+R-d1;
			}
			change(1,0,R,0ll,-g+s1[i]-1ll,i);
			change(1,0,R,s1[i],-g+R+s1[i]-1ll,i);
			change(1,0,R,s1[i]+R,R-1ll,i);
		}
	}
	else{
		for (int j=2;j<=n+1;j++){
			ll s=0;
			for (int i=j;i<=n+1;i++){
				s+=a[i];
				if (i>n) break;
				ll s1=(s+1ll)%R;
				if (1<=s1 && s1<=g) continue;
				s+=R-(s%R);
			}
			c[j-1]=s;
		}
	}
//	for (int i=1;i<=n;i++) printf("%lld\n",c[i]);
//	printf("\n");
//	return 0;
	memset(f,0,sizeof(f));
	f[0]=(code){inf,inf,0,0};
	tot=1,f[1]=f[0];
	for (int i=1;i<=n;i++){
		change(1,0,R,0ll,-s1[i],i);
		change(1,0,R,g-s1[i]+1ll,R-s1[i],i);
		change(1,0,R,R+g-s1[i]+1ll,R-1ll,i);
//		printf("0 %lld\n",1-s1[i]-1);
//		printf("%lld %lld\n",g-s1[i]+1,R+1-s1[i]-1);
//		printf("%lld %lld\n\n",R+g-s1[i]+1,R-1);
	}
	scanf("%d",&q);
	while (q--){
		ll x=0,ans=0;
		scanf("%lld",&x);
		ll x1=(x+1)%R;
		int stop=find(1,0,R,x1);
		if (stop==inf || !stop) ans=sum[n+1]+x;
		else ans=sum[stop]+(R-((s1[stop]+x1-1+R)%R))+c[stop]+x;
//		printf("stop at %d  ",stop);
//		printf("ans=");
		printf("%lld\n",ans);
	}
	return 0;
}