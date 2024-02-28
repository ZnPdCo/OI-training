>### 题目描述
>
>一年一度的 PuBaBa 杯开始了！
>
>今年的 PuBaBa 杯总共有 $n$ 个选手来参加，编号分别为 $1,2,\cdots,n$，他们的水平按编号依次递增，所以他们过的题目数量单调不降。
>
>作为本场比赛的出题人，PuBaBa 总共出了 $m$ 道题，他希望第 $i$ 道题至少有 $l_i$ 个选手通过，至多有 $r_i$ 个选手通过，PuBaBa 预计所有题的过题人数和为 $S$。
>
>作为毒瘤出题人，PuBaBa 例行会在赛前举行“毒奶”活动。不过，PuBaBa 的毒奶是有依据的，他会计算每位选手最多过的题目数量。
>
>不过，PuBaBa 有点太牛了，他决定将这个简单的任务交给您来完成。
>
>### 输入格式
>
>第一个，三个正整数 $n,m,S$ 分别表示参赛选手，题目数量，以及总过题人数。
>
>接下来 $m$ 行，每行两个正整数 $l_i,r_i$ 表示第 $i$ 道题至少有 $l_i$ 个选手通过，至多有 $r_i$ 个选手通过。
>
>### 输出格式
>
>若无解，输出 "-1"（不包含双引号）。
>
>否则，为了压缩输出量，我们令 $ans_i$ 表示第 $i$ 个选手的最多过题数。
>
>您仅需输出 $\bigoplus_{i=1}^{n} ans_ii$。
>
>### 样例
>
>#### Input 1
>
>```
>3 5 8
>1 3
>2 3
>1 3
>2 3
>1 3
>```
>
>#### Output 1
>
>```
>5
>```
>
>#### Input 2
>
>```
>10 8 41
>1 7
>5 6
>5 7
>4 9
>7 10
>1 2
>3 10
>3 5
>```
>
>#### Output 2
>
>```
>50
>```
>
>### 样例解释
>
>对于样例一：$ans$ 序列为 $2,4,5$。 
>
>对于样例二：$ans$ 序列为 $4,4,5,5,6,7,7,7,8,8$。
>
>### 数据范围
>
>由于输入量很大，请使用快速的读入方式。
>
>出题人为您准备了一份 fread 板子：[https://www.luogu.com.cn/paste/xc3a5u5w](https://www.luogu.com.cn/paste/xc3a5u5w)。
>
>| 测试点编号 | $n,m\le$       | 特殊性质       |
>| ---------- | -------------- | -------------- |
>| $1\sim 2$  | $5$            | 无             |
>| $3$        | $100$          | 保证 $l_i=r_i$ |
>| $4\sim 5$  | $100$          | 无             |
>| $6\sim8$   | $1000$         | 保证 $l_i=r_i$ |
>| $9\sim 10$ | $1000$         | 无             |
>| $11\sim12$ | $2\times 10^5$ | 保证 $l_i=r_i$ |
>| $13\sim14$ | $10^5$         | 无             |
>| $15\sim16$ | $2\times 10^5$ | 无             |
>| $17\sim18$ | $5\times 10^5$ | 无             |
>| $19$       | $2\times10^6$  | 无             |
>| $20$       | $5\times10^6$  | 无             |
>
>对于 $100\%$ 的数据，保证 $1\le n,m \le 5\times 10^6$，$1\le l_i\le r_i\le n$，$1\le S\le nm$。

~~比某些做法难，总之比题解简单~~

先问一个问题：一个长度为 $n$ 的数组 $a=\{0\}$，进行 $m$ 次操作，每次操作选择若干个**互不相同**的位置使这些位置加 $1$。给你一个数组 $b$，问这个数组可否通过上述 $m$ 次操作得出来。

这题非常简单，我们只需要求出 $\max_b$，若 $\max_b\le m$ 则可以，否则不可以。

---

我们将原问题化为一个二维问题，横方向表示题目，纵方向表示这道题做出的人数，黄色矩形表示 $[l_i,r_i]$。

![](data:image/png;base64,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)

明显得出，我们至少要填 $\sum l_i$ 个格子，至多能填 $\sum r_i$ 个格子。如果 $\sum l_i\le S\le\sum r_i$ 不满足，则答案为 $-1$。

我们设考虑到第 $i$ 个人，则后面有 $p=n-i+1$ 个人。又设 $ans_i=j$。

考虑写一个 `check`，传入 $p,j$，判断是否存在方案。

---

首先，有一个基础的构造，即必须在这个构造上动工。我们设第 $i$ 个人的做题数为 $a_i$。
$$
a=\{\underbrace{0,0,\cdots,0}_{n-p个0},\underbrace{j,j,\cdots,j}_{p个j}\}
$$
明显，这是一个满足递增且第 $i$ 个人为 $j$ 的方案。它总共填了 $p\times j$ 个格子。

---

先考虑后面 $p$ 个人的部分。

我们发现，“做题”的操作就很像上面“加一”的操作——选择若干个**互不相同**的位置使这些位置加 $1$。因为有 $p$ 个人，所以我们就有 $p$ 次操作。同理，只有每道题过题人数都小于 $p$ 才合法。（重申一下，先考虑后面 $p$ 个人的部分）

也就是说，我们需要画一条粗线，只能取粗线下面的部分。（下面这张图举了 $p=6$ 的例子）


![](data:image/png;base64,iVBORw0KGgoAAAANSUhEUgAAAMgAAADWCAYAAACUhM11AAAAAXNSR0IArs4c6QAAAARnQU1BAACxjwv8YQUAAAAJcEhZcwAADsMAAA7DAcdvqGQAAA2DSURBVHhe7ZOBiuQ6DAT3/3/63gbvQDCOpxS30JOtguZuMu0aWUt+/hVF8Ui9IEUxoV6QophQL0hRTEAvyM/PT6WyVSj4BVFSvjWaT5cz52OgZuSAhDN9upw5HwM1IwcknOnT5cz5GKgZOSDhTJ8uZ87HQM3IAQln+nQ5cz4Gao6E337k+v6pYxmQcKZPlzPnY6DmXXj9/5Mn+n7P7OwbzvTpcuZ8DNQcCZ9+hHQtAxLO9Oly5nwM1BwJn36EdC0DEs706XLmfAzUHAmffoR0LQMSzvTpcuZ8DNQcCZ9+hHQtAxLO9Oly5nwM1BwJn36EdC0DEs706XLmfAzUHAmffoR0LQMSzvTpcuZ8DNQcCWc/cv/OevYNZ/p0OXM+Bmrehdf/+4z49p2SM326nDkfAzUjBySc6dPlzPkYqBk5IOFMny5nzsdAzUtYqewUCn5BlJzp08XHpyPHfAzUjByQkMOni49PR475GKgZOSAhh08XH5+OHPMxUDNyQEIOny4+Ph055mOgZuSAhBw+XXx8OnLMx0BN64BX/5MRVt83cvh08fHpyDEfAzVNwq47Oht5YYKPTxcfn44c8zFQ0yQcdPtnkRcm+Ph08fHpyDEfAzVNwkG3fxZ5YYKPTxcfn44c8zFQ0yTsutfn0TMlOXy6+Ph05JiPgZrWAa/+J5/Pd6y+b+Tw6eLj05FjPgZqrg7Yn4+8MMHHp4uPT0eO+RiouTpgfz7ywgQfny4+Ph055mOgpnXAe390NvLCBB+fLj4+HTnmY6DmmwGvM0/nIi9M8PHp4uPTkWM+BmpGDkjI4dPFx6cjx3wM1IwckJDDp4uPT0eO+RioeQkrlZ1CwS+IkjN9uvj4dOSYj4GakQMScvh08fHpyDEfAzUjByTk8Oni49ORYz4GakYOSMjh08XHpyPHfAzUjByQkMOni49PR475GKhpHfDq39Nj9X0jh08XH5+OHPMxUNMkHHT7Z5EXJvj4dPHx6cgxHwM1TcJBt38WeWGCj08XH5+OHPMxUNMkHHT7Z5EXJvj4dPHx6cgxHwM1rQNe/Xt6rL5v5PDp4uPTkWM+BmpaB7z3R2cjL0zw8eni49ORYz4GapqEg27/LPLCBB+fLj4+HTnmY6CmSTjo9s8iL0zw8eni49ORYz4GapqEg27/LPLCBB+fLj4+HTnmY6CmdcCrf0+P1feNHD5dfHw6cszHQM3IAQk5fLr4+HTkmI+BmpEDEnL4dPHx6cgxHwM1L2GlslMo+AVR0ny65JhPlzP3p8PiQ80zF6hLDp+OHPMxUPPMBeqSw6cjx3wM1Dxzgbrk8OnIMR8DNc9coC45fDpyzMdATZPwtzvKnfZZl96/is98upy5Px0WH2qahINu/6x91sUyH8FnPl3O3J8Oiw81VwYcnc2xQF1y+HTkmI+Bmm8HfDqXY4G65PDpyDEfAzXfDvh0LscCdcnh05FjPgZqvh3w6VyOBeqSw6cjx3wM1Hwz4OxMjgXqksOnI8d8DNR8M+DsTI4F6pLDpyPHfAzUfDPg7EyOBeqSw6cjx3wM1Hwz4OxMjgXqksOnI8d8DNQ8c4G65PDpyDEfAzXPXKAuOXw6cszHQM1LWKnsFEq9IJUjQ8EviJLm0+VMnw4fny6R90XNHAvUJYdPh49Pl8j7omaOBeqSw6fDx6dL5H1RM8cCdcnh0+Hj0yXyvqiZY4G65PDp8PHpEnlf1Hwz4HXm6Vx7rsuZPh0+Pl0i74ua1gHv/dHZ9kyXM306fHy6RN4XNU1C0PVZoC45fDp8fLpE3hc1TcK/7vXvJz3tmS5n+nT4+HSJvC9qmoS/3b4//qzLmT4dPj5dIu+LmibhoNs/a591OdOnw8enS+R9UdMkHHT7Z+2zLmf6dPj4dIm8L2qahINu/6x91uVMnw4fny6R90VN64B9f/xZlzN9Onx8ukTeFzXfDHid+aSnPdPlTJ8OH58ukfdFzRwL1CWHT4ePT5fI+6JmjgXqksOnw8enS+R9UfMSVio7hYJfECXNp8uZPh0+Pl0i94eaZy5QFx+fDh+fLpH7Q80zF6iLj0+Hj0+XyP2h5pkL1MXHp8PHp0vk/lDzzAXq4uPT4ePTJXJ/qGkS/nZHudM+63KmT4ePT5fI/aGmSQi6ORaoi49Ph49Pl8j9oaZJCLo5FqiLj0+Hj0+XyP2hpkn42+3T057pcqZPh49Pl8j9oaZJOOj2z3wurEsOnw4fny6R+0PN1QX253MsUBcfnw4fny6R+0PN1QX253MsUBcfnw4fny6R+0NNk3DQ7Z/5XFiXHD4dPj5dIveHmibhoNs/87mwLjl8Onx8ukTuDzWtC7z69/S0Z7qc6dPh49Mlcn+oeeYCdfHx6fDx6RK5P9Q8c4G6+Ph0+Ph0idwfal7CSmWnUPALoqT5dPGZT0fddy2R+0PNHAvUUfddw+e+uljui5o5Fqij7ruGz311sdwXNXMsUEfddw2f++piuS9q5ligjrrvGj731cVyX9RcWeDobOSFCT4+Xc68ry6W+6Lm2wVe50ZnIy9M8PHpcuZ9dbHcFzXfLvA6NzobeWGCj0+XM++ri+W+qPlmgZ8zo7ORFyb4+HQ58766WO6LmtYF3vujs5EXJvj4dDnzvrpY7ouaJmHXHZ2NvDDBx6fLmffVxXJf1DQJf7tP+dD+r8vdrcDHp8uZ99XFcl/UXFng6GzkhQk+Pl3OvK8ulvui5soCR2cjL0zw8ely5n11sdwXNd8s8Dpzz532WZfev4qPT5cz76uL5b6omWOBOuq+a/jcVxfLfVEzxwJ11H3X8LmvLpb7ouYlrFR2CgW/IEqaTxef+XSc6dPFx8dAzRwL1FG+NZpPFx8fAzVzLFBH+dZoPl18fAzUzLFAHeVbo/l08fExUDPHAnWUb43m08XHx0BN6wKv/j097Zkuo99YoXxrNJ8uPj4GapqEg27/LPLChPKt0Xy6+PgYqGkSDrr9s8gLE8q3RvPp4uNjoObKAkdnIy9MKN8azaeLj4+Bmm8WeJ15Ohd5YUL51mg+XXx8DNRcWeDobOSFCeVbo/l08fExUHN1gf35yAsTyrdG8+ni42Ogpkk46PbPIi9MKN8azaeLj4+BmibhoNs/i7wwoXxrNJ8uPj4GaloXePXv6WnPdBn9xgrlW6P5dPHxMVAzxwJ1lG+N5tPFx8dAzRwL1FG+NZpPFx8fAzUvYaWyUyj4BVHSfLr4zKcjh0+XnfaHmvUHWSOHT5ed9oea9QdZI4dPl532h5r1B1kjh0+XnfaHmvUHWSOHT5ed9oea1gGv/j097Zkuo99Y4UyfLjvtDzVNwkG3f9Y+62KZj3CmT5ed9oeaJuGg2z9rn3WxzEc406fLTvtDzdUB+/Ptsy6RCyTk8Omy0/5Qc2XA0dn2TJfIBRJy+HTZaX+o+XbAp3PtuS6RCyTk8Omy0/5Q882AszPtO10iF0jI4dNlp/2hpnXAb/32vS6RCyTk8Omy0/5Q0yQcdPtn7bMulvkIZ/p02Wl/qGkS/nZHudM+69L7VznTp8tO+0PN+oOskcOny077Q836g6yRw6fLTvtDzUtYqewUCn5BlDSfLj7z6cjh02Wn/aFm/UHWyOHTZaf9oWb9QdbI4dNlp/2hZv1B1sjh02Wn/aFm/UHWyOHTZaf9oeabAWdn2ne6RC6QkMOny077Q02T8Lf7yRPtO10s8xHO9Omy0/5Q882AszPtO10iF0jI4dNlp/2h5psBZ2fad7pELpCQw6fLTvtDzTcDzs6073SJXCAhh0+XnfaHmm8GnJ1p3+kSuUBCDp8uO+0PNd8MODvTvtMlcoGEHD5ddtofar4ZcHamfadL5AIJOXy67LQ/1Hwz4OxM+06XyAUScvh02Wl/qGkS/nb79LRnuox+Y4UzfbrstD/UrD/IGjl8uuy0P9SsP8gaOXy67LQ/1LyElcpOoeAXREn51ijfGhYfatYC1yjfGpE+1KwFrlG+NSJ9qFkLXKN8a0T6ULMWuEb51oj0oeb/4cKzM1bf1b+nJ9p3Z9X3manPnf4zYeT5YPF9PH3u9J+/MXNdWHyoaRESTAP+XXJ2xurr6Z9F+u5c54h/Bula57v3Pebrn4X6/v6dYhES3vhmZ0wXHnT7Z5G+O9c54p9BupG+ntHZ1fn6Zybf379TLELCG9/szOp8/fkV3+jsG9/nzKrv6vbpGT174tNV+e48nbP4yDwm39+/UyxCwhvf7MzKfKOzb+d7Omf13fujsxYfOW/1fTtv8d15Omf1Xf17eiw+1LQICW98szNv53s6t3Lf0VmLr++u+kaQ33iCzPN2vqdzVt+9Pzpr8aGmdcBvvPHNzvwffHf68xbf1X3Kh/v/39Cft/hG3RXfh9mZyPlQ0yIkvPHNzlh93/oW36jbP7POd4f4Z6jnU/s+zM5EzoeaFiHhjW92xnThQbd/FunrIf4ZHvN9O2/1XczOWHyj7sp8qGkREqwX7tMzevZE7/rkTv/5GzPXhdV3MXNafTPXhdV34eF7wur7zPVJj8WHmhYhoXxrlG8Niw81a4FrlG+NSB9qXsJKZadQtK9mUWxGvSBFMaFekKKYUC9IUUyoF6QoJtQLUhQT6gUpign1ghTFhHpBimJCvSBF8ci/f/8BGaBK5QeYILAAAAAASUVORK5CYII=)

我们发现，对于 $l_i\le p$，**是合法的**，我们可以在后面的部分将其填完，不会超过 $p$。至少要填的格子数是 $\sum l_i[l_i\le p]$。

但对于 $l_i>p$​​，我们只能填 $p$​​ 个。只能填的格子数是 $\sum p[l_i>p]$​​。

我们可以发现，因为存在 $l_i>p$，只能填 $p$ 个的情况。我们需要在前面 $n-p$ 个人补全这 $\sum (l_i-p)[l_i>p]$ 个格子，那么现在每个题都满足下边界 $l_i$ 了。

那么前面的 $n-p$ 个人有没有足够的位置补全呢？

答案是有的！

设 $x=\sum [l_i>p]$，说明 $a_{n-p+1}$ **至少**为 $x$，最多有 $(n-p)x$ 个格子需要补全。

前面的 $a_i$ 必须小于等于 $x$，那么最多有 $(n-p)x$ 个位置，恰好可以补全！

---

我们发现，题目要求我们填恰好 $S$ 个，我们不一定能填够。由于至少填 $\sum l_i$ 个，我们有 $S-\sum l_i$ 个“自由”的格子。

考虑将这些填给后面 $l_i\le p$ 的题目，努力补全让它们尽量等于 $p$。那么总共有 $(S-\sum l_i)+(\sum l_i[l_i\le p])+(\sum p[l_i>p])$ 个格子。将其与**至少的**格子数 $pj$ 做比较即可。

---

完了吗？当然没有。我们是不是忘了某个叫 $r$ 的东西？

因为我们刚刚进行补全，有可能会补到 $r$ 之外。我们要与至多的进行比较。

我们求出至多的格子数，同上为：$(\sum r_i[r_i\le p])+(\sum p[r_i>p])$，与刚刚的总共值取 $\min$。

也就是得到了 `check` 函数。
$$
\min((S-\sum l_i)+(\sum l_i[l_i\le p])+(\sum p[l_i>p]),(\sum r_i[r_i\le p])+(\sum p[r_i>p]))\ge pj
$$

---

然后发现答案肯定是递增的。

所以可以均摊线性得到答案。

```cpp
#include <cstdio>
#include <algorithm>
#include <cctype>
using namespace std;
#define ll long long
#define N 5000010
ll n, m, s, mx, mn, ans[N], ANS;
ll l[N], r[N], sl[N], sr[N], cl[N], cr[N];
int main() {
//	freopen("pubaba.in", "r", stdin);
//	freopen("pubaba.out", "w", stdout);
	scanf("%lld %lld %lld", &n, &m, &s);
	
	for(ll i = 1; i <= m; i++) {
		scanf("%lld %lld", &l[i], &r[i]);
		mn += l[i], mx += r[i];
		sl[l[i]] += l[i];
		sr[r[i]] += r[i];
		cl[l[i]] ++;
		cr[r[i]] ++;
	}
	if(mn > s || mx < s) return printf("-1"), 0;
	for(ll i = 1; i <= n; i++) {
		sl[i] += sl[i-1];
		sr[i] += sr[i-1];
	}
	for(ll i = n; i >= 1; i--) {
		cl[i] += cl[i+1];
		cr[i] += cr[i+1];
	}
	ll pos = n;
	for(ll i = 1; i <= m; i++) {
		while(min(s - mn + sl[pos - 1] + pos * cl[pos], sr[pos - 1] + pos * cr[pos]) < pos * i)
			pos--;
		ans[n - pos + 1] = i;
	}
	for(ll i = 1; i <= n; i++) { 
		ans[i] = max(ans[i-1], ans[i]);
		ANS ^= ans[i] * i;
	}
	printf("%lld", ANS);
}
```

