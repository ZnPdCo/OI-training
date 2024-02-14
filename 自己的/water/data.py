from cyaron import *

_n = ati([0, 185, 2**59, 935, 989, 1E9-342, 1E9-648, 1E18-1232, 1E18-54088, 1E18-2223, 1E18-33311])

for i in range(1, 11):
    data = IO(file_prefix="data//water", data_id=i)

    n = _n[i]
    data.input_writeln(n)
