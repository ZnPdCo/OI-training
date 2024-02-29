#include<bits/stdc++.h>
#define ll long long
#define N 500010
using namespace std;
int m,tot,son[N][2],rt,g[N],x,y,z,u,v,cnt;
ll n,f[N],s[N],sum[N],siz[N],val,ans1,ans2,l,r;
mt19937 rnd(time(0));
int newn(){g[++tot]=rnd();return tot;}
void update(int k){siz[k]=siz[son[k][0]]+siz[son[k][1]]+sum[k];}
void split(int k,int &x,int &y,ll val,int id){
	if(val<=siz[son[k][0]]){
		y=k;split(son[k][0],x,son[k][0],val,id);
		update(x);update(y);
	}else if(val<=siz[son[k][0]]+sum[k]){
		if(id==0){
			x=k;y=son[k][1];son[k][1]=0;update(x);
		}else{
			y=k;x=son[k][0];son[k][0]=0;update(y);
		}
	}else{
		x=k;split(son[k][1],son[k][1],y,val-siz[son[k][0]]-sum[k],id);
		update(x);update(y);
	}
}
int merge(int x,int y){
	if(!x||!y)return x+y;
	if(g[x]<g[y]){
		son[x][1]=merge(son[x][1],y);
		update(x);return x;
	}else{
		son[y][0]=merge(x,son[y][0]);
		update(y);return y;
	}
}
int main(){
//	freopen("b.in","r",stdin);
//	freopen("b.out","w",stdout);
	scanf("%d%lld",&m,&n);
	rt=newn();f[rt]=1;s[rt]=1;sum[rt]=siz[rt]=n;
	for(;m>=1;m--){
		scanf("%lld%lld",&l,&r);x=y=z=0;
		split(rt,x,y,l,1);split(y,y,z,1,0);
		val=l-siz[x];ans1=f[y]+(val-1)*s[y];
		u=newn();siz[u]=sum[u]=siz[y]-val+1;s[u]=s[y];f[u]=ans1;
		siz[y]=sum[y]=val-1;
		rt=x;if(siz[y])rt=merge(rt,y);
		if(siz[u])rt=merge(rt,u);rt=merge(rt,z);
		
		x=y=z=0;
		split(rt,x,y,r,1);split(y,y,z,1,0);
		val=r-siz[x];ans2=f[y]+(val-1)*s[y];
		u=newn();siz[u]=sum[u]=siz[y]-val;s[u]=s[y];f[u]=ans2+s[y];
		siz[y]=sum[y]=val;
		rt=x;if(siz[y])rt=merge(rt,y);
		if(siz[u])rt=merge(rt,u);rt=merge(rt,z);
		printf("%lld %lld\n",ans1,ans2);
		
		x=y=z=0;
		split(rt,x,y,l,1);rt=x;cnt=0;
		while(l<=r){z=0;
			split(y,y,z,1,0);
			if(!cnt){
				f[y]=f[y]+s[y];s[y]*=2;l+=siz[y];
				cnt^=(siz[y]&1);siz[y]=sum[y]=siz[y]/2;
				if(siz[y])rt=merge(rt,y);y=z;
			}else{
				s[y]*=2;l+=siz[y];
				cnt^=(siz[y]&1);siz[y]=sum[y]=(siz[y]+1)/2;
				if(siz[y])rt=merge(rt,y);y=z;
			}
		}rt=merge(rt,y);
	}
}
