const nums = [6, 8, 19, 48, 9, 90];

for (let i = 0; i < nums.length; i++) {
  for (let j = i + 1; j < nums.length - 1; j++) {
    if (nums[j] < nums[i]) {
      console.log("swap");
      [nums[j], nums[i]] = [nums[i], nums[j]];
    }
  }
}

console.log(nums);
