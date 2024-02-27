#include<bits/stdc++.h>
using namespace std;
#define LL long long
struct op{int x,y;}a[5000005];int s,d,c[5000005],u[5000005];LL f,a1,a2,b[5000005],l[5000005],ans;
inline char gc(){
	const int BUF=1e6;static char ch[BUF],*l,*r;return(l==r&&(r=(l=ch)+fread(ch,1,BUF,stdin),l==r))?EOF:*l++;
}
template<typename T>inline void read(T &x){
	x=0;int f=1;char c=gc();for(;!isdigit(c);c=gc())if(c=='-')f=-f;for(;isdigit(c);c=gc())x=(x<<1)+(x<<3)+(c^48);
	x*=f;
}
int main(){
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	freopen("pubaba4.in","r",stdin);
	freopen("pubaba.ans","w",stdout);
	read(s),read(d),read(f);for(int g=1;g<=d;g++)read(a[g].x),read(a[g].y),a1+=a[g].x,a2+=a[g].y,b[a[g].x]++,
		u[a[g].y]++;
	if(f<a1||f>a2){cout<<-1;exit(0);}for(int g=1;g<=s;g++)c[g]=b[g],b[g]*=g,l[g]=1ll*u[g]*g;
	for(int g=1;g<=s;g++)b[g]+=b[g-1],c[g]+=c[g-1],u[g]+=u[g-1],l[g]+=l[g-1];
	for(int g=1;g<=s;g++){
		LL kk=b[s]-b[s-g+1]-1ll*(c[s]-c[s-g+1])*(s-g+1);kk=f-kk,kk=min(kk,l[s-g+1]+1ll*(u[s]-u[s-g+1])*(s-g+1)),
		kk/=s-g+1,ans^=kk*g;
		cout << kk << ' ';
	}
	cout<<ans;
	return 0;
}
