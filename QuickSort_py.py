def partition(num_list, low, high):
    lower_bound = (low - 1)
    piv = num_list[high]

    for j in range(low, high):
        if num_list[j] <= piv:
            lower_bound = lower_bound + 1
            num_list[lower_bound], num_list[j] = num_list[j], num_list[lower_bound]

    num_list[lower_bound + 1], num_list[high] = num_list[high], num_list[lower_bound + 1]
    return lower_bound + 1


def quickSort(num_list, low, high):
    if low < high:
        pi = partition(num_list, low, high)
        quickSort(num_list, low, pi - 1)
        quickSort(num_list, pi + 1, high)


num_list = []
list_len = int(input("Enter the number of element in list: "))
for i in range(0,list_len):
    item = int(input(f"Enter the {i} element: "))
    num_list.append(item)

quickSort(num_list,0,list_len-1)
print("\nSorted array using QuickSort: ",end=" ")
for i in range(list_len):
    print(num_list[i],end=" ")
