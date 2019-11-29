#include <stdio.h>
#define ACCNUM 901
#define ROW 2
#define COLUMN 50
extern float account_array[ROW][COLUMN];
int open_acc() ;
void deposit_to_acc(float , int, int);
double check_balance(int );
int is_acc_open(int );
void close_acc(int );
void add_interest(double);
void print_all_acc();
void close_all_acc();

