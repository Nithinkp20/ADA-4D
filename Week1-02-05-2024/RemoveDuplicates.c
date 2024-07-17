int removeDuplicates(int* nums, int numsSize){
    int a[100000];
    int n = 0;
    for(int i = 0; i < numsSize; i++){
        int x = nums[i];
        int flag = 0;
        for(int j = 0; j < n; j++){
            if(a[j] == x){
                flag = 1;
                break;
            }
        }
        if(flag == 0){
            a[n] = x;
            n++;
        }
    }
    for(int i = 0; i < n; i++){
        nums[i] = a[i];
    }
    return n;
}
