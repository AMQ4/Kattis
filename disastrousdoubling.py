n = int(input())
ei = list(map(int, input().split()))
b = 1

for _ in ei:
    b *= 2
    b -= _
    
    if b < 0:
        print('error')
        exit(0)


print(b % int(1e9 + 7))
