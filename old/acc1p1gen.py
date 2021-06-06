from random import *
from functools import partial

qc = 500
n = 500
its = 1

def make():
    getType = partial(choice, list('12'))
    # getType = lambda: '2'
    getIdx = partial(randint, 1, n)

    s = ''.join(choices(list('01'), k=n))

    def lr():
        l, r = getIdx(), getIdx()
        while l > r:
            l, r = getIdx(), getIdx()
        return l, r

    inp = ''
    ans = ''

    inp += f'{n} {qc}\n'
    inp += s + '\n'

    for qcounter in range(qc):
        # if not qcounter&255:
        #     print(f'Reached query {qcounter}')

        l, r = lr()
        t = getType()
        inp += f'{t} {l - 1} {r - l + 1}\n'

        if t == '1':
            ls = list(s)
            ls = ls[:l - 1] + list(reversed(ls[l - 1:r])) + ls[r:]
            s = ''.join(ls)
        elif t == '2':
            ss = s[l - 1:r]
            #print(ss)
            best = 0
            for i in range(len(ss), 0, -1):
                if ('1' * i) in ss:
                    best = i
                    break
            ans += f'{best}\n'

    return inp, ans

    # with open('in.txt','w') as f:f.write(inp)
    # with open('jout.txt','w') as f: f.write(ans)

for _ in range(its):
    make()
    print('---')
