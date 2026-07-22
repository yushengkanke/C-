#ifndef DENGLU_H
// #define DENGLU_H
//这里会重复定义变量
extern int dengluzhuangtai;//0为未登录,1为管理员,2为用户;
typedef struct glyaccount{
    char zhanghao[100];
    char mima[100];
    struct glyaccount* next;
} glyaccount;
typedef struct yhaccount{
    char zhanghao[100];
    char mima[100];
    struct yhaccount* next;
} yhaccount;
void free_glyaccount_list(glyaccount* t);
void free_yhaccount_list(yhaccount* t);
void denglu(void);
void zhuce(void);
int guan_li_yuan_zhang_mi(void);
int yong_hu_zhang_mi(void);
#endif


