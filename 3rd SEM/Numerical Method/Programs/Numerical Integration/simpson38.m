a = input('Enter the lower limit (a): ');
b = input('Enter the upper limit (b): ');
n = input('Enter the number of subintervals (n): ');

f = @(x) x^2 + 2;
h = (b - a) / n;
sum = f(a) + f(b);

for i = 1:n
    if mod(i, 3) == 1 || mod(i, 3) == 2
        sum = sum + 3 * f(a + i * h);
    else
        sum = sum + 2 * f(a + i * h);
    end
end

Simp38 = 3 * h / 8 * sum;

fprintf('Result of Simpson''s 3/8 Rule integration: %.6f\n', Simp38);
