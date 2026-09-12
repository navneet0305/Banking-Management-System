#ifndef BMS_H
#define BMS_H
#define MAX 100
typedef struct {
    int accNo;
    char name[50];
    char username[20];
    char password[20];
    int pin;
    float balance;
} Account;
extern Account accounts[MAX];
extern int totalAccounts;
void loadFromFile();
void saveToFile();
void registerAccount();
int login();
void deposit(int userIndex);
void withdraw(int userIndex);
void checkBalance(int userIndex);
void userMenu(int userIndex);
void displayAllAccounts();
void displayAccountSummary(int userIndex);

#endif