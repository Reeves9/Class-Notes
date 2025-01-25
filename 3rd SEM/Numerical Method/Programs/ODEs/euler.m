% Define the function f(x, y)
f = @(x, y) x^2 - y;

% Input values
x = input('Enter x0: ');
y = input('Enter y0: ');
xp = input('Enter xp: ');
n = input('Enter n: ');

h = (xp - x) / n;

fprintf('...........................................\n');
fprintf('y\n');
fprintf('...........................................\n');

for i = 1:n
    y = y + h * f(x, y);
    x = x + h;
    fprintf('%f\n', y);
end

fprintf('............................................\n');
