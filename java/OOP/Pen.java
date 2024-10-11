package OOP;

public class Pen {
  private String color;
  private int height;

  public void write(String message) {
    System.out.println("I am writing" + message);
  }

  /* Getters and Setters */
  public String getColor() {
    return this.color;
  }

  public void setColor(String color) {
    if ("red".equals(color) || "blue".equals(color) || "black".equals(color))
      this.color = color;
    else
      throw new IllegalArgumentException("Color must be red, blue or black");
  }

  public int getHeight() {
    return this.height;
  }

  public void setHeight(int height) {
    if (height > 0)
      this.height = height;
    else
      throw new IllegalArgumentException("Height must be greater than 0");
  }
}
