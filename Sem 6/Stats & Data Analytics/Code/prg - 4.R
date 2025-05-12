# Create matrices
A <- matrix(c(1, 2, 3, 4), nrow = 2, byrow = TRUE)
B <- matrix(c(5, 6, 7, 8), nrow = 2, byrow = TRUE)
C <- matrix(c(9, 10, 11, 12), nrow = 2, byrow = TRUE)

# Test Commutative Property: A*B = B*A
cat("Commutative Property:\n")
AB <- A %*% B
BA <- B %*% A
cat("\nA * B:\n"); print(AB)
cat("\nB * A:\n"); print(BA)
if (identical(AB, BA)) {
  cat("\nMatrix multiplication is commutative.\n\n")
} else {
  cat("\nMatrix multiplication is not commutative.\n\n")
}

# Test Associative Property: (A*B)*C = A*(B*C)
cat("Associative Property:\n")
left_associative <- (A %*% B) %*% C
right_associative <- A %*% (B %*% C)
cat("\n(A * B) * C:\n"); print(left_associative)
cat("\nA * (B * C):\n"); print(right_associative)
if (identical(left_associative, right_associative)) {
  cat("\nMatrix multiplication is associative.\n\n")
} else {
  cat("\nMatrix multiplication is not associative.\n\n")
}

# Test Distributive Property: A*(B+C) = A*B + A*C
cat("Distributive Property (A * (B + C) = A * B + A * C):\n")
left_distributive1 <- A %*% (B + C)
right_distributive1 <- (A %*% B) + (A %*% C)
cat("\nA * (B + C):\n"); print(left_distributive1)
cat("\nA * B + A * C:\n"); print(right_distributive1)
if (identical(left_distributive1, right_distributive1)) {
  cat("\nDistributive property (A * (B + C) = A * B + A * C) holds.\n\n")
} else {
  cat("\nDistributive property does not hold for A * (B + C) = A * B + A * C.\n\n")
}

# Test Distributive Property: (A+B)*C = A*C + B*C
cat("Distributive Property ((A + B) * C = A * C + B * C):\n")
left_distributive2 <- (A + B) %*% C
right_distributive2 <- (A %*% C) + (B %*% C)
cat("\n(A + B) * C:\n"); print(left_distributive2)
cat("\nA * C + B * C:\n"); print(right_distributive2)
if (identical(left_distributive2, right_distributive2)) {
  cat("\nDistributive property ((A + B) * C = A * C + B * C) holds.\n")
} else {
  cat("\nDistributive property does not hold for (A + B) * C = A * C + B * C.\n")
}
