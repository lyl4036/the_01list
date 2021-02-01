#include <stdio.h>
#include "Status.h"
#include<stdlib.h>
#include<string.h>
#ifndef __SEQUENCE_LIST 
#define __SEQUENCE_LIST
#define MAX_SIZE 100
#define MAX_NAME_SIZE 20
typedef struct STUDENTS
{
    char name[MAX_NAME_SIZE];
    int age;
}STUDENTS;
typedef struct SqList
{
    STUDENTS *ptr;
    int length;
    int max_length;
}SqList;


Status init_list(SqList *l);
Status add_elem (SqList *l,int i,STUDENTS elem);
Status delete_elem(SqList *l ,int j );
//STUDENTS get_elem(SqList l,int i);
//STUDENTS get_elem(SqList l,int i);
void print_elem(SqList l);
int length_list(SqList l);

#endif









