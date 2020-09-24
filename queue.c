//
// Created by Martin Alemajoh on 9/24/2020.
//
#include <stdlib.h>
#include "queue.h"


void initQueue(Queue *queue){

    queue->head = NULL;
    queue->tail = NULL;
}


void freeNode(void **node){

    if(node != NULL && *node != NULL){
        free(*node);
        *node = NULL;
    }
}

void clearQueue(Queue *queue){

    if(queue->head != NULL) {
        Node *node = queue->head, *nextNode;

        while (node != NULL) {
            nextNode = node->next;
            freeNode((void **) &node);
            node = nextNode;
        }
        queue->head = NULL;
        queue->tail = NULL;
    }
}


int enqueue(Queue *queue, void *data){

    Node *node = (Node *)malloc(sizeof(Node));
    if(node == NULL){
        return -1;
    }
    node->data = data;
    node->next = NULL;

    if(queue->head == NULL){
        queue->head = node;
    }
    else{
       queue->tail->next = node;
    }
    queue->tail = node;
    return 1;
}

void dequeue(Queue *queue){

    if(queue->head != NULL) {

        if(queue->head == queue->tail){
            freeNode((void *)&queue->head);
            queue->head = NULL;
            queue->tail = NULL;
        }
        else {
            Node *nextNode = queue->head->next;
            freeNode((void **) &queue->head);
            queue->head = nextNode;
        }
    }
}

void *peek(Queue *queue){
    if(queue->head != NULL) {
        Node *node = queue->head;
        return node->data;
    }
    return NULL;
}


unsigned int getSize(Queue *queue){

    unsigned int len = 0;
    if(queue->head != NULL){
        Node *node = queue->head;
        while(node != NULL){
            node = node->next;
            len += 1;
        }
        return len;
    }
    return len;
}
