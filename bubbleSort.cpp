#include <iostream>

using namespace std;

void print(int *arr,int len){

    for(int i=0;i<len;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;

}

void bubbleSort(int *arr,int len){

    bool flag = false;
    for(int i=0;i<len-1;i++){
        flag = false;
        for(int j=0;j<len-1-i;j++){
            if(arr[j] > arr[j+1]){
                flag = true;
                swap(arr[j],arr[j+1]);
            }
        }
        if(!flag){
            break;
        }
    }

}

int main(){


    int arr[10] = {1,22,0,4,5,65,5,8,9,22};

    print(arr,10);
    bubbleSort(arr,10);
    print(arr,10);



    return 0;
}