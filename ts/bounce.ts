export function bouncingBall(
  h: number,
  bounce: number,
  window: number,
): number {
  // conditions check
  if (h <= 0 || bounce <= 0 || bounce >= 1 || window >= h) return -1;

  let count = 0;
  let currentHeight = h;

  while (currentHeight > window) {
    count++; // Count the ball passing the window on the way down
    currentHeight *= bounce; // Simulate the ball bouncing
    if (currentHeight > window) {
      count++; // Count the ball passing the window on the way up
    }
  }

  return count;
}
