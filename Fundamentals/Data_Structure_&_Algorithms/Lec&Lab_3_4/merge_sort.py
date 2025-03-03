def merge(left_arr ,right_arr):

    sorted_array = []  # To store merged sorted elements
    i = j = 0  # Pointers for left and right arrays

    # Merge two sorted arrays
    while i < len(left_arr) and j < len(right_arr):
        if left_arr[i] < right_arr[j]:
            sorted_array.append(left_arr[i])
            i += 1
        else:
            sorted_array.append(right_arr[j])
            j += 1

    # Add remaining elements
    sorted_array.extend(left_arr[i:])
    sorted_array.extend(right_arr[j:])

    return sorted_array  # Return the merged sorted array

def merge_sort(array_):

    # if the array has no elements or one elemnt no need to sort
    if (len(array_)<= 1):
        return array_
    
    left_array = array_[:len(array_)//2]
    right_array = array_[len(array_)//2:]

    print(f"left_array: {left_array}" )
    print(f"right_array: {right_array}" )
    print("------------------------------------------")
    # recursion part 
    left_sorted = merge_sort(left_array)
    right_sorted = merge_sort(right_array)

    # Corrected print statement
    print(f"left_sorted: {left_sorted}")
    print(f"right_sorted: {right_sorted}")
    print("------------------------------------------")

    return(merge(left_sorted, right_sorted ))






def main():
    array = [4, 5, 7, 9, 1, 2, 6, 3, 8]
    sorted_array = merge_sort(array)
    print("Sorted Array:", sorted_array)

if __name__ == "__main__":
    main()