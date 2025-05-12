disp("Amit Singhal - 11614802722");

A = [-5, 2; -9, 6];

disp("The input matrix A is:");
disp(A);

// Use the spec function to compute eigenvalues and eigenvectors
[eigenvectors, eigenvalues] = spec(A);

// Display eigenvalues
disp("Eigenvalues:");
for i = 1:size(eigenvalues, 1)
    disp("λ" + string(i) + " = " + string(eigenvalues(i, i)));
end

// Display eigenvectors
disp("Eigenvectors:");
for i = 1:size(eigenvectors, 2)
    disp("Eigenvector corresponding to λ" + string(i) + " = " + string(eigenvalues(i, i)) + ":");
    disp(eigenvectors(:, i));
end

// Verification: Check A*v = λ*v for each eigenvalue and eigenvector
disp("Verification (A*v = λ*v):");
for i = 1:size(eigenvalues, 1)
    lambda_val = eigenvalues(i, i);
    eigenvector = eigenvectors(:, i);
    left_side = A * eigenvector;
    right_side = lambda_val * eigenvector;
    disp("For λ" + string(i) + " = " + string(lambda_val) + ":");
    disp("A*v = ");
    disp(left_side);
    disp("λ*v = ");
    disp(right_side);
end
