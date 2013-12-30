#include "mergeSort.h"
#include <memory.h>
#include <stdlib.h>
// void part(void* base,int min,int max,compare* compare,int elementSize)
// {
//  int mid;
//  if(min<max)
//  {
//    mid=(min+max)/2;
//    part(base,min,mid,compare,elementSize);
//    part(base,mid+1,max,compare,elementSize);
//    merge(base,min,mid,max,compare,elementSize);
//  }
// }

// void merge(void* base,int min,int mid,int max,compare* compare,int elementSize)
// {
//   void *element,*nextElement,*tmpElement;
//   void*  temp =  calloc(min+max, elementSize);
//   int i,j,k,m,result; 
//   j=min;
//   m=mid+1;

//   for(i=min; j<=mid && m<=max ; i++)
//   {
//   	element = base + j * elementSize;
//   	nextElement = base + m *elementSize;
//   	result = compare(element,nextElement);
//      if(result == 0)
//      {
//         memcpy(temp+i*elementSize,element,elementSize);
//         j++;
//      }
//      else
//      {
//         memcpy(temp+i*elementSize,nextElement,elementSize);
//         m++;
//      }
//   }
//   if(j>mid)
//   {
//      for(k=m; k<=max; k++)
//      {
//      	tmpElement = base + k * elementSize;
//         memcpy(temp+i*elementSize,tmpElement,elementSize);
//         i++;
//      }
//   }
//   else
//   {
//      for(k=j; k<=mid; k++)
//      {
//         memcpy(temp+i*elementSize,tmpElement,elementSize);
//         i++;
//      }
//   }
//   for(k=min; k<=max; k++)
//     memcpy(base,temp+k*elementSize,elementSize);
// }
  //-----------------------------------------------------------------------------------------

int merge(void** base, void** left, void** right, int leftLength, int rightLength, comparator cmp        ){
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
    while( j < rightLength){
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

void mergeSort(void** base, int numberOfElements, comparator comp){
    int mid = numberOfElements/2,i,j,leftLength,rightLength;
    void** left = calloc(mid,sizeof(void*));
    void** right = calloc(mid+1,sizeof(void*));
    if(numberOfElements < 2) return;
    leftLength = mid;
    rightLength = numberOfElements-mid;
    for(i=0;i<mid;i++)
        left[i] = base[i];
    for(i=mid;i<numberOfElements;i++)
        right[i-mid] = base[i];
    mergeSort(left,leftLength,comp);
    mergeSort(right,rightLength,comp);
    merge(base, left, right, leftLength, rightLength, comp);
    free(left);
    free(right);
}