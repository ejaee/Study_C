# Ex00

	1. z 이름의 파일 만들기
	2. cat으로 Z와 함께 줄바꿈이 표시되도록 하기

	```
	echo Z > z
	```
	
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
	* >(redirection)기호 : 사용을 통해 입력한 내용으로 새로운 파일을 만든다
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
	
* ls -l
	* 현재 디렉토리에 위치한 디렉, 파일을 출력
	* 형읽쓰실, 소유자계정, 그룹계정, 바이트크기 사이즈, 생성|최종수정된 시간, dir|fileName

	>> 그룹계정 : 각 계정들이 속해있는 소속
	>> 개발 1팀 소속이면 개발 1팀 그룹을 만들어 팀원들을 소속시킬 수 있다
	>> 별도의 그룹에 포함시키지 않으면 본인 아이디와 동일하게 기재

* 권한변경	
	* -(d,|)rwx(user) rwx(group) rxw(other)

	>> -(file), d(dir), |(link)
	>> r(read), w(write), x(excute)

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
	
	>> 그 외 명령어 dd, head 
	>> 숫자만 적으면 byte로 인식하고 K,M과 같은 단위를 통해 표현이 가능

* 생성|최종수정 날짜 변경
	* touch -t YYYYMMDDhhmm fileName
	
>> 시간이 안나오고 년도가 나오는 경우가 있던데 무슨차이인가?
	
* tar
	* 파일을 압축하는 명령어
	* c : 새로운 압축파일을 만드는 옵션
	* f : 파일을 저장
	* tar -cf 압축파일이름.tar 압축할 파일/디렉토리
	
# Ex02

	1. ls -l 했을 때 2개의 dir, 4개의 file, 1개의 link 보이기
	2. -> 가 보이므로 link는 soft link
	
* soft link
	* soft link 파일을 만드는 명령어
	```
	$ln -s source target
	```
	* target에 이미 있는 파일이름을 적용할 수 없음(링크와 동시에 생성)
	* 서로 다른 inode값을 가짐
	* 같은 dir공간에 없을 경우 끊김
	
	>> inode값을 확인하는법 : ls-li 의 좌측값

* hard link
	* hard link 파일을 만드는 명령어
	```
	$ln source target
	```
	

### 학습
linkFile은 다운받았을 때 사람이 알아보기 쉽도록 파일을 저장해놓은 링크파일
FileSystem은 컴퓨터 연산에 용이한 실제 물리적인 하드디스크 위치에 저장된 파일 시스템
두개의 테이블을 연결할 수 있는 key = inode
fileSystem's Ref는 실제 Filesystem을 참조하는 linkFile의 갯수
파일하나가 생성되면 최초 Ref 값은 1
Ref가 0이되면 파일 삭제
<HardLink>
파일 시스템에 저장된 inode 값을 똑같이 참조하는 linkFile을 또 만드는 것
이에 따라 Ref+1
HardLink는 원본이든 복사본이든 어느 파일이라도 수정하면 참조파일이 동시에 수정편집
HardLink 생성 후 원본과 복사본의 의미가 없음, 원본파일 삭제해도 복사본 영향 없음
HardLink는 file만 설정 가능(dir 불가)

<SoftLink>
dir 나 file의 바로가기 기능
링크파일이 링크파일을 참조하는 방식
cf) Hard-는 링크파일이 FileSystem의 물리적 위치인 inode를 참조하는 방식
dir, file 둘다 설정 가능

# Ex03