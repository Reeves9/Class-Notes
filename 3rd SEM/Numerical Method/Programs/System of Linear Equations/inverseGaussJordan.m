% Given matrix A
A = [3, 1, -1;
     1, -4, 2;
     -5, 2, 3];

% Number of rows/columns
n = size(A, 1);

% Augment the matrix with the identity matrix
augmented_matrix = [A, eye(n)];

% Gaussian elimination to transform A into upper triangular form
for col = 1:n-1
    % Partial Pivoting
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

% Back substitution to get the upper triangular form
for diag = n:-1:2
    for row = diag-1:-1:1
        factor = augmented_matrix(row, diag) / augmented_matrix(diag, diag);
        augmented_matrix(row, :) = augmented_matrix(row, :) - factor * augmented_matrix(diag, :);
    end
end

% Normalize diagonal elements to 1
for diag = 1:n
    augmented_matrix(diag, :) = augmented_matrix(diag, :) / augmented_matrix(diag, diag);
end

% Extract the inverse matrix
inverse_A = augmented_matrix(:, n+1:end);

disp('Inverse of A:');
disp(inverse_A);
