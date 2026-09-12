#include <stdio.h>
#include <string.h>
#include "bms.h"

void registerAccount() {
    loadFromFile();
    
    if(totalAccounts >= MAX) {
        printf("System limit reached! Cannot register more accounts.\n");
        return;
    }
    int newAccNo;
    if(totalAccounts == 0) {
        newAccNo = 1001;
    } else {
        int maxAccNo = accounts[0].accNo;
        for(int i = 1; i < totalAccounts; i++) {
            if(accounts[i].accNo > maxAccNo) {
                maxAccNo = accounts[i].accNo;
            }
        }
        newAccNo = maxAccNo + 1;
    }
    
    printf("\n=== NEW ACCOUNT REGISTRATION ===\n");
    accounts[totalAccounts].accNo = newAccNo;
    printf("Account Number: %d\n", newAccNo);
    
    printf("Enter Full Name: ");
    scanf("%s", accounts[totalAccounts].name);
    
    printf("Create Username: ");
    scanf("%s", accounts[totalAccounts].username);
    
    printf("Create Password: ");
    scanf("%s", accounts[totalAccounts].password);
    
    printf("Set 4-digit PIN: ");
    scanf("%d", &accounts[totalAccounts].pin);
    
    printf("Enter Initial Balance: ");
    scanf("%f", &accounts[totalAccounts].balance);
    
    if(accounts[totalAccounts].pin < 1000 || accounts[totalAccounts].pin > 9999) {
        printf("Invalid PIN! PIN must be 4 digits.\n");
        return;
    }
    
    if(accounts[totalAccounts].balance < 0) {
        printf("Invalid balance!\n");
        return;
    }
    FILE *fp = fopen("accounts.txt", "a");
    if(fp) {
        fprintf(fp, "%d %s %s %s %d %.2f\n",
                accounts[totalAccounts].accNo,
                accounts[totalAccounts].name,
                accounts[totalAccounts].username,
                accounts[totalAccounts].password,
                accounts[totalAccounts].pin,
                accounts[totalAccounts].balance);
        fclose(fp);
    }
    
    totalAccounts++;
    printf("\n✓ ACCOUNT CREATED SUCCESSFULLY!\n");
}

int login() {
    loadFromFile();
    
    char u[20], p[20];
    
    printf("\n=== LOGIN ===\n");
    printf("Enter Username: ");
    scanf("%s", u);
    printf("Enter Password: ");
    scanf("%s", p);
    
    for(int i = 0; i < totalAccounts; i++) {
        if(strcmp(u, accounts[i].username) == 0 && 
           strcmp(p, accounts[i].password) == 0) {
            return i;
        }
    }
    return -1;
}