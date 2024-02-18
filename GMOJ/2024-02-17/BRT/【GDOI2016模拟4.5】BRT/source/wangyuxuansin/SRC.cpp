#include <cstring>
#include <cstdio>
#include <algorithm>

using namespace std;

const int MAXN = 1e5 + 5, Inf = 1e9 + 7;
typedef long long LL;

struct Tree {int l, r, Num;} Tr[MAXN * 20];

int N, G, R, M, tot, Close, Root;
LL L, Jud[MAXN], Sum[MAXN], Go[MAXN];

int NewNode() { 
	Tr[++ tot].Num = Inf, Tr[tot].l = 0, Tr[tot].r = 0;
	return tot;
}

void Add(int &x, int l, int r, int Side, int Val) {
	if (!x) x = NewNode();
	if (l == r) {
		Tr[x].Num = min(Val, Tr[x].Num);
		return;
	}
	int Mid = (l + r) >> 1;
	if (Side <= Mid) Add(Tr[x].l, l, Mid, Side, Val); else
		Add(Tr[x].r, Mid + 1, r, Side, Val);
	Tr[x].Num = min(Tr[Tr[x].l].Num, Tr[Tr[x].r].Num);
}

void Query(int x, int l, int r, int lx, int rx) {
	if (!x || lx > rx) return;
	if (l == lx && r == rx) {
		Close = min(Close, Tr[x].Num);
		return;
	}
	int Mid = (l + r) >> 1;
	if (rx <= Mid) Query(Tr[x].l, l, Mid, lx, rx); else
	if (lx > Mid) Query(Tr[x].r, Mid + 1, r, lx, rx); else
		Query(Tr[x].l, l, Mid, lx, Mid), Query(Tr[x].r, Mid + 1, r, Mid + 1, rx);
}

LL Get(LL Dis) {
	return 1ll * (1ll * (Dis / L) + 1ll * (Dis % L != 0)) * L;
}

int main() {
	scanf("%d%d%d", &N, &G, &R);
	L = G + R, Tr[0].Num = Inf;
	for (int i = 1; i <= N + 1; i ++) {
		int Val;
		scanf("%d", &Val);
		Sum[i] = Sum[i - 1] + Val;
		Jud[i] = (Jud[i - 1] + Val) % L;
	}
	Go[N] = Sum[N + 1] - Sum[N];
	Root = NewNode();
	Add(Root, 0, L - 1, Jud[N], N);
	for (int i = N - 1; i > 0; i --) {
		Close = Inf;
		Query(Root, 0, L - 1, G + Jud[i], min(LL(L - 1), L - 1 + Jud[i]));
		Query(Root, 0, L - 1, max(G + Jud[i] - L, LL(0)), LL(Jud[i] - 1));
		Add(Root, 0, L - 1, Jud[i], i);
		Go[i] = (Close == Inf) ? Sum[N + 1] - Sum[i] : Go[Close] + Get(Sum[Close] - Sum[i]);
	}
	scanf("%d", &M);
	for (int i = 1; i <= M; i ++) {
		int Ord; LL Ans;
		scanf("%d", &Ord);
		int Jud = Ord % L;
		Close = Inf;
		Query(Root, 0, L - 1, max(0, G - Jud), L - Jud - 1);
		Query(Root, 0, L - 1, max(L - Jud + 1, L + G - Jud), L - 1);
		Ans = (Close == Inf) ? Sum[N + 1] + Ord : Get(LL(Ord) + Sum[Close]) + Go[Close];
		printf("%lld\n", Ans);
	}
}