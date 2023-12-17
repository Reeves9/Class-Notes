function root = secantMethod(f, x0, x1, tol, maxIter)
    % f: the function for which you want to find the root
    % x0, x1: initial guesses for the root
    % tol: tolerance (desired accuracy)
    % maxIter: maximum number of iterations
    
    % Initialize variables
    iter = 0;
    error = tol + 1;
    
    % Iteratively compute the root
    while error > tol && iter < maxIter
        % Calculate the new estimate of the root
        x2 = x1 - (f(x1) * (x1 - x0)) / (f(x1) - f(x0));
        
        % Calculate the error
        error = abs(x2 - x1);
        
        % Update the variables for the next iteration
        x0 = x1;
        x1 = x2;
        iter = iter + 1;
    end
    
    % Check if the method converged
    if iter >= maxIter
        disp('Secant method did not converge within the maximum number of iterations.');
    end
    
    % Return the root estimate
    root = x2;
end
