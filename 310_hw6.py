import sys


def parse_input(name):
    '''
    function to open a file and then fill a list with the values form that file
    returns the list
    '''
    file = open(name)
    raw = (file.read()).split()
    array = []
    for x in raw:
        array.append(float(x))
    print(array)
    return array

def selection_sort(arr):
    '''
    sorts a list using selection sort
    input is an unsorted list
    outputs a sorted list
    '''
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
    '''
    sorts a list using bubble sort
    input is an unsorted list
    outputs a sorted list
    '''
    for i in range(len(arr)):
        for m in range(0, len(arr)-i-1):
            if arr[m] > arr[m+1]:
                arr[m], arr[m+1] = arr[m+1], arr[m]
    print("\nBubble Sort:")  
    print(arr)   
    return arr
def merge(l_arr, r_arr):
    '''
    merges two sorted arrays
    takes two sorted arrays as input
    returns a list in ascending order
    '''
    arr = []
    l, r = 0,0
    while l < len(l_arr)  and r < len(r_arr):
        if l_arr[l] < r_arr[r]:
            arr.append(l_arr[l])
            l += 1
        else:
            arr.append(r_arr[r])
            r += 1
    if len(l_arr) - l == 0:
        for r in range(r, len(r_arr)):
            arr.append(r_arr[r])
    else:
        for l in range(l, len(l_arr)):
            arr.append(l_arr[l])
    print("\nMerge:")
    print(arr)
    return arr

def binary_search(arr, target):
    '''
    searches for a target in a sorted list
    returns result on the command line
    takes a sorted list and a target
    '''
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
        print("Found target @ ",mid)
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