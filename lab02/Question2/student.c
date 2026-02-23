#include "student.h"
#include <stdlib.h>
#include <stdbool.h>

/* Create queue */
MyCircularQueue* myCircularQueueCreate(int k) {
    MyCircularQueue* obj = (MyCircularQueue*)malloc(sizeof(MyCircularQueue));
    obj->data = (int*)malloc(sizeof(int) * k);
    obj->capacity = k;
    obj->size = 0;
    obj->head = 0;
    obj->tail = 0;
    return obj;
}


/* Insert element */
bool myCircularQueueEnQueue(MyCircularQueue* obj, int value) {
    if (obj->size == obj->capacity)
        return false;   // full

    obj->data[obj->tail] = value;
    obj->tail = (obj->tail + 1) % obj->capacity;
    obj->size++;

    return true;
}


/* Delete element */
bool myCircularQueueDeQueue(MyCircularQueue* obj) {
    if (obj->size == 0)
        return false;   // empty

    obj->head = (obj->head + 1) % obj->capacity;
    obj->size--;

    return true;
}


/* Get front */
int myCircularQueueFront(MyCircularQueue* obj) {
    if (obj->size == 0)
        return -1;

    return obj->data[obj->head];
}


/* Get rear */
int myCircularQueueRear(MyCircularQueue* obj) {
    if (obj->size == 0)
        return -1;

    int index = (obj->tail - 1 + obj->capacity) % obj->capacity;
    return obj->data[index];
}


/* Check empty */
bool myCircularQueueIsEmpty(MyCircularQueue* obj) {
    return obj->size == 0;
}


/* Check full */
bool myCircularQueueIsFull(MyCircularQueue* obj) {
    return obj->size == obj->capacity;
}


/* Free memory */
void myCircularQueueFree(MyCircularQueue* obj) {
    free(obj->data);
    free(obj);
}