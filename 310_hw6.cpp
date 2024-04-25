#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

void fileOpen(string, fstream& file);
vector<int> fillVec(fstream& file);

int main(int argc, char *argv[])
{
    vector<int> arr1;
    vector<int> arr2;
    string name = ""; 
    fstream file; 
    cout << "Enter File: ";
    cin >> name;
    fileOpen("arr1.txt",file);
    arr1 = fillVec(file);
    return 0; 
}

void fileOpen(string name, fstream& file){
    file.open(name);
    string num; 
    file >> num;

    if (num == ""){
        cout << "Empty File" << endl;
        exit(-1);
    }
    else{
        file.clear();
        file.seekg(0);
    }
return; 
}

vector<int> fillVec(fstream& file){
    vector<int> arr;
    string num; 
    file >> num;

    while (!file.eof()){
        int elt = stoi(num);
        arr.push_back(elt);
        file >> num;
    }

    for(int i = 0; i < arr.size(); i++){
        cout << arr[i] << " "; 
    }
    cout << endl;
    return arr; 
}