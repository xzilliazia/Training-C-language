int faktorial(int n){
    if (n == 0){
    return 1;
    }
    int rek = n * faktorial(n-1);
    return rek;
}