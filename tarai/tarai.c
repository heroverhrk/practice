#include <stdio.h>
#include <time.h>

int tarai(int x,int y,int z){
  if(x <= y)
  return y;
  else
  return tarai(tarai(x-1,y,z),tarai(y-1,z,x),tarai(z-1,x,y));
}

int main(){
  clock_t start = clock();

  tarai(13,5,0);

  clock_t end = clock();

  printf("%f\n",(double)(end - start) / CLOCKS_PER_SEC);

}
