# Implementation of Fractional Knapsack Problem

def fractional_knapsack(capacity, weights, values):
    n = len(weights)

    ratio = [values[i] / weights[i] for i in range(n)]


    items = list(zip(ratio, weights, values))
    items.sort(reverse=True, key=lambda x: x[0])
    ratio, weights, values = zip(*items)

    max_value = 0

    for i in range(n):
        if weights[i] <= capacity:
            max_value += values[i]
            capacity -= weights[i]
        else:
            max_value += values[i] * (capacity / weights[i])
            break


    return max_value




weights = [10, 20, 30]
values = [60, 100, 120]


print(fractional_knapsack(20, weights, values))  

print(fractional_knapsack(50, weights, values))
