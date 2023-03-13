/* factor.c

   Prime factors a number

   M. Williams - 2022-09-15
*/

#include <stdio.h>
#include <math.h>

long long MAX_VALUE = 9223372036854775807;

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

int main(){
    
    long long i;
    int is_valid;
    do{
        printf("Enter an integer:\n");
        //should probably be read as a string to avoid accidental wrapping but I'm too lazy
        is_valid = scanf("%lld", &i); 
        if(is_valid <= 0){
            printf("Sorry, couldn't read that number. Please try again.\n");
        }
    } while (is_valid <= 0);
    
    printf("The prime factors of %lld are:\n", i);
    
    prime_factor(2, i);
    
    return 0;
}

// Remember to include -lm to compile (so pow(b, p) works)