#include <stdio.h>
#include <windows.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <string.h>

#define LEN sizeof(struct Book)

typedef struct Book
{
	char num[14];
	char title[21];
	char author[9];
	char publisher[21];
	char time[11];
	char price[7];
	struct Book *next;
}Book;

Book stu, tem;

FILE *fp;
struct Book *p1, *p2, *p3, *head, *tail;
typedef unsigned char SString[30];

//
