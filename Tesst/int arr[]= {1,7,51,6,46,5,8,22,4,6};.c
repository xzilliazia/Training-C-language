int arr[]= {1,7,51,6,46,5,8,22,4,6};
int n=10;

void swap(int *a, int *b){
    int temp = *a;
    *a=*b;
    *b=temp;
}

void bublesort(){
    for (int q=0;q<n-1;q++){
        for (int w=0;w-q-1;w++){
        if(arr[w]>arr[w+1]){
            swap (&arr[w],&arr[w+1]);
        }
     }
    }
}
