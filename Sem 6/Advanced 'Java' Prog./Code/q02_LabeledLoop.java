package Code;

public class q02_LabeledLoop {
    public static void main(String[] args) {

        // Label for the outer loop
        outerLoop: for (int i = 1; i <= 3; i++) {
            System.out.println("Outer loop iteration " + i);

            // Label for the inner loop
            innerLoop: for (int j = 1; j <= 3; j++) {
                System.out.println("  Inner loop iteration " + j);

                // If the inner loop variable j is 2, break out of the inner loop and continue
                // with the next iteration of the outer loop
                if (j == 2) {
                    System.out.println("    Skipping the rest of the inner loop (j == 2)");
                    continue outerLoop; // Skips to the next iteration of the outer loop
                }
            }
        }
    }
}
