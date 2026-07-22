#include<conio.h>
#include<stdio.h>//我用clion得包含这个头文件，不知道你vs是不是一样
#include"hanshu.h"
void showmenuyh()
{
    clrscr();
    printf("====== 图书管理系统 ======\n");
    //printf("1. 添加图书\n");
    //printf("2. 删除图书\n");
    //printf("3. 修改图书信息\n");
    printf("1. 查询图书\n");
    printf("2. 显示所有图书\n");
    printf("3. 借书\n");
    printf("4. 还书\n");
    printf("5. 按书名查询\n");
    printf("0. 保存并退出\n");
    printf("请选择: ");
}