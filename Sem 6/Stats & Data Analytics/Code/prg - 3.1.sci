disp("Amit Singhal - 11614802722");
printf("\n");

A = input("Enter the matrix A: ");
b = input("Enter the vector b: ");
Aug = [A, b];

disp("Augmented Matrix:");
disp(Aug);
printf("\n");

n = size(A, 1);

// Forward elimination (Gauss Elimination)
for k = 1:n-1
    if Aug(k, k) == 0 then
        disp("Pivot element is zero, row swapping required!");
        break;
    end
    
    for i = k+1:n
        factor = Aug(i, k) / Aug(k, k);
        Aug(i, k:n+1) = Aug(i, k:n+1) - factor * Aug(k, k:n+1);
    end
end

printf("\n");
disp("Upper Triangular Matrix:");
disp(Aug);
printf("\n");

// Back substitution
x = zeros(n, 1);

for i = n:-1:1
    sum_val = 0;
    
    if i < n then
        sum_val = sum(Aug(i, i+1:n) .* x(i+1:n));
    end
    
    x(i) = (Aug(i, n+1) - sum_val) / Aug(i, i);
end

printf("\n");
disp("Solution:");
for i = 1:n
    printf("x%d = %.6f\n", i, x(i));
end
printf("\n");
