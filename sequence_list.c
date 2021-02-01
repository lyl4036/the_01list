/************************************************
//不变量用结构体变化的用结构体指针
//返回的error和元素不是同一处类型
//尽量用[i-1]去表达，好理解
*************************************************/


#include "sequence_lsit.h"
#include "Status.h"
Status init_list(SqList *l)
{
    (*l).ptr = (STUDENTS*)malloc((MAX_SIZE*sizeof(STUDENTS)));
    if (NULL == (*l).ptr)
        return ERROR;
    (*l).max_length = MAX_SIZE;
    (*l).length =0;
}

//统一以位置为起点
Status add_elem (SqList *l,int i,STUDENTS elem)
{
    if((*l).length >= MAX_SIZE)
        return OVERFLOW;
    if (i>(*l).length+1 || i<=0)
        return ERROR;
    //两种方法一时用指针作差二是用i作位置移动
    int num = l->length - i+1;//后面的元要动
    STUDENTS *temp = (*l).ptr+(*l).length-1;//最后的位置
    while (0 != num)
    {
        /* code */
        *(temp+1) = *temp;
        temp--;
        num--;
    }
     *((*l).ptr+i-1) = elem;
     ((*l).length)++;
}
Status delete_elem(SqList *l ,int j )
{   
    if (j>(*l).length||j<=0)
        return ERROR;
    STUDENTS *ptr = (*l).ptr + j-1;//指向要被删除的地方
    int num = (*l).length-j;
    int i;
    for(i=0;i<num;i++)
    {
    *(ptr+i) = *(ptr+i+1);
    }
    ((*l).length)--;
}
//不变量用结构体变化的用结构体指针
void print_elem(SqList l)
{
    int i;
    for (i = 1;i <= l.length;i++)
    {
        //先取出结构体
        STUDENTS temp;
        temp =*(l.ptr+i-1);
        printf("The location of the elem is %d ",i);
        printf("and the student name is %s, and the age is %d\n",temp.name,temp.age);
    }
}

int length_list(SqList l)
{
    return l.length;
}

// //返回的error和元素不是同一处类型
// STUDENTS get_elem(SqList l,int i)
// {
//     if(l.length< i ||i<=0)
//     {
//         absort();
//     }
//     return *(l.ptr+i-1);
// }




//返回的error和元素不是同一处类型
/*
STUDENTS * get_elem(SqList l,int i)
{
    if(l.length< i ||i<=0)
    {
        absort();
    }
    return (l.ptr+i-1);
}
*/
Status get_elem(SqList l,int i,STUDENTS *ptr)
{
    if(l.length< i ||i<=0)
    {
        return ERROR;
    }
    *ptr =l.ptr[i-1];//不有*了想想为啥
    return OK;
}