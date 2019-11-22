#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#define ACCNUM 901                                                                                                       // Account's numbers are from 901-950 this will add 901
                                                                                                                         // so the index of the array will match the account's number.
int open_acc() ;
void deposit_to_acc(double , int);
double check_balance(int );
int is_acc_open(int );
void close_acc(int );
void add_interest(double);
void print_all_acc();
void close_all_acc();

int main() {

    int boolean = 1;                                                                                                     // The "boolean" that will track is the user want to stay or close the program.
    char action_str[100] ;                                                                                               // Temp string to contain user input and validate before continuing
    char action_char;                                                                                                    // Determine what action the user wish to do after validation.
    int account_num;                                                                                                     // Determine what on what account the user wish to make the action.
    double deposit;                                                                                                      // Will contain the amount the user wish to deposit to a given account.
    double withdraw;                                                                                                     // Will contain the amount the user wish to withdraw from a given account.
    double interest;                                                                                                     // Will contain the interest the user wish to add to all accounts.



    printf("\t**Bank Account Simulator**\n");
    printf("This Simulator will let you do the following actions on bank acc:\n");
    printf("list of operations:\n"
           "\tO - Open new account with starting balance\n"
           "\tB - Balance of a given account\n"
           "\tD - Deposit to a given account\n"
           "\tW - Withdraw from a given account\n"
           "\tC - Close the account"
           "\tI - Interest adding to all open accounts\n"
           "\tP - Print all the open accounts and balance\n"
           "\tE - Close all accounts and end the program\n");
    printf("\nNote:\n"
           "++  Must open account before doing any action on them.\n"
           "++  Can open up to 50 accounts only.\n"
           "++  Deposit/balance will real numbers with only two digits after decimal point.\n"
           "++  Deposit with more then two digit after decimal point will be rounded.\n ");


    while(boolean){

        printf("\n What actions would you like to do:");
        scanf("%s", action_str);                                                                                  // Scan into a temp string the operation the user want's to make
         if(strlen(action_str) != 1){                                                                                    // Check the string length, most be 1 char
            printf("not valid \n");action_char = 'F';                                                             // If not 1 char, will give F so in switch case will go to default
        }
        else {
            printf("valid \n");
            action_char = action_str[0];                                                                                 // If it is 1 set the char to be the char the user entered
        }


        while ((getchar()) != '\n');



        switch(action_char)
        {
            case 'O':{                                                                                                   // Case O: Open new acc.
            account_num = open_acc();                                                                                    // Use open_acc function to get new account number.

            if(account_num == -1){                                                                                       // == -1, Meaning no account available.
                printf("\n Sorry no available account at the moment \n");
            }
            else{                                                                                                        // Ask for amount to deposit.
                printf("\n How much would you like to deposit? ");
                scanf("%lf", &deposit);
                if(deposit < 0){                                                                                         // If negative deposit will not allow it.
                    printf("\n not a valid deposit");
                }else {
                    deposit_to_acc(deposit, account_num);                                                                // Use the deposit function to add it to the amount in the bank.
                }
            }

            account_num =0;                                                                                              // Rest parameters and scanf buffer
            deposit =0;
            while ((getchar()) != '\n');
            break;
            }

            case 'B':{                                                                                                   // Case B: Check balance.

                printf("Checking balance for account number: ");
                scanf("%d", &account_num);                                                                        // Input account number from user.

                if(is_acc_open(account_num)==0){                                                                         // If the account is not in range will not allow.
                    printf("\n The account number is invalid ");
                }
                else{
                    if(check_balance(account_num)!=0){                                                                   // Use get balance function to show balance.
                        printf("\n The balance is : %.2lf",check_balance(account_num));
                    }
                }

                account_num =0;                                                                                          // Rest parameters and scanf buffer
                while ((getchar()) != '\n');
                break;
            }


            case 'D':{
                printf("\n Account number for deposit:");
                scanf("%d", &account_num);
                while ((getchar()) != '\n');

                if(is_acc_open(account_num)==0){                                                                         // If the account is not in range will not allow.
                    printf("\n The account number is invalid");
                    break;
                } else{
                    printf("\n How much would you like to deposit? ");
                    scanf("%lf",&deposit);
                    if(deposit < 0){
                        printf("\n not a valid deposit");
                    } else{
                        deposit_to_acc(deposit, account_num-ACCNUM);
                    }
                }

                account_num =0;                                                                                          // Rest parameters and scanf buffer
                deposit =0;
                while ((getchar()) != '\n');
                break;
            }

            case 'W':{
                printf("\n Account number for withdraw:");
                scanf("%d", &account_num);
                while ((getchar()) != '\n');

                if(check_balance(account_num)==0){                                                                       // If the account is not in range will not allow.
                    printf("\n The account is invalid or has zero balance");
                    break;
                } else{
                    printf("\n How much would you like to withdraw? ");
                    scanf("%lf",&withdraw);
                    if(withdraw < 0){
                        printf("\n not a valid deposit");
                    } else{
                        deposit_to_acc(withdraw*-1, account_num-ACCNUM);
                    }
                }

                account_num =0;                                                                                          // Rest parameters and scanf buffer
                withdraw =0;
                while ((getchar()) != '\n');
                break;

            }

            case 'C':{
                printf("\n Account number to close:");
                scanf("%d", &account_num);
                while ((getchar()) != '\n');

                if(is_acc_open(account_num)==0){
                    printf("\n The account is invalid or already closed");
                    break;
                } else{
                    close_acc(account_num);
                }

                account_num=0;
                break;
            }


            case 'I':{
                printf("\n How much interest to add:");
                scanf("%lf", &interest);
                while ((getchar()) != '\n');
                add_interest(interest);
                interest=0;
                break;
            }

            case 'P':{
                print_all_acc();
                break;
            }

            case 'E':{
                close_all_acc();
                boolean =0;
                break;
            }


            default:
                printf("Error! operator is not correct");

        }


    }

    printf("\n the end");


    return 0;
}