def fib(n):
    if n == 1 or n == 2:
        return 1
    else:
        return fib(n-1) + fib(n-2)

def fib_dp(n):
    if n == 1 or n == 2:
        return 1
    fib_array = [0, 1, 1]
    cnt = 0
    for i in range(3, n+1):
        cnt += 1
        num = fib_array[i-1] + fib_array[i-2]
        fib_array.append(num)
    return cnt

n = int(input())
print(fib(n), fib_dp(n))