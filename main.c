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
        in = s_malloc(strlen(buffer) + 1);      //buffer��ŭ ���ڿ� ������� �Ҵ�
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

        strcpy(buffer, search_inputs(in, teach));      //out�� ã>�Ƽ� buffer�� ����
        out = s_malloc(strlen(buffer) + 1);         //buffer��ŭ >���ڿ� ������� �Ҵ�
        strcpy(out, buffer);

        if (strcmp(out, ""))
        {                                   //������ ���� ����������
        return_answer(out);                  //out�� ���
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

