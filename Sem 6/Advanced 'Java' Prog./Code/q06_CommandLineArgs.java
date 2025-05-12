
public class q06_CommandLineArgs {

    public static void main(String[] args) {
        if (args.length != 2) {
            System.out.println("<name> <age> not defined in command line arguments");
            return;
        }

        String name = args[0];
        String ageString = args[1];

        try {
            int age = Integer.parseInt(ageString);
            System.out.println("Hello, " + name + "! You are " + age + " years old.");
        } catch (NumberFormatException e) {
            System.out.println("Error: The second argument should be a valid number (age).");
        }
    }
}
