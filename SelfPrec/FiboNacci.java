public class FiboNacci{
  public static void main(String agrs[]){
    System.out.println("Hello world!");
  }
  public static int fiboNacci(int n){
    if(n<=1) return 1;
    return fiboNacci(n-1) + fiboNacci(n-2);
  }
}
