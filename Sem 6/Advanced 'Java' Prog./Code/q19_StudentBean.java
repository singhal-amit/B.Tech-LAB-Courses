import java.io.Serializable;

public class q19_StudentBean implements Serializable {
    private static final long serialVersionUID = 1L;
    private int id; private int age;
    private String name;

    public q19_StudentBean() {}
    public q19_StudentBean(int id, String name, int age) {
        this.id = id;
        this.name = name;
        this.age = age;
    }
    public int getId() { return id; }
    public void setId(int id) { this.id = id; }

    public String getName() { return name; }
    public void setName(String name) { this.name = name; }

    public int getAge() { return age; }
    public void setAge(int age) {
        if (age > 0) {
            this.age = age;
        } else {
            System.out.println("Age must be positive.");
        }
    }

    @Override
    public String toString() {
        return "Student [ID=" + id + ", Name=" + name + ", Age=" + age + "]";
    }
}
