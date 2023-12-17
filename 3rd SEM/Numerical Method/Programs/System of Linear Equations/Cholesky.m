% Coefficient matrix A
A = [4, 10, 8;
     10, 26, 26;
     8, 26, 61];

% Right-hand side vector b
b = [44; 128; 214];

% Cholesky decomposition
L = chol(A, 'lower');

% Solve Ly = b using forward substitution
y = L \ b;

% Solve L'x = y using back substitution
x = L' \ y;

% Display the solution
fprintf('Solution: x = %f, y = %f, z = %f\n', x(1), x(2), x(3));
