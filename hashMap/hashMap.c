#include "hashMap.h"
#include <stdlib.h>
#include <stdio.h>

HashMap* createHashMap(HashCodeGenerator hashCode,Compare compare){
	HashMap* hm = (HashMap*)calloc(1,sizeof(HashMap));
	hm->hashCode = hashCode;
	hm->compare = compare;
	hm->buckets =  calloc(10,sizeof(List));
	return hm;
}
int hashc(void* key,int capacity){
	int hash;
	hash = *(int*)key % capacity;
	return hash;
}
int put(HashMap* hm,void* key,void* value){
	Data* data = getData(key, value);
	int hash = hashc(key,10);
	List* list = (List*)(hm->buckets+sizeof(List)*hash);
	printf("---before----%d\n",list->length);
	insert(list, list->length, data);
	printf("---after----%d\n",list->length);
	return 1;
}
void* removeData(HashMap* hm,void* key){
	if(!hm->buckets) return NULL;
	return NULL;
}
void* get(HashMap *hm, void *key){
        Node* node;
        Data* data;
        int hash = hashc(key,10);
        List* list = (List*)(hm->buckets+(sizeof(List)*hash));
        if(!list->length) return NULL;
        node = list->head;
        do{
                data = node->data;
                if (!hm->compare(key ,data->key)) return data;
                node = node->next;
        }while(node->next != NULL);
        return NULL;
}
Data* getData(void* key,void* value){
	Data* data = calloc(1, sizeof(Data));
	data->key = key;
	data->value = value;
	return data;
}		
void dispose(HashMap* hm){
	free(hm->buckets);
	free(hm);
}