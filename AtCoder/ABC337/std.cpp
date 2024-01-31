#include <iostream>
using namespace std;
int n, m, k;
int c[400001], all[200001];
int cnt[200001], box[200001], sum, ans;
void add(int i,int x){
	ans -= min(box[i] * k, all[i]);
	sum -= box[i];
	box[i] -= (cnt[i]+k-1)/k;
	cnt[i] += x;
	box[i] += (cnt[i]+k-1)/k;
	sum += box[i];
	ans += min(box[i] * k, all[i]);
}
int main(void){
	cin >> n >> m >> k;
	for(int i = 1; i <= n; i++) cin >> c[i], c[n+i] = c[i], all[c[i]]++;
	int r = 0;
	for(int l = 1; l <= n; l++){
		while(r+1 < l+n && sum < m) r++, add(c[r], 1);
		cout << ans << "\n";
		add(c[l], -1);
	}
	return 0;
}
