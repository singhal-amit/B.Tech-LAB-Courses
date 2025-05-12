disp("Amit Singhal - 11614802722");

A = [-5, 2; -9, 6];

disp("The input matrix A is:");
disp(A);

// Solve the characteristic equation det(A - λI) = 0
lambda = poly(0, 'lambda');
I = eye(A);
char_matrix = A - lambda * I;
characteristic_eq = det(char_matrix)

// Solve the characteristic equation for λ - roots = Eigen Values
eigenvalues = roots(characteristic_eq);

disp("Eigenvalues:");
for i = 1:length(eigenvalues)
    disp("λ" + string(i) + " = " + string(eigenvalues(i)));
end

// Solve for Eigen Vectors corresponding to each Eigen Value
disp("Eigenvectors:");
for i = 1:length(eigenvalues)
    lambda_val = eigenvalues(i);
    eigenvector_matrix = A - lambda_val * I;
    disp("Eigenvector corresponding to λ" + string(i) + " = " + string(lambda_val) + ":");
    eigenvector = kernel(eigenvector_matrix);
    disp(eigenvector);
end

// Verification: Check A*v = λ*v for each Eigen Value & Eigen Vector
disp("Verification (A*v = λ*v):");
for i = 1:length(eigenvalues)
    lambda_val = eigenvalues(i);
    eigenvector = kernel(A - lambda_val * I);
    left_side = A * eigenvector; 
    right_side = lambda_val * eigenvector;
    disp("For λ" + string(i) + " = " + string(lambda_val) + ":");
    disp("A*v = ");
    disp(left_side);
    disp("λ*v = ");
    disp(right_side);
end
