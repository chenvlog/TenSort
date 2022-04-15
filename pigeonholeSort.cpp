#include <iostream>

using namespace std;

void print(int *arr,int len){

    for(int i=0;i<len;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;

}

void pigeonholeSort(int *arr,int len){

    int *cnt = new int[100];

    for(int i=0;i<100;i++) cnt[i] = 0;

    for(int i=0;i<len;i++){
        cnt[arr[i]]++;
    }

    int k = 0;
    for(int i=0;i<100;i++){
       while(cnt[i]){
           arr[k++] = i;
           cnt[i]--;
       }
    }

    delete []cnt;

}


int main(){


    int arr[10] = {1,22,0,4,5,65,5,8,9,22};

    print(arr,10);
    pigeonholeSort(arr,10);
    print(arr,10);



    return 0;
}