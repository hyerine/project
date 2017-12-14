
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
        

        if (strcmp(out, ""))
        {                                   //질문에 대한 대답있을경우
            if (teach == 1)
            {                                 // 가르치기 상태일때
                printf("i know.\n\n");
                in = in - 3;                //할당 받은 만큼 free하기 위해 다시 in의 크기를 원상태로 복구
            }
            return_answer(out);                  //out을 출력
        }
        else
        {
            printf(" I don't know. Please teach me. \n\n");
            TEACH(in);
            if (teach == 1) in = in - 3;         //할당 받은 만큼 free하기 위해 다시 in의 크기를 원상태로 복구
        }
        free(in);
        free(out);
    }
    return 1;
}

void return_answer(char *out)
{
    printf("--------------------\n");
    printf("      |       |     \n");
    printf("          Y         \n");
    printf("-------------------- %s\n\n",out);
}

void inputs(char *buffer, char *nugu)
{
   while (1) {                         //아무것도 입력안하면 반복 -> 입력할때 까직 반복
    printf("%s : ", nugu);
    ffgets(buffer, SIZE, stdin);
    printf("\n");                       //내용을 SIZE만큼 프린트 stdin -> 출력장치
    if (strcmp(buffer, "")) break;            //입력되면 반복문 탈출
   }
}

void TEACH(char *in)
{
    char buffer[SIZE];
    int num, i;
    FILE *fp;
    fp = fopen("Q&A.txt", "a");

    printf("Enter number of answers to teach.(Zero input skip)");
    scanf("%s", buffer);
    num = atoi(buffer);

    if (num == 0)
    {
        fclose(fp);
        return;
    }
    fprintf(fp, "%d%s\n", num, in);//대답의 갯수와 질문을 저장
    for (i = 0; i < num; i++)
    {         //대답의 갯수만큼 for문
    inputs(buffer, "TEACH");//TEACH : 대답을 입력받음
    fprintf(fp, "%s\n", buffer);//입력받은 대답을 파일에 저장
    }
    fprintf(fp, " \n");

    fclose(fp);
}

char* search_inputs(char *in, int teach)
{
    FILE *fp;
    int out_num, random, check = 0, i;
    char *buffer;
    buffer = s_malloc(SIZE);

    if ((fp = fopen("Q&A.txt", "r")) == NULL) return "";      //파일이 없으면 리턴

        for (i = 0; i < 2; i++)
        {                                        //총 2번 파일을 탐색 i - 0.완벽히 일치하는가,  1.조금 일치하는가
        while (!feof(fp)) {                      //파일 끝까직 탐색
        fscanf(fp, "%d", &out_num);            //질문의 답이 몇개인지 output_num에 저장
        ffgets(buffer, SIZE, fp);                   //buffer에 질문 저장

        if (i == 0 && !strcmp(in, buffer)) check = 1;   //질문 일치?

            if (i == 1 && strlen(buffer) < strlen(in) && strstr(in, buffer) != NULL)
            {                                                                  
                check = 1;
             }

            if (check == 1) //input과 질문과 일치거나 비슷
            {
                random = rand() % out_num; //질문의 답중 출력할 답을 랜덤으로 설정
                nline(fp, random);//출력할 대답으로 이동
                ffgets(buffer, SIZE, fp);//대답을 buffer에 저장
                fclose(fp);
                return buffer;//저장한 대답을 리턴
            }
            nline(fp, out_num + 1);//다음 질문이 있는 파일위치로 이동
        }
        if (teach == 1) break;
        rewind(fp); //파일의 처음으로

        }
        fclose(fp);
        return "";
}

char* s_malloc(int len)
{
    return (char*)malloc(sizeof(char)*len);            //len 만큼 동적할당
}

char* ffgets(char *buffer, int max, FILE *file)
{
    fgets(buffer, max, file); //한줄불러옴
    buffer[strlen(buffer) - 1] = '\0';  //개행문자 제거 & 널문자 입력
    return buffer;
}

void nline(FILE *file, int sun)
{
    int i;
    for (i = 0; i < sun; i++)
    {
        while (!feof(file))
        {
            if (fgetc(file) == '\n') break;
        }
    }
}

