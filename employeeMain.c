#include <stdio.h>
#include <string.h>

#include "employeeOne.c"

void searchEmployee(Employee employees[], int size, void* key, int (*searchFunc)(Employee, void*)) {
    for (int i = 0; i < size; i++) {
        if (searchFunc(employees[i], key)) {
            printf("Match Found: ID=%d, Name=%s, Phone=%s, Salary=%.2f\n", 
                   employees[i].id, employees[i].name, employees[i].phone, employees[i].salary);
            return;
        }
    }
    printf("No match found.\n");
}

int main() {
    Employee employees[] = {
        {101, "Alice", "555-1234", 50000.0},
        {102, "Bob", "555-5678", 60000.0},
        {103, "Charlie", "555-9999", 55000.0}
    };

    char phoneKey[] = "555-5678"; 
    printf("Searching by Phone:\n");
    searchEmployee(employees, 3, phoneKey, searchByPhone);

    double salaryKey = 55000.0;
    printf("Searching by Salary:\n");
    searchEmployee(employees, 3, &salaryKey, searchBySalary);

    return 0;
}