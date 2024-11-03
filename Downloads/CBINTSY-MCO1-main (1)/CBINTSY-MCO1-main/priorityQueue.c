struct QueueTag {
    int head;
    int tail;
    PairPair elements[MAX_GRID*MAX_GRID];
};

typedef struct QueueTag Queue;

void initializeQueue(Queue *priorityQueue) {
	priorityQueue->head = 0;
	priorityQueue->tail = 0;
	for (int i=0; i<MAX_GRID*MAX_GRID; i++) {
		priorityQueue->elements[i].f = 0;
		priorityQueue->elements[i].innerPair.x = 0;
		priorityQueue->elements[i].innerPair.y = 0;
	}
}

// Checks if queue of PairPair is empty.
bool queueEmpty(Queue *priorityQueue) {
    return priorityQueue->head == priorityQueue->tail;
}

// Checks if queue of PairPair is full.
bool queueFull(Queue *priorityQueue) {
    return ( priorityQueue->head == (priorityQueue->tail + 1) % (MAX_GRID*MAX_GRID) );
}

// Sorts queue to priority queue by ascending order according to the f values of the PairPair elements.
void sortPriorityQueue(Queue *priorityQueue){
    int i, j, minIndex;
    PairPair temp;

    for(i = 0; i < priorityQueue->tail - 1; i++) {
        minIndex = i;
        for(j = i + 1; j < priorityQueue->tail; j++) {
            if(priorityQueue->elements[j].f < priorityQueue->elements[minIndex].f) {
                minIndex = j; 
            }
        }
        if (minIndex != i) {
            temp = priorityQueue->elements[i];
            priorityQueue->elements[i] = priorityQueue->elements[minIndex];
            priorityQueue->elements[minIndex] = temp;
        }
    }
}

void swapQueueElement(PairPair *x, PairPair *y){
	PairPair temp = *x;
	*x = *y;
	*y = temp;
}

void randomizePriorityQueue(Queue *priorityQueue){
    int idx = generateRandomNumber(priorityQueue->tail-1, priorityQueue->head);
    swapQueueElement(&priorityQueue->elements[priorityQueue->tail-1], &priorityQueue->elements[idx]);
}

// Enqueues a new PairPair into the queue.
void Enqueue(double f, int x, int y, Queue *priorityQueue, int mode){
    if(!queueFull(priorityQueue)){
        priorityQueue->elements[priorityQueue->tail].innerPair.x = x;
        priorityQueue->elements[priorityQueue->tail].innerPair.y = y;
        priorityQueue->elements[priorityQueue->tail].f = f;
        priorityQueue->tail = (priorityQueue->tail + 1) % (MAX_GRID*MAX_GRID);
    }
    if (mode == 1) // dumb
    	randomizePriorityQueue(priorityQueue);
    else // (mode == 2) smart
    	sortPriorityQueue(priorityQueue);
	// printf("\n");  
}

void Dequeue(PairPair *remove, Queue *priorityQueue){
    if(!queueEmpty(priorityQueue)){
        *remove = priorityQueue->elements[priorityQueue->head];
        priorityQueue->head = (priorityQueue->head + 1) % (MAX_GRID*MAX_GRID);
    }
}
