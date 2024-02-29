#include<bits/stdc++.h>
using namespace std;
const int N=1e6+5;
int T;
void read(int &x){
	char ch=getchar();x=0;
	while(ch<'0'||ch>'9')ch=getchar();
	while(ch>='0'&&ch<='9')x=(x<<1)+(x<<3)+ch-'0',ch=getchar();
}
int tot,to[N*2],nx[N*2],st[N];
void add(int x,int y){
	to[++tot]=y,nx[tot]=st[x],st[x]=tot;
}
int n,m,A,B,rt;
int fa[N];

void dfs(int x){
	for(int i=st[x];i;i=nx[i]){
		const int &v=to[i];
		if(!fa[v]){
			fa[v]=x;
			dfs(v);
		}
	}
}
void dfs2(int x){
	for(int i=st[x];i;i=nx[i]){
		const int &v=to[i];
		if(!fa[v])fa[v]=x;
	}
	for(int i=st[x];i;i=nx[i]){
		const int &v=to[i];
		if(fa[v]==x)dfs2(v);
	}
}
int _T[30],_t;
void write(int x){
	_t=0;
	if(x==0)putchar('0');
	while(x)_T[++_t]=x%10,x/=10;
	while(_t)putchar('0'+_T[_t--]);
	return;
}
int LAST;
int U[N],V[N];
int c[N];
int get(int x){
	if(fa[x]==x)return x;
	return fa[x]=get(fa[x]);
}
int bz[N];
int sum1,sum2,sum3;
void dfs4(int x){
	sum3++;
	bz[x]=1;
	for(int i=st[x];i;i=nx[i]){
		if(c[(i+1)/2]){
			if(!fa[to[i]])fa[to[i]]=x,dfs4(to[i]);
		}
		else if(bz[to[i]])sum1++;
		else if(!fa[to[i]])sum2++;
	}
	bz[x]=0;
}
int dfs3(int x,int y){
	if(y>n)return 0;
	if(y>n-1&&x>m){
		for(int i=1;i<=n;i++)fa[i]=0;
		fa[rt]=n+1;
		sum1=sum2=sum3=0;
		dfs4(rt);
		if(sum1==A&&sum2==B&&sum3==n){
			for(int i=1;i<=n;i++){
				if(fa[i]==n+1)write(0);
				else write(fa[i]);
				putchar(' ');
			}
			putchar('\n');return 1;
		}
		return 0;
	}
	if(x>m)return 0;
	c[x]=0;
	if(dfs3(x+1,y))return 1;
	c[x]=1;
	if(dfs3(x+1,y+1))return 1;
	c[x]=0;
	return 0;
}
namespace ac{
	int dep[N];
	int num[N];
	vector<int> zu[N];
	int cmp(int x,int y){
		return dep[x]<dep[y];
	}
	void dfs5(int x,int y){
		for(int i=st[x];i;i=nx[i]){
			const int &v=to[i];
			if(!fa[v]){
				dep[v]=dep[x]+1;		
				fa[v]=x;
				dfs5(v,x);
			}
			else if(v!=y)zu[x].push_back(v);
		}
	}
	void run(){
		fa[rt]=n+1;
		for(int i=1;i<=n;i++)zu[i].clear();
		dfs5(rt,0);
		for(int i=1;i<=n;i++)sort(zu[i].begin(),zu[i].end(),cmp),num[i]=i;
		sort(num+1,num+1+n,cmp);
		for(int i=n;i>=1&&B;i--){
			int x=num[i];
			if(!zu[x].size())continue;
			if(zu[x].size()<=B){
				fa[x]=zu[x][0];
				B-=zu[x].size();
			}
			else{
				fa[x]=zu[x][zu[x].size()-B];
				B=0;
			}
		}
		for(int i=1;i<=n;i++){
			if(fa[i]==n+1)write(0);
			else write(fa[i]);
			putchar(' ');
		}
		putchar('\n');
		return ;
	}
}
int main(){
	freopen("ex_flower2.in", "r", stdin);
	freopen("ex_flower2.out", "w", stdout);
//	freopen("a.in","r",stdin);
//	freopen("a.out","w",stdout);
	read(T);
	while(T--){
		for(int i=1;i<=LAST;i++){
			st[i]=0;
			fa[i]=0;
		}
		tot=0;
		read(n),read(m);
		read(A),read(B),read(rt);
		LAST=n;
		for(int i=1;i<=m;i++){
			int u,v;
			U[i]=u,V[i]=v;
			read(u),read(v);
			add(u,v),add(v,u);
		}
		if(B==0){
			fa[rt]=n+1;
			dfs(rt);
			for(int i=1;i<=n;i++){
				if(fa[i]==n+1)write(0);
				else write(fa[i]);
				putchar(' ');
			}
			putchar('\n');
			continue;
		}
		else if(A==0){
			fa[rt]=n+1;
			dfs2(rt);
			for(int i=1;i<=n;i++){
				if(fa[i]==n+1)write(0);
				else write(fa[i]);
				putchar(' ');
			}
			putchar('\n');
			continue;
		}
//		else if(n<=5&&m<=5)dfs3(1,1);
		else
		{
			ac::run();
		}
	}
}
