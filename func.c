#include "func.h"

void return_answer(char *out)
{
    printf(MAG "--------------------\n" RESET);
    printf(MAG "      |       |     \n" RESET);
    printf(MAG "          Y         \n" RESET);
    printf(MAG "-------------------- %s\n\n" RESET,out);
}

void inputs(char *buffer, char *nugu)
{
    while (1) {
        printf("%s : ", nugu);
        ffgets(buffer, SIZE, stdin);
        printf("\n");
        if (strcmp(buffer, "")) break;
    }
}

void TEACH(char *in)
{
    char buffer[SIZE];
    int num, i;
    FILE *fp;
    fp = fopen("q.txt", "a");

    printf(MAG "Enter number of answers to teach.(Zero input skip)" RESET);
    scanf("%s", buffer);
    getchar();
    num = atoi(buffer);

    if (num == 0)
    {
        fclose(fp);
        return;
    }
    fprintf(fp, "%d%s\n", num, in);
    for (i = 0; i < num; i++)
    {
        inputs(buffer, "TEACH");
        fprintf(fp, "%s\n", buffer);
    }
    fprintf(fp, " \n");

    fclose(fp);
}

char* search_inputs(char *in, int teach)
{
    FILE *fp;
    int out_num, random, fine = 0, i;
    char *buffer;
    buffer = s_malloc(SIZE);

    if ((fp = fopen("q.txt", "r")) == NULL) return "";

    for (i = 0; i < 2; i++)
    {                                        //�� 2�� ������ >Ž��
    while (!feof(fp)) {                      //���� ������
        fscanf(fp, "%d", &out_num);            //������ ���� �>���� out_num�� ����
        ffgets(buffer, SIZE, fp);

        if (i == 0 && !strcmp(in, buffer))
        {
            fine = 1;   //���� ��ġ?
        }

        if (i == 1 && strlen(buffer) < strlen(in) && strstr(in, buffer) != NULL)
        {
            fine = 1;
        }
        if (fine == 1)
        {
            random = rand() % out_num;
            nline(fp, random);              //����� ������� �̵�
            ffgets(buffer, SIZE, fp);       //����� buffer�� ����
            fclose(fp);
            return buffer;
        }
        nline(fp, out_num + 1);             //���� �������� �̵�
    }
    rewind(fp);                             //������ ó������
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
    {
        fgets(buffer, max, file);
        buffer[strlen(buffer) - 1] = '\0';               //���๮�� ���� & �ι��� �Է�
        return buffer;
    }
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
