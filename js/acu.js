const digitalRoot = (number) => {
  // your code here
  // reduce
};

const accu = (number) => {
  return Array.from(String(number)).reduce((acc, dig) => acc + Number(dig), 0);
};

console.log(accu([123]));
