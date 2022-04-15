#include <iostream>

using namespace std;

void print(int *arr,int len){

    for(int i=0;i<len;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;

}

void countingSort(int *arr,int len){

    //先做一个鸽巢
    int *cnt = new int[100];
    for(int i=0;i<100;i++){cnt[i] = 0;}

    for(int i=0;i<len;i++){
        cnt[arr[i]]++;
    }

    //求前缀和
    for(int i=1;i<100;i++){
        cnt[i]+=cnt[i-1];
    }

    int *ans = new int[len];
    for(int i=0;i<len;i++){
        ans[cnt[arr[i]]-1] = arr[i];
        cnt[arr[i]]--;
        
    }

    for(int i=0;i<len;i++){
        arr[i] = ans[i];
    }

    //print(ans,10);

    delete []ans;

}

int main(){


    int arr[10] = {1,22,0,4,5,65,5,8,9,22};

    print(arr,10);
    countingSort(arr,10);
    print(arr,10);



    return 0;
}