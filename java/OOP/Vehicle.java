package OOP;

public class Vehicle implements Engine {
  int numberOfSeats;
  int numberOfWheels;

  public void stop() {
    System.out.println("I am stopping");
  }

  @Override
  public void start() {
    System.out.println("I am starting");
  }
}
