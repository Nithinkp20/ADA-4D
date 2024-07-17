#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int a[15000];

void heapify(int n){
    for(int p = (n - 1) / 2; p >= 0; p--){
        int item = a[p];
        int c = 2 * p + 1;
        while(c <= n - 1){
            if(c + 1 <= n - 1 && a[c] < a[c + 1]){
                c++;
            }
            if(item >= a[c]){
                break;
            }
            a[p] = a[c];
            p = c;
            c = 2 * p + 1;
        }
        a[p] = item;
    }
}

void sort(int n){
    heapify(n);
    for(int i = n - 1; i > 0; i--){
        int temp = a[0];
        a[0] = a[i];
        a[i] = temp;
        heapify(i);
    }
}

int main(){
    int n;
    printf("Enter number of elements: ");
    scanf("%d", &n);
    printf("Enter elements: \n");
    for(int i = 0; i < n; i++){
        scanf("%d", &a[i]);
    }
    clock_t start, end;
    start = clock();
    sort(n);
    end = clock();
    printf("Sorted: \n");
    for(int i = 0; i < n; i++){
        printf("%d ", a[i]);
    }
    printf("\nTime taken to sort %d numbers is %f", n, (double)(end - start)/CLOCKS_PER_SEC);
    n = 500;
    while(n <= 14500){
        for(int i = 0; i < n; i++){
            a[i] = n - i;
        }
        start = clock();
        sort(n);
        for(int j = 0; j < 500000; j++){
            int temp = 38/600;
        }
        end = clock();
        printf("\nTime taken to sort %d numbers is %f", n, (double)(end - start)/CLOCKS_PER_SEC);
        n += 1000;
    }
    return 0;
}
