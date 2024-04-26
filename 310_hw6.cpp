//MinGW would not recognize .txt files on the command line
//I ended up needed to hardwire some values. Did not try it on a linux
//system where it could've worked without faulter
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

const int MAX = 30;
void fileOpen(string, fstream& file);
vector<float> fillArr(fstream& file, vector<float>);
vector<float> bubbleSort(vector<float> arr1);
vector<float> selectionSort(vector<float> arr2);
vector<float> merge(vector<float> left, vector<float> right);
void binarySearch(vector<float>, float);

int main(int argc, char *argv[])
{
    vector<float> arr1;
    vector<float> arr2;
    int size1,size2 = 0;
    vector<float> bigArr; 
    string name = ""; 
    fstream file; 
    float target; 

    //cout << "Enter File: ";
    //cin >> name;
    fileOpen("arr1.txt",file);
    cout << "Array 1:" << endl;
    arr1 = fillArr(file, arr1);
    //cout << "Enter File: ";
    //cin >> name;
    fileOpen("arr2.txt",file);
    cout << "Array 2: " << endl;
    arr2 = fillArr(file, arr2); 
    arr1 = bubbleSort(arr1); 
    arr2 = selectionSort(arr2);
    bigArr = merge(arr1, arr2);
    cout << "Target to search for: ";
    cin >> target;
    cout << endl; 
    binarySearch(bigArr, target);
    return 0; 
}
/*
    function to open a file and ensure that it is not empty
    the file stream is a referece that gets used between the fill function and this one
    takes a file name/path as input
*/
void fileOpen(string name, fstream& file){
    file.open(name);
    string num; 
    file >> num;

    if (num == ""){
        cout << "Empty File" << endl;
        file.close();
        exit(-1);
    }
    file.clear();
    file.seekg(0);
    return; 
}

/*
    function to fill the array and make sure that it is full of float/reals
    takes the fstream that was vetted in fileOpen()
    returns the filled vector
*/
vector<float> fillArr(fstream& file, vector<float> arr){
    string num; 
    file >> num;
    while (!file.eof()){
        float elt = stof(num);
        arr.push_back(elt);
        file >> num;
    }
        file >> num;
        float elt = stof(num);
        arr.push_back(elt);
    for(int i = 0; i < arr.size(); i++){
        cout << arr[i] << " "; 
    }
    cout << endl << endl;
    file.close();
    return arr; 
}
/*
    sorts an array with bubble sort. needs a vector
    inputs an unsorted vector and returns a sorted vector
*/
vector<float> bubbleSort(vector<float> arr){
    for(int i = 0; i < arr.size(); i++){
        for (int m = 0; m < arr.size()-i-1; m++){
            if (arr[m] > arr[m+1]){
                swap(arr[m], arr[m+1]);
            }
        }
    }
    cout << "Bubble Sort:" << endl; 
    for (int i = 0; i < arr.size(); i++){
        cout << arr[i] << " ";
    }
    cout << endl << endl; 
    return arr;
}
/*
    sorts and array with selection sort. needs a vector
    inputs an unsorted vector and returns a sorted vector
*/
vector<float> selectionSort(vector<float> arr){
    int minIdx,m = 0; 
    for (int i = 0; i < arr.size(); i++){
        minIdx = i; 
        for (m = i + 1; m < arr.size(); m++){
            if (arr[m] < arr[minIdx]){
                minIdx = m;
            }
        }
        if (minIdx != i){
            swap(arr[minIdx], arr[i]);
        }
    }
    cout << "Selection Sort: " << endl;
    for (int i = 0; i < arr.size(); i++){
        cout << arr[i] << " "; 
    }
    cout << endl << endl; 
    return arr;
}
/*
    merges two arrays and only requires two sorted arrays as input
    returns one merged array sorted
*/
vector<float> merge(vector<float> left, vector<float> right){
    vector<float> arr; 
    int l = 0;
    int r = 0; 
    while ((l < left.size()) && (r < right.size())){
        if (left[l] < right[r]){
            float elt = left[l];
            arr.push_back(elt);
            l++;
        }
        else{
            float elt = right[r];
            arr.push_back(elt);
            r++;
        }
    }
    if (left.size() - l == 0){
        for (r; r < right.size(); r++){
        float elt = right[r];
        arr.push_back(elt); 
        }
    }
    else{
        for (l; l < left.size(); l++){
        float elt = left[l];
        arr.push_back(elt);
        }
    }
    cout << "Merge:" << endl;
    for (int i = 0; i < arr.size(); i++){
        cout << arr[i] << " "; 
    }
    cout << endl << endl; 
    return arr; 
}
/*
    searches through a sorted array for a target
    requires a sorted array and a target
    returns success/failure on the command line
*/
void binarySearch(vector<float> arr, float target){
    int low = 0;
    int high = arr.size() - 1; 
    int mid = (low + high) / 2; 

    while (low < mid){
        if (arr[mid] > target){
            high = mid;
            mid = (low + high) / 2; 
        }
        else if (arr[mid] < target){
            low = mid; 
            mid = (low + high) / 2;
        }
        else
            break; 
    }
    if (arr[mid] == target)
        cout << "Found target @ idx " << mid << "." << endl;
    else
        cout << "Target not found" << endl; 
}