# :book: Dynamic Programming

## 조건

1. 문제가 세부 문제로 쪼개질 때
2. 세부 문제의 solution이 더 큰 규모의 문제를 해결할 수 있을 때
3. 세부 문제들이 곂칠 때(memoization)

    > 문제를 세부 문제로 어떻게 쪼갤 것인가?

### fibonacci

- origin

    ```.py
    def fib_naive(n):
        if n== 0:
            return 0
        elif n == 1:
            return 1
        else:
            fib = fib_naive(n-1) + fib_naive(n-2)
            return fib 
    ```

특징

- O(2^n)

----

개선

- recursive DP

    ```.py
    fib_array = [0, 1]

    def fib_recur_dp(n):
        if n < len(fib_array):
            return fib_array[n]
        else:
            fib = fib_recur_dp(n-1) + fib_recur_dp(n-2)
            fib_array.append(fib)
            return fib 
    ```

특징

- 최초의 문제부터(`fibo(n)`) 풀어가려는 방식(`Top-down` 방식의 메모이제이션)
- O(n)
- 단점 : 큰 수가 들어왔을 때 stack overflow 발생
    > maximum recursion depth exceeded in comparision
- Top-down 방식은 생각의 과정은 더 자연스러우나 좋은 방식은 아님

----

해결

- `Bottom-up` 방식의 상향식 계산법을 활용
- 가장 작은 문제(`fibo(1)`)부터 array를 채워나간다

    ```.py
    def fib_dp(n):
        if n == 0:
            return 0
        elif n == 1:
            return 1
        fib_array = [0, 1]

        for i in range(2, n+1):
            num = fib_array[i-1] + fib_array[i-2]
            fib_array.append(num)
            return fib_array[n]
    ```

특징

- 가장 작은 문제부터(`fibo(1)`) array에 저장 (for loop)
- O(1)
- Top-down 방식에서 큰 수의 문제를 해결할 수 있음
