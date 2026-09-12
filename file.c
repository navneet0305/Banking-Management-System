#include <stdio.h>
#include "bms.h"

Account accounts[MAX];
int totalAccounts = 0;

void loadFromFile() {
    FILE *fp = fopen("accounts.txt", "r");
    if(fp == NULL) {
        totalAccounts = 0;
        return;
    }
    
    totalAccounts = 0;
    while(fscanf(fp, "%d %s %s %s %d %f",
        &accounts[totalAccounts].accNo,
        accounts[totalAccounts].name,
        accounts[totalAccounts].username,
        accounts[totalAccounts].password,
        &accounts[totalAccounts].pin,
        &accounts[totalAccounts].balance) == 6) 
    {
        totalAccounts++;
        if(totalAccounts >= MAX) break;
    }
    
    fclose(fp);
}

void saveToFile() {
    FILE *fp = fopen("accounts.txt", "w");
    if(fp == NULL) {
        printf("Error saving to file!\n");
        return;
    }
    
    for(int i = 0; i < totalAccounts; i++) {
        fprintf(fp, "%d %s %s %s %d %.2f\n",
                accounts[i].accNo,
                accounts[i].name,
                accounts[i].username,
                accounts[i].password,
                accounts[i].pin,
                accounts[i].balance);
    }
    
    fclose(fp);
}