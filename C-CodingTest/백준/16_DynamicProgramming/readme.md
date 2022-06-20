# :book: Dynamic Programming

DP의 특징

```
답을 여러 번 계산하지 않고 한번 만 계산한다

이미 한번 계산 했다면, 해당 값을 저장해두고 이후에 재활용한다

>> 메모이제이션(memoization) 
```

<details>
<summary> Algorithm (click 👈)  </summary>

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

</details>

----

### :point_right: [02_24416](https://www.acmicpc.net/problem/9184)

- 핵심

```.py
1. 일반적인 recursion은 input 값이 클 경우 시간이 많이 걸린다
2. 이에대한 문제를 dp으로 해결한다
3. 메모이제이션(memoization)을 통해 이미 계산한 값을 재활용한다
```

-  새로 안 사실

메모이제이션 로직

```.py
메모이제이션(memoization)을 위해 전역 배열을 선언(1), 저장(3), 사용(2)

1.
python에서 3차원 배열을 정의할 때는 다음과 같이한다

세 값 중 하나라도 20이 넘으면 w(20, 20, 20)을 리턴하므로 max index 21

dp = [[[0 for col in range(21)] for row in range(21)] for depth in range(21)]

2.
만약 값이 있다면 recursion하지 않고 배열에 담긴 값을 그대로 return

if dp[a][b][c]:
    return dp[a][b][c]


1. 
이 외에 나머지는 값이 없는 것으로, 계산함과 동시에 값을 전역 배열에 저장

elif a < b and b < c:
    dp[a][b][c] =  w(a, b, c-1) + w(a, b-1, c-1) - w(a, b-1, c)
    return dp[a][b][c]
else:
    dp[a][b][c] =  w(a-1, b, c) + w(a-1, b-1, c) + w(a-1, b, c-1) - w(a-1, b-1, c-1)
    return dp[a][b][c]
```

입력 여러개 받기

```.py
a, b, c = map(int, input().split())
```

출력 여러개 하기

```.py
print("w({}, {}, {}) = {}".format(a,b,c,w(a,b,c)))
```

----