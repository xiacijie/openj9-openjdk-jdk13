public class Test {
   public static Object doTest() {
      Foo f = new Foo();
      f.x = 100;
      f.y = f.x + 20;
      return f;
   }

   public static void main(String[] args) {
      doTest();
	  doTest();
   }
}

class Foo {
  public int x;
  public long y;
}
