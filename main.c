#include<stdio.h>
#include<stdlib.h>
#include<string.h>
//结构体定义（单向链表）
int total_book_count=0;
typedef struct book{
    int id;             //计划自动生成（待完成）
    char name[100];     //书名
    char author[50];    //作者
    int total;          //总库存
    int available;      //可接数量
    int borrowcount;    //借阅次数
    struct book* next;
} book;
book* head=NULL;
book* t;//辅助链表操作
book* end;//指向链表最后的节点；
void showMenu() {
    printf("====== 图书管理系统 ======\n");
    printf("1. 添加图书\n");
    printf("2. 删除图书\n");
    printf("3. 修改图书信息\n");
    printf("4. 查询图书\n");
    printf("5. 显示所有图书\n");
    printf("6. 借书\n");
    printf("7. 还书\n");
    printf("8. 统计\n");
    printf("0. 退出\n");
    printf("请选择: ");
}
void addbook(void)//或许应该加一个批量添加书的功能
{
    
    book* bookptr=malloc(sizeof(book));
    if(bookptr==NULL)
    {
        printf("内存分配失败。\n");
        return ;
    }
    else{
        printf("请输入");
    }
}
int main(void)
{
    int choice;
    FILE* fp=fopen("bookdata.txt","r");
    head=malloc(sizeof(book));
    if(fp==NULL){
        total_book_count=0;
        printf("未找到数据文件，将创建新系统。\n");
        t=head;
        end=head;
    }
    else
    {
        //程序开始时先读入文件中的数据(或许可以写成函数再整个刷新功能？)
        fscanf(fp,"%d",&total_book_count);
        for(int i=0;i<total_book_count;i++)
        {
            book* s=malloc(sizeof(book));
            if(s==NULL)
            {
                printf("初始化时内存分配失败\n");
                //写一个free函数
                return ;
            }
            fscanf(fp,"%d %d %d %d",&(s->id),&(s->total),&(s->available),&(s->borrowcount));
            fgets(fp,100,s->name);
            fgets(fp,50,s->author);
            s->next=NULL;
            end->next=s;
            end=end->next;
        }
    }


    showMenu();
    scanf("%d",&choice);
    while(choice!=0)
    {
        switch (choice)
        {
        case 1:
            
            break;
        
        default:
            break;
        }
        scanf("%d",&choice);
    }
    //结束后应该把链表中的数据写入文件中（未完成）
    return 0;
}