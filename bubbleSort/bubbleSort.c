#include "bubbleSort.h"
#include <stdlib.h>
#include <memory.h>

void bubbleSort(void* base,int noOfElements,int elementSize,compare comp){
	int i,j,k;
	void* elementToCompare,*nextElement,*temp = calloc(1, elementSize);
	int comparisonResult;
	    for(i=1;i< noOfElements;i++){
        	for(j=0;j< noOfElements-1;j++){
	         	elementToCompare = base + j * elementSize;
	         	nextElement = base + (j+1) * elementSize;
	            comparisonResult = comp(elementToCompare,nextElement);
	         if(comparisonResult >= 0)
               {
             	memcpy(temp, elementToCompare, elementSize);
               	memcpy(elementToCompare, 
                       nextElement, elementSize);
              	memcpy(nextElement,temp, elementSize);
          	}
        free(temp);
	}
	}
}
