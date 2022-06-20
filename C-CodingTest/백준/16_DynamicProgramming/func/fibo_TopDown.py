fib_array = [0, 1]

def fib_recur_dp(n):
    if n < len(fib_array):
        return fib_array[n]
    else:
        fib = fib_recur_dp(n-1) + fib_recur_dp(n-2)
        fib_array.append(fib)
        return fib 

print(fib_recur_dp(10))

print(fib_recur_dp(35)) 
# 0.02s user 0.01s system 85% cpu 0.036

# print(fib_recur_dp(10000)) 
# #RecursionError: maximum recursion depth exceeded in comparison