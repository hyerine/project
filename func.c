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
    {                                        //총 2번 파일을 >탐색
    while (!feof(fp)) {                      //파일 끝까지
        fscanf(fp, "%d", &out_num);            //질문의 답이 몇개>인지 out_num에 저장
        ffgets(buffer, SIZE, fp);

        if (i == 0 && !strcmp(in, buffer))
        {
            fine = 1;   //질문 일치?
        }

        if (i == 1 && strlen(buffer) < strlen(in) && strstr(in, buffer) != NULL)
        {
            fine = 1;
        }
        if (fine == 1)
        {
            random = rand() % out_num;
            nline(fp, random);              //출력할 대답으로 이동
            ffgets(buffer, SIZE, fp);       //대답을 buffer에 저장
            fclose(fp);
            return buffer;
        }
        nline(fp, out_num + 1);             //다음 질문으로 이동
    }
    rewind(fp);                             //파일의 처음으로
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
    {
        fgets(buffer, max, file);
        buffer[strlen(buffer) - 1] = '\0';               //개행문자 제거 & 널문자 입력
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
