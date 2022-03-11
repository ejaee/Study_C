# Coding Test
각 코딩 테스트 사이트 문제풀이를 정리한다<br>
Git을 활용해 환경에 익숙해지고 체계적인 학습을 목적으로 한다

<사이트 목록>
1. 백준 
* 사용언어: C
* Link: [백준 온라인 사이트](https://www.acmicpc.net "BOJ")
* 진행방식: [단계별로 풀어보기](https://www.acmicpc.net/step "BOJ_step")
* 스터디 : [solved.ac](https://solved.ac/ranking/rival)


## Git 활용하기
[리눅스명령어 참고자료](https://github.com/wooseok1152/hadoop-spark/blob/master/Linux%20기본%20명령어%20&%20Hadoop,%20R%20및%20R-studio%20설치%20부록.pdf "Linux_Command")

1. 로컬저장소 생성<br>
    *  저장하고자 하는 폴더 위치에서 디렉토리 생성(***$ mkdir dir_name***)

2. 해당 저장소로 이동(***$ cd ./dir_name***) 후 파일 생성<br>
    * Git bash에서 touch(***$ touch file_name***)
    * 또는 마우스 우클릭으로 해당 폴더에 새로만들기 활용
    
3. Git 저장소 생성 <br>
    * 현재 상태를 확인해보면(***$ git status***) 이곳은 저장소가 아니라는 에러가 뜨는데,<br>
    Git 저장소 생성해야함(***$ git init***)<br>
    * **.git**이라는 하위 디렉토리가 생성되고 이후 ***$ git status*** 하면 정상작동<br>
  
4. 2에서 생성한 파일을 디렉토리 내의 모든 파일이 Git으로 관리되도록 추가
    * (***$ git add file_name***) 또는 해당 파일위치는 .(dot)이므로 (***$ git add .***)

5. commit하기<br>
    * ***$ git commit -m "수정내용"***
  
6. push하기<br>
    * push를 위해 Github의 원격저장소 만들기
    * ***$ git remote add origin https://github.com/계정 이름/원격 저장소 이름*** 으로 연동시키기
    * ***$ git push -u origin master***으로 연동된 원격 저장소에게 Push
    * -u 옵션을 한번하면 이후부터 git push만 입력 가능
   
7. 추가적으로 수정사항 발생 시
    * ***$ git add . -> $ git commit -m "init commit" -> $git push -u origin master***<br>
    (push에서 -u 옵션을 사용하면 이후 git push만 써도 가능)
------
## ETC<br>
### 오류문제 해결
* local git repos.에서 remote git repos.로 최초 pust 시에 오류 발생<br><br>
  ```
  error: src refspec master does not match any.
  error: failed to push some refs to 'https://github.com/id/repos. name.git'
  ```
  아무 파일이나 생성해 commit한 후 pust 하면 해결

### 옵션<br>
* push의 옵션<br>
  ```
  -u
  ```
  최초 1회 git push -u origin ***branch_name*** 입력 후 git push만 입력 가능<br>
  ```
    git config --global push.default ***matching***
  ```
  local과 remote 브랜치 명이 동일한 모든 브랜치를 push<br>
  ```
  git config --globla push.default ***simple***
  ```
  현재 작업중인 브랜치만 push
* remote 하기
원격 저장소를 등록해 push하기 위한 명령어 
  ```
  git remote add <name> <URL>
  ```
연결 상태를 확인하는 방법

  ```
  git remote -v
  ```
연결 끊는 방법

  ```
  git remote remove <name>
  
  ```
* clone 하기
git pull과 비슷하지만 클라이언트 상에 아무것도 없을 때 서버의 프로젝트를 내려받는 명령어

  ```
  git clone <저장소 주소>
  ```
