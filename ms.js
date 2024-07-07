const arr = [2, 3, 5, 22, 1, 7, 76, 24]; // 1 2 3 5 7 22 24 76

function mergeSort(arr) {
  // base
  if (arr.length === 1) return arr;

  // pre
  let mid = Math.floor(arr.length / 2);

  // rec
  let left = mergeSort(arr.slice(0, mid));
  let right = mergeSort(arr.slice(mid));

  // post
  return merge(left, right);
}

function merge(left, right) {
  let result = [];
  let leftIdx = 0;
  let rightIdx = 0;

  while (left.length > leftIdx && right.length > rightIdx) {
    if (left[leftIdx] <= right[rightIdx]) {
      result.push(left[leftIdx]);
      leftIdx++;
    } else {
      result.push(right[rightIdx]);
      rightIdx++;
    }
  }
  return result.concat(left.slice(leftIdx)).concat(right.slice(rightIdx));
}

const res = mergeSort(arr);
console.log(res);
