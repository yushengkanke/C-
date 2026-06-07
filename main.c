#include <windows.h>
#include<stdio.h>
#include"shengming.h"
int main(void)
{
    SetConsoleOutputCP(CP_UTF8);      // 设置输出代码页为 UTF-8
    SetConsoleCP(CP_UTF8);            // 设置输入代码页为 UTF-8
    
    

    kaishi();
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
        case 4:
            seekbook();
            break;
        case 5:
            viewbook();
            break;
        case 6:
            borrowbook();
            break;
        case 7:
            retbook();
            break;
        default:
            break;
        }
        showMenu();
        scanf("%d",&choice);
    }
    jieshu();
    
    return 0;
}