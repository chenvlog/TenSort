#include <iostream>

using namespace std;

void print(int *arr,int len){

    for(int i=0;i<len;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;

}

int parttion(int *arr,int L,int R){

    int mid = L + rand()%(R-L);
    int key = arr[mid];

    //与最后一个元素交换
    swap(arr[R],arr[mid]);

    int i = L;
    for(int j=L;j<=R-1;j++){
        if(arr[j] < key){
            swap(arr[i],arr[j]);
            i++;
        }
    }
    swap(arr[i],arr[R]);

    return i;
}

void quickSort(int *arr,int L,int R){

    if(L < R){
        int mid = parttion(arr,L,R);
        quickSort(arr,L,mid-1);
        quickSort(arr,mid+1,R);
    }

}

int parttion2(int *arr,int L,int R){

    int key = arr[L];

    while(L < R){
        while(L < R && arr[L] < key){L++;}
        arr[R] = arr[L];
        while(R > L && arr[R] >= key){R--;}
        arr[L] = arr[R];
    }
    arr[L] = key;

    return L;

}

void quichSort2(int *arr,int L,int R){
    if(L < R){
        int mid = parttion2(arr,L,R);
        quichSort2(arr,L,mid-1);
        quichSort2(arr,mid+1,R);
    }
}


int main(){


    int arr[10] = {1,22,0,4,5,65,5,8,9,22};

    print(arr,10);
    quickSort(arr,0,9);
    print(arr,10);



    return 0;
}