#include <windows.h>
#include <stdio.h>
#include "hanshu.h"
#include "denglu.h"
#include "guanliyuan.h"
#include "yonghu.h"
int main(void)
{
    SetConsoleOutputCP(CP_UTF8);      // 设置输出代码页为 UTF-8
    SetConsoleCP(CP_UTF8);            // 设置输入代码页为 UTF-8
    
    denglu();
    if(dengluzhuangtai==1)
    {
        if(guan_li_yuan_zhang_mi()){
            kaishi();
            showmenugly();//你打错字了鱼
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
                    seekbookname();
                    break;
                default:
                    break;
                }
                showMenu();
                scanf("%d",&choice);
            }
            jieshu();
        }
        else{
            denglu();
        }
    }
    if(dengluzhuangtai==2)
    {
        if(yong_hu_zhang_mi())
        {
            kaishi();
            showmenuyh();
            scanf("%d",&choice);
            while(choice!=0)
            {
                switch (choice)
                {
                
                case 1:
                    seekbook();
                    break;
                case 2:
                    viewbook();
                    break;
                case 3:
                    borrowbook();
                    break;
                case 4:
                    retbook();
                    break;
                case 5:
                    seekbookname();
                    break;
                default:
                    break;
                }
                showMenu();
                scanf("%d",&choice);
            }
            jieshu();
        }
        else{
            denglu();
        }
    }
    if(dengluzhuangtai==3)
    {
        zhuce();
        denglu();
    }

    /*kaishi();
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
        case 8:
            seekbookname();
            break;
        default:
            break;
        }
        showMenu();
        scanf("%d",&choice);
    }
    jieshu();
    */
    return 0;
}