
import java.util.HashSet;
import java.util.Iterator;
import java.util.Set;

public class Set_ {
  public static void main(String[] args) {
    Set<Integer> set = new HashSet<Integer>();
    set.add(2);
    set.add(2);
    set.add(3);
    set.add(4);
    // if (set.contains(2)) {
    // System.out.println("true");
    // } else {
    // System.out.println("false");
    // }
    // set.forEach(x => System.out.println(x));
    Iterator<Integer> iterator = set.iterator();
    while (iterator.hasNext()) {
      Integer value = iterator.next();
      System.out.println(value);
      if (value.equals(2)) {
        System.out.println("true");
        iterator.remove();
      } else {
        System.out.println("false");
      }
    }

    for (Integer i : set) {
      System.out.println(i);
    }
  }
}
