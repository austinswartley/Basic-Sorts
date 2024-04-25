import sys


def parse_input(name):
    file = open(name)
    raw = (file.read()).split()
    array = []
    for x in raw:
        array.append(int(x))
    print(array)
    return array

def selection_sort(arr):
    idx = 0
    while idx < len(arr):
        min_idx = idx
        for i in range(idx,len(arr)):
            if arr[i] < arr[min_idx]:
                min_idx = i
        if idx != min_idx:
            min = arr.pop(min_idx)
            swap = arr.pop(idx)
            arr.insert(idx,min)
            arr.insert(min_idx,swap)
        idx += 1
    print("\nSelection Sort:")
    print(arr) 
    return arr

def bubble_sort(arr):
    for i in range(len(arr)):
        for m in range(0, len(arr)-i-1):
            if arr[m] > arr[m+1]:
                arr[m], arr[m+1] = arr[m+1], arr[m]
    print("\nBubble Sort:")  
    print(arr)   
    return arr
def merge(l_arr, r_arr):
    arr = []
    l, r = 0,0
    while l < 20 and r < 20:
        if l_arr[l] < r_arr[r]:
            arr.append(l_arr[l])
            l += 1
        else:
            arr.append(r_arr[r])
            r += 1
    if l == 20:
        arr.append(r_arr[r])
    else:
        arr.append(l_arr[l])
    print("\nMerge:")
    print(arr)
    return arr

def binary_search(arr, target):
    low, high = 0, len(arr)-1
    mid = (low + high) // 2
    while low < mid:
        if arr[mid] > target:           #lower half
            high = mid
            mid = (low + high) // 2
        elif arr[mid] < target:         #upper half
            low = mid
            mid = (low + high) // 2
        else:                           #on target
            break
    print("\nBianary Search:")
    if arr[mid] == target:
        print("Found",target)
    else:
        print("Target not found")

if __name__ == "__main__":
    if len(sys.argv) == 4:
        print("\nArray 1:")
        raw1 = parse_input(sys.argv[1])
        print("\nArray 2:")
        raw2 = parse_input(sys.argv[2])
        arr1 = bubble_sort(raw1)
        arr2 = selection_sort(raw2)     
        big_arr = merge(arr1, arr2)
        binary_search(big_arr, int(sys.argv[3]))