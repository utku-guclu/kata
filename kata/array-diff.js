function arrayDiff(a, b) {
  let filt = [];
  for (let k of a) {
    if (!b.includes(k)) {
      filt.push(k);
    }
  }
  return filt;
}

console.log(arrayDiff([1, 2, 3], [1, 2]));
