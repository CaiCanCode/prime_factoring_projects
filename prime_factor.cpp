/*

    prime_factor.cpp
    
    Prints out the prime factors of a number entered by the user (definitely isn't *just* copied over C code)
    
    Michaiah J. Williams - 2023-09-12

*/

#include <iostream>
#include <string>
#include <cmath>

int is_prime(long long n){
    if (n == 2){
        return 1;
    }
    if (n % 2 == 0){
        return 0;
    }
    for(long long i = 3; i <= sqrt(n); i += 2){
        if(n % i == 0){
            return 0;
        }
    }
    return 1;
}

void prime_factor (long long start, long long end){
    if(end < 0){
        std::cout << "-1" << std::endl;
        end *= -1;
    }
    if (is_prime(end)){
        std::cout << end << std::endl;
        return;
    }
    for (long long i = start; i <= end; i++){
        if(is_prime(i) && end % i == 0){
            std::cout << i << std::endl;
            prime_factor(i, end/i);
            return;
        }
    }
}

int main() {
    while(1){
        std::string str{};
        long long n{};
    
        while(1){
            try{
                std::cout << "Enter an integer: ";
                std::getline(std::cin, str);
                for(unsigned int i = 1; i < str.length(); i++){ //make sure all characters (except the first) are digits
                    if (str.at(i) < '0' || str.at(i) > '9'){
                        throw std::invalid_argument {"that's not an int, idiot."};
                    }
                }
                n = std::stoll(str); //should check for everything else
                break;
            } catch (std::invalid_argument& e) {
                std::cout << "Sorry, invalid input, please try again" << std::endl;
            } catch (std::out_of_range& e) {
                std::cout << "Sorry, that number is out of range" << std::endl;
            }
        }
    
        std::cout << "The prime factors of " << n << " are:" << std::endl;
        
        prime_factor(2, n);
        
        std::cout << "Enter x to exit; enter anything else to re-run the program: ";
        std::getline(std::cin, str);
            
        if(!str.find('x')){ //if x is the first character in str
            break;
        }
        
    }

    return 0;

}

//compile with g++ -Wall -std=c++20 -o prime_factor prime_factor.cpp
