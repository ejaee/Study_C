# 📌 Coding Test
* 각 코딩 테스트 사이트 문제풀이를 정리한다<br>
* c언어 문제풀이로 c언어에 익숙해진다

### [백준](https://www.acmicpc.net "BOJ")

* 사용언어 : C
* 진행방식 : [단계별로 풀어보기](https://www.acmicpc.net/step "BOJ_step")
* 스터디 : [solved.ac](https://solved.ac/ranking/rival)

---

## 📌 Git 활용하기
[리눅스명령어 참고자료](https://github.com/wooseok1152/hadoop-spark/blob/master/Linux%20기본%20명령어%20&%20Hadoop,%20R%20및%20R-studio%20설치%20부록.pdf "Linux_Command")

1. 원격 저장소 생성
  * [깃허브 사이트에서 생성](https://github.com/new)

2. 로컬 저장소 생성<br>
* 원격 저장소와 짝이되는 로컬 저장소 생성
* ***$ mkdir dir_name***
  
3. Git 저장소 생성 <br>
* ***$ git status*** 으로 상태 확인해보면 이곳은 저장소가 아니라는 에러가 뜨는데 git이 설정 안되었기 떄문
* ***$ git init*** 으로 Git 저장소 생성
* **.git**이라는 하위 디렉토리가 생성되고 이후 ***$ git status*** 으로 git 설정 확인
  
4. 원격 저장소에 올리고 싶은 파일들을 선택
* ***$ git add file_name*** 
* 또는 해당 파일위치는 .(dot)이므로 ***$ git add .***를 통해 모든 파일 선택이 가능

5. commit하기<br>
* ***$ git commit -m "수정내용"***

6. 로컬 저장소와 원격 저장소 remote
* 원격 저장소 생성 시 만들어지는 URL이 필요
* ***$ git remote add origin https://github.com/Ejaeda/-.git***

6. 선택한 파일들 원격 저장소로 이동 시키기 push
* ***$ git push -u origin master***으로 연동된 원격 저장소에게 Push
  * -u 옵션 : 한번하면 이후부터 git push만 입력 가능
   
7. 추가적으로 수정사항 발생 시
    * ***$ git add .***
    * ***$ git commit -m "init commit"***
    * ***$git push (-u origin master)***
  

------

## 📌 git push 오류 모음<br>

* 최초 pust 시에 오류 발생

```.vim
  error: src refspec master does not match any.
  error: failed to push some refs to 'https://github.com/id/repos. name.git'
```
>  아무 파일이나 생성해 commit한 후 pust 하면 해결

* git push 충돌 발생시

```
```

### 기타
  
-u 옵션
> 최초 1회 입력 이후 git push만으로 push 가능
```.vim
  git push -u origin branch_name 
```

remote 연결 상태를 확인
  ```.vim
  git remote -v
  ```
연결 끊는 방법

  ```.vim
  git remote remove <name>
  ```

clone
> 서버의 프로젝트를 내려받는 명령어
  ```.vim
  git clone 원격 저장소 주소
  ```
