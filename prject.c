#include<stdio.h>
#include<time.h>
#include<stdlib.h>
#include<string.h>
#define SIZE 500

void return_answer(char *out);                      //��� ����Ʈ
void inputs(char *buffer, char *nugu);              //���ڿ� �Է�
void TEACH(char *buffer);                           //����� ���Ͽ� �Է�
char* search_inputs(char *in, int teach);           //������ ���� ���
char* s_malloc(int len);                            //���ڿ� �����Ҵ�
char* ffgets(char *buffer, int max, FILE *file);    //���๮������
void nline(FILE *file, int sun);                    // �����ٷ� �̵�

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
        in = s_malloc(strlen(buffer) + 1);      //buffer��ŭ �����Ҵ�(+�ι���)
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

        strcpy(buffer, search_inputs(in, teach));      //in�� �´� out�� ã�Ƽ� buffer�� ����
        out = s_malloc(strlen(buffer) + 1);         //out�� buffer��ŭ �����Ҵ�(+�ι���)
        strcpy(out, buffer);                     //out�� buffer�� ����
