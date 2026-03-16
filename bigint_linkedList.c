#include <stdio.h>
#include <stdlib.h>


struct Node {
    int digit;
    struct Node* next;
};


struct Node* createNode(int d) {
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    temp->digit = d;
    temp->next = NULL;
    return temp;
}


void insertEnd(struct Node** head, int d) {
    struct Node* temp = createNode(d);
    if (*head == NULL) {
        *head = temp;
        return;
    }
    struct Node* cur = *head;
    while (cur->next)
        cur = cur->next;
    cur->next = temp;
}


struct Node* createListFromNumber(int num) {
    struct Node* head = NULL;
    if (num == 0) {
        insertEnd(&head, 0);
        return head;
    }
    while (num > 0) {
        insertEnd(&head, num % 10);
        num /= 10;
    }
    return head;
}


void display(struct Node* head) {
    if (head == NULL)
        return;
    display(head->next);
    printf("%d", head->digit);
}


struct Node* add(struct Node* a, struct Node* b) {
    struct Node* result = NULL;
    int carry = 0;

    while (a || b || carry) {
        int sum = carry;
        if (a) { sum += a->digit; a = a->next; }
        if (b) { sum += b->digit; b = b->next; }

        insertEnd(&result, sum % 10);
        carry = sum / 10;
    }
    return result;
}


struct Node* multiply(struct Node* a, struct Node* b) {
    struct Node* result = createListFromNumber(0);
    struct Node* bPtr = b;
    int shift = 0;

    while (bPtr) {
        struct Node* temp = NULL;
        struct Node* aPtr = a;
        int carry = 0;

        
        for (int i = 0; i < shift; i++)
            insertEnd(&temp, 0);

        while (aPtr || carry) {
            int prod = carry;
            if (aPtr) {
                prod += aPtr->digit * bPtr->digit;
                aPtr = aPtr->next;
            }
            insertEnd(&temp, prod % 10);
            carry = prod / 10;
        }

        result = add(result, temp);
        bPtr = bPtr->next;
        shift++;
    }
    return result;
}


struct Node* factorial(int n) {
    struct Node* result = createListFromNumber(1);

    for (int i = 2; i <= n; i++) {
        struct Node* temp = createListFromNumber(i);
        result = multiply(result, temp);
    }
    return result;
}


int main() {
    int n1, n2, n;

    printf("Enter first number: ");
    scanf("%d", &n1);
    printf("Enter second number: ");
    scanf("%d", &n2);

    struct Node* num1 = createListFromNumber(n1);
    struct Node* num2 = createListFromNumber(n2);

    printf("\nAddition: ");
    struct Node* sum = add(num1, num2);
    display(sum);

    printf("\nMultiplication: ");
    struct Node* prod = multiply(num1, num2);
    display(prod);

    printf("\n\nEnter number for factorial: ");
    scanf("%d", &n);

    printf("Factorial: ");
    struct Node* fact = factorial(n);
    display(fact);

    return 0;
}