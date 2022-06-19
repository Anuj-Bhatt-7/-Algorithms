def merge(num_list, low, mid, high):
    list1 = mid - low + 1
    list2 = high - mid

    L = [0] *list1
    M = [0] * list2

    for i in range(0, list1):
        L[i] = num_list[low + i]
    for j in range(0, list2):
        M[j] = num_list[mid + 1 + j]

    
    i = 0
    j = 0
    k = low


    while i < list1 and j < list2:
        if L[i] <= M[j]:
            num_list[k] = L[i]
            i += 1
        else:
            num_list[k] = M[j]
            j += 1
        k += 1

    while i < list1:
        num_list[k] = L[i]
        i += 1
        k += 1

    while j < list2:
        num_list[k] = M[j]
        j += 1
        k += 1


def mergeSort(num_list, low, high):
    if low < high:
        mid = low + (high - low) // 2

        mergeSort(num_list, low , mid)
        mergeSort(num_list, mid + 1, high)
        merge(num_list, low, mid, high)


def display(num_list, size):
    for i in range(0, size):
        print(num_list[i], end=" ")


num_list = []
list_length = int(input("Enter the number of element in List"))
start = 0
end = list_length - 1
for i in range(0, list_length):
    ele = int(input(f"Enter the {i} element: "))
    num_list.append(ele)

mergeSort(num_list, start, end)
print(f"The Merge Sort is: ")
display(num_list,list_length)
