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

int main(int argc, char *argv[])
{
    float arr1[MAX];
    float arr2[MAX];
    int size1,size2 = 0;
    vector<float> bigArr; 
    string name = ""; 
    fstream file; 

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

    return 0; 
}

void fileOpen(string name, fstream& file){
    file.open(name);
    file.clear();
    file.seekg(0);
    string num; 
    file >> num;

    if (num == ""){
        cout << "Empty File" << endl;
        file.close();
        exit(-1);
    }
    else{

    }
return; 
}

vector<float> fillArr(fstream& file, vector<float> arr){
    string num; 
    file >> num;
    while (!file.eof()){
        float elt = stof(num);
        arr.push_back(elt);
        file >> num;
    }

    for(int i = 0; i < arr.size(); i++){
        cout << arr[i] << " "; 
    }
    cout << endl << endl;
    file.close();
    return arr; 
}

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

vector<float> merge(vector<float> left, vector<float> right){
    vector<float> arr; 
    int l,r = 0;
    while ((l < left.size()-1) && (r < right.size()-1)){
        if (left[l] < right[r]){
            arr.push_back(left[l]);
            l++;
        }
        else{
            arr.push_back(right[r]);
            r++;
        }
    }
    if (l == left.size()-1){
        arr.push_back(right[r]);
    }
    else{
        arr.push_back(left[l]);
    }
    cout << "Merge:" << endl;
    vector<float>::iterator it;
    for (it = right.begin();it < right.end(); it++){
        cout << *it << " ";
    }
    cout << endl; 
    return arr; 
}