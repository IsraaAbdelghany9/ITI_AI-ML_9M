def quick_sort(arr):

    length = len(arr)
    if length <= 1 :
        return arr
    
    else:
        pivot = arr.pop()


    items_greater = []
    items_lower = []

    for item in arr :
        if item > pivot :
            items_greater.append(item)

        else :
            items_lower.append(item)

    return quick_sort(items_lower) + [pivot] + quick_sort(items_greater)


array = [1,4,6,8,2,8,22,0]

print("sorted array is ", quick_sort(array))