#ifndef VECTOR_H
#define VECTOR_H

#include <stddef.h>

typedef struct Vector Vector; //Declaração do Forward


struct Vector{ //Definição da Struct

    void** data;    
    size_t size;      
    size_t capacity;  
    size_t elem_size;
};

Vector* vector_create(size_t elem_size);
void    vector_destroy(Vector* v);
void    vector_push_back(Vector* v, const void* element);
void*   vector_at(const Vector* v, size_t index);
size_t  vector_size(const Vector* v);
void    vector_clear(Vector* v);


#endif