# 

## 1. Hello, World!

// shift+cmd+b 빌드
// shift+cmd+r 런

// cmd+k+c 주석 지정
// cmd+k+u 주석 해제

// 미래의 나에게 보내는 설명
// 일기가 아니다.

## 2. Console 과 CLI, I/O Buffer

// 키보드 입력 시 그 값은 메모리(I/O Buffer)에 연속적으로 저장 (Queue)
// I/O Buffer에서 한 글자 단위로 처리

// user mode 에서 "디바이스 파일"(장치를 추상화한 인터페이스)을 이용하여 kernel mode에 접근하여, 입출력 장치를 제어한다.

//                                  [process: getchar]
//      User mode           File[I/O Buffer] -> AZ  File[I/O Buffer] -> A\n
//      ---------------------------------------------------------------------
//      Kernel mode                      OS      
//
// SW                   Driver                        Driver
// ------------------------------------------------------------------------------
// HW                  Console          RAM          keyboard

// keyboard 에서 key 입력 시 인터럽트 발생 -> 드라이버를 통해 -> OS 에서 처리하고 -> device file 의 I/O Buffer에 저장
// ch = getchar() : RAM에 ch를 만들고 I/O Buffer의 'A'를 복사
// putchar(ch) : I/O Buffer 에 ch의 내용 'A'추가
// putchar('Z') : I/O Buffer 에 'Z' 추가
// device file -> OS -> device driver -> console 출력

getchar() / putchar()
* <stdio.h>
* Buffered I/O
* 값이 저장된 메모리 값을 읽거나 출력

_getch()/ _getche()
* <conio.h> macOS 에서 사용불가
* Non-buffered I/O
* 키보드 입력 자체에 대한 감지

// 대부분의 장치는 I/O Buffer를 사용하는 Buffered I/O 방식을 사용한다.
// Non-buffered I/O 는 키입력 감지 (사용예: 진행하려면 아무키나 누르시오)

gets() / puts() / gets_s()
* gets()는 보안결함 문제가 있음, gets_s() 사용하자
* 리눅스 계열에서는 
fgets_(), fgets() 사용

fgets_() / fgets() 
* 파일 입출력 사용
* stdin 에서 문자열을 읽어온다
* fgets() 함수는 지정된 스트림(stream)에서 문자열을 읽어서 버퍼(str)에 저장하고, 지정된 최대 문자 수(size)를 초과하지 않도록 읽기를 중지합니다. 문자열의 끝에는 NULL 문자('\0')가 추가되어 문자열로 만듭니다. 이렇게 하면 읽은 문자열을 문자열로 처리할 수 있습니다.



// stdin : 키보드 입력 디바이스 파일 
// stdout : 콘솔 출력 디바이스 파일

// 파일 입출력
* 문자열은 null문자 '\0' 로 끝난다.
* 문자열의 길이를 사전에 알 수 없기 때문에, 문자열은 가변길이 메모리에 저장해야한다.
printf() / scanf(), scanf_s()
