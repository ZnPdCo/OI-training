#include<cstdio>
#define ll long long

const int N = 1e5 + 5;
ll n, g, r, Q, ans, a[N], s[N], f[N];

void read(ll &x)
{
	x = 0; ll f = 1; char c = getchar();
	while(c < '0' || c > '9')
		f = c == '-' ? -1 : f, c = getchar();
	while(c >= '0' && c <= '9')
		x = x * 10 + c - '0', c = getchar();
	x *= f;
}

int main()
{
	//freopen("brt.in","r",stdin);
	//freopen("brt.out","w",stdout);
	read(n), read(g), read(r), r += g, n++;
	for(int i = 1; i <= n; i++) read(a[i]), ans += a[i];
	for(int i = n; i >= 1; i--) s[i] = s[i + 1] + a[i];
	f[n] = 0, f[n - 1] = a[n];
	for(int i = n - 2; i >= 0; i--)
	{
		f[i] = s[i + 1];
		for(int j = i + 1; j < n; j++)
			if((s[i + 1] - s[j + 1]) % r >= g)
			{
				f[i] = s[i + 1] - s[j + 1] + (r - (s[i + 1] - s[j + 1]) % r) + f[j];
				break;
			}
	}
	read(Q);
	for(ll opt, p, t; Q--;)
	{
		read(opt), p = opt % r, t = 0;
		for(int i = 1; i < n; i++)
		{
			p += a[i], p %= r, t += a[i];
			if(p >= g) {opt += f[i] + r - p - a[n]; break;}
		}
		printf("%lld\n", opt + t + a[n]);
	}
	//fclose(stdin), fclose(stdout);
	return 0;
}