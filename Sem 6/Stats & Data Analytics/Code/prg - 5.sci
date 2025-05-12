clc;
clear;
disp("Amit Singhal - 11614802722")

function R = rref(A)
    [m, n] = size(A);
    R = A; 
    lead = 1;
    for r = 1:m
        if lead > n then
            return;
        end
        i = r;
        while R(i, lead) == 0
            i = i + 1;
            if i > m then
                i = r;
                lead = lead + 1;
                if lead > n then
                    return;
                end
            end
        end
        temp = R(i, :);
        R(i, :) = R(r, :);
        R(r, :) = temp;
        R(r, :) = R(r, :) / R(r, lead);
        for i = 1:m
            if i <> r then
                R(i, :) = R(i, :) - R(i, lead) * R(r, :);
            end
        end
        lead = lead + 1;
    end
endfunction

printf("\n");
n = input("Enter number of rows: ");
m = input("Enter number of columns: ");
A = zeros(n, m);

disp("Enter elements of the matrix row-wise:");
for i = 1:n
    for j = 1:m
        A(i, j) = input("A(" + string(i) + "," + string(j) + ") = ");
    end
end

disp("Original Matrix A:");
disp(A);
R = rref(A);

printf("\n");
disp("Reduced Row Echelon Form (RREF) of A:");
disp(R);
