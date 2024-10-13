
a = [i * pow(7, -1, 10) % 10 for i in range(10)]
a[0] = 10
n = int(input())
for i in range(n):
    v = int(input())
    print(a[v%10] if v >= 7 * a[v%10] else -1)

