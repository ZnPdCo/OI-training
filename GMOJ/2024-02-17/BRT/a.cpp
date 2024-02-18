#include<cstdio>
#include<algorithm>
#define N 100005
struct node{
	int time;
	long long dis,op;
}a[N];
int n,Case;
int fa[N];
long long g,r;
long long dis[N];
int lst[N],nxt[N];
long long read(){
	long long num=0;
	char ch;
	do
		ch=getchar();
	while(ch<48||ch>57);
	do{
		num=(num<<1)+(num<<3)+(ch^48);
		ch=getchar();
	}while(ch>47&&ch<58);
	return num;
}
int find(int x){
	if(fa[x]^x)fa[x]=find(fa[x]);
	return fa[x];
}
bool cmp1(node x,node y){return x.dis<y.dis;}
bool cmp2(node x,node y){return x.time<y.time;}
int main(){
	n=read(),g=read(),r=read();
	for(int i=1;i<=n+1;i++)
		dis[i]=read();
	Case=read();
	for(int i=1;i<=Case;i++){
		a[i].dis=read();
		a[i].op=a[i].dis/(g+r);
		a[i].dis%=(g+r);
		a[i].time=i;
		fa[i]=i;
		lst[i]=i-1,nxt[i]=i+1;
	}
	nxt[0]=1,lst[Case+1]=Case;
	std::stable_sort(a+1,a+1+Case,cmp1);
	for(int i=2;i<=Case;i++){
		if(a[i-1].dis==a[i].dis){
			fa[find(a[i].time)]=find(a[i-1].time);
			nxt[lst[i]]=nxt[i];
			lst[nxt[i]]=lst[i];
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=nxt[0];j<=Case;j=nxt[j]){
			a[j].dis=a[j].dis+dis[i];
			if(a[j].dis%(g+r)>=g)
				a[j].dis=(a[j].dis/(g+r)+1)*(g+r);
			if(a[lst[j]].dis==a[j].dis){
				fa[find(a[j].time)]=find(a[lst[j]].time);
				nxt[lst[j]]=nxt[j];
				lst[nxt[j]]=lst[j];
			}
		}
	}
	std::stable_sort(a+1,a+1+Case,cmp2);
	for(int i=1;i<=Case;i++)
		printf("%lld\n",a[find(i)].dis+a[i].op*(g+r)+dis[n+1]);
	return 0;
}
