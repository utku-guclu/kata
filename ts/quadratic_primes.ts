/*
 * Euler discovered the remarkable quadratic formula:
   n2+an+b, where |a|<range and |b|≤range
   where |n| is the modulus/absolute value of n
   e.g. |11|=11 and |−4|=4
   Function to check if a number is prime 
*/
function isPrime(num: number): boolean {
  if (num <= 1) return false; // Numbers less than or equal to 1 are not prime
  for (let i = 2; i <= Math.sqrt(num); i++) {
    // Check divisibility up to square root of num
    if (num % i === 0) return false; // If divisible, it's not prime
  }
  return true; // If we haven't found any divisors, it's prime
}

// Function to count consecutive primes produced by the quadratic formula
function consecutivePrimes(a: number, b: number): number {
  let n = 0; // Start with n = 0
  while (isPrime(Math.abs(n * n + a * n + b))) {
    // Check if the result is prime
    n++; // If prime, increment n and continue
  }
  return n; // Return the count of consecutive primes
}

// Main function to find the product of coefficients
function quadraticPrimes(range: number): number {
  let maxPrimes = 0; // Keep track of the maximum number of primes found
  let productAB = 0; // Keep track of the product of a and b for the best result

  // Loop through possible values of a
  for (let a = -range + 1; a < range; a++) {
    // Loop through possible values of b
    for (let b = -range; b <= range; b++) {
      let primes = consecutivePrimes(a, b); // Count primes for this a and b
      if (primes > maxPrimes) {
        // If we found a new maximum
        maxPrimes = primes; // Update the maximum count
        productAB = a * b; // Update the product of a and b
      }
    }
  }

  return productAB; // Return the product of a and b for the best result
}

// Call the function with range 1000 and log the result
console.log(quadraticPrimes(1000)); // -59231
