package Code;

// Defining first interface
interface Animal {
    // Method in Animal interface
    void sound();
}

// Defining second interface
interface Movable {
    // Method in Movable interface
    void move();
}

// A class that implements both Animal and Movable interfaces
public class q01_MultipleInheritance implements Animal, Movable {

    // Implementing the method from the Animal interface
    public void sound() {
        System.out.println("The animal makes a sound");
    }

    // Implementing the method from the Movable interface
    public void move() {
        System.out.println("The animal moves");
    }

    // Main method to test the implementation
    public static void main(String[] args) {
        // Creating an object of the MultipleInheritanceExample class
        MultipleInheritance obj = new MultipleInheritance();

        // Calling methods from both interfaces
        obj.sound(); // Calls sound() from Animal
        obj.move(); // Calls move() from Movable
    }
}
