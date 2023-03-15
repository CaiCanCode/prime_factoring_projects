/* factor.c

   Prime factors a number

   M. Williams - 2022-09-15
*/

#include <stdio.h>
#include <math.h>
#include <string.h>
#include <limits.h>

int is_prime(long long n){
    if (n == 2){
        return 1;
    }
    if (n % 2 == 0){
        return 0;
    }
    for(long long i = 3; i <= pow(n, 0.5); i += 2){
        if(n % i == 0){
            return 0;
        }
    }
    return 1;
}

void prime_factor (long long start, long long end){
    if(end < 0){
        printf("-1\n");
        end *= -1;
    }
    if (is_prime(end)){
        printf("%lld\n", end);
        return;
    }
    for (long long i = start; i <= end; i++){
        if(is_prime(i) && end % i == 0){
            printf("%lld\n", i);
            prime_factor(i, end/i);
            return;
        }
    }
}

int str_ll(char* str, int n, long long* dest){
    //printf("begin str -> ll\n"); //for debugging
    //printf("%s", str); //for debugging
    *dest = 0;
    int i = 0;
    int negative = 1;
    if(*str == '-'){
        //printf("str is negative\n"); //for debugging
        negative = -1;
        i++;
    }else if (n == 20){
        return -1;
    }
    while(i < n){
        char ch = str[i];
        //printf("%c\n", ch); //for debugging
        if(ch < '0' || ch > '9'){
            return -1;
        }
        long long decimal = (ch - '0');
        for(int j = 1; j < n-i; j++){
            decimal *= 10;
        }
        *dest += decimal;
        //printf("%lld\n", *dest); //for debugging
        i++;
    }
    if(*dest == LLONG_MIN && negative == -1){ //wrapped on purpose
        return 1;
    }
    if(*dest < 0){ //wrapped by accident
        return -1;
    }
    *dest *= negative;
    return 1;
}

int main(){
    
    long long i;
    int is_valid;
    do{
        printf("Enter an integer:\n");
        char buffer[25];
        fgets(buffer, 24, stdin); 
        if(strlen(buffer) > 21){ //remember to include space for '-' and '\n'
            is_valid = -1;
        }else{
            is_valid = str_ll(buffer, strlen(buffer) - 1, &i);
        }
        if(is_valid <= 0){
            printf("Sorry, couldn't read that number. Please try again.\n");
        }
    } while (is_valid <= 0);
    
    printf("The prime factors of %lld are:\n", i);
    
    prime_factor(2, i);

    printf("\nFun fact: the biggest prime this program can store is 9 223 372 036 854 775 783\n");
    
    return 0;
}

// Remember to include -lm to compile (so pow(b, p) works)
