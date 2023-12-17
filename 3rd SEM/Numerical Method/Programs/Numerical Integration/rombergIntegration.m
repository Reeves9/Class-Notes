function result = rombergIntegration(f, a, b, n)
    h = (b - a) ./ 2.^(0:n-1);
    R = zeros(n, n);
    
    R(1, 1) = (h(1) / 2) * (f(a) + f(b));
    for j = 2:n
        sum = 0;
        for i = 1:2^(j-2)
            sum = sum + f(a + (2*i-1) * h(j));
        end
        R(j, 1) = 0.5 * R(j-1, 1) + h(j) * sum;
    end
    
    for k = 2:n
        for j = k:n
            R(j, k) = R(j, k-1) + (R(j, k-1) - R(j-1, k-1)) / (4^(k-1) - 1);
        end
    end
    
    result = R(n, n);
end