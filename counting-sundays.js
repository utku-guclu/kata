function isLeapYear(year) {
  return (year % 4 === 0 && year % 100 !== 0) || year % 400 === 0;
}

function countingSundays(firstYear, lastYear) {
  let dayOfWeek = 2; // 1 Jan 1901 is a Tuesday (1=Monday, 2=Tuesday, ..., 0=Sunday)
  let sundayCount = 0;
  let daysInMonth = 0;

  for (let y = firstYear; y <= lastYear; y++) {
    for (let m = 1; m <= 12; m++) {
      //console.log(dayOfWeek)
      if (dayOfWeek === 0)
        // Check if it's Sunday
        sundayCount += 1;

      // Days in the current month
      if (m === 2) {
        // February
        daysInMonth = isLeapYear(y) ? 29 : 28;
      } else if ([4, 6, 9, 11].includes(m)) {
        // April, June, September, November
        daysInMonth = 30;
      } else {
        // January, March, May, July, August, October, December
        daysInMonth = 31;
      }
      /** Update the day of the week for the first day of the next month
      dayOfWeek is incremented by the number of days in the current month
      The result is taken modulo 7 to wrap around the week (0=Monday, ...,   6=Sunday) */
      dayOfWeek = (dayOfWeek + daysInMonth) % 7;
    }
  }
  return sundayCount;
}

const res = countingSundays(1995, 2000);
console.log(res);
