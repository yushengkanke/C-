#include<stdio.h>
#include<stdlib.h>
//结构体定义（单向链表）
typedef struct book{
    int id;             //计划自动生成（待完成）
    char name[100];     //书名
    char author[50];    //作者
    int total;          //总库存
    int available;      //可接数量
    int borrowcount;    //借阅次数
    struct book* next;
} book;

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
int main(void)
{
    int choice;
    showMenu();
    scanf("%d",&choice);
    return 0;
}