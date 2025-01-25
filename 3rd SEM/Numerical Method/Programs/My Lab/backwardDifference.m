function interpolatedValue = backwardDifference(x, y, n, xValue)
    h = x(2) - x(1); % Assuming equal intervals
    
    %calculate the forward difference table
    diffTable = zeros(n,n);
    for i = 1:n
        diffTable(i,1) = y(i);
    end
    
    for j=2:n
        for i=n: -1  :j
            diffTable(i,j) = diffTable(i,j-1) - diffTable(i-1,j-1);
        end
    end
    
    %calculate the value using Newton's backward difference method
    result = diffTable(n,1);
    u = (xValue - x(n)) / h;
    
    for i=2:n
        term = 1.0;
        for j=1:i-1
            term = term * (u + j - 1);
        end
        term = term / (i - 1);
        result  = result + term * diffTable(n,i);
    end
    interpolatedValue = result;
end