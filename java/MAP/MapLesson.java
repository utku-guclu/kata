import java.util.Map;
import java.util.TreeMap;

public class MapLesson {
  public static void main(String[] args) {
    TreeMap<String, Integer> map = new TreeMap<String, Integer>();
    map.put("Java", 1);
    map.put("Python", 2);
    map.put("C++", 3);
    map.put("C#", 4);
    System.out.println(map); // {C#=4, C++=3, Java=1, Python=2}

    System.out.println(map.get("Java")); // 1

    System.out.println(map.firstKey()); // C#
    System.out.println(map.lastEntry()); // Python=2

    for (Map.Entry<String, Integer> entry : map.entrySet()) {
      System.out.println(entry);
    }

  }
}

// compile and run java
