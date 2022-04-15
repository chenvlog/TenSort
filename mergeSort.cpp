#include <iostream>

using namespace std;

void print(int *arr,int len){

    for(int i=0;i<len;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;

    //cout<<"Aaa"<<endl;

}

void Merge(int *arr,int L,int R){
 
    //分左右两个数组
    int mid = (L+R)/2;
    int nL  = mid-L+1;
    int nR  = R-mid;

    //开辟两个数组分别存放左右两边
    int *arrL = new int[nL];
    int *arrR = new int[nR];
    
    //初始化
    for(int i=0;i<nL;i++){arrL[i] = arr[L+i];}
    for(int i=0;i<nR;i++){arrR[i] = arr[mid+1+i];}

    //合并
    int Li=0;        //arrL
    int Ri=0;        //arrR
    int k =L;

    while(Li < nL && Ri < nR){
        if(arrL[Li] <= arrR[Ri]){
            arr[k++] = arrL[Li];
            Li++;
        }else{
            arr[k++] = arrR[Ri];
            Ri++;
        }
    }

  

    while(Li < nL){
        arr[k++] = arrL[Li];
        Li++;
    }

    while(Ri < nR){
        arr[k++] = arrR[Ri];
        Ri++;
    }
   

}

void mergeSort(int *arr,int L,int R){
    int mid = (L+R)/2;

    if(L < R){
        
        mergeSort(arr,L,mid);
        mergeSort(arr,mid+1,R);  
        //cout<<"merge"<<endl;
        Merge(arr,L,R);
       
    }

}

int main(){


    int arr[10] = {1,22,0,4,5,65,5,8,9,22};

    print(arr,10);
    mergeSort(arr,0,9);
    print(arr,10);



    return 0;
}