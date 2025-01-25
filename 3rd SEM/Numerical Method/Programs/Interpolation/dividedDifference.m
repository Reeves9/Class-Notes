function interpolatedValue = dividedDifference(x, y, n, xValue)
    diffTable = zeros(n, n);
    
    % Initialize the first column with y-values
    for i = 1:n
        diffTable(i, 1) = y(i);
    end
    
    % Calculate the divided difference table
    for j = 2:n
        for i = 1:n - j + 1
            diffTable(i, j) = (diffTable(i + 1, j - 1) - diffTable(i, j - 1)) / (x(i + j - 1) - x(i));
        end
    end
    
    % Perform interpolation using divided differences
    result = diffTable(1, 1);
    term = 1.0;
    
    for j = 2:n
        term = term * (xValue - x(j - 1));
        result = result + term * diffTable(1, j);
    end
    
    interpolatedValue = result;
end