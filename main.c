#include "sequence_lsit.h"
#include "Status.h"
int main (void)
{
    STUDENTS student;
    SqList sq_list;
    init_list(&sq_list);
    int location;
    int i;
    STUDENTS temp;
    for(i=1;i<=2;i++ )
    {
        printf("Please enter the students info\n");
        printf("Please enter the students name \n");
        gets(temp.name);
        printf("Please enter the students age \n");
        scanf("%d",&temp.age); 
        while('\n' != getchar());//会有一个换行符
        printf("you name is %s, and you age is %d\n",temp.name,temp.age);
        add_elem(&sq_list,i,temp);
    }
    STUDENTS text_print;
    get_elem(sq_list,&text_print);
    printf("you get the name is %s, and you age is %d\n",temp.name,temp.age);
    delete_elem(&sq_list ,1);
    print_elem(sq_list);
    return 0;
}

