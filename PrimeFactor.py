import math

def isPrime(n: int) -> bool:
    for i in range(2, int(math.sqrt(n))+1):
        if (n%i == 0):
            return False
    return True

def printPrimeFactors (start: int, end: int):
    if end < 0:
        print(-1)
        end *= -1
    if isPrime(end):
        print(end)
        return
    for i in (start, end + 1):
        if end % i == 0 and isPrime(i):
            print(i)
            printPrimeFactors(i, end/i)
            return

s = input("Enter an integer: ")
n = int(s)
print("The prime factors of " + s + " are:")
printPrimeFactors(2, n)