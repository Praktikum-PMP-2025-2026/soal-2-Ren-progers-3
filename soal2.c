#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
typedef struct matrix {
    int val;
    int visited;
}mat;
int main (){
    int R, C, buffer;
    int max = 0;
    int island = 0;
    scanf ("%d", &R);
    scanf ("%d", &C);
    int count[R*C];
    for (int i = 0; i < R*C; i++){
        count[i] = 0;
    }
    mat reg[R][C];
    for (int i = 0; i < R;i++){
        int r = C-1, digit;
        scanf ("%d", &buffer);
        while (r >= 0){
            digit = buffer%10;
            buffer /= 10; //Dari wikibase.com
            reg[i][r].val = digit;
            reg[i][r].visited = 0;
            // printf ("%d\n", digit);
            r--;
        }
    }
    // for (int i = 0; i< R;i++){
    //     for (int j = 0; j < C; j++){
    //         printf ("%d", reg[i][j]);
    //     }
    //     printf ("\n");
    // }
    int idx = 0;
    for (int i = 0; i< R;i++){
        for (int j = 0; j < C; j++){
            if (reg[i][j].val == 1){
                int rchek = i;
                while (reg[rchek][j].val == 1 && rchek < R){
                    if (reg[rchek][j].visited == 0){
                        count[idx]++;
                        reg[rchek][j].visited = 1;
                    }
                    int cchek = j-1;
                    while (reg[rchek][cchek].val != 0 && cchek >= 0){
                        if (reg[rchek][cchek].val != 0 && reg[rchek][cchek].visited == 0){
                            count[idx]++;
                            reg[rchek][cchek].visited = 1;
                        }
                        cchek--;
                    }
                    cchek = j+1;
                    while (reg[rchek][cchek].val != 0 && cchek < C){
                        if (reg[rchek][cchek].val != 0 && reg[rchek][cchek].visited == 0){
                            count[idx]++;
                            reg[rchek][cchek].visited = 1;
                        }
                        cchek++;
                    }
                    rchek++;
                }
                idx++;
            }

            // if (reg[i-1][j].val == 1 && i-1 >= 0 && reg[i-1][j].visited == 0){
            //     count[idx][idx] ++;
            //     reg[i-1][j].visited = 1;
            //     printf ("TIPE 1\n");
            // }
            // if (reg[i+1][j].val == 1 && i+1 < R && reg[i+1][j].visited == 0){
            //     count[idx][idx] ++;
            //     reg[i+1][j].visited = 1;
            //     printf ("TIPE 2\n");
            // }
            // if (reg[i][j+1].val == 1 && j+1  < C && reg[i][j+1].visited == 0){
            //     count[idx][idx] ++;
            //     reg[i][j+1].visited = 1;
            //     printf ("TIPE 3\n");
            // }
            // if (reg[i][j-1].val == 1 && j-1 >= 0&& reg[i][j-1].visited == 0){
            //     count[idx][idx] ++;
            //     reg[i][j-1].visited = 1;
            //     printf ("TIPE 4\n");
            // }
        }
        idx++;
    }
    for (int i = 0; i < R*C; i++){
        if (count[i] > max){
            max = count[i];
        }
        if (count[i]>0){
            island++;
        }
    }
    printf ("ISLAND %d\n", island);
    printf ("LARGEST %d\n", max);
    return 0;
}
