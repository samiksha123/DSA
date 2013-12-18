#include "binarySearch.h"
#include <stdio.h>

void* binarySearch(void* base,void* key,int num,int size,compare* compare){
   int low = 0,mid,result;
   int high = num - 1;
   while(low <= high ){
      mid = (low+high)/2;
      result = compare(key,base+(mid*size));
      if(result == 0) return (void*)(base+(mid*size));
      if(result < 0)  high = mid-1;
      else low = mid+1;
   }
   return NULL; 
} 