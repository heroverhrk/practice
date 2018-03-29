public class tarai{
  public static int Tarai(int x,int y,int z){
    if(x <= y){
      return y;
    }
    else{
      return Tarai(Tarai(x-1,y,z),Tarai(y-1,z,x),Tarai(z-1,x,y));
    }
  }
  public static void main(String args []){
    long start = System.currentTimeMillis();

    Tarai(13,5,0);

    long end = System.currentTimeMillis();
    System.out.println((double)(end - start)/1000 + "s");
  }
}
