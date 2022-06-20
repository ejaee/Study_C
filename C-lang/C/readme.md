
## 📌 모두의 코드, C

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
![씹어먹는 C 4_page-0001](https://user-images.githubusercontent.com/87407504/168068297-255c0f3d-38b6-4719-9d0b-ed88d61a76cd.jpg)

[씹어먹는 C 5.pdf](https://github.com/nawooo/C_lang/files/8678659/C.5.pdf)
![씹어먹는 C 5_page-0001](https://user-images.githubusercontent.com/87407504/168068308-da9c8f9c-7dca-4975-ae7c-20d029cfbbe6.jpg)

[씹어먹는 C 6.pdf](https://github.com/nawooo/C_lang/files/8678660/C.6.pdf)
![씹어먹는 C 6_page-0001](https://user-images.githubusercontent.com/87407504/168068323-ed363ade-5585-4353-a926-adda62e89d31.jpg)

[씹어먹는 C 7.pdf](https://github.com/nawooo/C_lang/files/8678661/C.7.pdf)
![씹어먹는 C 7_page-0001](https://user-images.githubusercontent.com/87407504/168068356-0645a441-7b95-45f3-8f88-3888895c3a35.jpg)

[씹어먹는 C 8.pdf](https://github.com/nawooo/C_lang/files/8678662/C.8.pdf)
![씹어먹는 C 8_page-0001](https://user-images.githubusercontent.com/87407504/168068455-0a2221d2-9186-4b6d-866a-51dd4b6e8782.jpg)

[씹어먹는 C 9.pdf](https://github.com/nawooo/C_lang/files/8678663/C.9.pdf)
![씹어먹는 C 9_page-0001](https://user-images.githubusercontent.com/87407504/168068466-6a37f12b-214d-46fb-aaf5-79fb65c7421d.jpg)

[씹어먹는 C 10.pdf](https://github.com/nawooo/C_lang/files/8678665/C.10.pdf)
![씹어먹는 C 10_page-0001](https://user-images.githubusercontent.com/87407504/168069179-5f47e7d2-75e8-4fa3-9db2-3fc0b39a2111.jpg)

[씹어먹는 C 11.pdf](https://github.com/nawooo/C_lang/files/8678670/C.11.pdf)
![씹어먹는 C 11_page-0001](https://user-images.githubusercontent.com/87407504/168069198-e2a7fae7-b691-487a-8cbf-29a41c93c247.jpg)

[씹어먹는 C 12.pdf](https://github.com/nawooo/C_lang/files/8678671/C.12.pdf)
![씹어먹는 C 12_page-0001](https://user-images.githubusercontent.com/87407504/168069139-d799b959-92fc-4bc2-9e02-5bcd0238073f.jpg)

[씹어먹는 C 13.pdf](https://github.com/nawooo/C_lang/files/8678673/C.13.pdf)
![씹어먹는 C 13_page-0001](https://user-images.githubusercontent.com/87407504/168069153-4904f93d-6743-41ba-9041-fb945ffb5d4a.jpg)

[씹어먹는 C 14.pdf](https://github.com/nawooo/C_lang/files/8678674/C.14.pdf)
![씹어먹는 C 14_page-0001](https://user-images.githubusercontent.com/87407504/168069230-af00bf10-0033-4354-9c3f-2cc888855595.jpg)

[씹어먹는 C 15.pdf](https://github.com/nawooo/C_lang/files/8678675/C.15.pdf)
![씹어먹는 C 15_page-0001](https://user-images.githubusercontent.com/87407504/168069246-3a0319a5-9541-42f1-8fe7-813ca7d61af5.jpg)

[씹어먹는 C 16.pdf](https://github.com/nawooo/C_lang/files/8678676/C.16.pdf)
![씹어먹는 C 16_page-0001](https://user-images.githubusercontent.com/87407504/168069351-f6a8629b-7dd2-4b3c-b0e4-7196bd1e9d7e.jpg)

[씹어먹는 C 17.pdf](https://github.com/nawooo/C_lang/files/8678677/C.17.pdf)
![씹어먹는 C 17_page-0001](https://user-images.githubusercontent.com/87407504/168069376-5de35959-9803-4882-a2b4-5dd9968d7961.jpg)

[씹어먹는 C 18.pdf](https://github.com/nawooo/C_lang/files/8678678/C.18.pdf)
![씹어먹는 C 18_page-0001](https://user-images.githubusercontent.com/87407504/168069292-9ca740cb-06ad-41ae-b0c1-23cd2751e9ad.jpg)

[씹어먹는 C 19.pdf](https://github.com/nawooo/C_lang/files/8678680/C.19.pdf)
![씹어먹는 C 19_page-0001](https://user-images.githubusercontent.com/87407504/168069310-c731c3b8-0cb8-485f-8644-14109e0a3d4d.jpg)

[씹어먹는 C 20.pdf](https://github.com/nawooo/C_lang/files/8678688/C.20.pdf)
![씹어먹는 C 20_page-0001](https://user-images.githubusercontent.com/87407504/168069412-98173b22-7fd4-423d-8f3f-d0d13fae9680.jpg)

[씹어먹는 C 21.pdf](https://github.com/nawooo/C_lang/files/8678690/C.21.pdf)
![씹어먹는 C 21_page-0001](https://user-images.githubusercontent.com/87407504/168069473-5f817346-396c-446b-9027-35a316bcd1ab.jpg)

[씹어먹는 C 22.pdf](https://github.com/nawooo/C_lang/files/8678691/C.22.pdf)
![씹어먹는 C 22_page-0001](https://user-images.githubusercontent.com/87407504/168069508-ae362921-6349-409f-b0be-3efbfa433b96.jpg)

[씹어먹는 C 23.pdf](https://github.com/nawooo/C_lang/files/8678692/C.23.pdf)
![씹어먹는 C 23_page-0001](https://user-images.githubusercontent.com/87407504/168069538-1b639d35-1d6a-49d8-9bb6-0bd11c7f1561.jpg)

[씹어먹는 C 24.pdf](https://github.com/nawooo/C_lang/files/8678693/C.24.pdf)
![씹어먹는 C 24_page-0001](https://user-images.githubusercontent.com/87407504/168069554-cdcdacb6-499e-4041-8f14-78ff79f6fff3.jpg)

[씹어먹는 C 25.pdf](https://github.com/nawooo/C_lang/files/8678696/C.25.pdf)
![씹어먹는 C 25_page-0001](https://user-images.githubusercontent.com/87407504/168069573-dd4c3b6a-8ef4-4f85-8896-e1b5583d3f71.jpg)

[씹어먹는 C 26.pdf](https://github.com/nawooo/C_lang/files/8678699/C.26.pdf)
![씹어먹는 C 26_page-0001](https://user-images.githubusercontent.com/87407504/168069600-99bab44b-e940-4538-b131-cd77dbd9b58b.jpg)

[씹어먹는 C 27.pdf](https://github.com/nawooo/C_lang/files/8678700/C.27.pdf)
![씹어먹는 C 27_page-0001](https://user-images.githubusercontent.com/87407504/168069619-1e00f0b6-efd9-4961-9494-cb7fbc02976f.jpg)


