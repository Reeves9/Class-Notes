% Define the function f and its derivative df
f = @(x) x^3 - x - 1;
df = @(x) 3 * x^2-1;

% Call the newtonRaphsonMethod function
root = newtonRaphsonMethod(f, df, 1, 1e-6, 10);

% Display the root
fprintf('Estimated root: %f\n', root);

function root = newtonRaphsonMethod(f, df, x0, epsilon, maxIterations)
    % f: Function for which the root needs to be found
    % df: Derivative of the function f
    % x0: Initial guess for the root
    % epsilon: Tolerance for convergence
    % maxIterations: Maximum number of iterations
    
    % Initialize variables
    x = x0;
    iteration = 0;
    
    % Iterate until convergence or maximum iterations reached
    while abs(f(x)) > epsilon && iteration < maxIterations
        % Compute the next approximation of the root
        x = x - f(x) / df(x);
        
        % Increment the iteration counter
        iteration = iteration + 1;
    end
    
    % Check if convergence was achieved
    if abs(f(x)) <= epsilon
        fprintf('Convergence achieved after %d iterations\n', iteration);
    else
        fprintf('Maximum iterations reached\n');
    end
    
    % Return the estimated root
    root = x;
end

