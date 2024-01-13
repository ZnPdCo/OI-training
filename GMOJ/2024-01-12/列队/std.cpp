//考虑用n+1个线段树来维护，每行前m-1个人一个，最后一列一个 
//维护时并不进行移动，只是将某一个重新插入到队尾 
//用vector维护的其实是虚拟的 
#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
#define N 300005
#define M 12000005
#define int long long
using namespace std;
int n,m,q,x,y,lim,tot,pos;
vector<int> v[N];
int rt[N],ls[M],rs[M],sm[M];
//rt 根节点    ls 左儿子
//rs 右儿子    sm 该段区间移走了多少人 
inline void re(int &n){
	char ch=getchar();n=0;
	while(ch>'9'||ch<'0') ch=getchar();
	while(ch>='0'&&ch<='9') n=n*10+ch-'0',ch=getchar();
}
inline int query(int x,int l,int r,int p){  //二分查询在线段树中的实际位置 
	if(l==r) return l;
	int mid=(l+r)/2,tmp=mid-l+1-sm[ls[x]];
	if(p<=tmp) return query(ls[x],l,mid,p);//如果它未曾被移走，向左 
	else return query(rs[x],mid+1,r,p-tmp);//移走了，那就向右 
}
inline void update(int &x,int l,int r,int p){  //更新状态，将p所在的所有区间sm增加1 
	if(!x) x=++tot;
	sm[x]++;
	if(l==r) return;
	int mid=(l+r)/2;
	if(p<=mid) update(ls[x],l,mid,p);//二分更新 
	else update(rs[x],mid+1,r,p);
}
inline int work1(int x,int y){  //向前看齐的过程 
	pos=query(rt[n+1],1,lim,x);//找到在线段树中的位置 
	update(rt[n+1],1,lim,pos);
	int ans=pos<=n?pos*m:v[n+1][pos-n-1];//计算编号 
	v[n+1].push_back(y?y:ans);//此处为难点，即如果我在work2中已经找到编号，就直接加入，否则就说明出队的本来就在最后一列，加入计算出的编号 
	return ans;//如果出队的在最后一列，此时ans就是编号，否则就是在向左看齐中被挤入前面线段树那人的编号 
}
inline int work2(int x,int y){  //向左看齐的过程 
	pos=query(rt[x],1,lim,y);  //找到在线段树中的位置 
	update(rt[x],1,lim,pos);
	int ans=pos<m?(x-1)*m+pos:v[x][pos-m];//计算编号 
	v[x].push_back(work1(x,ans));  //因为会将原本在这一行第m个的挤入前m-1个 
	return ans;//返回编号 
}
//注意work1和work2中的y意义不同，work2中的是当前坐标，work1中表示是否已找到编号 
signed main()
{
//	freopen("phalanx.in","r",stdin);
//	freopen("phalanx.out","w",stdout);
	re(n);re(m);re(q);
	lim=max(n,m)+q;
	while(q--){
		re(x);re(y);
		printf("%lld\n",y==m?work1(x,0):work2(x,y));//如果是最后一排，不给y值，然后直接work1 
	}
	return 0;
}
