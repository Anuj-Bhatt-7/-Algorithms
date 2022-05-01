def binarySearch(arr, lower_bound, upper_bound, data):
    if upper_bound >= lower_bound:

        mid = (lower_bound + upper_bound) // 2

        if arr[mid] == data:
            return mid + 1


        elif arr[mid] >= data:
            upper_bound = mid - 1
            return binarySearch(arr, lower_bound, upper_bound, data)


        else:
            lower_bound = mid + 1
            return binarySearch(arr, lower_bound, upper_bound, data)

    else:
        # Element is not present in the array
        return -1


arr = [2, 3, 4, 10, 40]
data = int(input("Enter data to search "))
lower_bound = 0;
upper_bound = len(arr) - 1;

result = binarySearch(arr, lower_bound, upper_bound, data)

if result != -1:
    print("Element is present at location % d" % result)
else:
    print("Element is not present in array")
