
class Calculator {

    public int add(int a, int b) {
        return a + b;
    }

    public int add(int a, int b, int c) {
        return a + b + c;
    }

    public double add(double a, double b) {
        return a + b;
    }

    public double add(int a, double b) {
        return a + b;
    }
}

public class q10_MethodOverloading {

    public static void main(String[] args) {
        Calculator calc = new Calculator();

        System.out.println("Sum of 10 and 20: " + calc.add(10, 20));

        System.out.println("Sum of 10, 20, and 30: " + calc.add(10, 20, 30));

        System.out.println("Sum of 10.5 and 20.5: " + calc.add(10.5, 20.5));

        System.out.println("Sum of 10 and 20.5: " + calc.add(10, 20.5));
    }
}
