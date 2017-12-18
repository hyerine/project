#include "func.h"


int main()
{
    char *buffer;
    int teach;
    char *in;
    char *out;
    char name[15];
    buffer = s_malloc(SIZE);
    srand((unsigned)time(NULL));

    printf(MAG "what is your name? " RESET);
    scanf("%s", name);
    getchar();
    while (1)
    {
        teach = 0;

        inputs(buffer, name);
        in = s_malloc(strlen(buffer) + 1);      //buffer만큼 문자열 저장공간 할당
        strcpy(in, buffer);

        if(!strcmp("fuck",in))
        {
            printf(MAG "do not say bad word! :(\n" RESET);
            break;
        }

        if (!strcmp("bye", in))
        {
            printf(MAG "goodbye~ \n\n" RESET);
            break;
        }

        strcpy(buffer, search_inputs(in, teach));      //out을 찾>아서 buffer에 저장
        out = s_malloc(strlen(buffer) + 1);         //buffer만큼 >문자열 저장공간 할당
        strcpy(out, buffer);

        if (strcmp(out, ""))
        {                                   //질문에 대한 대답있을경우
        return_answer(out);                  //out을 출력
        }
        else
        {
            printf(MAG " I don't know. Please teach me. \n\n" RESET);
            TEACH(in);
        }
        free(in);
        free(out);
    }
    return 1;
}

