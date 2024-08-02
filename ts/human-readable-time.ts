export function humanReadable(seconds: number): string {
  // TODO
  //
  // Write a function, which takes a non-negative integer (seconds) as input and returns the time in a human-readable format (HH:MM:SS)

  //     HH = hours, padded to 2 digits, range: 00 - 99
  //     MM = minutes, padded to 2 digits, range: 00 - 59
  //     SS = seconds, padded to 2 digits, range: 00 - 59
  //
  // The maximum time never exceeds 359999 (99:59:59)
  const hours = Math.floor(seconds / 3600);
  const minutes = Math.floor(seconds / 60) % 60;
  seconds %= 60;

  return `${String(hours).padStart(2, "0")}:${String(minutes).padStart(
    2,
    "0",
  )}:${String(seconds).padStart(2, "0")}`;
}
