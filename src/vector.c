#include "vector.h"
#include <stdlib.h>
#include <string.h>

//TODO: private function
static void vector_grow(Vector* v){

    if(v->capacity == 0){
        v->capacity == 4;
    }
    else{
        v->capacity *= 2;
    }

    void** new_data = realloc(v->data,v->capacity * sizeof(void*));

    if(new_data == NULL){

        exit(1);
    }
    v->data = new_data
}

//TODO: public function

Vector* vector_create(size_t elem_size)
{
    if (elem_size == 0) {
        return NULL;
    }

    Vector* v = malloc(sizeof(Vector));
    if (v == NULL) {
        return NULL;
    }

    v->data       = NULL;
    v->size       = 0;
    v->capacity   = 0;
    v->elem_size  = elem_size;

    return v;
}

void vector_destroy(Vector* v)
{
    if (v == NULL) {
        return;
    }

    for (size_t i = 0; i < v->size; i++) {
        free(v->data[i]);
    }

    free(v->data);  
    free(v);        
}

void vector_push_back(Vector* v, const void* element)
{
    if (v == NULL || element == NULL) {
        return;
    }

    if (v->size >= v->capacity) {
        vector_grow(v);
    }

    void* new_element = malloc(v->elem_size);
    if (new_element == NULL) {
        exit(1);        
    }

    memcpy(new_element, element, v->elem_size);

    v->data[v->size] = new_element;
    v->size++;
}

void* vector_at(const Vector* v, size_t index)
{
    if (v == NULL || index >= v->size) {
        return NULL;
    }
    return v->data[index];
}

size_t vector_size(const Vector* v)
{
    return (v != NULL) ? v->size : 0;
}

void vector_clear(Vector* v)
{
    if (v == NULL) {
        return;
    }

    for (size_t i = 0; i < v->size; i++) {
        free(v->data[i]);
    }

    v->size = 0;
}

void vector_reserve(Vector* v, size_t new_capacity)
{
    if (v == NULL || new_capacity <= v->capacity) {
        return;
    }

    void** new_data = realloc(v->data, new_capacity * sizeof(void*));
    if (new_data == NULL) {
        exit(1);
    }

    v->data = new_data;
    v->capacity = new_capacity;
}

void vector_pop_back(Vector* v)
{
    if (v == NULL || v->size == 0) {
        return;
    }
    free(v->data[v->size - 1]);
    v->size--;
}
