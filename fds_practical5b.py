#b) Write a python program to store roll numbers of student array who attended
#training program in sorted order. Write function for searching whether particular
#student attended training program or not, using Binary search and Fibonacci
#search



# A function to perform binary search on a sorted array
def binary_search(arr, key):
  # Initialize the left and right pointers
  left = 0
  right = len(arr) - 1
  # Loop until the left pointer is less than or equal to the right pointer
  while left <= right:
    # Find the middle index
    mid = (left + right) // 2
    # Compare the key with the middle element
    if key == arr[mid]:
      # Return the index if found
      return mid
    elif key < arr[mid]:
      # Narrow the search to the left half
      right = mid - 1
    else:
      # Narrow the search to the right half
      left = mid + 1
  # Return -1 if not found
  return -1

# A function to perform fibonacci search on a sorted array
def fibonacci_search(arr, key):
  # Initialize the fibonacci numbers
  f1 = 0 # (n-2)th fibonacci number
  f2 = 1 # (n-1)th fibonacci number
  f3 = f1 + f2 # nth fibonacci number
  # Find the smallest fibonacci number greater than or equal to the array length
  while f3 < len(arr):
    f1 = f2
    f2 = f3
    f3 = f1 + f2
  # Initialize the offset
  offset = -1
  # Loop until the key is found or the array is exhausted
  while f3 > 1:
    # Find the index to compare with the key
    i = min(offset + f1, len(arr) - 1)
    # Compare the key with the element at index i
    if key == arr[i]:
      # Return the index if found
      return i
    elif key < arr[i]:
      # Narrow the search to the left subarray
      f3 = f1
      f2 = f2 - f1
      f1 = f3 - f2
    else:
      # Narrow the search to the right subarray
      f3 = f2
      f2 = f1
      f1 = f3 - f2
      offset = i
  # Check if the last element is the key
  if f2 and arr[offset + 1] == key:
    return offset + 1
  # Return -1 if not found
  return -1

# A function to sort an array using insertion sort
def insertion_sort(arr):
  # Loop through the array from the second element
  for i in range(1, len(arr)):
    # Store the current element as the key
    key = arr[i]
    # Move the elements of the left subarray that are greater than the key to one position right
    j = i - 1
    while j >= 0 and key < arr[j]:
      arr[j + 1] = arr[j]
      j -= 1
    # Insert the key at the correct position
    arr[j + 1] = key
  # Return the sorted array
  return arr

# Driver code
# Accept the roll numbers of the students who attended the training program
n = int(input("Enter the number of students who attended the training program: "))
arr = []
for i in range(n):
  roll = int(input(f"Enter the roll number of student {i + 1}: "))
  arr.append(roll)

# Sort the roll numbers using insertion sort
arr = insertion_sort(arr)

# Display the roll numbers
print("The roll numbers of the students who attended the training program are:")
for roll in arr:
  print(roll, end=" ")
print()

# Search for a particular student using binary search and fibonacci search
key = int(input("Enter the roll number of the student to be searched: "))
index1 = binary_search(arr, key)
index2 = fibonacci_search(arr, key)
if index1 != -1 and index2 != -1:
  print(f"Yes, the student with roll number {key} attended the training program.")
  print(f"The index of the student using binary search is {index1}.")
  print(f"The index of the student using fibonacci search is {index2}.")
else:
  print(f"No, the student with roll number {key} did not attend the training program.")
