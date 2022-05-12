
## 📌 CPU, 레지스터, RAM

[씹어먹는 C.pdf](https://github.com/Ejaeda/C_lang/files/8502450/C.pdf)
![0001](https://user-images.githubusercontent.com/87407504/163732171-37ccbe73-d151-4e6f-97ce-84588975984b.jpg)

-----

### 컴퓨터는 계산기다

- 컴퓨터는 CPU에서 연산을 수행한다

   64비트 운영체제에서  64비트를 가진 `레지스터`가 16개 있다
   
   ```.c
   레지스터
   
   CPU가 요청을 처리하는 데 필요한 데이터를 일시적으로 저장하는 기억장치
   ```
   
   - `하드디스크`에서는 데이터를 `영구적`으로 저장한다
   - `메모리(RAM)`에서는 데이터를`임시적`으로 저장한다
   - 메모리로 연산의 결과를 보내고 영구 저장 데이터를 하드디스크에 저장해야하는 명령을 처리하기위해 기억공간 하나 더 필요하다

      그것이 바로 `레지스터`
      
      - CPU옆에 붙어 있어서 연산 속도가 메모리보다 훨씬 빠르다

      - CPU는 자체적으로 데이터를 저장할 방법이 없으므로 메모리로 직접 데이터 전송이 불가하다

      - 때문에 연산을 위해서는 반드시 레지스터를 거쳐야하며 레지스터는 특정 주소를 가리키거나 값을 읽어올 수 있다


- 32비트와 64비트

   여기서 말하는 비트 수는 명령을 한 번에 처리할 수 있는 레지스터의 비트 수
   
   - 레지스터가 저장 가능한 공간의 크기가 32비트 / 64비트 인지를 나타낸 것
   - 32비트 시스템이 인식 가능한 메모리가 4GB인 이유

   ```.vim
   Q. 64비트 운영체제에서 64비트를 가진 레지스터가 16개인 이유가 있는가?
   ```
   
   
[씹어먹는 C 2.pdf](https://github.com/nawooo/C_lang/files/8678654/C.2.pdf)
![씹어먹는 C 2](https://user-images.githubusercontent.com/87407504/168067244-308ab3eb-e948-49e4-a8b3-6a52346c003f.jpg)

[씹어먹는 C 3.pdf](https://github.com/nawooo/C_lang/files/8678657/C.3.pdf)
![씹어먹는 C 3](https://user-images.githubusercontent.com/87407504/168067434-36799040-a3e2-47e5-9670-1ab865cedaec.jpg)

[씹어먹는 C 4.pdf](https://github.com/nawooo/C_lang/files/8678658/C.4.pdf)

[씹어먹는 C 5.pdf](https://github.com/nawooo/C_lang/files/8678659/C.5.pdf)

[씹어먹는 C 6.pdf](https://github.com/nawooo/C_lang/files/8678660/C.6.pdf)

[씹어먹는 C 7.pdf](https://github.com/nawooo/C_lang/files/8678661/C.7.pdf)

[씹어먹는 C 8.pdf](https://github.com/nawooo/C_lang/files/8678662/C.8.pdf)

[씹어먹는 C 9.pdf](https://github.com/nawooo/C_lang/files/8678663/C.9.pdf)

[씹어먹는 C 10.pdf](https://github.com/nawooo/C_lang/files/8678665/C.10.pdf)

[씹어먹는 C 11.pdf](https://github.com/nawooo/C_lang/files/8678670/C.11.pdf)

[씹어먹는 C 12.pdf](https://github.com/nawooo/C_lang/files/8678671/C.12.pdf)

[씹어먹는 C 13.pdf](https://github.com/nawooo/C_lang/files/8678673/C.13.pdf)

[씹어먹는 C 14.pdf](https://github.com/nawooo/C_lang/files/8678674/C.14.pdf)

[씹어먹는 C 15.pdf](https://github.com/nawooo/C_lang/files/8678675/C.15.pdf)

[씹어먹는 C 16.pdf](https://github.com/nawooo/C_lang/files/8678676/C.16.pdf)

[씹어먹는 C 17.pdf](https://github.com/nawooo/C_lang/files/8678677/C.17.pdf)

[씹어먹는 C 18.pdf](https://github.com/nawooo/C_lang/files/8678678/C.18.pdf)

[씹어먹는 C 19.pdf](https://github.com/nawooo/C_lang/files/8678680/C.19.pdf)

[씹어먹는 C 20.pdf](https://github.com/nawooo/C_lang/files/8678688/C.20.pdf)

[씹어먹는 C 21.pdf](https://github.com/nawooo/C_lang/files/8678690/C.21.pdf)

[씹어먹는 C 22.pdf](https://github.com/nawooo/C_lang/files/8678691/C.22.pdf)

[씹어먹는 C 23.pdf](https://github.com/nawooo/C_lang/files/8678692/C.23.pdf)

[씹어먹는 C 24.pdf](https://github.com/nawooo/C_lang/files/8678693/C.24.pdf)

[씹어먹는 C 25.pdf](https://github.com/nawooo/C_lang/files/8678696/C.25.pdf)

[씹어먹는 C 26.pdf](https://github.com/nawooo/C_lang/files/8678699/C.26.pdf)

[씹어먹는 C 27.pdf](https://github.com/nawooo/C_lang/files/8678700/C.27.pdf)


