function result = hornerMethod(coefficients, x)
    % coefficients: a vector of coefficients of the polynomial in descending order
    % x: the value at which to evaluate the polynomial
    
    n = length(coefficients); % degree of the polynomial
    result = coefficients(1); % initialize the result with the highest degree coefficient
    
    % Evaluate the polynomial using Horner's method
    for i = 2:n
        result = result * x + coefficients(i);
    end
end
