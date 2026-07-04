x, y, l, r, a, b = map(int, input().split())

prices = [0] * 23

for i in range(0,l,1):
    prices[i] = y

for i in range(l,r,1):
    prices[i] = x

for i in range(r,23,1):
    prices[i] = y

sum = 0

for i in range(a,b,1):
    sum += prices[i]

print(sum)