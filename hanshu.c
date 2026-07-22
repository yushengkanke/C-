#include"hanshu.h"
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<conio.h>
book* head;
book* t;//辅助链表操作
book* end;//指向链表最后的节点；
int total_book_count=0;
int choice;

//clion用不了这个函数，手写一下
void clrscr() {
    system("cls");
}

void kaishi(void)
{
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

        //程序开始时先读入文件中的数据()
        fscanf(fp,"%d",&total_book_count);
        for(int i=0;i<total_book_count;i++)
        {
            book* s=malloc(sizeof(book));
            if(s==NULL)
            {
                printf("初始化时内存分配失败\n");
                
                free_book_list(head);
                return ;
            }
            fscanf(fp,"%d|%d|%d|%d|%[^|]|%[^\n]",&(s->id),&(s->total),&(s->available),&(s->borrowcount),s->name,s->author);
        
            s->next=NULL;
            end->next=s;
            end=end->next;
        }

    }
    if(fp!=NULL)
    fclose(fp);
}
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
        temp=temp->next;
    }
    return NULL;
}
void showMenu() {
    clrscr();
    printf("====== 图书管理系统 ======\n");
    printf("1. 添加图书\n");
    printf("2. 删除图书\n");
    printf("3. 修改图书信息\n");
    printf("4. 查询图书\n");
    printf("5. 显示所有图书\n");
    printf("6. 借书\n");
    printf("7. 还书\n");
    printf("8. 按书名查询\n");
    printf("0. 保存并退出\n");
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
        printf("请输入：(示例：总库存 可借数量 借阅次数 书名{不能有空格} 作者{不能有空格})\n");
    
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
    printf("添加成功\n");
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
            total_book_count--;
            printf("删除成功\n");
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
void seekbook(void)
{
    printf("请输入要查询的ID\n");
    int ID;
    scanf("%d",&ID);
    book*s=idbook(ID);
    printf("ID: %d\n",s->id);
    printf("书名: %s\n",s->name);
    printf("作者: %s",s->author);
    printf("总库存: %d,可借数量: %d,借阅次数: %d\n",s->total,s->available,s->borrowcount);
    return ;
}
void viewbook(void)
{
    book*s=head;
    if(s->next==NULL)
    {
        printf("当前没有书目\n");
    }
    while(s->next!=NULL)
    {
        printf("ID: %d\n",s->next->id);
        printf("书名：%s\n",s->next->name);
        printf("作者：%s\n",s->next->author);
        printf("总库存：%d,可借数量：%d,借阅次数：%d\n",s->next->total,s->next->available,s->next->borrowcount);
        s=s->next;
    }
    printf("已输出所有书目\n");
}
void borrowbook(void)
{
    printf("请输入书的ID\n");
    int ID;
    scanf("%d",&ID);
    book*s =idbook(ID);
    if(s->available<=0)
    {
        printf("借阅失败，没有库存\n");
        return ;
    }
    else{
        s->available=s->available-1;
        s->borrowcount=s->borrowcount+1;
        printf("借阅成功\n");
        return ;
    }
}
void retbook(void)
{
    printf("请输入要还的书的ID\n");
    int ID;
    scanf("%d",&ID);
    book* s=idbook(ID);
    s->available++;
    printf("还书成功\n");
    return ;
}
void seekbookname(void)
{
    book* s=head;
    char a[100];
    printf("请输入书名:\n");
    scanf("%s",a);
    while(s->next!=NULL)
    {
        if(strstr(s->next->name,a)!=NULL){
            printf("ID: %d\n",s->next->id);
            printf("书名：%s\n",s->next->name);
            printf("作者：%s\n",s->next->author);
            printf("总库存：%d,可借数量：%d,借阅次数：%d\n",s->next->total,s->next->available,s->next->borrowcount);
        }
        s=s->next;
    }
    printf("已完成搜索\n");
}
void jieshu(void)
{
    
    //结束后应该把链表中的数据写入文件中（完成）
    FILE* fout=fopen("bookdata.txt","w");
    fprintf(fout,"%d\n",total_book_count);
    t=head;
    while(t->next!=NULL)
    {
        fprintf(fout,"%d|%d|%d|%d|%s|%s\n",(t->next->id),(t->next->total),(t->next->available),(t->next->borrowcount),t->next->name,t->next->author);
        
        t=t->next;
    }
    free_book_list(head);
    fclose(fout);
}