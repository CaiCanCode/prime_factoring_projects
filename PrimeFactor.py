import math

def isPrime(n: int) -> bool:
    for i in range(2, int(math.sqrt(n))+1):
        if (n%i == 0):
            return False
    return True

def printPrimeFactors (start: int, n: int):
    if n < 0:
        print(-1)
        n *= -1
    if isPrime(n):
        print(n)
        return 
    for i in range(start, n + 1):
        if n % i == 0 and isPrime(i):
            print(i)
            printPrimeFactors(int(i), int(n/i))
            return

n = int(input("Enter an integer: "))

print("The prime factors of ", n, " are:")
printPrimeFactors(2, n)
