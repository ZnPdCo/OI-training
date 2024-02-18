#include<bits/stdc++.h>
using namespace std;
#define ll long long 
const int N=1e6+2;
ll a[N],n,q,s[N],g,r;
ll f[N];
ll qr[N],h[N];
struct qujian{
    ll l1,r1,l2,r2;
}b[N];
unordered_map<ll,int>mp;
ll lsh[N<<2];
ll dy[N<<2];
int tr[N<<2],laz[N<<2];
#define ls v<<1
#define rs v<<1|1
inline void psd(int v){
    if(!laz[v])return ;
    laz[ls]=laz[v],tr[ls]=laz[v];
    laz[rs]=laz[v],tr[rs]=laz[v];
    laz[v]=0;
}
inline void modif(int v,int l,int r,int L,int R,int k){
    // printf("%d %d %d %d %d %d %d\n",v,l,r,L,R,k,type);
    if(L<1)return ;
    if(l>=L&&r<=R){
        tr[v]=k,laz[v]=k;
        return ;
    }
    int mid=l+r>>1;
    psd(v);
    if(R<=mid)modif(ls,l,mid,L,R,k);
    else if(L>mid)modif(rs,mid+1,r,L,R,k);
    else if(L<=mid&&R>mid)modif(ls,l,mid,L,mid,k),modif(rs,mid+1,r,mid+1,R,k);
    tr[v]=max(tr[ls],tr[rs]);
}
inline ll ask(int v,int l,int r,int p){
    // printf("%d %d %d %d\n",v,l,r,p);
    if(l==r)return tr[v];
    psd(v);
    int mid=l+r>>1;
    if(p<=mid)return ask(v<<1,l,mid,p);
    else return ask(v<<1|1,mid+1,r,p);
}
inline void clear(){
    for(int i=1;i<=2e6;++i)tr[i]=laz[i]=0;
}
int main(){
    scanf("%lld%lld%lld",&n,&g,&r);
    for(int i=1;i<=n+1;++i)scanf("%lld",&a[i]),s[i]=s[i-1]+a[i];
    scanf("%lld",&q);
    int d=g+r;
    for(int i=1;i<=q;++i)scanf("%lld",&qr[i]),h[i]=qr[i],qr[i]=qr[i]%d;
    int tot=n;
    for(int i=1;i<=n;++i){
        ll p=s[i]%d;
        if(g>=p)b[i]={g-p,d-p-1,-1,-1};
        else b[i]={0,d-p,g+d-p,d-1};
    }
    int cnt=0;
    for(int i=1;i<=tot;++i)lsh[++cnt]=b[i].l1,lsh[++cnt]=b[i].r1,lsh[++cnt]=b[i].l2,lsh[++cnt]=b[i].r2,lsh[++cnt]=(d-(s[i]%d))%d;
    for(int i=1;i<=q;++i)lsh[++cnt]=qr[i];
    sort(lsh+1,lsh+1+cnt);
    int xd=-1;
    for(int i=1;i<=cnt;++i)if(lsh[i]!=lsh[i-1])mp[lsh[i]]=++xd,dy[xd]=lsh[i];
    // for(int i=1;i<=cnt;++i)printf("%d %d\n",lsh[i],mp[lsh[i]]);
    for(int i=1;i<=n;++i)b[i].l1=mp[b[i].l1],b[i].r1=mp[b[i].r1],b[i].l2=mp[b[i].l2],b[i].r2=mp[b[i].r2];
    for(int i=1;i<=q;++i)qr[i]=mp[qr[i]];
    modif(1,1,xd,1,xd,n+1);
    for(int i=n;i;--i){
        ll gf=mp[(d-(s[i]%d))%d];
        int j=ask(1,1,xd,gf);
        f[i]=f[j]+s[j]-s[i];
        if(j!=n+1)f[i]=f[i]+(d-(s[j]-s[i])%d)%d;
        modif(1,1,xd,b[i].l1,b[i].r1,i);
        modif(1,1,xd,b[i].l2,b[i].r2,i);
        // printf("##%d %d %d %d\n",i,j,(d-(s[i]%d))%d,mp[(d-(s[i]%d))%d]);
        // printf("$$%lld %lld %lld %lld %lld\n",s[i]%d,dy[b[i].l1],dy[b[i].r1],dy[b[i].l2],dy[b[i].r2]);
        // printf("^^%lld %lld %lld %lld\n",b[i].l1,b[i].r1,b[i].l2,b[i].r2);
    }
    // for(int i=1;i<=n;++i)printf("%d %lld\n",i,f[i]);
    for(int i=1;i<=q;++i){
        int j=ask(1,1,xd,qr[i]);
        // printf("%lld %lld %lld\n",f[j],s[j],h[i]);
        ll hj=s[j]+h[i];
        ll gj=hj%d;
        if(j!=n+1){
            if(gj)hj=hj-gj+d;
            // printf("%d\n",i);
        }
        // printf("%d %d %d %lld %lld\n",i,j,f[j],hj,gj);
        printf("%lld\n",f[j]+hj);
    }
    return 0;
}