#include <stdio.h>

int main(){
    
    int all,asi,turu,kame,tento,kai;
    
    printf("鶴、亀、てんとう虫の合計数を入力:");
    scanf("%d",&all);

    printf("足の合計本数を入力:");
    scanf("%d",&asi);

    for(int i=0;i<=all;i++){
        turu = i*2;
        for(int j=0;j<=all-i;j++){
            kame = j*4;
            tento = all-i-j;
            if(turu+kame+tento==asi){
                printf("鶴が%d羽、亀が%d匹、てんとう虫は%d匹",i,j,all-i-j);
                kai++;
            }
        }
    }
    if(kai==0){
        printf("解なし");
    }

}