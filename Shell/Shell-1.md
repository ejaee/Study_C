# Ex00

	1. z 이름의 파일 만들기
	2. cat으로 Z와 함께 줄바꿈이 표시되도록 하기

	[내 정답]
	$ echo Z > z
	
	echo는 문자열을 출력하는데 사용한다
	따옴표를 쓰지 않아도 동작한다
	개행문자를 출력하므로 개행문자를 없애기 위해서는 -n 옵션을 사용한다
	echo 옵션 스트링
	
	redirection 연산자인 > 나 append 연산자인 >> 를 사용해서
	echo 결과를 파일로 저장할 수 있다
	
* echo
	* 인수로 전달되는 텍스트 / 문자열을 표시하는데 사용
	* echo [option] [string]
	* echo 내용 > 파일이름<br>
	-> z라는 파일을 만들고 Z라는 내용을 적어라

* 파일을 만드는 방법 세가지 touch / cat / vi
	* touch FileName<br>
	빈파일을 만들어 낸다

	* cat 명령어<br>
	파일을 보기 위한 명령어 이기도 하지만 파일을 만들거나 초기화 할 수 있다<br>
	cat > FileName
	
	* vi 명령어
	vi FileName<br>
	파일이 생성됨과 동시에 vi화면으로 전환된다<br>
	i눌러서 입력 후 esc
	:wq(저장 후 vi 종료)
	:q(파일 생성 안됨)ㅣㄴ -ㅁ
		
* etc
	* cat 명령 뒤에 파일 이름을 입력하면 그 파일의 내용을 출력<br>
	* 여러개의 파일을 전달하여 파일 내용을 연속 출력 가능<br>
	-> cat file1 file2 file3
	* '>'(redirection)기호 : 사용을 통해 입력한 내용으로 새로운 파일을 만든다
	* << 기호 : 직접 입력한 텍스트를 파일에 저장할때 사용한다
	-> 시작, 종료를 알리는 키워드를 설정하고 끝날때 해당 키워드로 종료한다
	
	```
	$ cat << EOF > file1.txt
	hello
	wold
	EOF
	
	$ cat file1.txt
	hello
	world
	```
# Ex01

	1. 파일 testShell00 생성하라
	2. ls -l 했을 때 -r--r-xr-x 1 XX XX 40 JUN 1 23:42 testShell00
	3. 다음 명령어 실행하여 제출 파일 생성
	tar -cf testShell00. tar testShell00.
	
	[내 풀이]
	권한부여와 바이트 개수 날짜시간을 변경하라
	touch로 파일 생성 경우 바이트 개수를위해 40바이트 적었다 
	(또는 head 명령어도 가능하다 head -c 40 /dev/urandom > fileName)
	권한부여는 chmod를 사용 이진수를 이용하여 455
	날짜변경은 touch -t 옵션을 통해 MMDDhhmm fileName
	완료되면 압축파일 생성 
	tar 새로운 압축파일을 만드는 옵션 c
	파일을 저장하는 옵션 f
	tar -cf [압축파일명] [압축할 파일 또는 폴더경로]
	tar -cf testShell00.tar testShell00
	
* ls -l
	* 현재 디렉토리에 위치한 디렉, 파일을 출력
	* 형읽쓰실, 소유자계정, 그룹계정, 바이트크기 사이즈, 생성|최종수정된 시간, dir|fileName

	> 그룹계정 : 각 계정들이 속해있는 소속
	> 개발 1팀 소속이면 개발 1팀 그룹을 만들어 팀원들을 소속시킬 수 있다
	> 별도의 그룹에 포함시키지 않으면 본인 아이디와 동일하게 기재

* 권한변경	
	* -(d,|)rwx(user) rwx(group) rxw(other)

	> -(file), d(dir), |(link)<br>
	> r(read), w(write), x(excute)

	* rwx
		* 각 1비틕 총 3비트의 공간을 가진다
		* 이진수로 4 2 1 이므로 7 =rwx, 5 =r-x
	
	* chmod 권한을 바꾸는 명령어
		* (숫자사용법) chmod 이진수합 fileName 
		```
		$chmod 664 fileName -> rw- rw- r--
		```
		* (문자사용법) chmod u|g|o +|- r|w|x 
		```	
		$chmod g-x fileName -> rwx rwx rwx -> rwx rw- rwx
		```

* 특정 크기의 파일을 만드는 방법
	* fallocate<br>
	바이트 기준으로 지정<br>
	```
	$fallocate -l byteSize fileName
	```
	* truncate<br> 
	```
	$truncate -s 0 fileName
	```
	
	> 그 외 명령어 dd, head 
	> 숫자만 적으면 byte로 인식하고 K,M과 같은 단위를 통해 표현이 가능

* 생성|최종수정 날짜 변경
	* touch -t YYYYMMDDhhmm fileName
	
> 시간이 안나오고 년도가 나오는 경우가 있던데 무슨차이인가?
	
* tar
	* 파일을 압축하는 명령어
	* c : 새로운 압축파일을 만드는 옵션
	* f : 파일을 저장
	* tar -cf 압축파일이름.tar 압축할 파일/디렉토리
	
# Ex02

	1. ls -l 했을 때 2개의 dir, 4개의 file, 1개의 link 보이기
	2. -> 가 보이므로 link는 soft link
	
	[내 풀이]
	
	mkdir로 두개의 파일 생성
	touch로 세개의 파일 생성
	test5와 test6은 이후 링크생성과 동시에 생성
	soft file test6은 in -s [test0] [test6]옵션을 통해 생성
	test3과 5가 링크가 2인것을 보아 헤드링크 관계로 추정
	ln [test2] [test5]
	앞 문제와 동일하게 권한과 날짜 변경 touch -t
	소프트 링크파일을 날짜 변경해주기 위해서는 추가적인 옵션필요
	-h 원본 파일대신 심볼릭 링크에 영향을 주는 옵션
	
* soft link
	* soft link 파일을 만드는 명령어
	```
	$ln -s source target
	```
	* target에 이미 있는 파일이름을 적용할 수 없음(링크와 동시에 생성)
	* 서로 다른 inode값을 가짐
	* 같은 dir공간에 없을 경우 끊김
	
	> inode값을 확인하는법 : ls-li 의 좌측값

* hard link
	* hard link 파일을 만드는 명령어
	```
	$ln source target
	```
	

### 학습
linkFile은 다운받았을 때 사람이 알아보기 쉽도록 파일을 저장해놓은 링크파일<br>
FileSystem은 컴퓨터 연산에 용이한 실제 물리적인 하드디스크 위치에 저장된 파일 시스템<br>
두개의 테이블을 연결할 수 있는 key = inode<br>
fileSystem's Ref는 실제 Filesystem을 참조하는 linkFile의 갯수<br>
파일하나가 생성되면 최초 Ref 값은 1<br>
Ref가 0이되면 파일 삭제<br>
<HardLink><br>
파일 시스템에 저장된 inode 값을 똑같이 참조하는 linkFile을 또 만드는 것<br>
이에 따라 Ref+1<br>
HardLink는 원본이든 복사본이든 어느 파일이라도 수정하면 참조파일이 동시에 수정편집<br>
HardLink 생성 후 원본과 복사본의 의미가 없음, 원본파일 삭제해도 복사본 영향 없음<br>
HardLink는 file만 설정 가능(dir 불가)<br>
<br>
<SoftLink><br>
dir 나 file의 바로가기 기능<br>
링크파일이 링크파일을 참조하는 방식<br>
cf) Hard-는 링크파일이 FileSystem의 물리적 위치인 inode를 참조하는 방식<br>
dir, file 둘다 설정 가능<br>

# Ex03
	커버로스란?
	티켓을 기반으로 동작하는 컴퓨터 네트워크 인증 암호화 프로토콜
	사용자와 서버가 서로 식별할 수 있는 상호인증을 제공
	기본적으로 대칭 키 암호로 빌드
	즉 클라이언트와 서버구조에서 서버 접근권한에 대한 관리를 위해
	대칭키 방식을 이용하여 인증하는 네트워크 인증 암호화 프로토콜
	
	[내 풀이]
	klist 커버로스 티켓이 있는지 확인
	없을 경우 kinit으로 초기화하여 티켓 생성
	klist -l 로 모든 티켓 목록을 확인할 수 있음
	목록을 작성하여 klist.txt 파일로 저장
	
	https://codecademy.tistory.com/entry/Kerberos-Protocol-%EC%BB%A4%EB%B2%A0%EB%A1%9C%EC%8A%A4%EA%B0%80-%EB%AD%98%EA%B9%8C?category=962621
	
	klist 목록보기
	klist init 초기화하기

# Ex04
	1. 현재 dir내의 모든 file, dir(숨김 파일은 제외) 생성일 순서로 쉼표로 분리 나열하는 명령어
	2. 디렉토리 이름 뒤에 슬래시가 추가되어 있는지 확인
	[내 풀이]
	$ ls -Utmp
	
	ls-Ut를 리스트의 내용을 파일이 생성된 시간 순서대로 정렬
	같이 썻을때 어떠한 옵션이 있는지 확인하기
	
	생성일 순서로(U) 최종수정 순서(t) 쉼표분리해(m) 나열 디렉뒤에 슬래시추가(p)
	
* ls -option
	* -U<br>
	디스크에 저장된 파일대로 추력
	* -m<br>
	파일을 쉼표로 구분하여 가로로 출력
	* -t<br>
	최근에 만들어진 파일 순서대로 출력
	* -p<br>
	dir에 /를 추가
	* -a<br>
	dir 내의 숨겨진 모든 파일 출력	
	
	> ls -al/home/ 과 같이 출력하고 싶은 dir를 지정할 수 있음
	> 다양한 조합으로 ls 명령어 사용 가능
	> ex )ls -alSrh(숨겨진파일(a)까지 포함해서 파일크기(S) 역순(r)으로 보기좋게(h) 자세히(l))
	> ls > file.txt 처럼 리다이렉션 연산자를 통해 dir 내용을 파일에 저장가능

# Ex05
	<내 풀이>
	git저장소의 커밋 중 마지막 5개의 ID를 출력하라
	ID는 해시값을 의미
	
	git log 하면 commit 기록들이 나온다
	
	--pretty 지정한 형식으로 출력
	--pretty의 옵션으로 format는 원하는 형식으로 출력
	
	%H 커밋 해시
	최근 5개를 보고 싶다면 -5	

	git log --pretty=format:"%H" -5
	
	vim으로 해당 파일을 만들고 pretty 내용을 저장
	bash로 실행 | cat -e
	
	[추가 공부]
	git은 commit의 순서를 기억하기 위해 알고리즘으로 만들어진 hash값을 사용
	이는 중복 없는 임의의 문자열
	
	[틀렸음]
	이유 : 개행문자의 개입을 없애야함 
	git log --pretty=format:"%H" | head -n 5
	
	
# Ex06
	.gitignore에서 무시된 파일만을 나열하는 명령어

	보통 git에서 수정된 파일리스트를 얻기 위해서 git status를 많이쓰지만
	우리가 알고 싶은것은 파일만 나열하는 명령어를 요구
	git ls-files 명령어를 통해 가능
	
	add되지않은 파일들을 출력하고 싶다
	--others 옵션을 통해 add되지 않은 파일 출력이 가능
	git ls-files --others
	이로인해 출력된 문서들은 무시된 게 아니라 add 하지않아 출력된 파일들도 포함되어있음
	
	git ls-files --others --ignored
	위 명령어를 쳐보면 --ignored는 some exclude pattern이 필요하다고 함
	
	--exclude는 valude를 요구하는데
	
	git ls-files --others --ignored --exclude-standard
	untracked 파일 목록 조회
	문제에서 보여주는 출력값은 자체 환경에서 사용한 것이므로 본인과 다름
	
	[추가 공부]
	https://pythonq.com/so/git/406835
	
	
# Ex07
	1. file 'b' 생성
	2. diff a b<br>
	a 이후 추가해서 b를 만들어 업데이트 된 부분을 알려주는 diff
	3. diff a b > sw.diff
	4. 업데이트 된 부분을 합쳐서 최종본을 만들어라<br>
	patch a sw.diff > b
	
	[내 풀이]
	b 파일을 만들어라고 한다
	sw.diff파일은 a와 b의 패치파일임을 알 수 있다
	즉 a와 sw.diff를 이용하여 b를 만들자
	a를 sw파일을 통해서 패치하자
	
	patch -p0 < sw.diff 패치파일을 이용하여 a를 패치하면 된다
	-p는 패치파일에서 파일 이름 경로를 얼마나 제거해서 적용하는지 나타냄
	같은 위치에 있으니까 -p0
	어떤 파일을 패치하겠냐고하면 a를 선택
	이후 a를 b로 파일명 변경
	b를 제외한 모든 파일 삭제 후 제출	
	
* diff
	* 두 파일 사이의 내용을 비교하는 명령어
	* 3개 파일까지 비교 가능
	```
	diff [option] [비교파일1][비교파일2]
	diff3 [option] [비교파일1][비교파일2][비교파일3]
	```	
	
* patch
	* 두 파일들 간의 차이를 출력해 주는 프로그램인 diff에 의해 생성된 파일
	* patch 만들기
	```
	diff -uNr [원본파일][수정파일]>[패치파일명]
	ex) a.c를 b.c로 수정한 후 b.patch를 생성
		diff -uNf a.c b.c > b.patch
	```
	* patch 적용하기
	```
	patch [option][원본파일][패치파일]
	ex) a.c를 b.c로 수정한 후 b.patch를 생성
		diff a.c b.patch
	```
	
# Ex08 
	1. 현재 dir와 하위 dir에서 파일이름 키워드 검색 찾기<br>
	-> ~로 끝, #로 시작하거나 끝
	2. 이 명령어를 통해 검색한 모든파일 표시, 삭제
	2. 하나의 명령어만 사용할 것
	
	[내 풀이]
	$ find . -type f \( -name "#*#"" -o -name "*~" \) -print -delete
	
	파일이름을 가지고 현재 dir와 하위 dir 상에서 해당 파일이 있는지 찾음
	find 명령어는 파일과 디렉 모든 옵션을 검색
	find [option] [path] [expression]
	찾고자 하는 파일이나 디렉의 위치를 찾을 때 사용
	
	디렉이 아닌 파일을 찾는 것으로 유형을 정해줘야함
	-type f
	
	찾고싶은 파일에 대한 특정 키워드를 설정해주자
	두개 이므로 or(옵션 -o)을 적용한다 -name ["조건"] -o -name ["조건"]
	text로 여러 패턴을 찾고 싶을때
	find dir \( -name "*.py" -o -name "*.html" \)
	
	이후 검색 파일을 표시하고 삭제해야하므로 추가적인 Action이 필요하다
	-print와 -delete를 붙여주면 완성
	
	action으로 - 추가적인 명령을 주기 위해선 -exec [명령어] {} \;을 사용
	-exec 부터 \;까지의 명령어를 실행하겠다.
	대상은 {} 안에 앞의 명령어(find . \( \) )를 가져옴
	
	-delete로 별도의 외부명령어 추가 없이 사용 가능
	
* find
	* 파일, 디렉토리의 모든 옵션을 검색
	```
	find [options][path][expression]
	```	
	* 찾고자하는 파일이나 디렉토리의 위치를 찾을 때 주로 사용

	```
	현재 home_dir기준으로 fileName 를 찾고 싶다면
	$find . -name fileName.txt
	<결과예시>
	-> ./fileName.txt (현재 dir에 있고)
	-> ./backup/fileName.txt (백업 dir에도 있구나)
	
	권한이 없는 dir에서 찾고 싶다면 sudo를 입력
	```
	
* expression에는 Tests, Aactions, Operators가 올 수 있음
	* -type(Tests expression)<br>
	파일의 유형으로 파일을 찾음<br>
	f : 일반파일<br>
	d : 디렉토리<br>
	
	* -o<br>
	or 연산자<br>
	-연산 -o 연산(맨앞의 - 생략 가능)<br>
	-o 앞의 연산이나 -o 뒤의 연산조건을 일치하는 것을 찾아줌<br>
	-o가 없을 경우 모두 만족시키는(and) 것을 찾아줌<br>
	
	* -print(Actions expression)<br>
	action은 찾은 파일에 대해서 실해할 액션으로 생략해도 -print가 됨<br>
	검색된 파일 화면에 출력 옵션<br>
	* delete(Actions -)<br>
	파일 삭제
	
	* text로 여러 패턴을 같이 찾고 싶을때<br>
	```
	find dir \(-name "*.py" -o -name "*.html"\)
	```
	
* 인용부호 정리
	* 작은 따옴표, 큰 따옴표, 역 따옴표
	```
	$echo hi 와 $echo "hi" 둘다
	-> hi로 출력
	```
	* 큰따옴표 출력하고 싶다면
	```
	$echo "\"" #역 슬러시 쓰거나
	$echo \"
	$echo '"' #작은 따옴표로 큰 따옴표 감싸기
	```
	* 백슬러시 출력하고 싶다면
	```
	$echo "\\" #역 슬러시 쓰거나
	$echo \\
	$echo '\' #작은 따옴표로 역 슬러시 감싸기
	```

	공통점 -> 작은 따옴표로 감싸진 문자열은 변화없이 그대로 출력<br>
	
	*작은따옴표 출력하고 싶다면
	```
	$echo\'
	$echo"'"
	```
	
	총 정리<br> 
	작은 따옴표는 작은 따옴표 안에 있는 것을 가급적 그대로 출력<br>
	변수를 작은 따옴표 내에서 출력하면 변수명 그대로 출력<br>
	```
	$echo '$HOME'
	-> $HOME
	```
	<br>
	큰 따옴표는 큰 따옴표 안에 넣으면 실제 값으로 치환된 후 출력<br>
	```
	$echo "$HOME"
	-> /home/storycompiler
	```
	

# Ex09
	매직파일에 대한 이해
	
	file 명령어는 file의 종류를 확인하는 명령어로,
	제목 확장자를 보지않고 내용을 보고 ASCII, BINARY인지 확인함
	(리눅스에서는 확장자가 존재하지 않기 때문에 file을 써야함)
	해당 명령어는 파일시스템테스트 메직테스트 언어테스트 3단계로 확인작업을 진행
	magic = 매직파일이라 하며 이 파일로 파일분류를 진행
	매직파일에는 파일 분류를 위한 정보가 들어있음
	
	옵션
	-C 매직파일의 포맷을 검사
	-m 매직파일 : 지정된 매직파일로 대상 파일을 확인(직접 매직파일로 확인하려할 때)
	file -m ./[매직파일] [검사하고싶은파일]
	
	magic파일의 엔트리는 4개의 필드로 구성
	(1. 레벨의 offset 값, 데이터 종류, 값, 출력 문자열)
	예를들어
	0  string  check  ELF
	파일의 처음부터 0바이트 떨어진 위치의 문자열이 check와 일치하면 ELF로 표시
	
	42번째 바이트에 "42" 문자열이 있으면 특정 확인완료 체크가 되면 됨
	41번째로 맞춰야 다음에 오는 값부터 읽을 수 있으므로
	41
	종류는 문자열이므로
	string
	42라는 내용이 들어가야 하므로
	42
	체크되었다는 의미로 아무거나 적어주자 나는 파일명 적기
	42file
	
	[틀렸음]
	체크되었다는 의미로 42 file이라는 문자열이 정확히 나와야함
	띄어쓰기 허용하기 때문에 _ 사용 가능
* file 명령어
	* 파일의 종류를 확인할 때 사용
	```
	$file fileName
	결과 : fileName: ASCII text(예시)
	```
	* file 명령어는 확장자가 아닌 파일의 내용을 보고 파일의 종류를 말해줌<br>
	C source code가 적혀있는 파일 제목을 .txt로 저장하더라도 c source로 출력
	* 지정된 파일이 test파일인지 binary파일인지 확인시킴
	* file 명령어를 통해 파일시스템 테스트 - 매직 테스트 - 언어 테스트의 3가지 단계의 확인작업을 진행함

	