% Example function
f = @(x) 1 / (1 + x^2);
a = input('Enter the lower limit (a): ');
b = input('Enter the upper limit (b): ');
n = input('Enter the number of iterations (n): ');

% Call the rombergIntegration function to calculate the result
result = rombergIntegration(f, a, b, n);

fprintf('Result of Romberg integration: %.6f\n', result);