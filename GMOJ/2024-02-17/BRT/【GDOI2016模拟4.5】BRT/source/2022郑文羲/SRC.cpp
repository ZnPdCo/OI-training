#include<cstdio>
#define N 100005
#define ll long long
#define rui register ui
#define getchar() (p1==p2&&(p2=(p1=buf)+fread(buf,1,1<<21,stdin),p1==p2)?EOF:*p1++)
typedef unsigned ui;
ui T,n,g,r,a[N],flag;
unsigned long long now[N],sum[N];
static char buf[1<<21],*p1=buf,*p2=buf;
template<typename _T>inline void read(_T&x){
	x=0;
	static char ch;
	do ch=getchar();while(ch<48||ch>57);
	while(ch>47&&ch<58)x=(x<<1)+(x<<3)+(ch^48),ch=getchar();
}
static short stk[105],len;
template<typename _T>inline void write(_T x){
	len=0;
	do stk[++len]=x%10,x/=10;while(x);
	while(len)putchar(stk[len--]+48);
	putchar(10);
}
int main(){
	read(n);read(g);read(r);
	for(rui i=1;i<=n+1;++i)read(a[i]);
	read(T);
	while(T--){
		read(now[0]);flag=1;
		for(rui lst,i=1;i<=n;++i){
			now[i]=now[i-1]+a[i];
			lst=now[i]%(g+r);
			if(lst>=g){
				now[i]+=g+r-lst;
				if(sum[i]){
					for(rui j=1;j<i;++j){
						lst=(now[j-1]+a[j])%(g+r);
						if(lst>=g)sum[j]=now[i]+sum[i]-now[j];
					}
					write(now[i]+sum[i]+a[n+1]);
					flag=0;break;
				}
			}
		}
		if(flag){
			for(rui lst,i=1;i<=n;++i){
				lst=(now[i-1]+a[i])%(g+r);
				if(lst>=g)sum[i]=now[n]-now[i];
			}
			write(now[n]+a[n+1]);
		}
	}
	return 0;
}