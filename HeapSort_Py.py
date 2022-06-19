def heapify(arr, length, i):
    largest = i
    left = 2 * i + 1
    right = 2 * i + 2

    if left < length and arr[i] < arr[left]:
        largest =left

    if right < length and arr[largest] < arr[right]:
        largest = right

    if largest != i:
        arr[i], arr[largest] = arr[largest], arr[i]
        heapify(arr, length, largest)


def heapSort(arr,length):
    for i in range(length // 2, -1, -1):
        heapify(arr, length, i)

    for i in range(length - 1, 0, -1):
        arr[i], arr[0] = arr[0], arr[i]
        heapify(arr, i, 0)


number_list = []
length = int(input("Enter the number of element in List: "))
for i in range(0,length):
    element = int(input(f"Enter the {i} element: "))
    number_list.append(element)
heapSort(number_list,length)
print("\nSorted Array: ")
for i in range(length):
    print(number_list[i], end=" ")
