package Code;


// Single Inheritance among Interfaces
interface Animal {
    void sound();
}

interface Dog extends Animal {
    void breed();
}

class Labrador implements Dog {
    public void sound() {
        System.out.println("Labrador barks");
    }

    public void breed() {
        System.out.println("Breed: Labrador");
    }
}

// Hierarchical Inheritance among Interfaces
interface Vehicle {
    void start();
}

interface Car extends Vehicle {
    void speed();
}

interface Bike extends Vehicle {
    void mileage();
}

class Sedan implements Car {
    public void start() {
        System.out.println("Sedan starts");
    }

    public void speed() {
        System.out.println("Sedan has a speed of 120 km/h");
    }
}

class SportsBike implements Bike {
  public void start() {
    System.out.println("Sports Bike starts");
  }

  public void mileage() {
    System.out.println("Sports Bike has a mileage of 30 km/l");
  }
}

public class q03_InterfaceInheritance{
    public static void main(String[] args) {
        // Single Inheritance
        Labrador labrador = new Labrador();
        labrador.sound();
        labrador.breed();

        // Hierarchical Inheritance
        Sedan sedan = new Sedan();
        sedan.start();
        sedan.speed();

        SportsBike bike = new SportsBike();
        bike.start();
        bike.mileage();
    }
}
