#include <stdio.h>
#include "myBank.h"
#define ACCNUM 901                                                                                                       // Account's numbers are from 901-950 this will add 901
                                                                                                                         // so the index of the array will match the account's number.

int main() {

    char action_char = 'A';                                                                                              // Determine what action the user wish to do after validation.
    int account_num =0;                                                                                                  // Determine what on what account the user wish to make the action.
    float deposit =0;                                                                                                    // Will contain the amount the user wish to deposit to a given account.
    float withdraw=0;                                                                                                    // Will contain the amount the user wish to withdraw from a given account.
    double interest=0;                                                                                                   // Will contain the interest the user wish to add to all accounts.
    int flag = 1;



    printf("\t**Bank Account Simulator**\n");
    printf("This Simulator will let you do the following actions on bank acc:\n");
    printf("list of operations:\n"
           "\tO - Open new account with starting balance\n"
           "\tB - Balance of a given account\n"
           "\tD - Deposit to a given account\n"
           "\tW - Withdraw from a given account\n"
           "\tC - Close the account\n"
           "\tI - Interest adding to all open accounts\n"
           "\tP - Print all the open accounts and balance\n"
           "\tE - Close all accounts and end the program\n");
    printf("\nNote:\n"
           "++  Must open account before doing any action on account.\n"
           "++  Can open up to 50 accounts only.\n"
           "++  Deposit/balance/withdraw real numbers with only two digits after decimal point.\n"
           "++  Deposit/withdraw with more then two digit after decimal point will be rounded.\n"
           "++  Characters other then number's in any of the cases will be ignored \n ");

    while(flag) {


        printf("\n What actions would you like to do:");
        TEST:
        if (scanf(" %c", &action_char) != 1 || action_char == '\n') {
            goto TEST;
        }
        printf("\n You have picked: %c", action_char);

        switch (action_char) {
            case 'O': {                                                                                                  // Case O: Open new acc.
                account_num = open_acc();                                                                                // Use open_acc function to get new account number.
                if (account_num ==-1) {                                                                                  // == -1, Meaning no account available.
                    printf("\n Sorry no available account at the moment \n");
                } else {                                                                                                 // Ask for amount to deposit.
                    printf("\n How much would you like to deposit? ");
                    if(scanf(" %f", &deposit) != 1){
                        break;
                    }else {
                        deposit_to_acc(deposit, account_num,1);                                                          // Use the deposit function to add it to the amount in the bank.
                    }
                }
                account_num = 0;
                deposit = 0;
                break;
            }

            case 'B': {                                                                                                  // Case B: Check balance.

                printf("Checking balance for account number: ");
                if(scanf(" %d",&account_num) != 1){                                                               // Input account number from user.
                    break;
                }

                if (is_acc_open(account_num) ==0) {                                                                      // Will use is_acc_open to determine if the it's a valid account
                    printf("\n The account number is invalid ");                                                  // Print out an invalid message and break and loop again
                    break;
                } else {
                    printf("\n The balance is : %.2f", check_balance(account_num));                               // If valid account, Use get balance function to show balance.
                }
                account_num = 0;
                break;
            }


            case 'D': {                                                                                                  // Case D: Deposit.
                printf("\n Account number for deposit:");
                if(scanf(" %d",&account_num) != 1){                                                               // Input account number from user.
                    break;
                }
                printf("\n How much would you like to deposit? ");
                if(scanf(" %f", &deposit) != 1) {
                    break;
                }
                deposit_to_acc(deposit, account_num - ACCNUM,1);                                                         // Will use deposit_to_acc function.
                account_num = 0;
                deposit = 0;
                break;
            }

            case 'W': {
                printf("\n Account number for withdraw:");
                if(scanf(" %d",&account_num) != 1){                                                               // Input account number from user.
                    break;
                }
                printf("\n How much would you like to withdraw? ");
                if(scanf(" %f", &withdraw) != 1){
                    break;
                }
                deposit_to_acc(withdraw * -1, account_num - ACCNUM,0);                                                   // Will use deposit_to_acc with a negative "deposit"
                account_num = 0;
                withdraw = 0;
                break;

            }

            case 'C': {                                                                                                  // Case C: close account.
                printf("\n Account number to close:");
                if(scanf(" %d",&account_num) != 1){                                                               // Input account number from user.
                    break;
                }

                close_acc(account_num);                                                                                  // Will use the close_acc function.
                account_num = 0;                                                                                         // Rest parameters.
                break;
            }


            case 'I': {                                                                                                  // Case I: add interest.
                printf("\n How much interest to add:");
                if(scanf(" %lf", &interest) != 1){
                 break;
                }
                add_interest(interest);                                                                                  // Will use add_interest function.
                interest = 0;
                break;
            }

            case 'P': {                                                                                                  // Case P: print all open accounts.
                print_all_acc();                                                                                         // Will use print_all_acc function.
                break;
            }

            case 'E': {                                                                                                  // Case E: close all accounts and finish the program.
                close_all_acc();                                                                                         // use close_all_acc function.
                flag = 0;
                break;
            }


            default:                                                                                                     // If giving an invalid operation.
                printf("\n Error! operator is not correct");

        }
    }


    printf("\n Thank you.");


    return 0;
}