#include <iostream>

using namespace std;

void print(int *arr,int len){

    for(int i=0;i<len;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;

}


void hillSort(int *arr,int len){

    int gap = len/2;
    while(gap >= 1){
        for(int i=gap;i<len;i++){
            int key = arr[i];
            int j;
            for(j=i-gap;j>=0;j-=gap){
                if(arr[j] > key){
                    arr[j+gap] = arr[j];
                }else{
                    break;
                }       
            }    
            arr[j+gap] = key; 
            //cout<<"-----"<<arr[j+gap]<<endl;       
        }
        gap/=2;

    }
}

int main(){


    int arr[10] = {1,22,0,4,5,65,5,8,9,22};

    print(arr,10);
    hillSort(arr,10);
    print(arr,10);



    return 0;
}