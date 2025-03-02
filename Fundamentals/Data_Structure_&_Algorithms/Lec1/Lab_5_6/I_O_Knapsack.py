def knapsack(capacity, weights, values):
    """
    This function takes the capacity of the knapsack, weights of items, and their values and returns the maximum value that can be obtained.

    Parameters:
    capacity: maximum weight the knapsack can hold
    weights: list of weights of items
    values: list of values of items

    Output:
    Maximum value that can be obtained
    """
    n = len(weights)

    dp = [[0 for _ in range(capacity + 1)] for _ in range(n + 1)] # initialize the DP table

    # Fill the DP table
    for i in range(1, n + 1):
        for w in range(1, capacity + 1):
            if weights[i - 1] <= w:
                dp[i][w] = max(dp[i - 1][w], values[i - 1] + dp[i - 1][w - weights[i - 1]]) # calculate the maximum value
            else:
                dp[i][w] = dp[i - 1][w] # Copy the value from the previous row

    print_dp_table(dp, capacity, n)

    return dp[n][capacity]

def print_dp_table(dp, capacity, n):
    """
    This function prints the DP table.

    Parameters:
    dp: the DP table
    capacity: maximum weight the knapsack can hold
    n: number of items

    Output:
    None It will just print the DP table
    """
    # Print DP Table 
    print("     ", end=" ")
    for w in range(capacity + 1):
        print(f"{w:3}", end=" ")
    print("\n" + "------" + "----" * (capacity + 1))

    for i in range(n + 1):
        print(f"{i:3} |", end=" ")
        for w in range(capacity + 1):
            print(f"{dp[i][w]:3}", end=" ")
        print('\n')   



weights = [2, 4, 5]
values = [60, 100, 120]
capacity = 5

print("Max Value:", knapsack(capacity, weights, values))
