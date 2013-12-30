#include "hashMap.h"
#include <stdlib.h>
#include <stdio.h>

int capacity = 10;
HashMap* createHashMap(HashCodeGenerator hashCode,Compare compare){
    HashMap* hm = calloc(1,sizeof(HashMap));
    int i;
    hm->hashCode = hashCode;
    hm->compare = compare;
    hm->buckets  =  calloc(capacity,sizeof(List));
    for ( i = 0; i < capacity; i++)
        hm->buckets[i] = create();
    return hm;
}
int hashc(void* key){
    int hash;
    hash = *(int*)key % capacity;
    return hash;
}
int put(HashMap* hm,void* key,void* value){
    HashElement* data = getHashElement(key, value);
    int hash = hashc(key);
    List* list = (List*)hm->buckets[hash];
    insert(list, list->length, data);
    return 1;
}
int findIndex(HashMap* hm ,void* key ,List* list){
    HashElement* data;
    int index = 0,i;
    Node* node = list->head;
    for(i = 0;i < list->length;i++){
        data = node->data;
        if (!hm->compare(key ,data->key)) return index;
        node = node->next;
        index++;
    };
    return index;
}
void* get(HashMap *hm, void *key){
    Node* node;
    HashElement* data;
    int i;
    int hash = hashc(key);
    List* list = (List*)hm->buckets[hash];
    if(list->length == 0) return NULL;
    node = list->head;
    for(i = 0;i < list->length;i++){
        data = node->data;
        if (hm->compare(key,data->key) == 0) return data->value;
        node = node->next;
    };
    return NULL;
}
HashElement* getHashElement(void* key,void* value){
    HashElement* data = calloc(capacity, sizeof(HashElement));
    data->key = key;
    data->value = value;
    return data;
}       
int removeData(HashMap *hm, void *key){
    void* value = get(hm, key);
    int index ,hash = hashc(key);
    List* list = (List*)hm->buckets[hash];
    if(!hm) return 0;
    index = findIndex( hm ,key ,list);
    deleteNode(list,index);
    return 1;
}
Iterator keys(HashMap* hm){
    Iterator it;
    int i;
    HashElement* data;
    List* list = create();
    for(i = 0;i < capacity;i++){
        list = hm->buckets[i];
        it = getIterator(list);
        while(it.hasNext(&it)){
            data = (HashElement*)it.next(&it);
            insert(list, list->length, data->key);
            break;
        };
    }
    it = getIterator(list);
    return it;
}
void dispose(HashMap* hm){
    free(hm->buckets);
    free(hm);
}