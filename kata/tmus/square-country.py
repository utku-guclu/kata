import math

def min_squares(N):
    count = 0
    while N > 0:
        # Find the largest square less than or equal to N
        largest_square = int(math.sqrt(N)) ** 2
        N -= largest_square  # Subtract that square from N
        count += 1  # We used one square
    return count

# Read input
N = int(input())

# Output the result
print(min_squares(N))

