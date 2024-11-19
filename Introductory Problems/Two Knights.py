k = int(input())

for i in range(1, k+1):
    print((i**2 * (i**2 - 1))//2 - 4*(i-1)*(i-2))
