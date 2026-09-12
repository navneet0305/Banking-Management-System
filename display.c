#include <stdio.h>
#include <string.h>
#include "bms.h"

void checkBalance(int userIndex) {
    int acc;
    char pass[20];

    printf("\n--- CHECK BALANCE ---\n");
    printf("Enter Account Number: ");
    scanf("%d", &acc);

    printf("Enter Password: ");
    scanf("%s", pass);
    if(acc == accounts[userIndex].accNo && 
       strcmp(pass, accounts[userIndex].password) == 0) {
        printf("\n");
        printf("Account Number: %-18d \n", accounts[userIndex].accNo);
        printf(" Name: %-26s \n", accounts[userIndex].name);
        printf("Username: %-24s \n", accounts[userIndex].username);
        printf("Balance: ₹%-24.2f\n", accounts[userIndex].balance);
        printf("\n");
    } else {
        printf("Invalid Details! Please check Account Number and Password.\n");
    }
}

void displayAllAccounts() {
    printf("\n");
    printf("ALL ACCOUNTS LIST\n");
    printf("\n");
    
    for(int i = 0; i < totalAccounts; i++) {
        printf(" %-3d | %-6d | %-15s | ₹%-10.2f \n", 
               i+1,
               accounts[i].accNo, 
               accounts[i].name, 
               accounts[i].balance);
    }
    printf("\n");
}
void displayAccountSummary(int userIndex) {
    printf("\n");
    printf("ACCOUNT SUMMARY\n");
    printf("\n");
    printf("Account No:    %-20d \n", accounts[userIndex].accNo);
    printf("Account Holder:%-20s \n", accounts[userIndex].name);
    printf("Username:      %-20s \n", accounts[userIndex].username);
    printf("Account Type:  %-20s \n", "Savings");
    printf("Current Balance:₹%-17.2f \n", accounts[userIndex].balance);
    printf("\n");
}

void userMenu(int userIndex) {
    int choice;
    printf("\n");
    printf("\n Welcome, %-20s ", accounts[userIndex].name);
    printf("\n");
    
    do {
        printf("\n\n--- USER MENU ---");
        printf("\n1. Deposit Money");
        printf("\n2. Withdraw Money");
        printf("\n3. Check Balance");
        printf("\n4. View Account Summary");
        printf("\n5. Logout");
        printf("\nEnter Choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1: 
                deposit(userIndex); 
                break;
            case 2: 
                withdraw(userIndex); 
                break;
            case 3: 
                checkBalance(userIndex); 
                break;
            case 4:
                displayAccountSummary(userIndex);
                break;
            case 5:
                printf("\nLogging out...\n");
                break;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    } while(choice != 5);
}