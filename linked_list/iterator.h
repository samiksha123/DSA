typedef struct iterator{
	int position;
	void* list;
	void* (*next)(struct iterator* it);	
	int (*hasNext)(struct iterator* it);
}Iterator;

