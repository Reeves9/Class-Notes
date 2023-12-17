a = input('Enter the lower limit (a): ');
b = input('Enter the upper limit (b): ');
n = input('Enter the number of subintervals (n): ');

f = @(x) 1 / (1 + x^2);
h = (b - a) / n;
sum = f(a) + f(b);

for i = 1:n
    sum = sum + 2 * f(a + i * h);
end

Trap = (h / 2) * sum;

fprintf('Result of Trapezoidal Rule integration: %.6f\n', Trap);
