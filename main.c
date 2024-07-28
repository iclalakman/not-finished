#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct friendNode {
    char name[20];
    int age;
    int array[5];
    struct friendNode *next;
};

struct friendNode * addFriend(struct friendNode *p);
void displayPopularFriend(struct friendNode *p);

int main() {
    int command;
    struct friendNode *friendList = NULL;
    do {
        printf("1. Add a friend\n");
        printf("2. Display popular friend\n");
        printf("3. Exit\n");
        printf("Enter command: ");
        scanf("%d", &command);
        switch (command) {
            case 1:
                friendList = addFriend(friendList);
                break;
            case 2:
                displayPopularFriend(friendList);
                break;
            case 3:
                break;
            default:
                printf("Invalid command. Please try again.\n");
        }
    } while (command != 3);
    return 0;
}

struct friendNode * addFriend(struct friendNode *p) {
    struct friendNode *newNode = (struct friendNode *) malloc(sizeof(struct friendNode));
    if (newNode == NULL) {
        printf("Memory allocation failed.");
        exit(0);
    }

    printf("Name: ");
    scanf("%19s", newNode->name);
    printf("Age: ");
    scanf("%d", &newNode->age);
    printf("The number of likes in the last five posts: ");
    scanf("%d %d %d %d %d", &newNode->array[0], &newNode->array[1], &newNode->array[2], &newNode->array[3], &newNode->array[4]);
    newNode->next = NULL;

    if (p == NULL) {
        return newNode;
    } else {
        struct friendNode *temp = p;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }

    return p;
}

void displayPopularFriend(struct friendNode *p) {
    if (p == NULL) {
        printf("No friends in the list.\n");
        return;
    }

    int totalLikes, mostLikes;
    char name[20];
    struct friendNode *temp = p;

    strcpy(name, temp->name);
    mostLikes = temp->array[0] + temp->array[1] + temp->array[2] + temp->array[3] + temp->array[4];
    temp = temp->next;

    while (temp != NULL) {
        totalLikes = temp->array[0] + temp->array[1] + temp->array[2] + temp->array[3] + temp->array[4];
        if (totalLikes > mostLikes) {
            mostLikes = totalLikes;
            strcpy(name, temp->name);
        }
        temp = temp->next;
    }
    printf("Friend with the highest likes is: %s\n", name);
}
