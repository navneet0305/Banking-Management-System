#include <stdio.h>
#include <string.h>
#include "bms.h"

void deposit(int userIndex) {
    int enteredPin;
    float amount;
    
    printf("Enter PIN: ");
    scanf("%d", &enteredPin);
    
    if(enteredPin != accounts[userIndex].pin) {
        printf("Wrong PIN!\n");
        return;
    }
    
    printf("Enter Amount to Deposit: ");
    scanf("%f", &amount);
    
    if(amount <= 0) {
        printf("Invalid amount!\n");
        return;
    }
    
    accounts[userIndex].balance += amount;
    saveToFile();
    printf("Deposit Successful! New Balance: %.2f\n", accounts[userIndex].balance);
}

void withdraw(int userIndex) {
    char pass[20];
    int enteredPin;
    float amount;
    
    printf("Enter Password: ");
    scanf("%s", pass);
    
    if(strcmp(pass, accounts[userIndex].password) != 0) {
        printf("Wrong Password!\n");
        return;
    }
    
    printf("Enter PIN: ");
    scanf("%d", &enteredPin);
    
    if(enteredPin != accounts[userIndex].pin) {
        printf("Wrong PIN!\n");
        return;
    }
    
    printf("Enter Amount to Withdraw: ");
    scanf("%f", &amount);
    
    if(accounts[userIndex].balance >= amount) {
        accounts[userIndex].balance -= amount;
        saveToFile();
        printf("Withdrawal Successful! Remaining Balance: %.2f\n", 
               accounts[userIndex].balance);
    } else {
        printf("Insufficient Balance!\n");
    }
}
