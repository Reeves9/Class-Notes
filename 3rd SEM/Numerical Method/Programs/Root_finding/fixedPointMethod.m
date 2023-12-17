function root = fixedPointMethod(g, x0, tol, maxIter)
    % g: the function obtained by rewriting f(x) = 0 as g(x) = x
    % x0: initial guess for the root
    % tol: tolerance (desired accuracy)
    % maxIter: maximum number of iterations
    
    % Initialize variables
    iter = 0;
    error = tol + 1;
    
    % Iteratively compute the root
    while error > tol && iter < maxIter
        % Calculate the new estimate of the root
        x1 = g(x0);
        
        % Calculate the error
        error = abs(x1 - x0);
        
        % Update the variables for the next iteration
        x0 = x1;
        iter = iter + 1;
    end
    
    % Check if the method converged
    if iter >= maxIter
        disp('Fixed-point method did not converge within the maximum number of iterations.');
    end
    
    % Return the root estimate
    root = x1;
end
