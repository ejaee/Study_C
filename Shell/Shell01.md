# ex00 금요일 시험 관련 공지
	터미널 켜기
	docs 파일로 이동
	ls -a 명령어로 Readme.ko.md 확인
	Readme 파일에 따라서 기본 터미널에 examshell 입력
	examshell이 켜지면 요구하는대로 kinit '인트라아이디' 입력
	요구하는대로 터미널에 다시 examshell 입력

	완료하면 왼쪽위에 자기 얼굴이 나타남
	시험시작 10분안에 자기 사진이 띄워져 있으면 시험응시가능
	
	시험시작
	기본 터미널 홈 디렉토리에 subject, rendum trace 디렉이 생김
	subject
	이 디렉에 영어 불어 국어 문제들이 주어짐
	rendu
 	subject에서 요구한 디렉과 파일들을 작성해서 제출하는 디렉
	평소 과제를 제출하는 것 처럼 git add commit push 하면 됨
	trace
	제출한 파일을 시스템에서 적절히 컴파일하고 실행한 후
	diff 명령어를 통해 testcase와 비교한 로그들이 찍혀있음
	디버깅할 때 살펴보면 좋음
	
	제출방법
	rendu 디렉에 문제에서 요구한 디렉과 파일만 남긴다
	rendu 디렉에서 git add, commit, push
	examshell에 grademe 입력
	30초정도 지나면 success 또는 fail 이뜸
	fail 경우 수정제출이 가능하지만 대기시간 패널티 발생
	success 경우 subject 디렉에 다음문제가 주어짐
	
# 환경변수에 대한 이해
	FT_USER는 환경변수에 포함 된 로그인 그룹 목록을 표시하는 방법
	환경변수가 무엇인가
	
	프로그램에서
	전역변수(프로그램 전체에 영향을 미치는 변수)
	지역변수(프로그램 함수 내에서만 통영되는 변수)
	
	리눅스 시스템상에서
	전역변수(시스템 환경 전체에 영향을 미치는 변수, 환경변수) -env
	지역변수 - set
	
	리눅스에서는 두종류의 사용자가 있다
	# root시스템 전체를 관리할 수 있는 사용자
	$, % 일반사용자
	HOME 디렉토리를 벗어나면 일반사용자는 권한이 없다
	root사용자는 모든 권한을 가진다
	
	env 명령어를 쓰면
	좌측에 환경변수, 우측에 값
	HOME=root
	
	변수를 출력할 때는 $를 붙인다
	echo $HOME 하면
	root
	
	HISTSIZE 변수 우리가 내린 가장 최근에 명령어 1000개를 저장할 수 있는 변수
	
	set 명령어를 쓰면 지역변수가 나온다
	지역변수 만드는법
	a=600
	b"korea"
	echo $a(b) 하면
	600(korea) 나온다
	
	지역변수 set는 터미널을 껏다키면 세션이 달라지므로 초기화된다
	set은 사실 엄밀히 말하면 명령행 인자를 다루는 것
	명령행 위치 인자를 설정할 수 있다
	
	환경변수 설정하는 방법
	$ export Test='testing'
	echo $Test 하면
	teting 이라고 출력
	unset Test 하면 환경변수를 해제한다
	
	환경변수의 값은 절대 변하지 않는다
# ex01 print_groups	
	tr 명령어
	tr [옵션] 문자열1 [문자열2]
	지정한 문자를 변환하거나 삭제하는 명령어
	특정 문자를 다른 문자로 변환하거나
	특정 문자를 제거하는데 사용
	
	[옵션]
	-d 문자열1에서 지정한 문자 삭제
	-s 문자열2에서 반복되는 문자 삭제
	-t 문자열1을 문자열2의 길이로 자르기
	
	echo AaAa | tr 'a-z' 'A-Z'
					소문자를 대문자로
	AAAA
	echo a b c | tr ' ' ','
					빈칸에 쉼표
	
	

	groups 그룹명 명령어
	그룹에 속한 사용자 계정을 확인할때 사용하는 명령어
	$groups user01 하면
	user01 그룹에 포함되어있는 사용자를 나열
	
	$groups FT_user | tr ' ' ','
	
# ex02 find_sh
	현재 디렉과 그 하위 디렉에서 '.sh'로 끝나는 모든 파일 찾기
	파일이름 나열할때는 .sh를 제외해서 세로로 출력
	어제 문제와 다른점은 파일과 dir이 아닌 파일만을 찾는 것
	find . -name"*.sh" -execdir basename{} .sh ";"
	
	핵심
	1. .sh을 찾되 출력에서는 제외시킨다
	basename 명령어 사용
	이는 file full path로 부터 파일 이름만 추출
	suffix(접미사)를 없앨 수 있음
	/usr/lib64/test.co라는 파일이 있을 경우
	$basename /usr/lib64/test.co을 실행하면
	test.co 가 출력(dir 미출력)
	접미사를 지우고 싶다면
	$basename /usr/lib64/test.co .co를 실행하면
	test
	
	execdir command{} 액션을 사용하는 경우
	-execdir은 그 다음 오는 명령어를 사용할 때 검색된 파일의 경로를 제외하고
	파일명 만을 인자로 사용
	-exec는 경로를 포함한 파일을 보여주지만
	-execdif은 경로 없이 파일명만을 보여줌
	
	;인지 ";"인지 확인하자
	
# ex03 count_files.sh
	현재 디렉과 그 하위 모든 디렉에 있는 일반 파일과 디렉 개수를 세어 표시하는 명령어
	.도 포함되어서 출력
	
	find . -type f | wc -l | tr -d " " 
	
	tr 명령어
	tr [옵션] 문자열1 [문자열2]
	지정한 문자를 변환하거나 삭제하는 명령어
	특정 문자를 다른 문자로 변환하거나
	특정 문자를 제거하는데 사용
	
	[옵션]
	-d 문자열1에서 지정한 문자 삭제
	
# ex04 MAC
	컴퓨터의 MAC 주소를 표시하는 명령어
	출력 시 줄바꿈이 나타나야함
	ifconfig -a 모든 네트워크 인터페이스 구성을 확인
	https://blog.naver.com/cumulusworld/220102945835
	
	ifconfig -a | grep 'ether ' | tr -d '\t' | sed 's/ether //g'
	Ifconfig -a ether | grep ether | cut -d “ “ -f2
	
	ifconfig
	ip를 확인하는 명령어
	
	mac 주소는 ether이라고 함
	
	
	
# ex05 can you create it?
	오직 42만 포함하는 파일 작성
	파일이름 = "\?$*'MaRViN'*$?\"
	원래 파일에는 특수문자가 안되는데 앞에 \를 붙이면 특수문자 사용이 가능
	
	"\\\?\$\*’MaRViN’\*\$\?\\\"
	 "  \  ?  $  *  '
	\" \\ \? \$ \* \'
	
	<cat -e 명령어>
	제어 문자를 ^ 형태로 출력하면서 각 행의 끝에 $을 추가
	cat -e = cat -vE
	-v : taa과 행바꿈 문자를 제외한 제어문자를 ^형태로 출력
	-E : 행마다 끝에 $ 문자를 출력
	
	오직 42만을 포함하는 파일을 작성하기위해서는 개행문자를 넣어야하는가?에 대한 나의 생각
	tr -d '\n' 으로 삭제해야 하는것이 맞음
	xxd 헥사덤프를 통해 유닉스 체제에서는 개행문자가 16진수로 0a로 나타낸다는 것을 확인
	파일의 크기에 영향을 주므로 반드시 삭제하는것이 맞음
	
# ex06 skip
	ls -l 명령어의 첫번째 행부터 시작해 다른 모든 행을 보여주는 명령어
	ls -l | awk "NR%2==1"
		
	awk 파일로부터 레코드를 선택하고 선택된 레코드에 포함된 값을 조작하거나 데이터화하는 것을 목적으로 사용하는 프로그램
		텍스트 파일의 전체내용을 출력하거나
		파일의 특정 필드만 출력할 때 사용
		한마디로 말해 텍스트 파일로 저장되어있는 파일을 자신이 원하는 부분만 출력
		파일의 내용을 모두 출력할 때 (awk '{print}' FILE)
		파일의 첫번째 두번째 필드만 출력(awk '{print $1, $2}' FILE) --- 1,2열 출력
		문자열 "A"를 포함하는 레코드만 출력(awk '/A/' FILE)
		즉 입력데이터로부터 주어진 패턴을 포함하는 라인을 찾기 위해 파일의 내용을 탐색한 뒤 패턴에 일치하는 라인이 발견되면 해당 라인에 대해 지정된 액션을 실행
	awk [option] [awk program] [argument]
	
	행번호를 출력하기 위해서는 print NR 옵션
	
	
	https://mug896.github.io/awk-script/basics.html
	
# ex07

# ex08
