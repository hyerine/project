#ifndef FUNC_H
#define FUNC_H
#define SIZE 500
#define RESET "\x1B[0m"
#define MAG   "\x1B[35m"
#include<stdio.h>
#include<time.h>
#include<stdlib.h>
#include<string.h>

void return_answer(char *out);                                                                                //��� ����Ʈ
void inputs(char *buffer, char *nugu);              //���ڿ� �Է�
void TEACH(char *buffer);                           //����� ����>�� �Է�
char* search_inputs(char *in, int teach);           //������ ���� ���
char* s_malloc(int len);                            //���ڿ� ����>�Ҵ�
char* ffgets(char *buffer, int max, FILE *file);    //���๮������
void nline(FILE *file, int sun);                    // �����ٷ� �̵�

#endif
