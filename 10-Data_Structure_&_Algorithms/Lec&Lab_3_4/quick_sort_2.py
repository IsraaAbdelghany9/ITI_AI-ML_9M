def partition(array, start_index, end_index):

    Pivot = array[start_index]
    low = start_index + 1
    high = end_index

    while(low <= high):
        while(array[low] < Pivot):
            low += 1

        while(array[high] > Pivot):
            high -= 1

        if(high > low): 
            array[low], array[high] = array[high], array[low]


        array[start_index], array[high] = array[high], array[start_index]
    
    return high  # Return final pivot position

def quick_sort(array, start_index, end_index):
    if start_index < end_index:
        pivot_index = partition(array, start_index, end_index)
        quick_sort(array, start_index, pivot_index - 1)  # Sort left part
        quick_sort(array, pivot_index + 1, end_index)  # Sort right part


# Example usage
arr = [8, 4, 7, 3, 9, 2, 6, 5, 1]
print(arr)
quick_sort(arr, 0, len(arr) - 1)
print("Sorted array:", arr)