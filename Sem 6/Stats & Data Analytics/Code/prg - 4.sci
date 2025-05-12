clc;
clear;

disp("Amit Singhal - 11614802722");
disp("Matrix Properties: Associative, Commutative, and Distributive");

n = input("Enter the size of square matrices (n x n): ");

disp("Enter elements of Matrix A:");
A = zeros(n, n);
for i = 1:n
    for j = 1:n
        A(i, j) = input("A(" + string(i) + "," + string(j) + ") = ");
    end
end

disp("Enter elements of Matrix B:");
B = zeros(n, n);
for i = 1:n
    for j = 1:n
        B(i, j) = input("B(" + string(i) + "," + string(j) + ") = ");
    end
end


disp("Enter elements of Matrix C:");
C = zeros(n, n);
for i = 1:n
    for j = 1:n
        C(i, j) = input("C(" + string(i) + "," + string(j) + ") = ");
    end
end

LHS_assoc = (A + B) + C;
RHS_assoc = A + (B + C);

disp("Associative Property Check: (A + B) + C == A + (B + C)");
if isequal(LHS_assoc, RHS_assoc)
    disp("True");
else
    disp("False");
end

disp("Commutative Property Check: A + B == B + A");
if isequal(A + B, B + A)
    disp("True");
else
    disp("False");
end

LHS_dist = A * (B + C);
RHS_dist = (A * B) + (A * C);

disp("Distributive Property Check: A(B + C) == AB + AC");
if isequal(LHS_dist, RHS_dist)
    disp("True");
else
    disp("False");
end
