# Exercise 00 : Z

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
# Exercise 01 : testshell00

	1. 파일 testShell00 생성
	2. ls -l 했을 때 -r--r-xr-x 1 XX XX 40 JUN 1 23:42 testShell00
	3. 다음 명령어 실행하여 제출 파일 생성
	tar -cf testShell00. tar testShell00.
	
* tar
	* 파일을 압축하는 명령어
	* c : 새로운 압축파일을 만드는 옵션
	* f : 파일을 저장
	* tar cf 압축파일이름.tar압축할 파일/디렉토리
	
* rxl

* byte 크기

* YYYYWWDDTTTT