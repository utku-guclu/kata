def merge_sort(A, a=0, b=None):
    # If b is None, set it to the length of the array
    if b is None:
        b = len(A)

    # Base case: If the subarray has 0 or 1 elements, return
    if b - a <= 1:
        return

    # Recursive case: Split the array into two halves
    mid = (a + b) // 2 # mid point
    # Recursive Calls: The function calls itself recursively for the left and right halves of the array.
    merge_sort(A, a, mid)
    merge_sort(A, mid, b)

    # Merge the sorted subarrays
    merge(A, a, mid, b)

def merge(A, a, mid, b):
    # Create a temporary array to store the merged elements
    temp = A[a:b].copy()

    i, j = 0, mid - a
    for k in range(a, b):
        if i >= mid - a:
            A[k] = temp[j]
            j += 1
        elif j >= b - a:
            A[k] = temp[i]
            i += 1
        elif temp[i] < temp[j]:
            A[k] = temp[i]
            i += 1
        else:
            A[k] = temp[j]
            j += 1

# Example usage
if __name__ == "__main__":
    A = [3, 1, 4, 1, 5, 9, 2, 6]
    print("Original array:", A)

    merge_sort(A)

    print("Sorted array:", A)

