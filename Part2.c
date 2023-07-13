#include <stdio.h>
#include <stdlib.h>

// Structure for a node in the Priority Queue
struct Node {
    int data;
    int priority;
    struct Node* next;
};

// Function to create a new node
struct Node* createNode(int data, int priority) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->priority = priority;
    newNode->next = NULL;
    return newNode;
}

// Function to insert a node with priority into the Priority Queue
void enqueue(struct Node** head, int data, int priority) {
    struct Node* newNode = createNode(data, priority);

    // If the Priority Queue is empty or the new node has higher priority than the head
    if (*head == NULL || priority < (*head)->priority) {
        newNode->next = *head;
        *head = newNode;
    } else {
        struct Node* current = *head;

        // Traverse the Priority Queue until the new node has higher priority than the next node
        while (current->next != NULL && current->next->priority <= priority) {
            current = current->next;
        }

        newNode->next = current->next;
        current->next = newNode;
    }

    printf("Enqueued: %d\n", data);
}

// Function to delete the node with the highest priority from the Priority Queue
void dequeue(struct Node** head) {
    if (*head == NULL) {
        printf("Priority Queue is empty.\n");
        return;
    }

    struct Node* temp = *head;
    *head = (*head)->next;
    printf("Dequeued: %d\n", temp->data);
    free(temp);
}

// Function to check if the Priority Queue is empty
int isEmpty(struct Node* head) {
    return head == NULL;
}

// Function to check if the Priority Queue is full (always returns false for a linked list implementation)
int isFull() {
    return 0;
}

// Function to display the Priority Queue
void display(struct Node* head) {
    if (isEmpty(head)) {
        printf("Priority Queue is empty.\n");
        return;
    }

    struct Node* current = head;
    printf("Priority Queue: ");

    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }

    printf("\n");
}

int main() {
    struct Node* head = NULL;
    int choice, data, priority;

    do {
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Is Empty\n");
        printf("4. Is Full\n");
        printf("5. Display\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the data and priority: ");
                scanf("%d %d", &data, &priority);
                enqueue(&head, data, priority);
                break;
            case 2:
                dequeue(&head);
                break;
            case 3:
                if (isEmpty(head)) {
                    printf("Priority Queue is empty.\n");
                } else {
                    printf("Priority Queue is not empty.\n");
                }
                break;
            case 4:
                if (isFull()) {
                    printf("Priority Queue is full.\n");
                } else {
                    printf("Priority Queue is not full.\n");
                }
                break;
            case 5:
                display(head);
                break;
            case 6:
                printf("Exiting the program.\n");
                break;
            default:
                printf("Invalid choice. Please enter a valid option.\n");
                break;
        }

        printf("\n");
    } while (choice != 6);

    return 0;
}
