#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#include "bms.h"
void adminMenu();

int main() {
    printf("\n");
    printf("WELCOME TO BANK SYSTEM \n");
    printf("\n");
    loadFromFile();
    
    int choice;
    int loginAttempts = 0;
    const int MAX_LOGIN_ATTEMPTS = 3;

    do {
        printf("\n\n===== MAIN MENU =====");
        printf("\n1. Register New Account");
        printf("\n2. Login");
        printf("\n3. Admin Login");
        printf("\n4. Exit");
        printf("\nEnter Choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                registerAccount();
                break;
                
            case 2:
                {
                    int userIndex = login();
                    if(userIndex == -1) {
                        loginAttempts++;
                        printf("Invalid Login! Attempts: %d/%d\n", 
                               loginAttempts, MAX_LOGIN_ATTEMPTS);
                        
                        if(loginAttempts >= MAX_LOGIN_ATTEMPTS) {
                            printf("Too many failed attempts! Exiting...\n");
                            return 1;
                        }
                    } else {
                        printf("\n✓ Login Successful!\n");
                        printf("Welcome back, %s!\n", accounts[userIndex].name);
                        loginAttempts = 0;  
                        userMenu(userIndex);
                    }
                }
                break;
                
            case 3:
                adminMenu();  
                break;
                
            case 4:
                printf("\n✓ Thank you for using our banking system!\n");
                printf("  Have a great day!\n");
                break;
                
            default:
                printf("Invalid choice! Please select 1, 2, 3, or 4.\n");
        }
    } while(choice != 4);

    return 0;
}

void adminMenu() {
    char adminUser[20], adminPass[20];
    
    printf("\n=== ADMIN LOGIN ===\n");
    printf("Admin Username: ");
    scanf("%s", adminUser);
    printf("Admin Password: ");
    scanf("%s", adminPass);
    
    if(strcmp(adminUser, "admin") == 0 && strcmp(adminPass, "admin123") == 0) {
        printf("\n✓ Admin access granted!\n");
        int adminChoice;
        do {
            printf("\n--- ADMIN MENU ---");
            printf("\n1. View All Accounts");
            printf("\n2. Search Account");
            printf("\n3. Delete Account");
            printf("\n4. View Total Bank Balance");
            printf("\n5. View Account Statistics");
            printf("\n6. Logout");
            printf("\nEnter Choice: ");
            scanf("%d", &adminChoice);
            
            switch(adminChoice) {
                case 1:
                    displayAllAccounts();  
                    break;
                    
                case 2:
                    {
                        int searchAccNo;
                        printf("Enter Account Number to search: ");
                        scanf("%d", &searchAccNo);
                        
                        int found = -1;
                        for(int i = 0; i < totalAccounts; i++) {
                            if(accounts[i].accNo == searchAccNo) {
                                found = i;
                                break;
                            }
                        }
                        
                        if(found != -1) {
                            printf("\n--- ACCOUNT FOUND ---\n");
                            printf("Account No: %d\n", accounts[found].accNo);
                            printf("Name: %s\n", accounts[found].name);
                            printf("Username: %s\n", accounts[found].username);
                            printf("Balance: ₹%.2f\n", accounts[found].balance);
                        } else {
                            printf("Account not found!\n");
                        }
                    }
                    break;
                    
                case 3:
                    {
                        int deleteAccNo;
                        printf("Enter Account Number to delete: ");
                        scanf("%d", &deleteAccNo);
                        
                        int index = -1;
                        for(int i = 0; i < totalAccounts; i++) {
                            if(accounts[i].accNo == deleteAccNo) {
                                index = i;
                                break;
                            }
                        }
                        
                        if(index != -1) {
                            for(int i = index; i < totalAccounts - 1; i++) {
                                accounts[i] = accounts[i + 1];
                            }
                            totalAccounts--;
                            saveToFile();
                            printf("✓ Account %d deleted successfully!\n", deleteAccNo);
                        } else {
                            printf("Account not found!\n");
                        }
                    }
                    break;
                    
                case 4:
                    {
                        float totalBalance = 0;
                        for(int i = 0; i < totalAccounts; i++) {
                            totalBalance += accounts[i].balance;
                        }
                        printf("\n=== TOTAL BANK BALANCE ===\n");
                        printf("Total Accounts: %d\n", totalAccounts);
                        printf("Total Balance: ₹%.2f\n", totalBalance);
                        printf("Average Balance: ₹%.2f\n", 
                               totalBalance / totalAccounts);
                    }
                    break;
                    
                case 5:
                    {
                        float maxBalance = 0, minBalance = 99999999;
                        int maxIndex = 0, minIndex = 0;
                        
                        for(int i = 0; i < totalAccounts; i++) {
                            if(accounts[i].balance > maxBalance) {
                                maxBalance = accounts[i].balance;
                                maxIndex = i;
                            }
                            if(accounts[i].balance < minBalance) {
                                minBalance = accounts[i].balance;
                                minIndex = i;
                            }
                        }
                        
                        printf("\n=== ACCOUNT STATISTICS ===\n");
                        printf("Total Accounts: %d\n", totalAccounts);
                        printf("Highest Balance: ₹%.2f (Acc: %d - %s)\n", 
                               maxBalance, accounts[maxIndex].accNo, accounts[maxIndex].name);
                        printf("Lowest Balance: ₹%.2f (Acc: %d - %s)\n", 
                               minBalance, accounts[minIndex].accNo, accounts[minIndex].name);
                    }
                    break;
                    
                case 6:
                    printf("Logging out from admin panel...\n");
                    break;
                    
                default:
                    printf("Invalid choice!\n");
            }
        } while(adminChoice != 6);
        
    } else {
        printf("Invalid admin credentials!\n");
    }
}