a = input('Enter the lower limit (a): ');
b = input('Enter the upper limit (b): ');
n = input('Enter the number of subintervals (n): ');

f = @(x) x^2 + 2; % @(x) x / ((x^2 + 2)^2);
h = (b - a) / n;
sum = f(a) + f(b);

for i = 1:n
    if mod(i, 2) == 1
        sum = sum + 4 * f(a + i * h);
    else
        sum = sum + 2 * f(a + i * h);
    end
end

result = h / 3 * sum;

fprintf('Result of Simpson''s Rule integration: %.6f\n', result);
