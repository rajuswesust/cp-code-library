#include <stdio.h>

#define MX 101
typedef struct stack Stack;

struct stack{
    int top = -1;
    int data[MX];
};

void push(Stack *s, int item) {
    //printf("%d %d\n", s->top, item);
    if(s->top >= MX) {
        printf("Stack is full\n");
    }
    else {
        //printf("check push!!!\n");
        s->top++;
        s->data[s->top] = item;
    }
}

void pop(Stack *s) {
    if(s->top == -1) {
        printf("stack is empty\n");
    }
    else {
        s->top--;
    }
}

int top(Stack *s) {
    if(s->top == -1) {
        return -1;
    }
    else {
        return s->data[s->top];
    }
}

bool is_empty(Stack *s) {
    return (s->top <= -1);
}

void print_stack(Stack s) {
    while(!is_empty(&s)) {
        printf("%d ", top(&s));
        pop(&s);
    }
    printf("\n");
}

int main() {
    struct stack s;
    printf("current stack top = %d\n", top(&s));

    push(&s, 50);
    push(&s, 40);
    push(&s, 30);
    push(&s, 20);
    push(&s, 10);
    printf("top = %d\n", top(&s));

    pop(&s);
    pop(&s);
    print_stack(s);
}
