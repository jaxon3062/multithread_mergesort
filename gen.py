import random

no = int(input("Testcase No. ? : "))
n = int(input("How many ints? : "))
range_lim = int(input("How wide the value range is? : "))

l = [random.randint(-range_lim, range_lim) for i in range(n)]

with open(f"./testcase/testcase{no}.in", 'w') as f:
     f.write(str(n) + '\n')
     for i in range(n):
         f.write(str(l[i]) + ' ')
     f.write('\n')
l.sort()
with open(f"./testcase/testcase{no}.ans", 'w') as f:
     f.write(' '.join(map(str, l)) + '\n')