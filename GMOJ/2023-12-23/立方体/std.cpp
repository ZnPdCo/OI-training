#include<bits/stdc++.h>
#define INF 2147483647
#pragma GCC optimize(3)
#pragma GCC optimize(2)
#define mem(a,b) memset(a,b,sizeof(a))
using namespace std;

struct point
{int x,y;}s,t;
char ch;
int i,j,k,ans,f[9][9][7][7][7],a[9];

void dfs(int x,int y,int front,int back,int up,int right ,int down,int left,int sum) 
{
	if(sum > f[x][y][front][up][left]) return ;
	f[x][y][front][up][left] = sum;
	if(x==t.x && y==t.y)  ans = min(ans,sum);
	if(x<8) dfs(x+1,y,down,up,front,right,back,left,sum+a[back]);
	if(x>1) dfs(x-1,y,up,down,back,right,front,left,sum+a[front]);
	if(y>1) dfs(x,y-1,front,back,right,down,left,up,sum+a[left]);
	if(y<8) dfs(x,y+1,front,back,left,up,right,down,sum+a[right]);
}

int main()
{
	ch = getchar();
	scanf("%d ",&s.x);  s.y =  ch- 'a' + 1;
	ch = getchar();
	scanf("%d ",&t.x);  t.y =  ch -'a' + 1;
	for(int i=1;i<=6;i++) scanf("%d ",&a[i]);
	ans = INF;
	mem(f,127);
	dfs(s.x,s.y,1,2,3,4,5,6,a[5]);
	printf("%d",ans);
}
