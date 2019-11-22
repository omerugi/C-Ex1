#include <stdio.h>
#include <string.h>

#define ACCNUM 901
static double account_array[2][50];

int open_acc(){

    for (int i = 0; i < 50; ++i) {
        if(account_array[0][i]== 0){
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
    account_array[1][acc] += dep;
    printf("\n The balance in account number %d is: %.2lf \n",acc+ACCNUM, account_array[1][acc]);
}

void check_balance(int acc){
    int acc_index = acc-ACCNUM;
    if(account_array[0][acc_index] == 0){
        printf("\n This account is closed.");
    }
    else{
        printf("%.2lf", account_array[1][acc_index]);
    }

}






