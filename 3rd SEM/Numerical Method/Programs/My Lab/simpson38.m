a = input('Enter the lower limit (a):');
b = input('Enter the upper limit (b):');
n = input('Enter the number of intervals (n):');

f = @(x) 1 / (1 + x^2);
h = (b - a) / n;
sum = f(a) + f(b);

for i = 1 : n - 1
	if mod(i,3) == 1 || mod(i,3) == 2
		sum = sum + 3 * f(a + i * h);
	else
		sum = sum + 2 * f(a + i * h);
	end
end

Simp38 = ((3 * h) / 8) * sum;

fprintf('Result of simpson rule integration is: %.6f\n',Simp38);

