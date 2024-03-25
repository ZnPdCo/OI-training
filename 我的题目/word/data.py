from cyaron import *
import math

_n = ati([0, 2, 3, 7, 8, 97, 95, 79, 77, 98, 100])
_m = ati([0, 2, 4, 3, 4, 4, 3, 4, 4, 4, 4])
_k = ati([0, 10, 914514, 891981, 1000000, 4, 810000, 900010, 998765, 914451, 999911])

for i in range(1, 11):
    data = IO(file_prefix="data//word", data_id=i)
    n = _n[i]
    q = n + 1
    m = _m[i]
    k = _k[i]
    data.input_writeln(n, m, k)
    output = Vector.random(m, [(1,k)])
    data.input_writeln(output)
    if(i == 4):
        cnt = 0
        for i in range(q):
            if(i <= n / m):
                cnt += 1
        data.input_writeln(q - cnt)
        for i in range(q):
            if(i > n / m):
                data.input_writeln(i)
    else:
        data.input_writeln(q)
        for i in range(q):
            data.input_writeln(i)
    data.output_gen("std.exe")
