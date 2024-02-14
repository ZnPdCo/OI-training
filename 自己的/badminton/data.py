from cyaron import *

_t = ati([0, 1, 10, 2000000, 2114514, 2919201, 2999919, 2922222, 3000000, 2999999, 2918292, 2910232, 2991210])
_k = ati([0, 1, 8, 1010201, 1919810, 1029124, 1555556, 1212412, 1234567, 1999999, 2777717, 2342124, 1353253])

_u1 = ati([0, 10, 4, 8, 1E14-1423, 1E14-34343, 0, 0, 0, 1E14-34623, 1E12-12312, 99, 1E14-234125])
_u2 = ati([0, 8, 6, 1, 1E14-12232, 1E14-34343, 0, 1E14-114514, 1E13-114514, 0, 1E12-34325, 98, 1E14-34235])
_v1 = ati([0, 5, 9, 7, 1E14-1232, 1E14-34343, 0, 0, 0, 1E14-12325, 1E14-231, 1E14-97, 1E14-3242394])
_v2 = ati([0, 7, 5, 4, 1E14-933435, 1E14-34343, 0, 0, 1E12-1919810, 1E14-121241, 1E14-123, 1E14-10000, 1E14])

for i in range(1, 13):
    data = IO(file_prefix="data//badminton", data_id=i)

    t = _t[i]
    k = _k[i]
    data.input_writeln(t, k)
    for j in range(4):
        if(i == 4):
            p = 0
            q = 0
        else:
            p = randint(0, 998244352)
            q = randint(0, 998244352)
        data.input_writeln(p, q)
    u1 = _u1[i]
    u2 = _u2[i]
    v1 = _v1[i]
    v2 = _v2[i]
    data.input_writeln(u1, u2, v1, v2)

    if(i == 5):
        a = 0
        b = 0
    else:
        a = randint(0, 998244352)
        b = randint(0, 998244352)
    data.input_writeln(a, b)
    
    data.output_gen("badminton.exe")
