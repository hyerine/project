
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
        

        if (strcmp(out, ""))
        {                                   //������ ���� ����������
            if (teach == 1)
            {                                 // ����ġ�� �����϶�
                printf("i know.\n\n");
                in = in - 3;                //�Ҵ� ���� ��ŭ free�ϱ� ���� �ٽ� in�� ũ�⸦ �����·� ����
            }
            return_answer(out);                  //out�� ���
        }
        else
        {
            printf(" I don't know. Please teach me. \n\n");
            TEACH(in);
            if (teach == 1) in = in - 3;         //�Ҵ� ���� ��ŭ free�ϱ� ���� �ٽ� in�� ũ�⸦ �����·� ����
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
   while (1) {                         //�ƹ��͵� �Է¾��ϸ� �ݺ� -> �Է��Ҷ� ���� �ݺ�
    printf("%s : ", nugu);
    ffgets(buffer, SIZE, stdin);
    printf("\n");                       //������ SIZE��ŭ ����Ʈ stdin -> �����ġ
    if (strcmp(buffer, "")) break;            //�ԷµǸ� �ݺ��� Ż��
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
    fprintf(fp, "%d%s\n", num, in);//����� ������ ������ ����
    for (i = 0; i < num; i++)
    {         //����� ������ŭ for��
    inputs(buffer, "TEACH");//TEACH : ����� �Է¹���
    fprintf(fp, "%s\n", buffer);//�Է¹��� ����� ���Ͽ� ����
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

    if ((fp = fopen("Q&A.txt", "r")) == NULL) return "";      //������ ������ ����

        for (i = 0; i < 2; i++)
        {                                        //�� 2�� ������ Ž�� i - 0.�Ϻ��� ��ġ�ϴ°�,  1.���� ��ġ�ϴ°�
        while (!feof(fp)) {                      //���� ������ Ž��
        fscanf(fp, "%d", &out_num);            //������ ���� ����� output_num�� ����
        ffgets(buffer, SIZE, fp);                   //buffer�� ���� ����

        if (i == 0 && !strcmp(in, buffer)) check = 1;   //���� ��ġ?

            if (i == 1 && strlen(buffer) < strlen(in) && strstr(in, buffer) != NULL)
            {                                                                  
                check = 1;
             }

            if (check == 1) //input�� ������ ��ġ�ų� ���
            {
                random = rand() % out_num; //������ ���� ����� ���� �������� ����
                nline(fp, random);//����� ������� �̵�
                ffgets(buffer, SIZE, fp);//����� buffer�� ����
                fclose(fp);
                return buffer;//������ ����� ����
            }
            nline(fp, out_num + 1);//���� ������ �ִ� ������ġ�� �̵�
        }
        if (teach == 1) break;
        rewind(fp); //������ ó������

        }
        fclose(fp);
        return "";
}

char* s_malloc(int len)
{
    return (char*)malloc(sizeof(char)*len);            //len ��ŭ �����Ҵ�
}

char* ffgets(char *buffer, int max, FILE *file)
{
    fgets(buffer, max, file); //���ٺҷ���
    buffer[strlen(buffer) - 1] = '\0';  //���๮�� ���� & �ι��� �Է�
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

