#include <iostream>
#include <math.h>

using namespace std;

float nCk(int n, int k){
  int N=1, K=1;
  for(int i=n; i>(N-k); i--){
    N*=i;
  }
  for(int i=k; i>0; i--){
    K*=i;
  }
  return N/K;
}

int main(){
  int hoge = nCk(5, 2);
  cout << hoge << endl;

  return 0;
}
