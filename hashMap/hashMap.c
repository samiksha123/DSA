#include "hashMap.h"
#include <stdlib.h>
#include <stdio.h>

HashMap* createHashMap(HashCodeGenerator hashCode,Compare compare){
    HashMap* hm = calloc(1,sizeof(HashMap));
    int i;
    hm->hashCode = hashCode;
    hm->compare = compare;
    hm->capacity = 10;
    hm->buckets  =  calloc(hm->capacity,sizeof(List));
    for ( i = 0; i < hm->capacity; i++)
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
    int hash = hashc(key,hm->capacity);
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
    HashElement* data = calloc(1, sizeof(HashElement));
    data->key = key;
    data->value = value;
    return data;
}       
Iterator keys(HashMap* hm){
    Iterator it;
    int i;
    HashElement* data;
    List* list, *temp= create();
    for(i = 0;i < hm->capacity;i++){
        list = hm->buckets[i];
        if(list->head == NULL) continue;
        it = getIterator(list);
        while(it.hasNext(&it)){
            data = (HashElement*)it.next(&it);
            insert(temp, temp->length, data->key);
        };
    }
    return getIterator(temp);
}
void increaseBucket(HashMap* hm){
    int i;
    hm->capacity *= 2;
    hm->buckets  =  realloc(hm->buckets , hm->capacity*(sizeof(List)));
    for ( i = hm->capacity/2; i < hm->capacity; i++)
        hm->buckets[i] = create();
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
// void insertInNewBucket( HashMap* hm ,List* list){
//     Iterator it;
//     HashElement* hashElement;
//     if(list->head != NULL){
//         printf("hi");
//         it = getIterator(list);
//         while(it.hasNext(&it)){
//             hashElement = (HashElement*)it.next(&it);
//             put(hm, hashElement->key, hashElement->value);
//             printf("key %d\n",*(int*)hashElement->key);
//             deleteNode(list,it.position-1);
//         }
//     }
// }
// void rehash(HashMap *hm){
//     List* list;
//     int i;
//     increaseBucket(hm);
//     for(i = 1 ; i >0 ; i--) {
//         list = (List*)hm->buckets[i];
//         printf(" list %p\n",list);
//         insertInNewBucket(hm,list);
//     }
// }
void rearrangeBuckets( HashMap* map ,List* list){
    Iterator it;
    HashElement* hashElement;
    if(list->head != NULL){
        it = getIterator(list);
        while(it.hasNext(&it)){
            hashElement = (HashElement*)it.next(&it);
            put(map,hashElement->key,hashElement->value);
            deleteNode(list,it.position-1);
        }
    }
}

void rehash(HashMap* map){
    int i;
    List* list;
    map->capacity*=2;       
    map->buckets =realloc(map->buckets,map->capacity*sizeof(List));
    for ( i = map->capacity/2; i < map->capacity; i++)
        map->buckets[i] = create();
    for(i = 0 ; i < map->capacity ; i++)
        rearrangeBuckets(map,map->buckets[i]);
};
void disposeMap(HashMap *hm){
    int i;
    List* list;
    Iterator it;
    for(i=0;i<hm->capacity;i++){
        list = (List*)get(hm,&i);
        free(list);
    };
    free(hm->buckets);
};