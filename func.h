#ifndef FUNC_H
#define FUNC_H
#define SIZE 500
#define RESET "\x1B[0m"
#define MAG   "\x1B[35m"
#include<stdio.h>
#include<time.h>
#include<stdlib.h>
#include<string.h>

void return_answer(char *out);                                                                                //대답 프린트
void inputs(char *buffer, char *nugu);              //문자열 입력
void TEACH(char *buffer);                           //대답을 파일>에 입력
char* search_inputs(char *in, int teach);           //질문에 대한 대답
char* s_malloc(int len);                            //문자열 동적>할당
char* ffgets(char *buffer, int max, FILE *file);    //개행문자제거
void nline(FILE *file, int sun);                    // 다음줄로 이동

#endif
