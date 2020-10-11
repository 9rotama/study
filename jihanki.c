#include <stdio.h>

int main()
{
    int nedan[6] = {130, 120, 200, 80, 150, 110};
    int zaiko[6] = {3, 5, 10, 4, 8, 6};
    int zeni[6] = {1000, 500, 100, 50, 10};
    int in[5]={0},syuno[5]={0},turi[5]={0}, ureta[6] = {0}, dore, oturi, insum = 0,uriage;
    char OX[6];


    while (1)
    {
        insum, oturi= 0;
        for (int i = 0; i <= 5; i++)
        {
            if (zaiko[i] > 0)
            {
                OX[i] = 'O';
            }
            else
            {
                OX[i] = 'X';
            }

            printf("%d(%c) %d円\n", i + 1, OX[i], nedan[i]);
            
        }
        printf("お金と飲み物番号を入力してください\n");

        if (scanf("%d%d%d%d%d%d", &in[0], &in[1], &in[2], &in[3], &in[4], &dore) == EOF)
            break;
        

        for (int i = 0; i <= 4; i++)
        {
            
            syuno[i] += in[i];
            insum = insum + (zeni[i] * in[i]);
        }
        
        printf("\n");
        printf("-- 状態表示エリア --\n");
        printf("\n");

        if (zaiko[dore - 1] == 0)
        {
            printf("飲み物%dは売り切れです\n", dore - 1);
            printf("お金%d円が戻ります\n", insum);
        }
        else if (insum < nedan[dore - 1])
        {
            printf("投入金額が足りません\n");
            printf("お金%d円が戻ります\n", insum);
        }
        else if (insum >= nedan[dore - 1] && zaiko[dore - 1] != 0)
        {
            oturi = insum - nedan[dore - 1];
            ureta[dore - 1]++;
            zaiko[dore-1]--;

            printf("飲み物%dが出ます\n", dore);
            printf("お釣り\n");

            for (int j = 0; j <= 4; j++)
            {
                if (oturi / zeni[j] > 0)
                {
                    turi[j] = oturi / zeni[j];
                    printf("%d円%d枚 ", zeni[j], turi[j]);
                    oturi -= oturi / zeni[j] * zeni[j];

                }
            }

            printf("が出ます\n");
        }
    }
    printf("\n");
    printf("-- 売上サマリ --\n");
    printf("\n");

    printf("売れた飲み物の番号ごとの本数\n");

    for(int i=0; i<=5;i++){
        uriage = ureta[i] * nedan[i];
    }
    
    for (int i = 0; i <= 5; i++)
    {
        printf("%d: %d本\n", i + 1, ureta[i]);

    }
    printf("\n");
    printf("各金種毎の収納枚数・お釣り使用枚数\n");
    
    for(int i=0; i<=4;i++) {  
        printf("%d円: 収納%d枚  釣り%d枚\n",zeni[i],syuno[i],turi[i]);

    }
}
