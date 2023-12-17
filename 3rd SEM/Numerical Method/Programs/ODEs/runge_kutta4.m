% Define the function f(x, y)
f = @(x, y) x^2 - y;

% Input values
x = input('Enter x0: ');
y = input('Enter y0: ');
xp = input('Enter xp: ');
n = input('Enter n: ');

h = (xp - x) / n;

fprintf('............................................\n');
fprintf('k1\t\t k2\t\t k3\t\t k4\t\t y\n');
fprintf('............................................\n');

for i = 1:n
    k1 = h * f(x, y);
    k2 = h * f(x + h/2, y + k1/2);
    k3 = h * f(x + h/2, y + k2/2);
    k4 = h * f(x + h, y + k3);
    y = y + ((k1 + 2*k2 + 2*k3 + k4) / 6);
    x = x + h;
    fprintf('%f\t %f\t %f\t %f\t %f\n', k1, k2, k3, k4, y);
end

fprintf('..............................................\n');
