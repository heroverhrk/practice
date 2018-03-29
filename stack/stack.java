public class stack{
  int stack[];
  int nelem;

  public stack(){
    nelem = 0;
    stack = new int[1000];
  }
  public synchronized void push(int d){
    stack[nelem] = d;
    nelem++;
    notify();
  }
  public synchronized int pop(){
    while (nelem <= 0){
      try{
      wait();
      }
    catch(InterruptedException e){}
    }
    nelem--;
    return stack[nelem];
  }

  public static void main(String[] args){
    stack stack1 = new stack();
    stack1.push(5);
    System.out.println(stack1.pop());
    stack1.push(3);
    System.out.println(stack1.pop());
    }
}
