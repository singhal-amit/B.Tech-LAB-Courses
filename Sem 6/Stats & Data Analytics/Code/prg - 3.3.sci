disp("Amit Singhal - 11614802722");
printf("\n");

disp("Solving system using Gauss-Seidel Method:");
printf("\n");

disp("Enter the coefficient matrix A:");
A = input("A = ");
printf("\n");

disp("Enter the constant matrix b:");
b = input("b = ");

n = size(A, 1);
x = zeros(n, 1);  // Initial guess (x, y) = (0, 0)
tolerance = 1e-6;
max_iterations = 100;

printf("Iteration\t x\t\t y");
printf("\n");

for iter = 1:max_iterations
    x_old = x;  // Store previous values for convergence check
    
    // Update x1
    x(1) = (1/2) * (8 - x(2));  
    
    // Update x2 (y)
    x(2) = (1/2) * (1 - x(1));  
    
    // Display current iteration values
    printf("%d\t\t %.6f\t %.6f\n", iter, x(1), x(2));

    // Check for convergence
    if norm(x - x_old, "inf") < tolerance
        printf("\nConvergence reached in %d iterations.\n", iter);
        break;
    end
end

printf("\nFinal Solution:\n");
printf("x = %.6f ≅ %.0f\n", x(1), round(x(1)));
printf("y = %.6f ≅ %.0f\n", x(2), round(x(2)));
printf("\n");
