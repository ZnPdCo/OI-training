#include<cstdio>
#include<queue>
using namespace std;
int n;
char s[1000010];
int trie[1000010]['z'+1];
int tail[1000010];
int fail[1000010];
bool vis[1000010];
int cnt;
inline void insert() {
	int p=0;
	for(int i=1; s[i]!='\0'; i++) {
		if(!trie[p][s[i]]) {
			trie[p][s[i]]=++cnt;
		}
		p=trie[p][s[i]];
	}
	tail[p]++;
}

void makeFail() {
	queue<int> q;
	for(int i='a'; i<='z'; i++) if(trie[0][i]) q.push(trie[0][i]);
	while(!q.empty()) {
		int p=q.front();
		q.pop();
		for(int i='a'; i<='z'; i++) {
			if(trie[p][i]) {
				fail[trie[p][i]]=trie[fail[p]][i];
				q.push(trie[p][i]);
			} else {
				trie[p][i]=trie[fail[p]][i];
			}
		}
	}
}

int query() {
	int p=0,ans=0;
	
	for(int i=1; s[i]!='\0'; i++) {
		p=trie[p][s[i]];
		for(int j=p; vis[j]==false; j=fail[j]) {
			ans+=tail[j];
			vis[j]=true;
		}
	}
	
	return ans;
}

int main() {
	scanf("%d",&n);
	for(int i=1; i<=n; i++) {
		scanf("%s",s+1);
		insert();
	}
	makeFail();
	scanf("%s",s+1);
	printf("%d",query());
}
