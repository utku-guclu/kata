function divisibleTriangleNumber(n) {
  let start = 1;
  const triCache = {};
  const divSumCache = {};

  while (true) {
    let triangle = tri(start, triCache);
    let divTri = divSum(triangle, divSumCache);
    if (divTri >= n) {
      return triangle;
    }
    start++;
  }
}

const divSum = (n, cache) => {
  if (cache[n]) return cache[n];

  let sum = 0;
  for (let i = 1; i <= Math.floor(Math.sqrt(n)); i++) {
    if (n % i === 0) {
      sum += 2;
    }
  }
  cache[n] = sum;
  return sum;
};

// const tri = (n, cache) => {
//   if (cache[n]) return cache[n];

//   let sum = 0;
//   for (let i = 1; i <= n; i++) {
//     sum += i;
//   }
//   cache[n] = sum;
//   return sum;
// }

const tri = (n) => {
  return (n * (n + 1)) / 2;
};

const res = divisibleTriangleNumber(5);
console.log(res);
