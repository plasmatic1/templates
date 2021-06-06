n, q = map(int, input().split())
s = input()

for _ in range(q):
    a, b, c = map(int, input().split())
    print(f'Q: {a} {b} {c}')
    print(_, s)
    if a == 1:
        rev = s[b:b+c]
        print(rev)
        rev = ''.join(reversed(rev))
        print(rev)
        s = s[:b] + rev + s[b+c:]
    else:
        print(f'QA: {s[b:b+c]}')
    print(_, s[6:19])