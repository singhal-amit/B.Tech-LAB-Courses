disp("Amit Singhal - 11614802722");

// Create Identity Matrix first
I_matrix = eye(3, 3);
disp("Identity Matrix of size 3x3:");
disp(I_matrix);

A = [1, 2, 3; 0, 1, 4; 5, 6, 0]; 
B = [2, 1, 1; 1, 3, 2; 1, 2, 4]; 

disp("Matrix A:");
disp(A);

size_A = size(A);
disp("Size of Matrix A:");
disp(size_A);

disp("Matrix B:");
disp(B);

size_B = size(B);
disp("Size of Matrix B:");
disp(size_B);

// Matrix Addition
C = A + B;
disp("Matrix A + B:");
disp(C);

// Matrix Subtraction
D = A - B;
disp("Matrix A - B:");
disp(D);

// Matrix Multiplication
E = A * B;
disp("Matrix A * B:");
disp(E);

// Matrix Transpose
F = A';
disp("Transpose of Matrix A:");
disp(F);

// Element-wise multiplication with itself
H = A .* A; 
disp("Element-wise Multiplication of A and A:");
disp(H);

// Element-wise squaring
I = A .^ 2;
disp("Element-wise Squared Matrix A:");
disp(I);

// Matrix Determinant
det_A = det(A);
disp("Determinant of Matrix A:");
disp(det_A);

// Matrix Inversion with error handling
try
    inv_A = inv(A); // Inverse of A
    disp("Inverse of Matrix A:");
    disp(inv_A);
    
    // Verify inverse by multiplying A * A^(-1)
    verify = A * inv_A;
    disp("Verification A * A^(-1) (should be identity matrix):");
    disp(verify);
catch
    disp("Matrix A is singular and cannot be inverted.");
end
