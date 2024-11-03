#include "priorityQueue.c"
void initializeQueue(Queue *priorityQueue);
bool queueEmpty(Queue *priorityQueue);
bool queueFull(Queue *priorityQueue);
void swapQueueElement(PairPair *x, PairPair *y);
void randomizePriorityQueue(Queue *priorityQueue);
void Enqueue(double f, int x, int y, Queue *priorityQueue, int mode);
void Dequeue(PairPair *remove, Queue *priorityQueue);
void sortPriorityQueue(Queue *priorityQueue);
