def fib_naive(n):
        if n== 0:
            return 0
        elif n == 1:
            return 1
        else:
            fib = fib_naive(n-1) + fib_naive(n-2)
            return fib

print(fib_naive(10))

print(fib_naive(35)) 
# 2.09s user 0.01s system 99% cpu 2.108

# print(fib_naive(10000))
# #RecursionError: maximum recursion depth exceeded in comparison
