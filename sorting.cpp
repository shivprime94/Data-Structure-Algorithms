#include<iostream>
using namespace std;
void swapp(int *a,int *b){
int temp= *b;
*b=*a;
*a=temp;
}
void Bubble_sort(int arr[],int n){
    int temp;
    for(int i=0;i<n-1;i++){
        for(int j=0;j<n-i-1;j++){
            if (arr[j+1]<arr[j]){
               swapp(&arr[j+1],&arr[j]);
            }
        }
    }
}
void selection_sort(int arr[],int n){
    int smallest;
for(int i=0;i<n-1;i++){
 smallest=i;
    for(int j=i+1;j<n;j++){

        if(arr[j]<arr[smallest]){
            smallest=j;
        }

    }swapp(&arr[i],&arr[smallest]);
}


}
void insertion_sort(int arr[],int n){

for(int i=1;i<n;i++){
    int temp=arr[i];
    int j;
   for( j=i-1;j>=0 &&arr[j]>temp;j--){

    arr[j+1]=arr[j];
   }
   arr[j+1]=temp;
}


}
void mergee(int arr[],int beg,int endd,int mid){
    int i,j,k;
    int m=sizeof(arr);
    int c[m];
for(i=0, j=mid+1,k=0;i<=mid&&j<=endd;k++){
if(arr[i]<arr[j]){
        c[k]=arr[i];
    i++;
}
else{
        c[k]=arr[j];
    j++;
}

}
while(i<=mid){
    c[k]=arr[i];
    k++;
    i++;
}

while(j<=endd){
    c[k]=arr[j];
    k++;
    j++;
}
for( k=0,i=beg;i<endd;k++,i++){
    arr[i]=c[k];
}

}



void merge_sort(int arr[],int beg,int endd){
    if(beg==endd){
        return;
    }
int mid=(beg+endd)/2;
merge_sort(arr, beg, mid);
merge_sort(arr, mid+1, endd);
mergee(arr,beg,endd,mid);
}




int partitionn(int arr[],int lb,int ub){
int pivot=arr[lb];

int start=lb;
int endd=ub;
while(start<endd){
while(arr[start]<=pivot)
{
    start++;
}
while(arr[endd]>pivot){
    endd--;
}
if(start<endd){
    swapp(&arr[start],&arr[endd]);
}
}
swapp(&arr[endd],&arr[lb]);
return endd;
}



void quick_sort(int arr[],int lb,int ub){
    if(lb<ub){
int loc=partitionn(arr,lb,ub);
quick_sort(arr,lb,loc-1);
quick_sort(arr,loc+1,ub);
}
}

void max_heapify(int a[],int n,int i){
int largest=i;
int l=2*i;
int r=2*i+1;
while(l<=n&&a[l]>a[largest]){

    largest=l;
}
while(r<=n&&a[r]>a[largest])
{
    largest=r;

}
if(largest!=i){
    swapp(&a[largest],&a[i]);
    max_heapify(a,n,largest);
}
}
void heap_sort(int a[],int n){
for(int i=n/2;i>=1;i--){
    max_heapify(a,n,i);
    //heapify
}

for(int i=n;i>=1;i--){
    swapp(&a[1],&a[i]);
    max_heapify(a,i-1,1);

}
//deletion

}
















void print(int arr[],int n){
for(int i=0;i<n;i++){
    cout<<arr[i];
}
}
int main(){
    int arr1[6]={1,7,9,10,8,5};
    int i;
    cout<<"the original array is";
    print(arr1,6); cout<<endl;
    cout<<"1.Bubble sort/n 2.selection/n 3.insertion sort/n 4.merge sort/n 5.quicksort/n6.heap sort";
    cin>>i;

switch (i){
    case 1:
    Bubble_sort(arr1,6);
    print(arr1,6);
    break;
    case 2:
    selection_sort(arr1,6);

    print(arr1,6);
    break;
     case 3 :
   insertion_sort(arr1,6);

    print(arr1,6);
    break;
      case 4 :
   merge_sort(arr1,0,5);

    print(arr1,5);
    break;
    case 5 :
   quick_sort(arr1,0,sizeof(arr1)/sizeof(arr1[0]) - 1);

    print(arr1,sizeof(arr1)/sizeof(arr1[0]) );
    break;
    case 6 :
    heap_sort(arr1,6);

    print(arr1,6);
    break;
}
}
