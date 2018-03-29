#include <iostream>
#include <time.h>

using namespace std;

int Tarai(int x,int y,int z){
  if(x <= y){
    return y;
  }
  else{
    return Tarai(Tarai(x-1,y,z),Tarai(y-1,z,x),Tarai(z-1,x,y));
  }
}

int main(){
  clock_t start = clock();
  Tarai(13,5,0);
  clock_t end = clock();

  cout << (double)(end - start) / CLOCKS_PER_SEC <<"s"<< endl;

  return 0;
}
