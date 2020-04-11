#include <stdio.h>
#include <stdlib.h>

#define MAXSIZE 10
typedef enum {false, true} bool;
typedef int ElementType;

typedef int Position;
typedef struct LNode *List;
struct LNode {
    ElementType Data[MAXSIZE];
    Position Last; /* 保存线性表中最后一个元素的位置 */
};

List ReadInput(); /* 裁判实现，细节不表。元素从下标0开始存储 */
void PrintList( List L ); /* 裁判实现，细节不表 */
bool Insert( List L, ElementType X );

int main()
{
    List L;
    ElementType X;

    L = ReadInput();
    scanf("%d", &X);
    if ( Insert( L, X ) == false )
        printf("Insertion failed.\n");
    PrintList( L );

    return 0;
}

/* 你的代码将被嵌在这里 */
bool Insert( List L, ElementType X ){
    bool ret=false;
    if(L->Last+1!=MAXSIZE){
        for(int i=0;i<=L->Last;i++){
            if(L->Data[i]==X){
                break;
            }else if(L->Data[i]<X){
               for(int j=L->Last;j>=i;j--){
                    L->Data[j+1]=L->Data[j];
                }
                L->Data[i]=X;
                L->Last++;
                ret=true;
                break;
            }else if(L->Last==i&&L->Data[i]>X){
                L->Data[++(L->Last)]=X;
                ret=true;
                break;
            }
        }
    }

    return ret;
}