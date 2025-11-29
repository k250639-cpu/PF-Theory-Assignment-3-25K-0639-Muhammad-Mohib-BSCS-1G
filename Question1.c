#include <stdio.h>

float calculateRepayment(float loan, float interestRate, float installment, float extraPay, int years, int currentYear){
    if (loan <= 0 || years == 0){
        printf("Loan fully repaid or no years remaining.\n");
        return 0;
    }
    float interest = loan * (interestRate / 100.0);
    loan = loan + interest;
    float payment = installment + extraPay;
    loan = loan - payment;
    if (loan < 0){
        loan = 0;
    }
    printf("Year %d: Remaining loan = %.2f\n", currentYear, loan);
    return payment + calculateRepayment(loan, interestRate, installment, extraPay, years - 1, currentYear + 1);
}

void valueInput(){
    float loan, rate, installment, extra;
    int years;
    printf("\nEnter Initial Loan Amount: ");
    scanf("%f", &loan);
    printf("Enter Yearly Interest Rate (%%): ");
    scanf("%f", &rate);
    printf("Enter Fixed Yearly Installment: ");
    scanf("%f", &installment);
    printf("Enter Extra Yearly Payment (0 if none): ");
    scanf("%f", &extra);
    printf("Enter Number of Years to Simulate: ");
    scanf("%d", &years);
    printf("\n==== Repayment Schedule ====\n");
    float totalPaid = calculateRepayment(loan, rate, installment, extra, years, 1);
    printf("\nTotal Paid Over %d Years = %.2f\n", years, totalPaid);
}

int main(){
    int choice;
    do{
        printf("\n======= Loan Repayment Menu =======\n");
        printf("1. Run Loan Repayment Simulation\n");
        printf("2. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);
        switch (choice){
            case 1:
                valueInput();
                break;
            case 2:
                printf("Exiting program...\n");
                break;
            default:
                printf("Invalid choice. Try again.\n");
        }
    } while (choice != 2);
    return 0;
}
