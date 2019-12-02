
public class Test extends F {
   
   // public static int doTest(Object obj) {
   //    int i = 1;
   //    Object b = obj;
   //    return ((String)obj).length();
   // }

   public static int doTest() {
      int a = 1;
      int b = 2;
      return a * b;
  }
  public static void main(String[] args) {
      doTest();
      doTest();
  }

}

interface IFoo {
   public int get1();
   
}
class F {
   public int x;
   static public int y;
}

class Foo extends F implements IFoo{
   Foo(Foo a){

      
   }

   Foo(){

   }
   public int get1(){
      return 1;
   }

   static int get2(){
      return 2;
   }
   public void get(){}
}
