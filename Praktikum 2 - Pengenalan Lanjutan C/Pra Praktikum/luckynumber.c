#include <stdio.h>

int powC(int base, int powC) {
    int num = 1;
    while (powC > 0) {
        num *= base;
        powC--;
    }
    return num;
}

int get_digit(int num, int pos){
    num/=powC(10,pos);
    return num%10;
}

int swap_digit(int num, int from, int to){
    int temp;
    temp = get_digit(num,to);
    num -= get_digit(num,to)*powC(10,to);
    num += get_digit(num,from)*powC(10,to);
    num -= get_digit(num,from)*powC(10,from);
    num += temp*powC(10,from);
    return num;
}

int sort_descending(int num){
    int pos;
    for (int i=0;i<4;i++){
        int max=0;
        for (int j=0;j<(4-i);j++){
            if (get_digit(num,j)>=max){
                max = get_digit(num,j);
                pos = j;
            }
        }
        num = swap_digit(num, pos, (3-i));
    }
    return num;
}

int main() {
    int ascending, descending, num, n=0;
    scanf("%d", &num);
    while ((num!=6174) && (n!=-1)){
        n++;
        descending = sort_descending(num);
        ascending = swap_digit((swap_digit(descending,0,3)),1,2);
        num = descending - ascending;
        if (num == 0) n = -1;
    }
    printf("%d\n",n);
}
