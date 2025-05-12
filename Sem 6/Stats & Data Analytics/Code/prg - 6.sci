clc;
clear;
disp("Amit Singhal - 11614802722")

// Prompt user for function input
disp("Enter the function in terms of x (e.g., x^2 + 3*x + 5): ");
func_str = input("Function f(x) = ", "s");

// Define symbolic variable x as a polynomial
x = poly(0, "x");

// Convert input function string into a polynomial expression
func = evstr(func_str);

// Compute first and second derivatives
first_derivative = derivat(func);
second_derivative = derivat(first_derivative);

disp("First Derivative f(x): " + string(first_derivative));
disp("Second Derivative f(x): " + string(second_derivative));

// Generate x values from -10 to 10
x_vals = linspace(-10, 10, 100);

// Ensure function and derivatives are properly evaluated
y_vals = horner(func, x_vals');
y_first_derivative = horner(first_derivative, x_vals');
y_second_derivative = horner(second_derivative, x_vals');

// Create the plot
clf;
plot(x_vals, y_vals, "b", "LineWidth", 2);

// Disable auto-clear so that new plots add to the current graph
a = gca();
a.auto_clear = "off";

plot(x_vals, y_first_derivative, "r", "LineWidth", 2);
plot(x_vals, y_second_derivative, "g", "LineWidth", 2);

// Add labels and title
xlabel("x");
ylabel("Function Values");
title("Function and its Derivatives");

// Create legend for identification
legend(["f(x) - Original", "f(x) First Derivative", "f(x) Second Derivative"]);

// Show grid
grid on;
