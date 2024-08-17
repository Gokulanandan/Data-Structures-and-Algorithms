#include <stdio.h>
#include <stdlib.h>

// Create a Stack of dynamic queues

typedef struct node{
    int data;
    struct node *next;
}Node;

#define SIZE 10
static int top = -1;

Node* createNode(int val){
         Node *node = (Node*)malloc(sizeof(Node));
         if(node != NULL) {
            node->data = val;
            node->next = NULL;
         }
    return node;
}
// queue

Node* deleteNode(Node* head){
    if(head == NULL){
        printf("List/Queue is empty\n");
        return NULL;
    }
        Node *tmp = head;
        while(tmp->next->next != NULL){
            tmp = tmp->next;
        }
        printf("Delete Node called , deleting %d\n",tmp->next->data);
        free(tmp->next);
        tmp->next = NULL;
        return head;
}

Node* addNode(Node *head, int val){
    if(head == NULL) {
        head = createNode(val);
    } else {
        Node *tmp = head;
        head = createNode(val);
        head->next = tmp;
    }
    return head;
}

void deleteQueue(Node *head){
    while(head != NULL){
        Node *tmp = head->next;
        free(head);
        head = tmp;
    }
}
// stack functions

void push(Node** arr,int val){
    if (top == SIZE -1){
        printf("Stack is full\n");
        return;
    }
    printf("push called\n");
    Node *head = arr[++top];
    arr[top] = addNode(head, val);
}
void pop(Node** arr){
    if(top == -1){
       printf("Stack is empty\n");
       return;
    }
    printf("pop called\n");
    deleteQueue(arr[top--]);
}

void peek(Node** arr){
    Node* head = arr[top];
    printf("Value at the top stack Head Node is %d\n",head->data);
}

void printStack(Node** arr){
    if(top == -1){
        printf("Stack is empty\n");
    }
    Node* head = arr[top];
    while(head != NULL){
        printf("|%d|->",head->data);
        head = head->next;
    }
    printf("|NULL|\n");
}



int main(){
Node* arr[SIZE] = {NULL};
push(arr,10);
peek(arr);
arr[top] = addNode(arr[top],20);
peek(arr);
printStack(arr);
arr[top] = deleteNode(arr[top]);
printStack(arr);
push(arr,30);
arr[top] = addNode(arr[top],40);
peek(arr);
printStack(arr);
pop(arr);
printStack(arr);
return 0;
}
