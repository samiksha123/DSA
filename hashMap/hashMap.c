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
    insert(list, list->length, data);
    return 1;
}
int findIndex(HashMap* hm ,void* key ,List* list){
    Data* data;
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
    Data* data;
    int i;
    int hash = hashc(key,10);
    List* list = (List*)(hm->buckets+(sizeof(List)*hash));
    if(list->length == 0) return NULL;
    node = list->head;
    for(i = 0;i < list->length;i++){
        data = node->data;
        if (hm->compare(key,data->key) == 0) return data->value;
        node = node->next;
    };
    return NULL;
}
Data* getData(void* key,void* value){
    Data* data = calloc(1, sizeof(Data));
    data->key = key;
    data->value = value;
    return data;
}       
int removeData(HashMap *hm, void *key){
    void* value = get(hm, key);
    int index ,hash = hashc(key, 10);
    List* list = (List*)(hm->buckets+(sizeof(List)*hash));
    if(!hm) return 0;
    index = findIndex( hm ,key ,list);
    deleteNode(list,index);
    return 1;
}

Iterator keys(HashMap* hm){
    Iterator it;
    int i;
    void* data;
    List* list;
    for(i = 0;i < 10;i++){
        list = (List*)(hm->buckets+(sizeof(List)*i));
        it = getIterator(list);
            while(it.hasNext(&it)){
            printf("................");
            data = it.next(&it);
            insert(list, list->length, data);
            break;
            }
    }
    it = getIterator(list);
    it.next = &next;
    return it;
}         
void dispose(HashMap* hm){
    free(hm->buckets);
    free(hm);
}