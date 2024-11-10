def prefix_max_index(A, i):
    # Base case: If i is less than 0, return -1 (indicating no valid index)
    if i < 0:
        return -1

    # Recursive case: Get the index of the max for the previous index
    max_index = prefix_max_index(A, i - 1)

    # Determine the current maximum index
    if max_index == -1:  # If there are no previous elements
        return i  # Current index is the maximum
    else:
        # Compare current element with the element at max_index
        return max_index if A[max_index] >= A[i] else i

# Example usage
if __name__ == "__main__":
    A = [3, 1, 4, 1, 5, 9, 2, 6]
    result_index = prefix_max_index(A, len(A) - 1)
    print("Index of Maximum in Prefix:", result_index)
    print("Maximum Value in Prefix:", A[result_index] if result_index != -1 else None)

