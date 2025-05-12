print("Week 3 - Experiment 14")
print("Amit Singhal | 11614802722")

def longest_increasing_subsequence(lst):
    if not lst:
        return []

    n = len(lst)
    dp = [1] * n  # Length of LIS ending at each index
    prev = [-1] * n  # To reconstruct the sequence

    max_length = 1
    max_index = 0

    for i in range(1, n):
        for j in range(i):
            if lst[i] > lst[j] and dp[i] < dp[j] + 1:
                dp[i] = dp[j] + 1
                prev[i] = j
        if dp[i] > max_length:
            max_length = dp[i]
            max_index = i

    # Reconstructing the LIS
    lis = []
    while max_index != -1:
        lis.append(lst[max_index])
        max_index = prev[max_index]

    return lis[::-1]

# Taking list input from the user
numbers = list(map(int, input("Enter a list of numbers separated by spaces: ").split()))

# Finding the longest increasing subsequence
lis = longest_increasing_subsequence(numbers)

# Displaying the result
print(f"The longest increasing subsequence is: {lis}")
