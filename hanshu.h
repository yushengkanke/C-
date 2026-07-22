#ifndef HANSHU_H
#define HANSHU_H
#ifndef CP_UTF8
#define CP_UTF8 65001
#endif
extern int choice;
typedef struct book{
    int id;             //计划自动生成
    char name[100];     //书名
    char author[50];    //作者
    int total;          //总库存
    int available;      //可接数量
    int borrowcount;    //借阅次数
    struct book* next;
} book;

void free_book_list(book* t);
book* idbook(int ID);
void showMenu();
void addbook(void);
void delbook(void);
void corbook(void);
void seekbook(void);
void viewbook(void);
void borrowbook(void);
void retbook(void);
void seekbookname(void);
void kaishi(void);
void jieshu(void);
void clrscr() ; //clion用不了这个函数，手写一下
#endif