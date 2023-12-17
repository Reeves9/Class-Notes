function interpolatedValue = forwardDifference(x, y, n, xValue)
    h = x(2) - x(1); % Assuming equal intervals

    % Calculate the forward difference table
    diffTable = zeros(n, n);
    for i = 1:n
        diffTable(i, 1) = y(i);
    end

    for j = 2:n
        for i = 1:n - j + 1
            diffTable(i, j) = diffTable(i + 1, j - 1) - diffTable(i, j - 1);
        end
    end

    % Calculate the value using Newton's forward difference formula
    result = diffTable(1, 1);
    u = (xValue - x(1)) / h;

    for i = 2:n
        term = 1.0;
        for j = 1:i - 1
            term = term * (u - j + 1);
        end
        term = term / (i - 1);
        result = result + term * diffTable(1, i);
    end

    interpolatedValue = result;
end