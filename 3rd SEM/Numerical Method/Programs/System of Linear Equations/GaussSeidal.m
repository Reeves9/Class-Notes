%%% 3x + y - z = 1
%%% x - 4y + 2z = -2
%%% -5x + 2y + 3z = 3


% Coefficient matrix A
A = [3, 1, -1;
     1, -4, 2;
     -5, 2, 3];

% Right-hand side vector b
b = [1; -2; 3];

% Initial guess
x0 = [0; 0; 0];

% Maximum number of iterations
maxIter = 100;

% Tolerance for convergence
tolerance = 1e-6;

x = x0;
for k = 1:maxIter
    x_prev = x;
    
    for i = 1:length(x)
        sigma = 0;
        
        for j = 1:length(x)
            if j ~= i
                sigma = sigma + A(i, j) * x(j);
            end
        end
        
        x(i) = (b(i) - sigma) / A(i, i);
    end
    
    % Check for convergence
    if norm(x - x_prev, inf) < tolerance
        break;
    end
end

% Display the solution
fprintf('Solution: x = %f, y = %f, z = %f\n', x(1), x(2), x(3));
fprintf('Number of iterations: %d\n', k);
