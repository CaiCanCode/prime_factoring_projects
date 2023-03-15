using System;

namespace PrimeFactor{

    public class Program{

        static bool isPrime(long n){
            if (n == 2){
                return true;
            }
            if(n % 2 == 0){
                return false;
            }
            for(long i = 3; i <= Math.Sqrt(n); i += 2){
                if(n%i == 0){
                    return false;
                }
            }
            return true;
        }

        static void printPrimes(long start, long end){
            if(end < 0){
                Console.WriteLine("-1");
                end *= -1;
            }
            if(isPrime(end)){
                Console.WriteLine(end);
                return;
            }
            for(long i = start; i <= end; i++){
                if(isPrime(i) && end % i == 0){
                    Console.WriteLine(i);
                    printPrimes(i, end/i);
                    return;
                }
            }
        }

        static void Main(string[] args){
            long n;
            while(true){
                try{
                    Console.WriteLine("Enter an integer:");
                    n = Convert.ToInt64(Console.ReadLine());
                    break;
                }
                catch (System.Exception){
                    Console.WriteLine("Sorry, value could not be read. Please try again.");
                }
            }
            Console.WriteLine("The prime factors of " + Convert.ToString(n) + " are:");
            printPrimes(2, n);
            Console.WriteLine("\nFun fact: the biggest prime this program can store is 9 223 372 036 854 775 783");
        }

    }

}