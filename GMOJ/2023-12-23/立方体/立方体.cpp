/**
 * @file 立方体.cpp 
 * @tag: #GMOJ #大模拟 #最短路
 * @author: ZnPdCo
 * @date: 2023-12-23 16:02:14
 * @problem: https://gmoj.net/senior/#main/show/4628
 **/
#include <cstdio>
#include <queue>
#define ll long long
#define F 1
#define B 2
#define U 3
#define D 4
#define L 5
#define R 6
#define FU 1
#define FD 2
#define FL 3
#define FR 4
#define BU 5
#define BD 6
#define BL 7
#define BR 8
#define UF 9
#define UB 10
#define UL 11
#define UR 12
#define DF 13
#define DB 14
#define DL 15
#define DR 16
#define LF 17
#define LB 18
#define LU 19
#define LD 20
#define RF 21
#define RB 22
#define RU 23
#define RD 24
using namespace std;

struct node {
	ll up;
	ll down;
	ll left;
	ll right;
	ll me;
	bool flag;
	node(ll u=0, ll d=0, ll l=0, ll r=0, ll m=0) {
		up = u;
		down = d;
		left = l;
		right = r;
		me = m;
		flag = true;
	}
} a[10][10];

ll num[10];





char st[10], ed[10];

ll stx, sty, edx, edy; // 定义，x、i是行，y、j是列

ll zip(ll x, ll y, ll s) {
	return s * 100 + y * 10 + x;
}


ll head[100000];
ll nxt[200000];
ll cost[200000];
ll to[200000], cnt;

ll dis[200000];
ll vis[200000];

void addEdge(ll u, ll v, ll w) {
	++cnt;
	to[cnt] = v;
	cost[cnt] = w;
	nxt[cnt] = head[u];
	head[u] = cnt;
}
void unzip(ll s) {
//	printf("x : %lld ; y : %lld ; s : %lld ; dis : %lld\n", s % 10, s % 100 / 10, s / 100, dis[s]);
}

ll fun(ll x) {
	switch (x) {
	case FU:
	case BU:
	case LU:
	case RU:
		return U;
		break;
	case FD:
	case BD:
	case LD:
	case RD:
		return D;
		break;
	case UF:
	case DF:
	case LF:
	case RF:
		return F;
		break;
	case UB:
	case DB:
	case LB:
	case RB:
		return B;
		break;
	case UL:
	case DL:
	case FL:
	case BL:
		return L;
		break;
	case UR:
	case DR:
	case FR:
	case BR:
		return R;
		break;
	}
}
priority_queue<pair<ll, ll> > que;
int main() {
	scanf("%s %s", st, ed);
	stx = st[1]-'1';
	sty = st[0]-'a';
	edx = ed[1]-'1';
	edy = ed[0]-'a';
	scanf("%lld", &num[F]);
	scanf("%lld", &num[B]);
	scanf("%lld", &num[U]);
	scanf("%lld", &num[R]);
	scanf("%lld", &num[D]);
	scanf("%lld", &num[L]);
	for(ll i = 1; i <= 6; i++) {
		for(ll j = 1; j <= 6; j++) {
			a[i][j].flag = false;
		}
	}
	
	// wdf??!
	a[F][U] = node(UB, DF, FR, FL, FU);
	a[F][D] = node(DB, UF, FL, FR, FD);
	a[F][L] = node(LB, RF, FU, FD, FL);
	a[F][R] = node(RB, LF, FD, FU, FR);
	
	a[B][U] = node(UF, DB, BL, BR, BU);
	a[B][D] = node(DF, UB, BR, BL, BD);
	a[B][L] = node(LF, RB, BD, BU, BL);
	a[B][R] = node(RF, LB, BU, BD, BR);
	
	a[U][F] = node(FD, BU, UL, UR, UF);
	a[U][B] = node(BD, FU, UR, UL, UB);
	a[U][L] = node(LD, RU, UB, UF, UL);
	a[U][R] = node(RD, LU, UF, UB, UR);
	
	a[D][F] = node(FU, BD, DR, DL, DF);
	a[D][B] = node(BU, FD, DL, DR, DB);
	a[D][L] = node(LU, RD, DF, DB, DL);
	a[D][R] = node(RU, LD, DB, DF, DR);
	
	a[L][F] = node(FR, BL, LD, LU, LF);
	a[L][B] = node(BR, FL, LU, LD, LB);
	a[L][U] = node(UR, DL, LF, LB, LU);
	a[L][D] = node(DR, UL, LB, LF, LD);
	
	a[R][F] = node(FL, BR, RU, RD, RF);
	a[R][B] = node(BL, FR, RD, RU, RB);
	a[R][U] = node(UL, DR, RB, RF, RU);
	a[R][D] = node(DL, UR, RF, RB, RD);
	
	for(ll i = 0; i < 8; i++) {
		for(ll j = 0; j < 8; j++) {
			for(ll d = 1; d <= 6; d++) {	// 前面颜色
				for(ll k = 1; k <= 6; k++) {	// 底面颜色
					if(a[d][k].flag) {
						if(i+1 < 8) addEdge(zip(i, j, a[d][k].me), zip(i+1, j, a[d][k].up), num[fun(a[d][k].up)]);
						if(i-1 >= 0) addEdge(zip(i, j, a[d][k].me), zip(i-1, j, a[d][k].down), num[fun(a[d][k].down)]);
						if(j+1 < 8) addEdge(zip(i, j, a[d][k].me), zip(i, j+1, a[d][k].right), num[fun(a[d][k].right)]);
						if(j-1 >= 0) addEdge(zip(i, j, a[d][k].me), zip(i, j-1, a[d][k].left), num[fun(a[d][k].left)]);
					}
				}
			}
		}
	}
	
	for(ll i = 0; i <= 200000; i++) dis[i] = 1e15;
	dis[zip(stx, sty, FD)] = num[D];
	que.push(make_pair(-num[D], zip(stx, sty, FD)));
	while(!que.empty()) {
		ll u = que.top().second;
		unzip(u);
		que.pop();
		if(vis[u]) continue;
		vis[u] = 1;
		for(ll i = head[u]; i; i = nxt[i]) {
			ll v = to[i];
			if(!vis[v]) {
				if(dis[v] > dis[u] + cost[i]) {
					dis[v] = dis[u] + cost[i];
					unzip(v);
					que.push(make_pair(-dis[v], v));
				}
			}
		}
	}
	ll ans = 1e15;
	for(ll i = 1; i <= 24; i++) {
		if(dis[zip(edx, edy, i)] < ans) {
			ans = dis[zip(edx, edy, i)];
		}
	}
	printf("%lld", ans);
}
