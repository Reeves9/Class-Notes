% Coefficient matrix A
A = [3, 1, -1;
     1, -4, 2;
     -5, 2, 3];

% Right-hand side vector b
b = [1; -2; 3];

% Augmented matrix [A | b]
augmented_matrix = [A, b];

% Number of equations/variables
n = size(A, 1);

% Gaussian elimination
for col = 1:n-1
    % Partial Pivoting: Find the row with the maximum value in the current column
    [~, max_row] = max(abs(augmented_matrix(col:n, col)));
    max_row = max_row + col - 1;
    
    % Swap rows
    augmented_matrix([col, max_row], :) = augmented_matrix([max_row, col], :);
    
    % Elimination
    for row = col+1:n
        factor = augmented_matrix(row, col) / augmented_matrix(col, col);
        augmented_matrix(row, col:end) = augmented_matrix(row, col:end) - factor * augmented_matrix(col, col:end);
    end
end

% Back substitution
x = zeros(n, 1);
for row = n:-1:1
    x(row) = (augmented_matrix(row, end) - augmented_matrix(row, row+1:n) * x(row+1:n)) / augmented_matrix(row, row);
end

% Display the solution
fprintf('Solution: x = %f, y = %f, z = %f\n', x(1), x(2), x(3));
