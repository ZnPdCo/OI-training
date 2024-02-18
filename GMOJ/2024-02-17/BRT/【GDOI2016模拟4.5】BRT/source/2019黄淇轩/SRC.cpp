#include<cstdio>
#include<iostream>
#define N 200010
#define INF 0x7fffffff
#define uni unsigned
#define reg register
using namespace std;
uni n,q,g,r,a[N];
uni long long f[N],s[N];
struct ST{
    uni a[N<<4],s[N<<4][2],last;
    void insert(uni m,uni l,uni r,uni x,uni y){
        if(l==r){
            a[m]=min(a[m],y);
            return;
        }
        uni mid=(l+r)>>1;
        if(mid>=x){
            if(!s[m][0]){
                a[s[m][0]=++last]=INF;
            }
            insert(s[m][0],l,mid,x,y);
        }else{
            if(!s[m][1]){
                a[s[m][1]=++last]=INF;
            }
            insert(s[m][1],mid+1,r,x,y);
        }
        a[m]=min(s[m][0]?a[s[m][0]]:INF,s[m][1]?a[s[m][1]]:INF);
    }
    uni smin(uni m,uni l,uni r,uni x,uni y){
        if(x<=l&&r<=y){
            return(a[m]);
        }
        uni mid=(l+r)>>1,re=INF;
        if(mid>=x&&s[m][0]){
            re=smin(s[m][0],l,mid,x,y);
        }
        if(mid<y&&s[m][1]){
            re=min(re,smin(s[m][1],mid+1,r,x,y));
        }
        return(re);
    }
    uni value(uni x,uni y){
        if(x<=y){
            return(smin(0,0,g+r-1,x,y));
        }
        return(min(smin(0,0,g+r-1,0,y),smin(0,0,g+r-1,x,g+r-1)));
    }
}t;
char BuF[1<<26],*InF=BuF;
template<typename T>void read(T &x){
    for(;47>*InF||*InF>58;++InF);
    for(x=0;47<*InF&&*InF<58;x=(x<<3)+(x<<1)+(*InF++^48));
}
int main(){
//    freopen("2.in","r",stdin);
//    freopen("2.out","w",stdout);
    fread(BuF,1,1<<26,stdin);
    read(n);read(g);read(r);
    for(reg uni i=0;i<=n;++i){
        read(a[i]);
        s[i]=a[i]+(i?s[i-1]:0);
    }
    f[n-1]=a[n];
    for(reg uni i=n-2;~i;--i){
        t.insert(0,0,g+r-1,s[i+1]%(g+r),i+1);
        reg uni crash=t.value((g+s[i]%(g+r))%(g+r),(g+r+s[i]%(g+r)-1)%(g+r));
        if(!crash||crash==INF){
            f[i]=s[n]-s[i];
        }else{
            f[i]=f[crash]+s[crash]-s[i]+g+r-(s[crash]-s[i])%(g+r);
        }
    }
    t.insert(0,0,g+r-1,a[0]%(g+r),0);
    for(read(q);q--;){
        reg uni x;
        read(x);
        reg uni long long crash=t.value((g+g+r-x%(g+r))%(g+r),(g+r-x%(g+r)-1)%(g+r)),ans;
        if(crash==INF){
            ans=s[n]+x;
        }else{
            ans=x+f[crash]+s[crash]+g+r-(s[crash]+x)%(g+r);
        }
        printf("%llu\n",ans);
    }
    return(0);
}