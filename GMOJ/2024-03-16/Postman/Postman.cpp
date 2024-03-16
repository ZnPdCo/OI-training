#pragma GCC optimize(3)
#pragma GCC target("avx")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("inline")
#pragma GCC optimize("-fgcse")
#pragma GCC optimize("-fgcse-lm")
#pragma GCC optimize("-fipa-sra")
#pragma GCC optimize("-ftree-pre")
#pragma GCC optimize("-ftree-vrp")
#pragma GCC optimize("-fpeephole2")
#pragma GCC optimize("-ffast-math")
#pragma GCC optimize("-fsched-spec")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("-falign-jumps")
#pragma GCC optimize("-falign-loops")
#pragma GCC optimize("-falign-labels")
#pragma GCC optimize("-fdevirtualize")
#pragma GCC optimize("-fcaller-saves")
#pragma GCC optimize("-fcrossjumping")
#pragma GCC optimize("-fthread-jumps")
#pragma GCC optimize("-funroll-loops")
#pragma GCC optimize("-fwhole-program")
#pragma GCC optimize("-freorder-blocks")
#pragma GCC optimize("-fschedule-insns")
#pragma GCC optimize("inline-functions")
#pragma GCC optimize("-ftree-tail-merge")
#pragma GCC optimize("-fschedule-insns2")
#pragma GCC optimize("-fstrict-aliasing")
#pragma GCC optimize("-fstrict-overflow")
#pragma GCC optimize("-falign-functions")
#pragma GCC optimize("-fcse-skip-blocks")
#pragma GCC optimize("-fcse-follow-jumps")
#pragma GCC optimize("-fsched-interblock")
#pragma GCC optimize("-fpartial-inlining")
#pragma GCC optimize("no-stack-protector")
#pragma GCC optimize("-freorder-functions")
#pragma GCC optimize("-findirect-inlining")
#pragma GCC optimize("-fhoist-adjacent-loads")
#pragma GCC optimize("-frerun-cse-after-loop")
#pragma GCC optimize("inline-small-functions")
#pragma GCC optimize("-finline-small-functions")
#pragma GCC optimize("-ftree-switch-conversion")
#pragma GCC optimize("-foptimize-sibling-calls")
#pragma GCC optimize("-fexpensive-optimizations")
#pragma GCC optimize("-funsafe-loop-optimizations")
#pragma GCC optimize("inline-functions-called-once")
#pragma GCC optimize("-fdelete-null-pointer-checks")
#include <cstdio>
#include <random>
#include <ctime>
#include <iostream>
#include <vector>

using namespace std;
#define N 1010
#define M 200010
#define K 100000000
#define X 900010

char infile[100], outfile[100];
#define INIO freopen(infile, "r", stdin);
#define OUTIO freopen(outfile, "w", stdout);
mt19937 rnd(time(0));
int n, m;

int head[N], nxt[M], to[M], cost[M], cnt;
void add_edge(int u, int v, int w) {
	++ cnt;
	to[cnt] = v;
	nxt[cnt] = head[u];
	cost[cnt] = w;
	head[u] = cnt;
}

bool vis[M];

int mn = 1e9;
vector<int> ans;
vector<int> a;

int times;

void dfs(int u, int tot, int num) {
	times ++;
	if(times > K) return;
	if(tot >= mn) return;
	if(u == 1 && num == m) {
		if(tot < mn) {
			mn = tot;
			ans = a;
			OUTIO
			for(int i = 0; i < ans.size(); i++) {
				printf("%d ", ans[i]);
			}
			fclose(stdout);
			if(ans[0] != 1 || ans[ans.size() - 1] != 1) cerr << "fuck" << '\n';
			cerr << "step:" << mn << " times:" << times << '\n';
		}
	}
	for(int i = head[u]; i; i = nxt[i]) {
		int v = to[i], w = cost[i];
		bool r;
		r = rnd() % 2 == 0;
		if(r) {
			bool flag = 0;
			int ii = (i % 2 == 1) ? (i + 1) : i;
			if(!vis[ii]) {
				vis[ii] = 1;
				flag = 1;
				num ++;
			}
			a.push_back(v);
			dfs(v, tot + w, num);
			a.pop_back();
			if(flag) {
				vis[ii] = 0;
				num --;
			}
		}
	}
}

int fileid;
int main() {
	scanf("%d", &fileid);
	sprintf(infile, "postman%d.in", fileid);
	sprintf(outfile, "postman%d.out", fileid);
	INIO
	scanf("%d %d", &n, &m);
	for(int i = 1; i <= m; i++) {
		int u, v, w;
		scanf("%d %d %d", &u, &v, &w);
		add_edge(u, v, w);
		add_edge(v, u, w);
	}
	a.push_back(1);
	for(int i = 1; i <= 100; i++) {
		cerr << "Batch " << i << '\n';
		times = 0;
		dfs(1, 0, 0);
	}
//	OUTIO
//	for(int i = 1; i <= ans.size(); i++) {
//		printf("%d ", ans[i]);
//	}
//	fclose(stdout);
}
