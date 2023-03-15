import java.util.*;

public class PrimeFactor {

    public static boolean isPrime(long n) {

        if(n == 2){
            return true;
        }else if(n%2 == 0) {
            return false;
        }

        for(long i = 3; i <= Math.sqrt(n); i+=2) {

            if(n%i==0) {
                return false;
            }

        }
        return true;

    }

    public static void printPrimeFactors(long n, long j) {
        if(n<0) {
            System.out.println("-1");
            n*=-1;
        }
        if(isPrime(n)){
            System.out.println(n);
            return;
        }
        for(long i = j; i<=n; i++) {
            if(n%i==0 && isPrime(i)) {

                System.out.println(i);
                printPrimeFactors(n/i, i);
                return;

            }
        }

    }
    
    public static void main(String[] args) {

        Scanner scn = new Scanner(System.in);
        long n;
        while(true){
            System.out.println("\nEnter an integer:");
            try{
                String input = scn.nextLine();
                n = Long.parseLong(input);
                break;
            }catch(Exception e){
                System.out.println("Sorry, value could not be read. Please try again.");
            }
        }
        System.out.println("\nThe prime factors of " + n + " are:\n");
        printPrimeFactors(n, 2);
        scn.close();

        System.out.println("\nFun fact: the biggest prime this program can store is 9 223 372 036 854 775 783");

    }

}
