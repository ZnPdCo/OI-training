#include <bits/stdc++.h>
//#define int long long
typedef long long ll;
using namespace std;
namespace Mine{
	inline int read(){
		int x=1,a=0;
		char ch=getchar();
		while(ch>'9' || ch<'0')x=(ch=='-')?-1:x,ch=getchar();
		while(ch>='0' && ch<='9')
			a=(a<<1)+(a<<3)+(ch-'0'),ch=getchar();
		return a*x;
	}
	const int N=4e5+100,M=4*N,inf=0x3f3f3f3f;
	int he_tree[N],he_all[N],nxt[M],e[M];
	int idx;
	void add(int he[],int a,int b){
		e[++idx]=b;
		nxt[idx]=he[a];
		he[a]=idx;
		return ;
	}
	int n,t,col[N];
	struct node{
		int l,r;
		int mx,num,add;
	} tr[N<<2];
	void push_up(int u){
		tr[u].mx=max(tr[u<<1].mx,tr[u<<1|1].mx);
		tr[u].num=0;
		if(tr[u<<1].mx==tr[u].mx)
			tr[u].num+=tr[u<<1].num;
		if(tr[u<<1|1].mx==tr[u].mx)
			tr[u].num+=tr[u<<1|1].num;
		return ;
	}
	void apply(int u,int x){
		// cout<<x<<endl;
		tr[u].add+=x;
		tr[u].mx+=x;
		return ;
	}
	void push_down(int u){
		if(tr[u].add){
			apply(u<<1,tr[u].add);
			apply(u<<1|1,tr[u].add);
			tr[u].add=0;
		}
		return ;
	}
	int a[N];
	void build(int u,int l,int r){
		auto &t=tr[u];
		t.l=l,t.r=r;
		t.add=0;
		if(l==r){
			// t={l,r,a[l],1,0};
			t.num=1;
			t.mx=a[l];
			return ;
		}
		int mid=(l+r)>>1;
		build(u<<1,l,mid);
		build(u<<1|1,mid+1,r);
		push_up(u);
	}
	void change(int u,int l,int r,int add){
		//		cout<<u<<endl;
		auto &t=tr[u];
		if(l<=t.l && t.r<=r){
			apply(u,add);
			return ;
		}
		push_down(u);
		int mid=(t.l+t.r)>>1;
		if(l<=mid) change(u<<1,l,r,add);
		if(mid<r) change(u<<1|1,l,r,add);
		push_up(u);
		return ;
	}
	int tot;
	void init(){
		memset(he_all,0,sizeof he_all);
		memset(he_tree,0,sizeof he_tree);
		idx=tot=0;
		return ;
	}
	int dfn[N],last[N],dist[N],rk[N],d[N];
	void dfs_1(int u){
		dfn[u]=last[u]=++tot;
		rk[tot]=u;
		// cout<<u<<endl;
		for(int it=he_tree[u];it;it=nxt[it]){
			int to=e[it];
			dfs_1(to);
			last[u]=max(last[u],last[to]);
		}
		//		cout<<u<<" "<<dfn[u]<<" "<<last[u]<<endl;
		return ;
	}
	int q[N];
	void get_dist(int u){
		int hh=1,tt=0;
		q[++tt]=u;
		memset(dist,-1,sizeof dist);
		dist[u]=0;
		while(hh<=tt){
			int u=q[hh++];
			// cout<<u<<" "<<dist[u]<<endl;
			for(int it=he_all[u];it;it=nxt[it]){
				int to=e[it];
				if(dist[to]==-1){
					dist[to]=dist[u]+1;
					q[++tt]=to;
				}
			}
		}
	}
	void get_d(int u,int dep){
		if(col[u]==0){
			d[u]=tr[1].mx+dep;
		}
		for(int it=he_tree[u];it;it=nxt[it]){
			int to=e[it];
			change(1,dfn[to],last[to],-2);
			get_d(to,dep+1);
			change(1,dfn[to],last[to],2);
		}
		return ;
	}
	void add_sq(int l,int r,int add){
		if(l>r)
			return ;
		if(l<=0){
			l+=t;
			change(1,dfn[l],last[t],add);
			if(r>0)
				change(1,dfn[1],last[r],add);
			return ;
		}
		if(r>t){
			r-=t;
			change(1,dfn[1],last[r],add);
			if(l<=t)
				change(1,dfn[l],last[t],add);
			return ;
		}
		change(1,dfn[l],last[r],add);
		return ;
	}
	int res[N];
	void get_res(int u,int dep){
		if(col[u]==1){
			if(tr[1].mx+dep==0){
				res[u]=tr[1].num;
			}
			else{
				res[u]=-inf;
			}
		}
		for(int it=he_tree[u];it;it=nxt[it]){
			int to=e[it];
			change(1,dfn[to],last[to],-2);
			get_res(to,dep+1);
			change(1,dfn[to],last[to],2);
		}
		return ;
	}
	void solve(){
		init();
		n=read(),t=read();
		for(int i=t+1;i<=n;i++){
			int fa=read();
			add(he_tree,fa,i);
			add(he_all,fa,i);
			add(he_all,i,fa);
		}
		for(int i=1;i<=t;++i){
			add(he_all,i,i==1?t:i-1);
			add(he_all,i,i==t?1:i+1);
		}
		for(int i=1;i<=n;i++){
			col[i]=read();
		}
		for(int i=1;i<=t;i++){
			dfs_1(i);
		}
		get_dist(1);
		//		cout<<last[1]<<endl;
		for(int i=1;i<=n;i++){
			if(col[i]==1){
				a[dfn[i]]=dist[i];
			}
			else a[dfn[i]]=-inf;
		}
		build(1,1,n);
		for(int i=1;i<=t;i++){
			get_d(i,0);
			add_sq(i-t/2+1,i,1);
			add_sq(i+1,i+t/2,-1);
		}
		for(int i=1;i<=n;i++){
			if(col[i]==0){
				a[dfn[i]]=dist[i]-d[i];
			}
			else{
				a[dfn[i]]=-inf;
			}
		}
		build(1,1,n);
		for(int i=1;i<=t;i++){
			get_res(i,0);
			add_sq(i-t/2+1,i,1);
			add_sq(i+1,i+t/2,-1);
		}
		int ans=0;
		for(int i=1;i<=n;i++){
			if(col[i]==1){
				ans=max(ans,res[i]);
			}
		}
		printf("%d\n",ans);
		return ;
	}
	// signed main(){
	// n=read();
	// for(int i=1;i<=n;i++){
	// a[i]=read();	
	// }
	// build(1,1,n);
	// int q=read();
	// while(q--){
	// int l=read(),r=read(),add=read();
	// change(1,l,r,add);
	// cout<<tr[1].mx<<" "<<tr[1].num<<endl;
	// }
	// return 0;
	// }
	signed main(){
		int T=read();
		while(T--){
			solve();
		}
		return 0;
	}
}
signed main(){
	freopen("tree.in","r",stdin);
	freopen("tree.out","w",stdout);
	return Mine::main();
}
