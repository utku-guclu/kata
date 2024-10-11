package OOP;

public class ObjectFactory {
  public static void main(String[] args) {
    Pen pen = new Pen();
    // pen.color = "blue";
    pen.setColor("blue");
    // pen.height = 10;
    pen.setHeight(10);
    String message = "I am writing";
    pen.write(message);

    Pen pen2 = new Pen();
    // pen2.color = "red";
    pen2.setColor("red");
    // pen2.height = 20;
    pen2.setHeight(20);
    // pen2.write(message + " " + pen.color + " " + pen.height);
    pen2.write(message + " " + pen.getColor() + " " + pen.getHeight());

    Car car = new Car(); // as a car
    car.numberOfSeats = 5;
    car.numberOfWheels = 4;
    System.out.println("Car has " + car.numberOfSeats + " seats and " + car.numberOfWheels + " wheels");

    Bicycle bicycle = new Bicycle();
    bicycle.numberOfSeats = 1;
    bicycle.numberOfWheels = 2;
    System.out.println("Bicycle has " + bicycle.numberOfSeats + " seats and " + bicycle.numberOfWheels + " wheels");

    Vehicle car2 = new Car(); // as a vehicle

    car2.start();
    bicycle.start();

    car2.stop();
    bicycle.stop();

    Engine engine = new Car(); // as an engine

    Vehicle[] vehicles = new Vehicle[10];
    vehicles[0] = car;
    vehicles[1] = car2;
    vehicles[2] = bicycle;
    // vehicles[3] = engine;

    /* Car car3 = new Vehicle(); */
  }
}
