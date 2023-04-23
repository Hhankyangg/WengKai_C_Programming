#include "array.h"

const BLOCK_SIZE = 5;			

Array array_create(int init_size) {
    Array a;
    a.array = (int*)malloc(sizeof(int) * init_size);
    a.size = init_size;
    return a;			// 返回一个结构体变量 a
}

void array_free(Array* a) {
    free(a->array);
    a->size = 0;
}

int array_size(Array* a) {
    return a->size;		// 封装
}

void array_inflate(Array* a, int more_size) {
    int* p = (int*)malloc(sizeof(int) * (a->size + more_size));
    int i;
    for (i = 0; i < a->size; i++) {
        p[i] = a->array[i];
    }
    // for 循环可用 memcpy()
    // C 库<string.h>函数 
    // void *memcpy(void *str1, const void *str2, size_t n) 
    // 从存储区 str2 复制 n 个字节到存储区 str1
    // for 循环可改写为:
    // memcpy(p, a->array, sizeof(int)*a->size);
    free(a->array);
    a->array = p;
    a->size += more_size;
}

int* array_at(Array* a, int index) {
    return &(a->array[index]);	// 返回指针, 使得可被写入, 可被读
    if (index >= a->size) {
        array_inflate(a, (index / BLOCK_SIZE + 1) * BLOCK_SIZE - a->size);
        // array_at 自动增长
    }
}