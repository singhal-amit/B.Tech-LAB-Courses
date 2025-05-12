class Animal {

    String name;

    public Animal(String name) {
        this.name = name;
    }

    public void makeSound() {
        System.out.println("The animal makes a sound.");
    }

    public String getName() {
        return name;
    }
}

class Dog extends Animal {

    public Dog(String name) {
        super(name);  // Calls the constructor of the parent class
    }

    @Override
    public void makeSound() {
        System.out.println("The dog barks.");
    }

    public void fetch() {
        System.out.println("The dog is fetching the ball.");
    }
}

public class q08_SingleInheritance {

    public static void main(String[] args) {
        Dog myDog = new Dog("Buddy");

        System.out.println("Dog's name: " + myDog.getName());
        myDog.makeSound();
        myDog.fetch();
    }
}
