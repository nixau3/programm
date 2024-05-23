#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* nextNode;
    struct Node* nextList;
} Node;

Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->nextNode = NULL;
    newNode->nextList = NULL;
    return newNode;
}

Node* addNode(Node* head, int data, Node** tail) {
    Node* newNode = createNode(data);
    if (head == NULL) {
        *tail = newNode;
        return newNode;
    } else {
        (*tail)->nextNode = newNode;
        *tail = newNode;
        return head;
    }
}

void printList(Node* head) {
    for (Node* current = head; current != NULL; current = current->nextNode) {
        printf("%d ", current->data);
    }
    printf("\n");
}

void freeList(Node* head) {
    while (head != NULL) {
        Node* temp = head;
        head = head->nextNode;
        free(temp);
    }
}

int main() {
    Node* firstList = NULL;
    Node* secondList = NULL;
    Node *firstTail = NULL, *secondTail = NULL;
    int data, count = 0;

    printf("Введите последовательность чисел (0 для окончания ввода):\n");
    while (1) {
        scanf("%d", &data);
        if (data == 0) break;

        count++;
        if (count % 2 == 1) {
            firstList = addNode(firstList, data, &firstTail);
        } else {
            secondList = addNode(secondList, data, &secondTail);
        }
    }

    if (firstTail && secondTail) {
        firstTail->nextList = secondList;
        secondTail->nextList = firstList;
    }

    printf("Первый список:\n");
    printList(firstList);

    printf("Второй список:\n");
    printList(secondList);

    printf("Нажмите 'a' для перехода к предыдущему списку и 'd' для перехода к следующему. Любая другая клавиша для выхода.\n");
    Node* current = firstList;
    char key;
    getchar();
    while (1) {
        printf("Значение: %d; Адрес предыдущего списка: %p, Адрес следующего узла: %p\n", current->data, (void*)current->nextList, (void*)current->nextNode);
        scanf("%c%*c", &key);

        if (key == 'a') {
            if (current->nextList) {
                current = current->nextList;
            } else {
                printf("Невозможно перейти: предыдущий список отсутствует\n");
            }
        } else if (key == 'd') {
            if (current->nextNode) {
                current = current->nextNode;
            } else {
                printf("Невозможно перейти: следующий узел отсутствует\n");
            }
        } else {
            printf("Выход..\n");
            break;
        }
    }

    freeList(firstList);
    freeList(secondList);

    return 0;
}
