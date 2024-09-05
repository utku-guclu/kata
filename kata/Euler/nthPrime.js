function time(cb) {
  let startTime = new Date();
  cb();
  let endTime = new Date();
  console.log("end");
  return endTime - startTime;
}

function isPrime(x) {
  for (let i = 2; i <= Math.floor(Math.sqrt(x)); i++) {
    if (x % i === 0) return false;
  }
  return true;
}

function nthPrime(n) {
  let primes = [];
  let num = 2;

  while (true) {
    if (isPrime(num)) {
      primes.push(num);
    }

    num++;

    if (primes.length === n) {
      return primes.pop();
    }
  }
}

const fn = () => nthPrime(1001);
console.log(`Time taken: ${time(fn)} ms`);
console.log(`10001st prime: ${fn()}`);
