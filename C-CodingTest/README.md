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

📌 최초 pust 시에 오류 발생

```vim
  error: src refspec master does not match any.
  error: failed to push some refs to 'https://github.com/id/repos. name.git'
```
>  아무 파일이나 생성해 commit한 후 pust 하면 해결

-----

📌 문제
```.vim
git add . -> commit -> untrack file 의 경우
```
`git add .`는 명령어를 실행한 디렉 이하에서 발생한 변경 내용만 포함한다

📌 해결
```vim

 git add -A
 
```
 -  -A 옵션은 작업 디렉토리 상에 어디에 위치하든 모든 변경 내용을 스테이징으로 넘긴다
 -  최상위 디렉에서 `git add .` 하는것과 같다

-----
📌 문제
```.vim
Pulling is not possible because you have unmerged files.
Committing is not possible because you have unmerged files.
```
git pull 하니까 발생한 에러
- 충돌로 인해 merge 했음에도 에러 발생

알고보니 로컬과 원격 둘다 같은 파일이 있는데 로컬에서 아직 merge가 잘 안됐다고 인식
📌 해결
```.vim
 git commit -am '커밋메시지'
```
하니 잘 돌아감

[도움](https://velog.io/@2ujin/%EA%B9%83-Pull-is-not-possible-because-you-have-unmerged-files-%EC%97%90%EB%9F%AC)<br>

-----

📌 문제
```.vim
git push 충돌 발생시
```

📌 해결
```.vim
git push -> git pull
```

-----
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
