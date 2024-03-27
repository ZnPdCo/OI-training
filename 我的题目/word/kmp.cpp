#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
mt19937 mrand(random_device{}());
int rnd(int x) { return mrand() % x;}
int ne[10], f[100005][10];
char str[100005];
char p[10] = " 010";
int T;
int main()
{
	// time_t startt = clock();
	int m = 3;
	for(int i = 2, j = 0; i <= m; i++)
	{
		while(j && p[i] != p[j + 1]) j = ne[j];
		if(p[i] == p[j + 1]) j++;
		ne[i] = j;
	}
	scanf("%d", &T);
	while(T--)
	{
		scanf("%s", str + 1);
		int n = strlen(str + 1);
		
		for(int i = 0; i <= n; i++)
			for(int j = 0; j <= 4; j++) f[i][j] = 0x3f3f3f;
		f[0][0] = 0;
		for(int i = 0; i < n; i++)
		{
			for(int j = 0; j < m; j++)
			{
				int u = j;
				while(u && str[i + 1] != p[u + 1]) u = ne[u];
				if(str[i + 1] == p[u + 1]) u++;
				if(u < m) f[i + 1][u] = min(f[i + 1][u], f[i][j]);
				f[i + 1][j] = min(f[i + 1][j], f[i][j] + 1);
			}
		}
		int res = 0x3f3f3f;
		for(int i = 0; i < m; i++) res = min(res, f[n][i]);
		cout << res << endl;
	}
	// cerr << "~ #" << " done! time : " << (double)(clock()-startt) << " ms" << endl;
	// cerr << "~ #" << " done! time : " << (double)(clock()-startt)/CLOCKS_PER_SEC << " s" << endl;
}
