#include <stdio.h>
#include <string.h>
#define ACCNUM 901

//// This array will represent the account.
//// The first [] parameter - will determine if the account is closed/open.
///  The second [] parameter - will determine the balance in the account.
static double account_array[2][50];

/**
 * This function will check if a given account number us -valid-
 * by checking if it's in the range of 50.
 * @param acc_num - an account number
 * @return 0 - invalid account. 1 - valid account.
 */
int is_acc_valid(int acc_num){
    if(acc_num-ACCNUM<0 || acc_num-ACCNUM>49){
        return 0;
    }
    return 1;
}
/**
 * This function will check if a given account number us -open-
 * by: 1. use is_acc_open 2. if valid, will check in the array in the account is open/closed.
 * @param acc_num - an account number
 * @return 0 - invalid/close account. 1 - open account.
 */

int is_acc_open(int acc_num){

    if(is_acc_valid(acc_num)==0){
        return 0;
    }

    if(account_array[0][acc_num-ACCNUM]==0){
        return 0;
    }
    return 1;
}

/**
 * This function will check the balance of a given account,
 * by: 1. use is_acc_open 2. If open will take the amount from the place in the array.
 *
 * @param acc_num - an account number
 * @return 0 - invalid/close account. otherwise the balance of the account
 */
double check_balance(int acc_num){
    int acc_index = acc_num-ACCNUM;
    if(is_acc_open(acc_num) == 0){
        return 0;
    }
    else{
        return account_array[1][acc_index];
    }
}
/**
 * This function will open a new account by looping over the array
 * and checking if there are any closed account using is_acc_open function.
 * @return -1 - All account are open. otherwise new Account number
 */
int open_acc(){
    for (int i = 0; i < 50; ++i) {
        if(is_acc_open(i+ACCNUM)==0){
            printf("\n Your new account number is: %d \n",i+ACCNUM);
            account_array[0][i] = 1;
            return i;
        }
    }

    return -1;
}

/**
 * This function will take any number and make into
 * a number with only two digits after decimal point.
 * @param dep - Number wish to convert.
 * @return The number after conversion.
 */
double two_digit_dcimal(double dep){
    double temp = (int)(dep*100);
    dep = (double)temp/100;
    return dep;
}

/**
 * This function will deposit a given amount to a selected account.
 * by 1. use is_acc_open 2. Check if the dep is valid according to the action that would like to do
 * 3. If all valid will convert the deposit to be with only two digits after decimal point.
 * 4. Will add the deposit amount to the account in the array.
 * @param dep - The amount wish to deposit.
 * @param acc - The account number wish to deposit to.
 * @param action - Will determine what action would like to do: 1 - Deposit 0 - Withdraw
 */
void deposit_to_acc(double dep, int acc, int action){

    if(is_acc_open(acc+ACCNUM)==0){
        printf("\n The account number is invalid");
        return;
    }
    else if(action == 1 && dep < 0){
        printf("\n Not a valid deposit");
        return;
    } else if(action == 0 && dep > 0){
        printf("\n Not a valid withdraw");
        return;
    }

    dep = two_digit_dcimal(dep);
    account_array[1][acc] = account_array[1][acc] + dep;
    printf("\n The balance in account number %d is: %.2lf \n",acc+ACCNUM, account_array[1][acc]);
}

/**
 * This function will close any given account
 * by 1. use is_acc_open 2. If valid setting the "open" parameter to zero and the balance parameter to zero.
 * @param acc_num - The account number wish to close.
 */
void close_acc(int acc_num){

    if(is_acc_open(acc_num)==0){
        printf("\n The account is invalid or already closed");
    }
    int acc_index = acc_num-ACCNUM;
    account_array[0][acc_index] = 0;
    account_array[1][acc_index] = 0;
    printf("\n The account %d has been closed",acc_num);

}

/**
 * This function will add interest to all -open- accounts,
 * by 1. Looping over all the array 2. Using is_acc_open 3. If open interest.
 * @param interest
 */
void add_interest(double interest){

    for (int i = 0; i < 50 ; ++i) {
        if(is_acc_open(i+ACCNUM)==1){
            account_array[1][i]= account_array[1][i]*(interest+100)/100;
        }
    }

}
/**
 * This function will print out all the -open- account
 * by 1. Looping over all the array 2. Using is_acc_open 3. If open print.
 */
void print_all_acc(){
    for (int i = 0; i < 50 ; ++i) {
        if(is_acc_open(i+ACCNUM)==1){
            printf("\n Account number: %d  Balance: %.2lf",i+ACCNUM,account_array[1][i]);
        }
    }

}

/**
 * This function will close all the account's.
 * by 1. Looping over all the array 2. Using is_acc_open 3. If open print.
 *
 */
void close_all_acc(){
    for (int i = 0; i < 50 ; ++i) {
        if(is_acc_open(i+ACCNUM)==1){
            close_acc(i+ACCNUM);
        }
    }

}








