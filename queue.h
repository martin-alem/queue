//
// Created by Martin Alemajoh on 9/24/2020.
//

#ifndef QUEUE_QUEUE_H
#define QUEUE_QUEUE_H

/*
 * Node structure
*/
typedef struct node{

    void *data;
    struct node *next;
}Node;

/*
Queue structure
*/
typedef struct queue{

    Node *head;
    Node *tail;
}Queue;


/*
DEF: Initialize queue structure
PARAM: Queue *queue - queue structure to be initialize
RETURN: returns void
*/
void initQueue(Queue *stack);


/*
DEF: frees a node inside a queue
PARAM: void **node - pointer to node
RETURN: returns void
*/
void freeNode(void **node);


/*
DEF: Destroys the queues by deallocating all nodes
PARAM: Queue *queue - queue structure to be destroyed
RETURN: returns void
*/
void clearQueue(Queue *queue);



/*
DEF: Push a node onto the queue
PARAM1: Queue *queue - queue structure.
PARAM2: void data - data to be store inside node.
RETURN: returns 1 if push was successful otherwise -1
*/
int enqueue(Queue *stack, void *data);


/*
DEF: Pops off a node from the top of the queue
PARAM: Queue *queue - queue structure.
RETURN: returns void
*/
void dequeue(Queue *queue);


/*
DEF: Retrieves data stored at the top of the queue
PARAM: Queue *queue - queue structure
RETURN: returns pointer to void
*/
void *peek(Queue *queue);


/*
DEF: Gets the size of the queue
PARAM: Queue *queue - queue structure
RETURN: returns the size of the stack otherwise 0
*/
unsigned int getSize(Queue *queue);

#endif //QUEUE_QUEUE_H
