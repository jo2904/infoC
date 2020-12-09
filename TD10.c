int Miror(int N){
  int b, n=0;
  while(N>0){
    b= N%10;
    N= (N-b)/10;
    n= (n*10)+b;
  }
  return n;
}

int Compter(int N){
  in n=0;
  while(N>0){
    N = n/10;
    n++;
  }
  return n;
}

