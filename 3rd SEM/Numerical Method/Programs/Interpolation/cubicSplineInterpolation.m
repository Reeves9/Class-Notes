function coefficients = cubicSplineInterpolation(x, y)
    n = length(x);
    h = diff(x);
    
    % Calculate second derivatives using the tridiagonal matrix algorithm
    alpha = diff(y) ./ h;
    beta = diff(y, 2) ./ h(2:end);
    diagonal = [1; 2 * (h(1:end-1) + h(2:end)); 1];
    A = spdiags([alpha; diagonal; beta], [-1, 0, 1], n-2, n-2);
    M = A \ [beta(1); 3 * (alpha(2:end) + alpha(1:end-1)); beta(end)];
    
    % Calculate coefficients for each cubic polynomial segment
    coefficients = zeros(n-1, 4);
    for i = 1:n-1
        coefficients(i, :) = [M(i), (M(i+1) - M(i)) / (3 * h(i)), ...
                              (y(i+1) - y(i)) / h(i) - h(i) * (M(i+1) + 2 * M(i)) / 3, y(i)];
    end
end