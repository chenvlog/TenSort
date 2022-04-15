#include <iostream>

using namespace std;

void print(int *arr,int len){

    for(int i=0;i<len;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;

}

int Left(int i,int len){
    if(2*i+1 >= len ) return -1;
    return 2*i+1;
}

int Right(int i,int len){
    if(2*i+2 >= len ) return -1;
    return 2*i+2;
}


void minHapify(int *arr,int i,int len){

    int L = Left(i,len);
    int R = Right(i,len);

    int minIndex = i;
    if(L != -1 && arr[L] > arr[minIndex]) minIndex = L;   //
    if(R != -1 && arr[R] > arr[minIndex]) minIndex = R;   //

    if(minIndex != i){
        swap(arr[i],arr[minIndex]);
        i= minIndex;
        minHapify(arr,i,len);
    }

}

int Delete(int *arr,int len){

    int value = arr[0]; 
    swap(arr[0],arr[len-1]);
    minHapify(arr,0,len-1);

    return value;
}

void heapSort(int *arr,int len){//大顶堆-->从小到大

    int i = (len-1)/2;
    for(i;i>=0;i--){
        minHapify(arr,i,len);
    }

    int* myarr = new int[len];
    for(int i=0;i<len;i++){
        Delete(arr,len-i);
    }

}



int main(){


    int arr[10] = {1,22,0,4,5,65,5,8,9,22};

    print(arr,10);
    heapSort(arr,10);
    print(arr,10);



    return 0;
}