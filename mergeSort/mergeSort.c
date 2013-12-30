#include "mergeSort.h"
#include <memory.h>
#include <stdlib.h>
int merge(void** base, void** left, void** right, int leftLength, int rightLength, comparator cmp){
    int  i=0,j=0,k=0;
    while(i < leftLength && j < rightLength){
        if(cmp(left[i], right[j])){
            base[k] = left[i];
            i++;
        }
        else{
            base[k] = right[j];
            j++;
        }
        k++;
    }
    while(j < rightLength){
        base[k] = right[j];
        j++;
        k++;
    }
    while(i < leftLength){
        base[k] = left[i];
        i++;
        k++;
    }
    return 1;
}
void mergeSort(void** base, int size, comparator comp){
    int mid = size/2,i,leftLength,rightLength;
    void** left = calloc(mid,sizeof(void*));
    void** right = calloc(mid+1,sizeof(void*));
    if(size < 2) return;
    leftLength = mid;
    rightLength = size - mid;
    for(i = 0;i < mid;i++)
        left[i] = base[i];
    for(i = mid;i < size;i++)
        right[i - mid] = base[i];
    mergeSort(left,leftLength,comp);
    mergeSort(right,rightLength,comp);
    merge(base, left, right, leftLength, rightLength, comp);
    free(left);
    free(right);
}
