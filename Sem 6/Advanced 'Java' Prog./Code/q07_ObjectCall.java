
public class q07_ObjectCall {
    String name;
    int age;

    public void greet() {
        System.out.println("Hello, my name is " + name + " and I am " + age + " years old.");
    }

    public int getAge() {
        return age;
    }

    public void setAge(int newAge) {
        this.age = newAge;
    }

    public static void main(String[] args) {
        ObjectCall person1 = new ObjectCall();

        person1.name = "John";
        person1.age = 25;

        person1.greet();
        System.out.println("Age: " + person1.getAge());

        person1.setAge(30);
        System.out.println("Updated Age: " + person1.getAge());
    }
}
