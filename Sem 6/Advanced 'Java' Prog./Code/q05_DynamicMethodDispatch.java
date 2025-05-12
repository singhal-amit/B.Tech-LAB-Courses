package Code;

// Superclass
class Animal {
    // Method in superclass
    void sound() {
        System.out.println("Animal makes a sound");
    }
}

// Subclass 1
class Dog extends Animal {
    // Overriding sound() method
    @Override
    void sound() {
        System.out.println("Dog barks");
    }
}

// Subclass 2
class Cat extends Animal {
    // Overriding sound() method
    @Override
    void sound() {
        System.out.println("Cat meows");
    }
}

public class q05_DynamicMethodDispatch {
    public static void main(String[] args) {
        // Creating objects of subclasses
        Animal animal1 = new Dog(); // Reference type: Animal, Object type: Dog
        Animal animal2 = new Cat(); // Reference type: Animal, Object type: Cat

        // Dynamic method dispatch: the method that is called depends on the actual
        // object type
        animal1.sound(); // Output: Dog barks (since animal1 points to a Dog object)
        animal2.sound(); // Output: Cat meows (since animal2 points to a Cat object)
    }
}
