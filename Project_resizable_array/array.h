#ifndef _ARRAY_H_
#define _ARRAY_H_

typedef struct {
    int* array;
    int size;
} Array;

Array array_create(int init_size);
void array_free(Array* a);
int array_size(Array* a);
void array_inflate(Array* a, int more_size);
int* array_at(Array* a, int index);

#endif
