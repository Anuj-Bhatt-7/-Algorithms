def insertionSort(number_list):
    for i in range(1,len(number_list)):
        temp = number_list[i]

        while number_list[i-1] > temp and i>0:
            number_list[i],number_list[i-1] = number_list[i-1],number_list[i]
            i = i-1
        print(number_list)

number_list = []
list_length = int(input("Enter the number of element in List: "))
for i in range(0,list_length):
    element = int(input(f"Enter the {i} element: "))
    number_list.append(element)

print("The Insertion sort List is: ",end=" ")
insertionSort(number_list)