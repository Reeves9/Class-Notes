% Coefficient matrix A
A = [3, 1, -1;
     1, -4, 2;
     -5, 2, 3];

% Right-hand side vector b
b = [1; -2; 3];

% Augment the matrix A with the right-hand side vector b
augmented_matrix = [A, b];

% Number of equations/variables
n = size(A, 1);

% Gauss-Jordan elimination
for col = 1:n
    % Scale the current row to make the pivot element 1
    factor = augmented_matrix(col, col);
    augmented_matrix(col, :) = augmented_matrix(col, :) / factor;
    
    % Eliminate non-pivot elements in other rows
    for row = 1:n
        if row ~= col
            factor = augmented_matrix(row, col);
            augmented_matrix(row, :) = augmented_matrix(row, :) - factor * augmented_matrix(col, :);
        end
    end
end

% Extract the solution from the augmented matrix
solution = augmented_matrix(:, n+1);

% Display the solution
fprintf('Solution: x = %f, y = %f, z = %f\n', solution(1), solution(2), solution(3));
