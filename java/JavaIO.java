import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.File;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.util.Scanner;

public class JavaIO {
  public static void main(String[] args) throws IOException {
    /*
     * Scanner s = new Scanner(System.in);
     * System.out.println(s.next());
     * s.close();
     */

    File myFile = new File("./test.txt");
    if (!myFile.exists()) {
      myFile.createNewFile();
    }

    Scanner fileReader = new Scanner(myFile);
    FileWriter fileWriter = new FileWriter(myFile);

    fileWriter.flush();

    fileWriter.write("Hello, World!\n");
    fileWriter.write("Welcome!");

    while (fileReader.hasNext()) {
      fileWriter.write(fileReader.nextLine());
    }

    fileReader.close();
    fileWriter.close();

    bufferedWriterAndReader();
  }

  private static void bufferedWriterAndReader() throws IOException {
    // TODO Auto-generated method stub
    File mySecondFile = new File("buffer.txt");
    FileWriter buffer = new FileWriter(mySecondFile);
    BufferedWriter bufferedWriter = new BufferedWriter(buffer);

    FileReader read = new FileReader(mySecondFile);
    BufferedReader bufferedReader = new BufferedReader(read);

    bufferedWriter.write("Hello, World!");
    bufferedWriter.newLine();
    bufferedWriter.append("Welcome").append(" \n to the real world");
    bufferedWriter.flush();

    for (int i = 0; i < 12; i++)
      System.out.println((char) bufferedReader.read());
    System.out.println(bufferedReader.readLine());
    System.out.println(bufferedReader.readLine());
    System.out.println(bufferedReader.readLine());

    bufferedReader.close();
    bufferedWriter.close();
  }
}
