#include<stdio.h>
#include<time.h>
#include<stdlib.h>
#include<string.h>
#define SIZE 500

void return_answer(char *out);                      //대답 프린트
void inputs(char *buffer, char *nugu);              //문자열 입력
void TEACH(char *buffer);                           //대답을 파일에 입력
char* search_inputs(char *in, int teach);           //질문에 대한 대답
char* s_malloc(int len);                            //문자열 동적할당
char* ffgets(char *buffer, int max, FILE *file);    //개행문자제거
void nline(FILE *file, int sun);                    // 다음줄로 이동

int main()
{
    char *buffer;
    int teach;
    char *in;
    char *out;
    char name[15];
    buffer = s_malloc(SIZE);
    srand((unsigned)time(NULL));

    printf("what is your name? ");
    scanf("%s",name);

    while (1)
    {
        teach = 0;

        inputs(buffer, name);
        in = s_malloc(strlen(buffer) + 1);      //buffer만큼 동적할당(+널문자)
        strcpy(in, buffer);

        if(!strcmp("fuck",in))
        {
            printf("do not say bad word! :(\n");
            break;
        }

        if (!strcmp("bye", in))
        {
            printf("goodbye~ \n\n");
            break;
        }

        strcpy(buffer, search_inputs(in, teach));      //in에 맞는 out을 찾아서 buffer에 저장
        out = s_malloc(strlen(buffer) + 1);         //out을 buffer만큼 동적할당(+널문자)
        strcpy(out, buffer);                     //out에 buffer를 넣음
