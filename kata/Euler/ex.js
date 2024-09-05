function compress(str) {
  // aabcc
  let prev = 0;
  let counter = 1;
  let compressed = "";

  if (str.length <= 1) return str;

  for (let i = 1; i <= str.length; i++) {
    if (str[i] === str[prev]) {
      counter++;
    } else {
      compressed += counter + str[prev];
      prev = i;
      counter = 1;
    }
  }
  return compressed;
}

module.exports = compress;
