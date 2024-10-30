#include <stdio.h>
#include <string.h>

//store account information
struct Account {
    int accountNumber;
    char accountHolder[50];
    float balance;
};
// Array of accounts accept only `100
struct Account accounts[100];
int totalAccounts = 0;
//create a new account
void createAccount() {
    struct Account newAccount;
    printf("\nEnter Account Holder Name: ");
    scanf("%s", newAccount.accountHolder);
    printf("Enter Initial Deposit: ");
    scanf("%f", &newAccount.balance);
    newAccount.accountNumber = totalAccounts + 1; // Unique account number
    accounts[totalAccounts++] = newAccount;
    printf("Account created successfully! Your Account Number is %d\n", newAccount.accountNumber);
}
//deposit money
void deposit(int accountNumber) {
    float amount;
    printf("Enter amount to deposit: ");
    scanf("%f", &amount);
    for (int i = 0; i < totalAccounts; i++) {
        if (accounts[i].accountNumber == accountNumber) {
            accounts[i].balance += amount;
            printf("Deposit successful! New balance: %.2f\n", accounts[i].balance);
            return;
        }
    }
    printf("Account not found.\n");
}
//withdraw money
void withdraw(int accountNumber) {
    float amount;
    printf("Enter amount to withdraw: ");
    scanf("%f", &amount);
    for (int i = 0; i < totalAccounts; i++) {
        if (accounts[i].accountNumber == accountNumber) {
            if (accounts[i].balance >= amount) {
                accounts[i].balance -= amount;
                printf("Withdrawal successful! New balance: %.2f\n", accounts[i].balance);
            } else {
                printf("Insufficient balance!\n");
            }
            return;
        }
    }
    printf("Account not found.\n");
}
//view account details
void viewAccount(int accountNumber) {
    for (int i = 0; i < totalAccounts; i++) {
        if (accounts[i].accountNumber == accountNumber) {
            printf("\nAccount Number: %d\n", accounts[i].accountNumber);
            printf("Account Holder: %s\n", accounts[i].accountHolder);
            printf("Current Balance: %.2f\n", accounts[i].balance);
            return;
        }
    }
    printf("Account not found.\n");
}
// Main program menu
int main() {
    int choice, accountNumber;
    while (1) {
        printf("\nBanking System Menu\n");
        printf("1. Create Account\n");
        printf("2. Deposit\n");
        printf("3. Withdraw\n");
        printf("4. View Account\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                createAccount();
                break;
            case 2:
                printf("Enter account number: ");
                scanf("%d", &accountNumber);
                deposit(accountNumber);
                break;
            case 3:
                printf("Enter account number: ");
                scanf("%d", &accountNumber);
                withdraw(accountNumber);
                break;
            case 4:
                printf("Enter account number: ");
                scanf("%d", &accountNumber);
                viewAccount(accountNumber);
                break;
            case 5:
                printf("Exiting the program.\n");
                return 0;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }
    return 0;
}