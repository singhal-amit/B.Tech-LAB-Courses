class Car {

    String model;
    int year;
    String color;

    public Car() {
        this.model = "Unknown";
        this.year = 0;
        this.color = "Unknown";
        System.out.println("Default constructor called");
    }

    public Car(String model, int year, String color) {
        // Initialize with the provided values
        this.model = model;
        this.year = year;
        this.color = color;
        System.out.println("Parameterized constructor called");
    }

    public void displayDetails() {
        System.out.println("Car Model: " + model);
        System.out.println("Car Year: " + year);
        System.out.println("Car Color: " + color);
    }
}

public class q09_Constructor {

    public static void main(String[] args) {
        Car car1 = new Car();
        car1.displayDetails();

        System.out.println();

        Car car2 = new Car("Tesla Model S", 2023, "Red");
        car2.displayDetails();
    }
}
