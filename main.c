#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include <windows.h>
#ifndef CP_UTF8
#define CP_UTF8 65001
#endif
//书名作者不能有空格；

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
void free_book_list(book* t)
{
    
    while(t!=NULL)
    {
        book* dell=t;
        t=t->next;
        free(dell);
        
    }
}
//按ID查找书
book* idbook(int ID)
{
    book* temp=head;
    while(temp->next!=NULL)
    {
        if(temp->next->id==ID)
        {
            return temp->next;
        }
    }
    return NULL;
}
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
        printf("请输入：(示例：总库存 可借数量 借阅次数 书名{不能有空格} 作者{不能有空格})");
    
    int ntotal,navailable,nborrowcount;
    char nname[100];
    char nauthor[50];
    scanf("%d %d %d %s %s",&ntotal,&navailable,&nborrowcount,nname,nauthor);
    total_book_count++;
    book* neww=bookptr;
    neww->id=total_book_count;
    neww->total=ntotal;
    neww->available=navailable;
    neww->borrowcount=nborrowcount;
    neww->next=NULL;
    strcpy(neww->name,nname);
    strcpy(neww->author,nauthor);
    end->next=neww;
    end=end->next;
    }

}
void delbook(void)
{
    printf("请输入要删除的书的ID\n");
    int ID;
    scanf("%d",&ID);
    t=head;
    book* delet;
    while(t->next!=NULL)
    {
        if(t->next->id==ID)
        {
            delet=t->next;
            t->next=delet->next;
            free(delet);
            
        }
    }
    return ;
}
void corbook(void)
{
    printf("请输入要修改的书的ID\n");
    int id;
    scanf("%d",&id);
    book* s=idbook(id);
    if(s==NULL)
    {
        printf("未找到该书\n");
        return ;
    }
    else{
        printf("请输入该书新的全部信息\n");
        int ntotal,navailable,nborrowcount;
        char nname[100];
        char nauthor[50];
        scanf("%d %d %d %s %s",&ntotal,&navailable,&nborrowcount,nname,nauthor);
        strcpy(s->name,nname);
        strcpy(s->author,nauthor);
        s->total=ntotal;
        s->available=navailable;
        s->borrowcount=nborrowcount;
        return ;
    }

}
int main(void)
{
    SetConsoleOutputCP(CP_UTF8);      // 设置输出代码页为 UTF-8
    SetConsoleCP(CP_UTF8);            // 设置输入代码页为 UTF-8
    int choice;
    FILE* fp=fopen("bookdata.txt","r");
    head=malloc(sizeof(book));
    head->next=NULL;
    if(fp==NULL){
        total_book_count=0;
        printf("未找到数据文件，将创建新系统。\n");
        t=head;
        end=head;
    }
    else
    {
        end=head;
        t=head;

        //程序开始时先读入文件中的数据(或许可以写成函数再整个刷新功能？)
        fscanf(fp,"%d",&total_book_count);
        for(int i=0;i<total_book_count;i++)
        {
            book* s=malloc(sizeof(book));
            if(s==NULL)
            {
                printf("初始化时内存分配失败\n");
                
                //free_book_list(head);
                return 0;
            }
            fscanf(fp,"%d|%d|%d|%d|%[^|]|%[^\n]",&(s->id),&(s->total),&(s->available),&(s->borrowcount),s->name,s->author);
        
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
            addbook();
            break;
        case 2:
        delbook();
        break;
        case 3:
        corbook();
        break;
        
        default:
            break;
        }
        scanf("%d",&choice);
    }
    if(fp!=NULL)
    fclose(fp);
    //结束后应该把链表中的数据写入文件中（完成）
    FILE* fout=fopen("bookdata.txt","w");
    fprintf(fout,"%d\n",total_book_count);
    t=head;
    while(t->next!=NULL)
    {
        fprintf(fout,"%d|%d|%d|%d|%s|%s\n",(t->next->id),(t->next->total),(t->next->available),(t->next->borrowcount),t->next->name,t->next->author);
        
        t=t->next;
    }
    
    fclose(fout);
    
    return 0;
}