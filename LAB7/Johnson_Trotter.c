#include <stdio.h>
#include <stdlib.h>

struct ele{
    int num;
    int dir;
};

void main(){
    int n;
    printf("Enter number of elements: ");
    scanf("%d", &n);
    struct ele e[n];
    printf("Enter sorted elements: ");
    for(int i = 0; i < n; i++){
        scanf("%d", &e[i].num);
        e[i].dir = -1;  // -1 indicates left, 1 indicates right
    }
    while(1){
        for(int i = 0; i < n; i++){
            printf("%d ", e[i].num);
        }
        printf("\n");

        int curri = -1;
        // Find the largest mobile integer
        for(int i = 0; i < n; i++){
            if(e[i].dir == 1 && i < n - 1 && e[i].num > e[i + 1].num){
                if(curri == -1 || e[i].num > e[curri].num){
                    curri = i;
                }
            }
            if(e[i].dir == -1 && i > 0 && e[i].num > e[i - 1].num){
                if(curri == -1 || e[i].num > e[curri].num){
                    curri = i;
                }
            }
        }

        // If there is no mobile integer, break the loop
        if(curri == -1) break;

        // Swap the largest mobile integer
        struct ele temp;
        if(e[curri].dir == 1){
            temp = e[curri];
            e[curri] = e[curri + 1];
            e[curri + 1] = temp;
            curri++;
        } else {
            temp = e[curri];
            e[curri] = e[curri - 1];
            e[curri - 1] = temp;
            curri--;
        }

        // Reverse the direction of all elements larger than the current largest mobile integer
        for(int i = 0; i < n; i++){
            if(e[i].num > temp.num){
                e[i].dir = -e[i].dir;
            }
        }
    }
}
