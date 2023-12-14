#Write a python program to store first year percentage of students in array. Write function for sorting array of floating point numbers in ascending order using 
#a) Selection Sort 
#b) Bubble sort and display top five scores



# a) Selection Sort
def selection_sort(arr):
    n = len(arr)

    for i in range(n):
        min_index = i

        for j in range(i+1, n):
            if arr[j] < arr[min_index]:
                min_index = j

        arr[i], arr[min_index] = arr[min_index], arr[i]

    return arr

# b) Bubble sort
def bubble_sort(arr):
    n = len(arr)

    for i in range(n):
        swapped = False

        for j in range(0, n-i-1):
            if arr[j] > arr[j+1]:
                arr[j], arr[j+1] = arr[j+1], arr[j]
                swapped = True

        if swapped == False:
            break

    return arr

def main():
    students = [78.5, 89.0, 75.0, 91.0, 73.0, 67.0, 92.0, 78.0, 83.0, 80.0]

    print("Unsorted array: ", students)

    sorted_arr = selection_sort(students)
    print("Sorted array: ", sorted_arr)

    bubble_sorted_arr = bubble_sort(students)
    print("Bubble sorted array: ", bubble_sorted_arr)

    # Display top five scores
    top_five = sorted_arr[-5:]
    print("Top five scores: ", top_five)

if __name__ == "__main__":
    main()
