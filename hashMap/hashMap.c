#include "hashMap.h"
#include <stdlib.h>
#include <stdio.h>

int capacity = 10;
HashMap* createHashMap(HashCodeGenerator hashCode,Compare compare){
    HashMap* hm = calloc(1,sizeof(HashMap));
    int i;
    hm->hashCode = hashCode;
    hm->compare = compare;
    hm->capacity = capacity;
    hm->buckets  =  calloc(capacity,sizeof(List));
    for ( i = 0; i < capacity; i++)
        hm->buckets[i] = create();
    return hm;
}
int hashc(void* key,int capacity){
    int hash;
    hash = *(int*)key % capacity;
    return hash;
}
int put(HashMap* hm,void* key,void* value){
    HashElement* data = getHashElement(key, value);
    int hash = hashc(key,capacity);
    List* list = (List*)hm->buckets[hash];
    reset(hm);
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
    int hash = hashc(key,10);
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
    int index,hash;
    List* list;
    if(key == NULL || value == NULL) return 0;
    hash = hashc(key,10);
    list = (List*)hm->buckets[hash];
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

void increaseBucket(HashMap* hm,int capacity){
    int i;
    hm->buckets  =  realloc(hm->buckets , capacity*(sizeof(List)));
    for ( i = hm->capacity; i < capacity; i++)
        hm->buckets[i] = create();
    hm->capacity = capacity;
}
void reset(HashMap* hm){
    List* list = create();
    Iterator it = getIterator(list);
    HashElement* data;
    while(it.hasNext(&it)){
        data = (HashElement*)it.next(&it);
        if(list->length > 2){
            rehash(hm);
            return;            
        }
    }
}
void rehash(HashMap* hm){
    int i;
    List* list;
    Iterator it;
    List* dataList;
    HashElement *data;
    for(i = 0;i < capacity;i++){
        list = (List*)hm->buckets[i];
        it = getIterator(list);
        if(list->head != NULL){
            printf(".....");
            while(it.hasNext(&it)){
                printf("*");
                data = (HashElement*)it.next(&it);
                insert(dataList, i, data);
                removeData(hm, data->key);
                break;
            }
        }
    }
    capacity = capacity*2;
    increaseBucket(hm, capacity);
    it  = getIterator(dataList);
    while(it.hasNext(&it)){
        data = (HashElement*)it.next(&it);
        put(hm, data->key, data->value);
    }
}
void dispose(HashMap *hm){
    int i;
    List* list;
    Iterator it;
    for(i=0;i<capacity;i++){
        list = (List*)get(hm,&i);
        free(list);
    };
    free(hm->buckets);
};