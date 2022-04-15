#include <iostream>
#include <queue>

using namespace std;

void print(int *arr,int len){

    for(int i=0;i<len;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;

}

int radixSort(int *arr,int len){

    

    int maxnum  = -1;
    for(int i=0;i<len;i++){
        maxnum = maxnum > arr[i] ? maxnum:arr[i];
    }

    //求位数
    int t = 0;
    while (maxnum > 0)
    {
        t++;
        maxnum/=10;
    }

    int mod = 10;
    for(int i=0;i<t;i++){

        queue<int>bush[10];//得每次更新下,会更好  0~9

        
        //分解
        for(int j=0;j<len;j++){
            bush[(arr[j]%mod) / (mod/10)].push(arr[j]);
        }
        //合并
        int k = 0;
        for(int j=0;j<10;j++){
            while(!bush[j].empty()){
                arr[k++] = bush[j].front();
                bush[j].pop();
            }
        }
        mod = mod * 10;

    }   
    



}

int main(){


    int arr[10] = {1,22,0,4,5,65,5,8,9,22};

    print(arr,10);
    radixSort(arr,10);
    print(arr,10);



    return 0;
}