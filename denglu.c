#include"denglu.h"
#include"hanshu.h"
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<conio.h>
void free_glyaccount_list(glyaccount* t)
{
    
    while(t!=NULL)
    {
        glyaccount* dell=t;
        t=t->next;
        free(dell);
        
    }
}
void free_yhaccount_list(yhaccount* t)
{
    
    while(t!=NULL)
    {
        yhaccount* dell=t;
        t=t->next;
        free(dell);
        
    }
}
void denglu(void)
{
    clrscr();
    dengluzhuangtai=-1;
    printf("=====================================\n");
    printf("               登陆界面               \n");
    printf("0. 退出\n");
    printf("1. 管理员登陆\n");
    printf("2. 普通用户登录\n");
    printf("3. 注册\n");
    printf("=====================================\n");
    printf("请输入:\n");
    scanf("%d",&dengluzhuangtai);
    

}
void zhuce(void)
{
    clrscr();
    int xz;
    printf("1. 注册管理员账户\n");
    printf("2. 注册普通用户账户\n");
    printf("请选择：\n");
    scanf("%d",&xz);
    if(xz==1){
        char zh[100];
        char mm[100];
        FILE* f=fopen("glyzhanghu.txt","a");
        printf("请输入账号：\n");
        scanf("%s",zh);
        printf("请输入密码：\n");
        scanf("%s",mm);
        fprintf(f,zh);
        fprintf(f," ");
        fprintf(f,mm);

        
    }
    if(xz==2){
        char zh[100];
        char mm[100];
        FILE* f=fopen("yhzhanghu.txt","a");
        printf("请输入账号：\n");
        scanf("%s",zh);
        printf("请输入密码：\n");
        scanf("%s",mm);
        fprintf(f,zh);
        fprintf(f," ");
        fprintf(f,mm);
        fclose(f);
        
    }

}
int guan_li_yuan_zhang_mi(void)
{
    FILE* f=fopen("glyzhanghu.txt","w");
    glyaccount* head=malloc(sizeof(glyaccount));
    head->next=NULL;
    glyaccount* t=head;
    char zh[100];
    char mm[100];
    while(fscanf(f,"%s",zh)!=NULL)
    {
        fscanf(f,"%s",mm);
        glyaccount* temp=malloc(sizeof(glyaccount));
        temp->next=NULL;
        strcpy(temp->zhanghao,zh);
        strcpy(temp->mima,mm);
        t->next=temp;
        t=t->next;
    }
    fclose(f);
    printf("请输入账号：\n");
    scanf("%s",zh);
    printf("请输入密码：\n");
    scanf("%s",mm);
    glyaccount* s=head;
    while(s->next!=NULL)
    {
        if(strcmp(s->zhanghao,zh)==0)
        {
            if(strcmp(s->mima,mm)==0)
            {
                printf("登陆成功\n");
                free_glyaccount_list(s);
                return 1;
            }
            else {
                printf("密码错误\n");
                free_glyaccount_list(s);
                return 0;
            }
        }
        else {
            continue;
        }

    }
    if(s->next==NULL)
    {
        printf("未找到账号\n");
        free_glyaccount_list(s);
        return 0;
    }
    free_glyaccount_list(s);
    return 0;
}
int yong_hu_zhang_mi(void)
{
    FILE* f=fopen("yhzhanghu.txt","w");
    yhaccount* head=malloc(sizeof(yhaccount));
    head->next=NULL;
    yhaccount* t=head;
    char zh[100];
    char mm[100];
    while(fscanf(f,"%s",zh)!=NULL)
    {
        fscanf(f,"%s",mm);
        yhaccount* temp=malloc(sizeof(yhaccount));
        temp->next=NULL;
        strcpy(temp->zhanghao,zh);
        strcpy(temp->mima,mm);
        t->next=temp;
        t=t->next;
    }
    fclose(f);
    printf("请输入账号：\n");
    scanf("%s",zh);
    printf("请输入密码：\n");
    scanf("%s",mm);
    yhaccount* s=head;
    while(s->next!=NULL)
    {
        if(strcmp(s->zhanghao,zh)==0)
        {
            if(strcmp(s->mima,mm)==0)
            {
                printf("登陆成功\n");
                free_yhaccount_list(s);
                return 1;
                
            }
            else {
                printf("密码错误\n");
                free_yhaccount_list(s);
                return 0;
            }
        }
        else {
            continue;
        }

    }
    if(s->next==NULL)
    {
        printf("未找到账号\n");
        free_yhaccount_list(s);
        return 0;
    }
    free_yhaccount_list(s);
    return 0;
}