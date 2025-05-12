import java.io.Serializable;

public class q20_EmployeeBean implements Serializable {
    private static final long serialVersionUID = 1L;
    private int empId;
    private double salary;
    private String empName;

    public q20_EmployeeBean() {}

    public int getEmpId() { return empId; }
    public void setEmpId(int empId) { this.empId = empId; }

    public String getEmpName() { return empName; }
    public void setEmpName(String empName) { this.empName = empName; }

    public double getSalary() { return salary; }
    public void setSalary(double salary) {
        if (salary > 0) {
            this.salary = salary;
        } else {
            System.out.println("Salary must be positive.");
        }
    }

    @Override
    public String toString() {
        return "Employee [ID=" + empId + ", Name=" + empName + ", Salary=" + salary + "]";
    }
}
