#include <stdio.h>
#include <string.h>

typedef struct {
    int id;
    char name[50];
    char phone[15];
    double salary;
} Employee;

// Existing search functions
int searchByID(Employee e, void* key) {
    return e.id == *(int*)key;
}

int searchByName(Employee e, void* key) {
    return strcmp(e.name, (char*)key) == 0;
}

// Add search by phone number using a function pointer
int searchByPhone(Employee e, void* key) {
    return strcmp(e.phone, (char*)key) == 0;
}