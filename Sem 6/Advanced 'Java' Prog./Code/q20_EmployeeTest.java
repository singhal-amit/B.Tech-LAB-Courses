public class q20_EmployeeTest {
    public static void main(String[] args) {
        // Creating an Employee Bean using the no-arg constructor
        Employee emp = new Employee();

        // Setting properties using setter methods with random values
        emp.setEmpId(2034);
        emp.setEmpName("Lena Rivers");
        emp.setSalary(78560.50);

        // Getting properties using getter methods
        System.out.println("Employee ID: " + emp.getEmpId());
        System.out.println("Employee Name: " + emp.getEmpName());
        System.out.println("Employee Salary: $" + emp.getSalary());
        System.out.println("The Employee Details Are : " + emp);
    }
}
