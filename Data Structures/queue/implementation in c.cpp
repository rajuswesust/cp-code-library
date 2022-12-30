#include <cstdio>

#define N 100

struct Queue {
    int head = 0, tail = 0;
    int data[N+1];
};

bool is_empty(struct Queue *q) {
    if(q->head == q->tail) return true;
    return false;
}

void enqueue(struct Queue *q, int x) {
    if((q->tail + 1) % (N+1) == q->head) {
        printf("queue is full");
        return;
    }
    q->data[q->tail] = x;
    q->tail++;
    q->tail %= (N+1);
}

void dequeue(struct Queue *q) {
     if(is_empty(q)) {
        printf("queue is empty\n");
        return;
    }
    q->head++;
    q->head %= (N+1);
}

int front(struct Queue *q) {
    if(is_empty(q)) {
        printf("queue is empty\n");
        return -1;
    }
    return q->data[q->head];
}
void print(struct Queue q) {
    if(is_empty(&q)) {
        printf("your queue is empty!\n");
        return;
    }
    while(!is_empty(&q)) {
        printf("%d ", front(&q));
        dequeue(&q);
    }
    printf("\n");
}
int main() {

    struct Queue q;
    front(&q);
    dequeue(&q);

    enqueue(&q, 10);
    enqueue(&q, 20);
    enqueue(&q, 30);

    print(q);

    dequeue(&q);
    dequeue(&q);
    print(q);

    dequeue(&q);
    print(q);

    enqueue(&q, 11);
    enqueue(&q, 22);
    print(q);
}
