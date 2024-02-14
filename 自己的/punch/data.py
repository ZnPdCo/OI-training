from cyaron import *

_t = ati([0, 3, 3, 5, 5, 5, 6, 6, 6, 6, 6])
_n = ati([0, 114, 514, 1919, 8100, 1E4, 5E4, 5E4, 8E4, 1E5, 1E5])
_m = ati([0, 0, -1, 0, -1, -1, 0, 0, 0, 0, 0])

for i in range(1, 11):
    data = IO(file_prefix="data//punch", data_id=i)

    t = _t[i]
    data.input_writeln(t)
    for j in range(t):
        n = _n[i] - j
        m = n + _m[i]
        if(j == 5):
            n //= 5
            if(n % 2 == 0):
                n-=1
            data.input_writeln(n*5, n*5)
            for k in range(1, n):
                data.input_writeln(k, k+1)
            data.input_writeln(1, n)
            cnt = n
            for k in range(1, n+1):
                cnt+=1
                data.input_writeln(k, cnt)
                cnt+=1
                data.input_writeln(cnt-1, cnt)
                cnt+=1
                data.input_writeln(cnt-randint(1, 2), cnt)
                cnt+=1
                data.input_writeln(cnt-1, cnt)
        else:
            data.input_writeln(n, m)
            if(i == 2):
                graph = Graph.chain(n)
            else:
                graph = Graph.UDAG(n, m)
            data.input_writeln(graph.to_str(output=Edge.unweighted_edge, shuffle=True))

    data.output_gen("punch.exe")
