#include <stdio.h>
#include <string.h>

struct Employee{
    int id;
    char name[50];
    char designation[50];
    float salary;
};

void displayEmployees(struct Employee emp[], int n){
    int i;
    printf("\n-----------------------------------------------\n");
    printf("%-10s %-20s %-20s %-10s\n", "ID", "Name", "Designation", "Salary");
    printf("-----------------------------------------------\n");
    for (i = 0; i < n; i++) {
        printf("%-10d %-20s %-20s %-10.2f\n", emp[i].id, emp[i].name, emp[i].designation, emp[i].salary);
    }
    printf("-----------------------------------------------\n");
}

void findHighestSalary(struct Employee emp[], int n){
    int i, index = 0;
    float max = emp[0].salary;
    for (i = 1; i < n; i++) {
        if (emp[i].salary > max) {
            max = emp[i].salary;
            index = i;
        }
    }
    printf("\nEmployee with Highest Salary:\n");
    printf("ID: %d\n", emp[index].id);
    printf("Name: %s\n", emp[index].name);
    printf("Designation: %s\n", emp[index].designation);
    printf("Salary: %.2f\n", emp[index].salary);
}

void searchEmployee(struct Employee emp[], int n) {
    int choice;
    printf("\nSearch Employee By:\n1. ID\n2. Name\nEnter choice: ");
    scanf("%d", &choice);
    if (choice == 1){
        int id, i;
        printf("Enter ID: ");
        scanf("%d", &id);
        for (i = 0; i < n; i++){
            if (emp[i].id == id){
                printf("\nRecord Found:\n");
                printf("ID: %d\nName: %s\nDesignation: %s\nSalary: %.2f\n", emp[i].id, emp[i].name, emp[i].designation, emp[i].salary);
                return;
            }
        }
        printf("Employee not found!\n");
    }else if (choice == 2){
        char name[50];
        int i;
        printf("Enter Name: ");
        getchar(); 
        scanf("%[^\n]", name);
        for (i = 0; i < n; i++){
            if (strcmp(emp[i].name, name) == 0){
                printf("\nRecord Found:\n");
                printf("ID: %d\nName: %s\nDesignation: %s\nSalary: %.2f\n", emp[i].id, emp[i].name, emp[i].designation, emp[i].salary);
                return;
            }
        }
        printf("Employee not found!\n");
    }
    else{
        printf("Invalid option!\n");
    }
}

void giveBonus(struct Employee emp[], int n){
    int i, threshold = 50000;
    for (i = 0; i < n; i++){
        if (emp[i].salary < threshold){
            emp[i].salary = emp[i].salary + emp[i].salary * 0.10;
        }
    }
    printf("\nBonus Applied Successfully!\n");
}

int main() {
    struct Employee emp[100];
    int n, i;
    printf("Enter number of employees: ");
    scanf("%d", &n);
    for (i = 0; i < n; i++){
        printf("\n--- Enter details for Employee %d ---\n", i + 1);
        printf("Enter ID: ");
        scanf("%d", &emp[i].id);
        getchar();
        printf("Enter Name: ");
        scanf("%[^\n]", emp[i].name);
        getchar();
        printf("Enter Designation: ");
        scanf("%[^\n]", emp[i].designation);
        printf("Enter Salary: ");
        scanf("%f", &emp[i].salary);
    }
    int choice;
    do{
        printf("\n===== EMPLOYEE MANAGEMENT MENU =====\n");
        printf("1. Display All Employees\n");
        printf("2. Find Highest Salary\n");
        printf("3. Search Employee\n");
        printf("4. Give 10%% Bonus (Salary < 50000)\n");
        printf("5. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);
        switch(choice) {
            case 1: displayEmployees(emp, n); break;
            case 2: findHighestSalary(emp, n); break;
            case 3: searchEmployee(emp, n); break;
            case 4: giveBonus(emp, n); break;
            case 5: printf("Exiting\n"); break;
            default: printf("Invalid choice!\n");
        }
    } while (choice != 5);
    return 0;
}
