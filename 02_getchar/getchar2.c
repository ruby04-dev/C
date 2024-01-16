#include <stdio.h>
#include <curses.h>
//콘솔 입출력 함수를 제공하는 헤더
//<conio.h> MacOS 에서 support 되지 않음
//<curses.h> 사용, ncurses 설치 필요
//brew install ncurses
#include <locale.h>
//locale 설정 라일브러리
//ncurses 라이브러리와 유니코드 문자를 사용하려면 locale 설정 필요.

int main(void)
{   
    setlocale(LC_ALL,"en_US.UTF-8");
    //유니코드를 사용하기 위해 locale 설정해준다.

    initscr();
    noecho();

    refresh();

    char ch = 0;
    printw("아무키나 누르면 다음으로 넘어갑니다.\n");

    ch = getch();
    // <conio.h>의 _getch() 대신 <ncurses.h>의 getch() 사용
    printw("입력한 키는 ");
    addch(ch);
    printw("입니다.\n");

    printw("아무키나 누르면 종료합니다.\n");

    getch(); //자동 종료 방지

    endwin();
    return 0;

}
