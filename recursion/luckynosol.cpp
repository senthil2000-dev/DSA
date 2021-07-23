bool isLucky(int n, int counter = 2) {
    if(counter>n) return true;
    if(n%counter == 0) return false;
    return isLucky(n-n/counter, counter+1);
}
