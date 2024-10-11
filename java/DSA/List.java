// package DSA;

import java.util.ArrayList;
import java.util.LinkedList;

public class List {
  public static void main(String[] args) {
    int array[] = new int[3];
    array[2] = 12;
    array[0] = array[2];

    ArrayList<Integer> ArrayList = new ArrayList<Integer>();

    ArrayList.add(3);
    ArrayList.add(4);
    ArrayList.add(5);

    LinkedList<Integer> linkedList = new LinkedList<Integer>();

    linkedList.add(2);
    if (linkedList.contains(2)) {
      System.out.println("true");
    } else {
      System.out.println("false");
    }
  }
}
