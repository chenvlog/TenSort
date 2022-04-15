#include <iostream>

using namespace std;

void print(int *arr,int len){

    for(int i=0;i<len;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;

}



void selectionSort(int *arr,int len){

    for(int i=1;i<len-1;i++){
        int minIndex = i;
        for(int j=i;j<len;j++){
            if(arr[minIndex] > arr[j]){
               minIndex = j;
            }
        }
        swap(arr[minIndex],arr[i]);
    }

}


int main(){


    int arr[10] = {1,22,0,4,5,65,5,8,9,22};

    print(arr,10);
    selectionSort(arr,10);
    print(arr,10);



    return 0;
}