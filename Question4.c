#include <stdio.h>
#include <string.h>

struct Book {
    int id;
    int popularity;
    int lastAccessTime;
};

int findBook(struct Book *shelf, int size, int id) {
    struct Book *ptr = shelf;
    for (int i = 0; i < size; i++, ptr++) {
        if ((*ptr).id == id) {
            return i;
        }
    }
    return -1;
}

int findLRU(struct Book *shelf, int size) {
    int index = 0;
    struct Book *ptr = shelf;
    int minTime = (*ptr).lastAccessTime;
    for (int i = 1; i < size; i++) {
        ptr = shelf + i;
        if ((*ptr).lastAccessTime < minTime) {
            minTime = (*ptr).lastAccessTime;
            index = i;
        }
    }
    return index;
}

int main() {
    int capacity, Q;
    scanf("%d %d", &capacity, &Q);
    if (capacity > 1000) capacity = 1000;
    struct Book shelf[1000];
    for (int i = 0; i < 1000; i++) {
        shelf[i].id = -1;
        shelf[i].popularity = 0;
        shelf[i].lastAccessTime = 0;
    }
    int size = 0;
    int timer = 1;
    while (Q--) {
        char command[10];
        scanf("%s", command);
        if (strcmp(command, "ADD") == 0) {
            int x, y;
            scanf("%d %d", &x, &y);
            int index = findBook(shelf, size, x);
            if (index != -1) {
                struct Book *ptr = shelf + index;
                (*ptr).popularity = y;
                (*ptr).lastAccessTime = timer++;
            } else {
                if (size < capacity) {
                    struct Book *ptr = shelf + size;
                    (*ptr).id = x;
                    (*ptr).popularity = y;
                    (*ptr).lastAccessTime = timer++;
                    size++;
                } else {
                    int lru = findLRU(shelf, size);
                    struct Book *ptr = shelf + lru;
                    (*ptr).id = x;
                    (*ptr).popularity = y;
                    (*ptr).lastAccessTime = timer++;
                }
            }
        }
        else if (strcmp(command, "ACCESS") == 0) {
            int x;
            scanf("%d", &x);
            int index = findBook(shelf, size, x);
            if (index == -1) {
                printf("-1\n");
            } else {
                struct Book *ptr = shelf + index;
                printf("%d\n", (*ptr).popularity);
                (*ptr).lastAccessTime = timer++;
            }
        }
    }
    return 0;
}
