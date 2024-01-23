# 【GDKOI 2024 TG Day2】染色（set） 题解

发现我们给一个点染上色后有：

![](data:image/png;base64,iVBORw0KGgoAAAANSUhEUgAAALgAAACNCAYAAAAEhLDZAAAAAXNSR0IArs4c6QAAAARnQU1BAACxjwv8YQUAAAAJcEhZcwAADsMAAA7DAcdvqGQAAAT+SURBVHhe7ZvBqmpBEMT8/5++T9+4i0jR0FAjCfRuKmA4Wx9/AY9H9GyEbqKbTN3P3eP/2PN+8t4f+ldeD7fQTXSTqTtaGZzoJo3uaGVwops0uqOVwYlu0uiOVgYnukmjO1oZnOgmje5oZXCimzS6o5XBiW7S6I5WBie6SaM7Whmc6CaN7mhlcKKbNLqjlcGJbtLojlYGJ7pJoztaGZzoJo3uaGVwops0uqOVwYlu0uiOVgYnukmj+7n78C8Iz/uVe3/oX3k93EI30U2m7mhlcKKbNLqjlcGJbtLojlYGJ7pJoztaGZzoJo3uaGVwops0uqOVwYlu0uiOVgYnukmjO1oZnOgmje5oZXCimzS6o5XBiW7S6I5WBie6SaM7Whmc6CaN7mhlcKKbNLqjlcGJbtLojlYGJ7pJoztaGZzoJo3u5+7DvyA871fu/aF/5fVwi7vdO2dvMnVHK4OT4945e5OpO1oZnBz3ztmbTN3RyuDkuHfO3mTqjlYGJ8e9c/YmU3e0Mjg57p2zN5m6o5XByXHvnL3J1B2tDE6Oe+fsTabuaGVwctw7Z28ydUcrg5Pj3jl7k6k7WhmcHPfO2ZtM3dHK4OS4d87eZOqOVgYnx71z9iZTd7QyODnunbM3mbqjlcHJce+cvcnUHa0MTo575+xNpu5oZXBy3DtnbzJ1P3cnqOf95L0/9K+8Hm6x7965u907NLqj1d1Rdu5u9w6N7mh1d5Sdu9u9Q6M7Wt0dZefudu/Q6I5Wd0fZubvdOzS6o9XdUXbubvcOje5odXeUnbvbvUOjO1rdHWXn7nbv0OiOVndH2bm73Ts0uqPV3VF27m73Do3uaHV3lJ27271Dozta3R1l5+5279DojlZ3R9m5u907NLqj1d1Rdu5u9w6N7mh1d5Sdu9u9Q6M7Wt0dZefudu/Q6I5Wd0fZubvdOzS6n7vzoz3vJ+/9oX/l9XCLu907Z28ydUcrg5Pj3jl7k6k7WhmcHPfO2ZtM3dHK4OS4d87eZOqOVgYnx71z9iZTd7QyODnunbM3mbqjlcHJce+cvcnUHa0MTo575+xNpu5oZXBy3DtnbzJ1RyuDk+PeOXuTqTtaGZwc987Zm0zd0crg5Lh3zt5k6o5WBifHvXP2JlN3tDI4Oe6dszeZuqOVwclx75y9ydQdrQxOjnvn7E2m7mhlcHLcO2dvMnU/dyeo5/3kvT/0r7webqGb6CZTd7QyONFNGt3RyuBEN2l0RyuDE92k0R2tDE50k0Z3tDI40U0a3dHK4EQ3aXRHK4MT3aTRHa0MTnSTRne0MjjRTRrd0crgRDdpdEcrgxPdpNEdrQxOdJNGd7QyONFNGt3RyuBEN2l0RyuDE92k0R2tDE50k0b3c/fhXxCe9yv3/tC/8nq4hW6im0zd0crgRDdpdEcrgxPdpNEdrQxOdJNGd7QyONFNGt3RyuBEN2l0RyuDE92k0R2tDE50k0Z3tDI40U0a3dHK4EQ3aXRHK4MT3aTRHa0MTnSTRne0MjjRTRrd0crgRDdpdEcrgxPdpNEdrQxOdJNGd7QyONFNGt3P3Yd/QXjer9z7Q//K6+EWuoluMnVHK4MT3aTRHa0MTnSTRne0MjjRTRrd0crgRDdpdEcrgxPdpNEdrQxOdJNGd7QyONFNGt3RyuBEN2l0RyuDE92k0R2tDE50k0Z3tDI40U0a3dHK4EQ36XP//f0DFqz/GR4ShtkAAAAASUVORK5CYII=)

我们称这是一个大小为 $1$ 的十字。

进一步地，我们给这 $5$ 个点再次染上色后有：

![](data:image/png;base64,iVBORw0KGgoAAAANSUhEUgAAAJYAAACCCAYAAACkRjFvAAAAAXNSR0IArs4c6QAAAARnQU1BAACxjwv8YQUAAAAJcEhZcwAADsMAAA7DAcdvqGQAAAOzSURBVHhe7ZoxriNREAJ9/0v/Ha+d4YzqAEFJTFhqwQvn9QfweiGan8ytJLgRywZS2t2IZQMp7W7EsoGUdjdi2UBKuxuxbCCl3Y1YNpDS7kYsG0hpdyOWDaS0ux/P679sWdB8H5jFW3TF3EqCG7FsIKXdjVg2kNLuRiwbSGl3I5YNpLS7EcsGUtrdiGUDKe1uxLKBlHY3YtlASrsbsWwgpd2NWDaQ0u5GLBtIaXcjlg2ktLsRywZS2t2IZQMp7W7EsoGUdjdi2UBKu/vx/Pj7b1ncfB+YxVt0xb37Jtmd+CCW7BJvkt2JD2LJLvEm2Z34IJbsEm+S3YkPYsku8SbZnfggluwSb5LdiQ9iyS7xJtmd+CCW7BJvkt2JD2LJLvEm2Z34IJbsEm+S3YkPYsku8SbZnfggluwSb5LdiQ9iyS7xJtmd+CCW7BJvkt2JD2LJLvEm2Z34IJbsEm+S3YkPYsku8SbZnfg8nk8Jy4Lm+8As3qIr5lYS3IhlAyntbsSygZR2N2LZQEq7G7FsIKXdjVg2kNLuRiwbSGl3I5YNpLS7EcsGUtrdiGUDKe1uxLKBlHY3YtlASrsbsWwgpd2NWDaQ0u5GLBtIaXcjlg2ktLsRywZS2t2P58fff8vi5vvALN6i53uSj/uG3a2h7kYsG0jTfjdi2UCa9rsRywbStN+NWDaQpv1uxLKBNO13I5YNpGm/G7FsIE373YhlA2na70YsG0jTfjdi2UCa9rsRywbStN+NWDaQpv1uxLKBNO13I5YNpGm/G7FsIE373YhlA2na7348H9myoPk+MIu36Iq5lQQ3YtlASrsbsWwgpd2NWDaQ0u5GLBtIaXcjlg2ktLsRywZS2t2IZQMp7W7EsoGUdjdi2UBKuxuxbCCl3Y1YNpDS7kYsG0hpdyOWDaS0uxHLBlLa3YhlAyntbsSygZR29+P58fffsrj5PjCLt+iKe/dNsjvxQSzZJd4kuxMfxJJd4k2yO/FBLNkl3iS7Ex/Ekl3iTbI78UEs2SXeJLsTH8SSXeJNsjvxQSzZJd4kuxMfxJJd4k2yO/FBLNkl3iS7Ex/Ekl3iTbI78UEs2SXeJLsTH8SSXeJNsjvxQSzZJd4kuxMfxJJd4k2yO/FBLNkl3iS7Ex/Ekl3iTbI78Xk8nxKWBc33gVm8RVfMrSS4EcsGUtrdiGUDKe1uxLKBlHY3YtlASrsbsWwgpd2NWDaQ0u5GLBtIaXcjlg2ktLsRywZS2t2IZQMp7W7EsoGUbvff3z8gA2mw22z8TwAAAABJRU5ErkJggg==)

我们称这是一个大小为 $2$ 的十字。

同理可得，我们给这 $5$ 个点染上**相同**的大小为 $2$ 的十字，可得一个大小为 $4$ 的十字：

![](data:image/png;base64,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)

---

假设我们图的边长为 $N=2^n$，我们只需要染上一个大小为 $w=\frac{N}{2}$ 的十字，左边的那一个点就会和右边的点抵消，上面的点就会和下面的点抵消。最终效果就是只染了一个点。

![](data:image/png;base64,iVBORw0KGgoAAAANSUhEUgAAAPYAAADjCAYAAAC2CengAAAAAXNSR0IArs4c6QAAAARnQU1BAACxjwv8YQUAAAAJcEhZcwAADsMAAA7DAcdvqGQAABUaSURBVHhe7Z0rmBU5E4ZHIpFIJBKJRCKRSNYhkbhdt2IFEjlyJBKJHIlEIpEjkefvb3q+f3I63enO9eTyvc9TO+yZOZXuqlQnqVz66iSq4efP0+n793O5uTmd/v77XP791/67Pfnx46EQMQQK7ELc3s4BxuB8+/Z0ev36dHr2bHLC5IVLCMo35dOn8wcIHirmw+H374ebEdUzuVek5tevOSg+fpwDZi2olvLypR1oHz6cB9qWsJw9QRlrZYfK8prNa/r8+fyhABHlmNwjQrm7myssKjGCEJV7LQDQKqOFZqX/+nX+Xg3dYzPwIOjmmwH67t158D59un6PvgJdsBkfACItk4nFEdANRSuM7ioq5ZMndmWFoOLj9/g7BDBa754xHwrfvp0/FPiwM2XLbvgcD78vX/q3WQkmk4ot0KKim/vihV0RGcBsiVGpNQY9DhKFfBC8f2/nGmBz9B4U5GFMJhQmf/6cTtfXp9OrV3ZFQws0Qit8KZBgXHuQwhdoyTH0EceYzCYAAhothDmGZIVSIJcHLTqC3GzJ0V1H647fCTcK7Am0ws+fP1YgdK/Reog6QJcdAW2OzzEMQs5DrDN0YOPJ/+bNeUBrIUe9oCuOHpTZVccDGUMncc6QgY1uN7LWbAEwH6sWui3gLzyIzQDH1Bl8KwYMbHS7OW7DeBrjatEu6GGZAY7WXA/pgQIbzsa4jBUAlUHTU/2AADeHVeiRjdx6dx/YGH+ZYzJ0u5GMEX0Cf3NmY+TWu9vAXma6MXWFz0T/oCc2euvdXWCvZbo15hqTkVvvbgIbT2msDGNAI0GmLrdYtt6jJEu7CGzzyYwpLKw/1rSHMMFUGKc30Xr3PixrPrDhMD6NsQRRmW6xBYZp5swI8i69bhltOrCxhptPYXW7xVHQWpszJQj23gK86cDmwgS01EL4giHcco9ALxt+mg1sLEiAM5Ak03haxLAMcDQUrW8RbTawmenEpgAhYkHjgIw5h3atz6o0GdhMmGEVmRApWU6PYbtoiz3C5gIb3SYYHE9WbbgXuTCnUNGAtDbb0lRgm0GtLLjIDYIZQY06hzF4S4m1ZgIbCQ0FtSgNkmjsmmOKrJWkWhOBzaBG10hBLUqDMTYPt8TPFsbc1Qc2FhOwpdaxReJSoKXmoha04LUHd/WBzUUoOrhOXBqMsTnfXXtwVx/YNGSLUw6iPxDcbLmxFLXWMXfVgY2sJAyo+WpREwhmZssR5DVOu1Yd2Jzewj5rIWoCwc2dYjUmdasNbBiOp4kqaSZqhTM2EKyIrIVqA5sGw08BN+UUEQMSu1xjXssS1Cq9qp1bSxiAuUTEgjpbU8a8Sq9yMYCmuAgDMJeIFNQ0HVadVxHMMAwSE4IwAHOJSIWZMX/37uHDC1CdV2EMtdZLGIC5RKQEwc2W+1IJteq8SoP0ckRNGhiAuUSkBnPbSKhdail0dV7lHlhhYgZhDhE5wOk+qMuXWGBVnVdhCAX2Ehgkp4hccLxd+givqryKsQmMgO64MGEA5hItAsoFjjVGncbUbclTWGavVgK3aF4ym1gnDMA8guWQsHtNK6d6AotWYF/8LAU8WwWY82PiTG/FXDIHYC7h1ljZPQ+XWB4Nz1YBXnWKG1drvcYcgDnk7u7pfeYWSUut8ssH12eUSqTBuxcHTzFUrtLjkHY4D8aUcnv76r7CodUWeWEirUTPCN69OLxhbNMUa8xBmENubt7d2x6CZZAYZ2sNQR6YQyqxBwLevSg8/B/rw8UWcFMeQVccrTV3J5lBjgetuudp4T6I3IlKePdioNvNCqXpFhdwU06ZQXYc22SZ6IHg33jfuIZIaUA9p11zPjQfvXoBuC5ce673gJtyig2SPWi1GeB4ACPBiQyviIOzEHhg5mLdqwUwJ+5VWfaAm3LKNhhv48HLpb74iZfXqYseDlttPCxz9YTcXs0IE2bLXVxX04eSGuXZJF8mmf12dfVzkpeTrP2txCUA5/jhn7l6q3MpheFKp7WEGW88B9Jt46sbrQ0TQGhx0HpvIXvbUDfzS5AcsxD57sABl9itTW+pMtjUqNt8l/TWUknZ28bUjdYa/5tjDUG+O9gAYzOM01Ap1sZpqgw2terGnmPXUUCyt42pG602ZyBSzwrlu4MNOG+9dVa4KoNNzbrNc76QNzETobK3zVI34yF1q53vDlbAE33vCaXKYFO7bgQ3k6FmcMveNkvdR2IihHx3sMKRp5Mqg00LuhHMfDMGghvBLnvbrOne68WGkO8OVmCXzfVkUmWwaUU3Wh8uvph9Pf0nEz3Z28yQp5rXzncHCzjFtTeW6MlhqWhNN2c9rq5+rCZIU9CbvZkhT7UaLd8dLOB+670dXL05LAUt6mbLnW0BRmf2RkuNX2G8nYJ8d7CA6473EgS9OSwFLeqeK+qfpN1Lkx7tzRhJ8ebOfHewAE8iOHmPHh0WS7u6P0+Sp9Xu0d58bXSKs9Hy3YEBMqa4YGRL9+jRYbG0q/vZ/cM8x7FLPdobNmISLdZe+e7AgCdHHHkS9eiwWFrWzc0Oqc/V7tXe3Moce3xSvjswYCLlyMX26rAYWtbN7blHems+9Gpvvj3EtbnmCPnu4AEz23eke9Grw2JoXfeLF/h34pVVndr79na2Vexpvfnu4AE8eXChmO46Qq8Oi6F13VxZlTKJ1qu9mY+KPQMw3x1MoIXmOtije057dVgMretGry1VUoj0bG8kGyEx5LuDCabv91abmeDGJT0KT1/5aHw2puzBgyzMnXK+ZA1s7vjxGVsdufFQpNumlG7UAfxvqiRaz/bmZhrsdw8l2x1wist3rNCzw0LpRTdbImTKY+nZ3lxrH2OnbHfA1tp3Pq5nh4XSi24+7H2GZlv0bG/O/e/tq3CR5Q6Ysg/pdvXssFB60c1kKpJosevHe7Y3dnjhz2LmsrPcARekLI8WPkLPDgulJ92+059b9GxvBnbMFs7kd8AkydEFKUt6dlgoPek2p75iWu2e7c3ZpKoCm2tdsSghhJ4dFkpvunmoQMyClZ7tzcCOss/DzyRg3o1P49A5uJ4dFkpvulO02j3bO8X2zaR3wLf2x6xz7dlhofSom622enY2PEasmsDmoD8qTd+xw0LpUTcWX+DXOPQwhJ7tzR1x1QQ2s+Exu3h6dlgovermCitMj/rSs72rC2w8fTFuilno37PDQulVN6e+QrK/Pdu7qsD2Of7IRc8OC6VX3eyOayHTOVUFNlebxVwM6NlhofSsmy+R8H2VbM82qSqwuZk+NMtJenZYKD3rZnbc90y0nm1SVWCnyIiDnh0WSs+6WYm1C/ARThtXEdgpdqSAnh0WSu+6fU/ZAT3bpKoFKrgIXEyKwJaMJv9OAt//Y3zWr+zBwI55+2bywEbXKoYjNx6KdNvUoNvcOHSUnm3CfFUVm0C4+UOBnZ4RdPNgjqPvrerZJsxXxbxkIdkdcBWRAjs9I+jmQflH9xn0bBP2fkPOMyDJ7iBmeaBJzw4LZQTdXOB09Njd1m3iWnbNt27GNJLJ7kAttnQv8dXtU4datgnuD0VsrfngsKSKU0o1xpbuJb66fZJGLdtkbwaJe9VjSHYHvNjYl3a37LBcjKKb2XG03Hu0a5Mn98MNBO7aYSSYy0fx1bziJ+U8di6k26Y23Udfb9OuTV5PMo+j1+AhCzFz2CDZHXDNrwI7PSPp5ps5947Watcmn+/vb2t8nayBfPgZjdaKS/eSEN3MCO8d1tGuTW7v729t+SzOMXB1031IdgcM7OgXdjfrMOleEqKbew723iDTrk3uNoca3Pyx1U33IdkdMLCPZDRdjFSJjzKSbp6qsrf9t0Wb4ERWqF5LjGFqCwGP38fOLIFkd5BifSsYqRIfZSTdbLX2ztRu0SY8MQbjaBN0wZlbiDlL3CTZHWBsjQtTYKdnJN2c8trrjrZoEy5MYWBjlSY+4yGgR6b5jpLsDhjYsU+ckSrxUUbSjdYLX9s7lrhFm/BtowhsZr8paLFjE2Ymye6Agb3sZvgyUiU+ymi62S11nXbbok240eWvv+af2KaKZCF6uTHvMVsj2R1wbBQ9sd6gw4B024TqPnI+fYs2wRtGofq//+Y42ZvSiyHwDvC1c/nz58n05PlnulicJWv//qjAqJLRhSeqvDM+60FuJkmT9d4D0RTAYyCmFhggF23rziM12oS9P9c7tFu09/Pnv+7vK+aFGkdBiQGcX3BKqbGiHaHFigap0SbMjKNLvkVr9r67e3p/T1dXGfvfBig1gPOLTik1VrQjtFbRKDXahJlxJNG2aM3et7ev7u/p6ipyzfVBUGoA5xedUmqsaEdoraJRarUJDxvY6ra2Zu+bG+QLpn9dRRxk5gFKDeD8olNKrRVtj9YqGqVWm/Dgjq3McWv2vr5+f38/OGK5BCg1gPOLTim1VrQ9WqtolFptwjXjWyd1tmbvx8C+vs+Kb4nvO8y2QKkBnF90Sqm1ou3RWkWj1GoTrtLaWsnYmr0fu+LHBBtF0GvBHoyQYJ9UhICv5ZFaK9oerVU0Sq02YWZ86zji1uyNrPj799eT7u/3a8JdguKXgrXzWN2JVv3IScDTV0LA1/JIrRVtj9YqGqVWm+yd/dW7vZE0xDFJWKHG7Zym7G22OlaKBb6WR2qtaHv0XtFCiNWNr29tBhnN3li0g3l9tOj4uXc0cVgpi4tNKTVXNBejVbQjxOrmWzjXkL3dBJZyfrEppeaK5kIVzSZWN3d5rSWPZG83gaWcX2xKqbmiuVBFs4nVzUTSWrJI9nYTWMr5xaaUmiuaC1U0m1jdrrfLyN5uAks5v9iUUnNFc6GKZhOrm6eMrB1pLXu7CSzl/GJTSs0VzYUqmk2sbkzpQMXa6jPZ201gKecXm1JqrmguVNFsYnVzWenanK3s7SawlPOLTSm4cYlkFq6vxokqa79vU0pQphQPct64dNvUrJsnqawdkCl7uylTigdymM2oupENh4q19eKyt5sypXggh9mMqpuBjfnsJbK3mzKleCCH2YyqmxtBFNj+lCnFAznMZlTdDOy1jSCyt5sypXggh9mMqpuHGiqw/SlTigdymM3IuqFCge1PmVI8kMNsRtYNFU+ePPyPgeztpkwpHshhNiPrhoo1NbK3mzKleCCH2Yyse+uwBdnbTZlSPJDDbEbWjfH1mhrZ202ZUjyQw2xG1q3ADqNMKR7IYTYj61Zgh1GmFA/kMJuRdSuwwyhTigdymM3IuhXYYZQpxQM5zGZk3QrsMMqU4oEcZjOybgV2GGVK8QA3LpE8yq9J+qoXJagysHMh3Ta161aLHUaZUjyQw2xG1q3ADqNMKR7IYTYj61Zgh1GmFA/kMJuRdSuwwyhTigdymM3IuhXYYZQpxQM5zGZk3QrsMMqU4oEcZjOybqjQQQv+lCnFAznMZlTdOvMsnDKleCCH2Yyqm6eU4gX4S2RvN2VK8UAOsxlV98+f0KFzxUMoU4oHcpjNqLr5JpA3bx4+MJC93ZQpxQM5zGZU3V+/QodeyhdCmVI8kMNsRtV9fQ0dp9OHDw8fGMjebsqU4oEcZjOq7s+foeNSL77PQ07dJmVK8UAOsxlVNwIaKhDgS2RvN2VK8UAOsxlV98eP0DF3yZfI3m7KlOKBHGYzqm688B4qkERbInu7KVOKB7hxiWSW20lQJ14Yn7UvJagysHMh3TY16376FDrmpaVLZG83ZUrxQA6zGVH33R2+v75OHMjebsqU4oEcZjOi7ttbfH991RmQvd2UKcUDOcxmRN03N/j+nBlfQ/Z2U6YUD+QwmxF1f/qE759OX748fLBA9nZTphQP5DCbEXWjC46v//jx8MEC2dtNmVI8kMNsRtSNjDhOTlnLiAPZ202ZUjyQw2xG080DFl6+fPhgBdnbTZlSPJDDbEbTze2aa7u6iOztpkwpHshhNqPpdq0RJ7K3mzKleCCH2YymG11wfBVd8i1kbzdlSvFADrMZSffeijMie7spU4oHcpjNSLp5ztnacUgmsrebMqV4IIfZjKSbp6asHa5gInu7KVOKB3KYzUi60VLja2i5XcjebsqU4oEcZjOS7mfP8L15rO1C9nZTphQP5DCbUXRz/vrVq4cPHMjebsqU4gFuXDKq/JgEdeCt8Vl/UoIqAzsXbevOI7XYBLu48OeuZaQmbfsyP2VK8UAOs5l15xHf68b7tI5yVDd2cGHDB/58L2lG2vZlfsqU4oEcZjPrziM+182M9dYe6SVHdOOkFJ5thj3YR2nbl/kpU4oHcpjNrDuPHL1uBjVWhLmWepq4dCOg376ddUJcGz7WaNuX+SlTigdymM2sO48cue6QoAZrupH5RtYbv6LOb98efulB277MT5lSPJDDbGbdeWTvukODGpi6cYYZN3dA8G/X7q092vZlfsqU4oEcZjPrziOu6+a7s3yDGq3y3M3+/v/xMwUBvfZmD19UT9yUKcUDOcxm1p1Htq6bQY3APJoJxzFGfC2PKa9fz4GeIqCJ6ombMqV4IIfZzLrzyNp1c4cVpqCOTj8haF+8mL+Hn/O7raenQiZUT9yUKcUDOcxm1p1H1q6bY+G9HVbg9+/HE0UhaJm5zlu+tMmp26RMKR7IYTaz7jyyvG4e1G+uAMMCErTcS8ERRhxDo5XGZybypU1O3SZlSvFADrOZdeeR5XVjPIyPOB5GsOL/XYI56LXdWPKlTU7dJmVK8UAOs5l15xHzupH8wrgarTDP88ZPtMwIeFOQJMMKNFdiTb60yanbpEwpHshhNrPuPGJeN1+Eh3FyCuRLm5y6TcqU4oEcZjPrziPmdbPbjUUpKZAvbXLqNilTigdymM2sO4+Y163AnmlVt0mZUjyQw2xm3XnEvG4GNsbQKZAvbXLqNilTige4ccml5Okk8MFP4zNJailBdYEtLgsXpyCRJtpFgS3O4BFFWHCyd1KoqBcFtrDAGBvBjdZbwd0mCmxhgWBmlxzrwLdePi/qRYEtVsHmDuzDVnC3iQJbbILDFczgFu2gwBZOzODGmnHRBgpssQuCm+/UCjl4UJRHgS0OwVVpCHCNt+tHgS0OwxNLfQ72F5dBgS0Og0y5uuRtoMAWXvDoJBzIgEAXdaLAFt6gK47gPnLYobgMCmzhDVam4dxx3zeDiHIosIXoEAW2EB2iwBaiQxTYQnSIAluIDlFgC9EhCmwhOkSBLUSHKLCF6BAFthAdosAWokMU2EJ0iAJbiA5RYAvRIQpsITpEgS1Ed5xO/wOlaGGqI9nYdQAAAABJRU5ErkJggg==)

假如我们要染一个大小为 $w=\frac{N}{2}$ 的十字，可以通过在这个十字的 $5$ 个红色的点位染上 $5$ 个大小为 $\frac{w}{2}=\frac{N}{4}$ 的十字来实现：

![](data:image/png;base64,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)

进一步地，如果我们要染一个大小为 $w=\frac{N}{4}$ 的十字，可以染上 $5$ 个大小为 $\frac{w}{2}=\frac{N}{8}$ 的十字来实现。

同理，我们可以使用分治来实现这一过程，最后就只会需要染若干个大小为 1 的十字，我们就能通过若干次操作染上一个点，而题目要求染的点我们只需要一个点一个点这么染就可以了。

我们只需要对于每个需要染色的位置跑一遍分治即可。时间复杂度由 $T(n)=5T(\frac{n}{2})+O(1)$ 得 $O(N^2n^{\log_25})$，就可以拿到不错的分数。

```c++
#include <cstdio>
#include <cstdlib>
#include <set>
#define ll long long
#define N 3000
using namespace std;
ll n, siz;
ll a[N][N], v[N][N];
ll tot;
inline ll calc(ll x) {
	return (x%siz+siz)%siz;
}
void fun(ll x, ll y, ll w) {
	if(w == 1) {
		v[x][y] ^= 1;
		return;
	}
	
	fun(x, y, w/2);
	fun(calc(x+w/2), y, w/2);
	fun(calc(x-w/2), y, w/2);
	fun(x, calc(y+w/2), w/2);
	fun(x, calc(y-w/2), w/2);
}
int main() {
	freopen("set.in", "r", stdin);
	freopen("set.out", "w", stdout);
	scanf("%lld", &n);
	siz = 1<<n;
	for(ll i = 0; i < siz; i++) {
		for(ll j = 0; j < siz; j++) {
			scanf("%lld", &a[i][j]);
		}
	}
	
	for(ll i = 0; i < siz; i++) {
		for(ll j = 0; j < siz; j++) {
			if(a[i][j]) {
				fun(i, j, siz / 2);
			}
		}
	} 
	
	for(ll i = 0; i < siz; i++) {
		for(ll j = 0; j < siz; j++) {
			if(v[i][j]) {
				tot++;
			}
		}
	}
	printf("%lld\n", tot);
	for(ll i = 0; i < siz; i++) {
		for(ll j = 0; j < siz; j++) {
			if(v[i][j]) {
				printf("%lld %lld\n", i, j);
			}
		}
	}
}
```

---

考虑为什么会这么慢，因为一个点可能被染了多次，这可以被抵消，我们可以枚举 $w$，在染完一种大小的十字后再去染较小的十字，十字可以互相抵消，然后再同理得解。时间复杂度 $O(N^2n)$，可以满分。

不要开 `long long`。

```c++
#include <cstdio>
#include <cstdlib>
#include <set>
#define N 3000
using namespace std;
int n, siz;
bool a[N][N], v[N][N];
int tot;
inline int calc(int x) {
	return (x % siz + siz) % siz;
}
inline int read() {
	int x = 0;
	char c = '.';
	while(c < '0' || c > '9') c = getchar();
	while(c >= '0' && c <= '9') {
		x = (x << 1) + (x << 3) + (c ^ '0');
		c = getchar();
	}
	return x;
}
void print(int x) {
	if(x > 9) print(x / 10);
	putchar(x % 10 + '0');
}
int main() {
	freopen("set.in", "r", stdin);
	freopen("set.out", "w", stdout);
	n = read();
	siz = 1<<n;
	for(int i = 0; i < siz; i++) {
		for(int j = 0; j < siz; j++) {
			a[i][j] = read();
		}
	}
	
	for(int w = siz/2; w >= 2; w /= 2) {
		for(int i = 0; i < siz; i++) {
			for(int j = 0; j < siz; j++) {
				v[i][j] = 0;
			}
		}
		for(int i = 0; i < siz; i++) {
			for(int j = 0; j < siz; j++) {
				if(a[i][j]) {
					v[i][j] ^= 1;
					v[calc(i+w/2)][j] ^= 1;
					v[calc(i-w/2)][j] ^= 1;
					v[i][calc(j+w/2)] ^= 1;
					v[i][calc(j-w/2)] ^= 1;
				}
			}
		}
		for(int i = 0; i < siz; i++) {
			for(int j = 0; j < siz; j++) {
				a[i][j] = v[i][j];
			}
		}
	}
	
	for(int i = 0; i < siz; i++) {
		for(int j = 0; j < siz; j++) {
			if(v[i][j]) {
				tot++;
			}
		}
	}
	print(tot);
	putchar('\n');
	for(int i = 0; i < siz; i++) {
		for(int j = 0; j < siz; j++) {
			if(v[i][j]) {
				print(i);
				putchar(' ');
				print(j);
				putchar('\n');
			}
		}
	}
}
```



