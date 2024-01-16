#include <stdio.h>


int main()
{
    char szName[32] = { 0 }; // 32개를 다 0으로 채워준다.
    // 'sz' :  0으로 끝나는 문자열

    printf("이름을 입력하세요: ");
    fgets(szName, sizeof(szName), stdin);
    // gets()는 보안결함 문제가 있음, gets_s() 사용, macOS 사용 불가
    // fgets(버퍼의 포인터, 읽을 최대 문자 수, 입력 스트림 포인터)
    
    printf("당신의 이름은 ");
    puts(szName);
    puts("입니다.");

    return 0;
}
