class PandigitalProducts {
  constructor() {
    this.uniqueProducts = new Set();
    this.pandigitalMasks = new Array(10);

    // Pre-compute pandigital masks
    for (let n = 1; n <= 9; ++n) {
      this.pandigitalMasks[n] = (1 << (n + 1)) - 2;
    }
  }

  isPandigital(num, n) {
    let mask = 0;
    while (num > 0) {
      const digit = num % 10;
      if (digit === 0 || digit > n || (mask & (1 << digit)) !== 0) return false;
      mask |= 1 << digit;
      num = Math.floor(num / 10);
    }
    return mask === this.pandigitalMasks[n];
  }

  solve(n) {
    if (n < 2 || n > 9) {
      throw new Error("n must be between 2 and 9 inclusive");
    }

    this.uniqueProducts.clear(); // Clear any previous results

    const maxProduct = 10 ** n - 1;
    const maxMultiplicand = Math.floor(Math.sqrt(maxProduct));

    for (let i = 2; i <= maxMultiplicand; i++) {
      for (let j = i; j <= Math.floor(maxProduct / i); j++) {
        const product = i * j;
        if (product > maxProduct) break;

        const combined = `${i}${j}${product}`;
        if (combined.length !== n) continue;

        if (this.isPandigital(parseInt(combined, 10), n)) {
          this.uniqueProducts.add(product);
        }
      }
    }

    return Array.from(this.uniqueProducts).reduce((a, b) => a + b, 0);
  }
}

// Usage
const solver = new PandigitalProducts();

for (let n = 2; n <= 9; n++) {
  console.time(`Execution Time for n=${n}`);
  const result = solver.solve(n);
  console.timeEnd(`Execution Time for n=${n}`);
  console.log(`The sum of all ${n}-digit pandigital products is: ${result}`);
}
