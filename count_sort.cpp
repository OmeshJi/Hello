#include <bits/stdc++.h>
using namespace std;

int findMax(vector<int>&arr){
    int max = arr[0];
    for(int i=1; i<arr.size(); i++){
        if(arr[i]>max){
            max = arr[i];
        }
    }
    return max;
}

void countSort(vector<int>& arr){

    int max = findMax(arr);
    
    vector<int> count(max+1);
    vector<int> output(arr.size());

    for(int i = 0; i<arr.size(); i++){
        count[arr[i]]++;
    }

    for(int i = 1; i<count.size(); i++){
        count[i] += count[i-1];
    }

    for(int i = arr.size()-1; i>=0; i--){
        output[--count[arr[i]]]=arr[i];
    }

    for(int i = 0; i<arr.size(); i++){
        arr[i] = output[i];
    }
    
}

int main(){

     vector<int> arr = {1,1,4, 5,4, 6, 8, 4, 9, 10, 2, 7, 3};
     cout<<"Before :";
     for (int i = 0; i < arr.size(); i++)
    {
        cout << arr[i] << " ";
    }
    cout<<endl;
    cout<<"After :";

    countSort(arr);
    for (int i = 0; i < arr.size(); i++)
    {
        cout << arr[i] << " ";
    }


    return 0;
}