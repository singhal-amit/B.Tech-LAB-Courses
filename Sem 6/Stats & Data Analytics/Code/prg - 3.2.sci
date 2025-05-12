disp("Amit Singhal - 11614802722");
printf("\n");  // Print a blank line

A = input("Enter the matrix A: ");
printf("\n");  
b = input("Enter the vector b: ");
printf("\n");  

Aug = [A, b];  // Augmented matrix

disp("Augmented Matrix:");
disp(Aug);
printf("\n");

n = size(A, 1);

for k = 1:n
    // Pivoting: Make the diagonal element 1
    if Aug(k, k) == 0 then
        disp("Division by zero detected.");
        break;
    end
    Aug(k, :) = Aug(k, :) / Aug(k, k);  // Scale the k-th row

    // Make the elements below and above the pivot 0
    for i = 1:n
        if i ~= k then
            factor = Aug(i, k);
            Aug(i, :) = Aug(i, :) - factor * Aug(k, :);
        end
    end
end

printf("\n");
disp("Reduced Row Echelon Form (RREF) matrix:");
disp(Aug);
printf("\n");

x = Aug(:, $);  // Extract the solution from the last column

disp("Solution:");
disp(x);
printf("\n");
