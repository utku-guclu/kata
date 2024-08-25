function reciprocalCycles(n: number): number {
  // Helper function to get the length of the recurring cycle for a given denominator
  function getCycleLength(d: number): number {
    // Map to store remainders and their positions
    const remainders = new Map<number, number>();
    let value = 1; // Start with 1 as the initial value (numerator)
    let position = 0; // Keep track of the current position in the division process

    // Continue until we find a repeating remainder or get a zero remainder
    while (!remainders.has(value) && value !== 0) {
      remainders.set(value, position); // Store the current remainder and its position
      value *= 10; // Multiply by 10 (equivalent to adding a decimal zero)
      value %= d; // Take the remainder when divided by d
      position++; // Move to the next position
    }

    if (value === 0) {
      return 0; // If remainder is 0, there's no recurring cycle
    } else {
      // The cycle length is the difference between the current position
      // and the position where we first saw this remainder
      return position - (remainders.get(value) || 0);
    }
  }

  let maxCycleLength = 0; // Store the maximum cycle length found
  let result = 0; // Store the denominator with the longest cycle

  // Check all denominators from 2 to n-1
  for (let d = 2; d < n; d++) {
    const cycleLength = getCycleLength(d); // Get cycle length for current denominator
    if (cycleLength > maxCycleLength) {
      // If this is the longest cycle so far
      maxCycleLength = cycleLength; // Update the max cycle length
      result = d; // Update the result to this denominator
    }
  }

  return result; // Return the denominator with the longest recurring cycle
}

// Call the function with 1000 and log the result
console.log(reciprocalCycles(1000));
