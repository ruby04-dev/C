#include <stdio.h>

int main(void)
{
    char ch = 0;
    // 변수의 선언 + 정의
    // char : 1byte,  int : 4byte
    // 하지만 어느정도 호환되는 부분이 있다.

    ch = getchar();
    // I/O Buffer(Queue)에서 1글자를 가져와.
    putchar(ch); 
    putchar('Z');

    return 0;
}

//                                  [process: getchar]
//      User mode           File[I/O Buffer] -> AZ  File[I/O Buffer] -> A\n
//      ---------------------------------------------------
//      Kernel mode                      OS      
//
// SW                   Driver                        Driver
// -------------------------------------------------------------
// HW                  Console          RAM          keyboard

// keyboard 에서 key 입력 시 **인터럽트** 발생 -> 드라이버를 통해 -> OS 에서 처리하고 -> interface file 의 I/O Buffer에 저장
// ch = getchar() : RAM에 ch를 만들고 I/O Buffer의 'A'를 복사
// putchar(ch) : I/O Buffer 에 ch의 내용 'A'추가
// putchar('Z') : I/O Buffer 에 'Z' 추가
// interface file -> OS -> 인터럽트 + 출력요청 -> device driver -> console 출력



