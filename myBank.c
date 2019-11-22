#include <stdio.h>
#include <string.h>

#define ACCNUM 901
static double account_array[2][50];

int is_acc_valid(int acc_num){
    if(acc_num-ACCNUM<0 || acc_num-ACCNUM>49){
        return 0;
    }
    return 1;
}

int is_acc_open(int acc_num){

    if(is_acc_valid(acc_num)==0){
        return 0;
    }

    if(account_array[0][acc_num-ACCNUM]==0){
        return 0;
    }
    return 1;
}

double check_balance(int acc){
    int acc_index = acc-ACCNUM;
    if(is_acc_open(acc) == 0){
        return 0;
    }
    else{
        return account_array[1][acc_index];
    }
}

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

double two_digit_dcimal(double dep){
    double temp = (int)(dep*100);
    dep = (double)temp/100;
    return dep;
}

void deposit_to_acc(double dep, int acc ){
    dep = two_digit_dcimal(dep);
    account_array[1][acc] = account_array[1][acc] + dep;
    printf("\n The balance in account number %d is: %.2lf \n",acc+ACCNUM, account_array[1][acc]);
}

void close_acc(int acc_num){
    int acc_index = acc_num-ACCNUM;
    account_array[0][acc_index] = 0;
    account_array[1][acc_index] = 0;
    printf("\n The account %d has been closed",acc_num);

}
void add_interest(double interest){

    for (int i = 0; i < 50 ; ++i) {
        if(is_acc_open(i+ACCNUM)==1){
            account_array[1][i]= account_array[1][i]*(interest+100)/100;
        }
    }

}

void print_all_acc(){
    for (int i = 0; i < 50 ; ++i) {
        if(is_acc_open(i+ACCNUM)==1){
            printf("\n Account number: %d  Balance: %.2lf",i+ACCNUM,account_array[1][i]);
        }
    }

}

void close_all_acc(){
    for (int i = 0; i < 50 ; ++i) {
        if(is_acc_open(i+ACCNUM)==1){
            close_acc(i+ACCNUM);
        }
    }

}








