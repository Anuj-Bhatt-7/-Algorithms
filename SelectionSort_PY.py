def SelectionSort(num_list, list_len):
    for i in range(0, list_len - 1):
        min_index = i
        for j in range(i + 1,list_len):
            if num_list[min_index] > num_list[j]:
                min_index = j

        num_list[min_index], num_list[i] = num_list[i], num_list[min_index]
    return num_list


num_list = []
list_len = int(input("Enter the number of element in List: "))
for i in range(0,list_len):
    item = int(input(f"Enter the {i} element: "))
    num_list.append(item)

print(f"The Selection Sort is: {SelectionSort(num_list,list_len)}")
