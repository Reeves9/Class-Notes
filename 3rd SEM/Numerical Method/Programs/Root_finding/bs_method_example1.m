clc;
clear all;

% Define the equation
f = @(x) x^3 - x - 1;
% Set the interval [a, b] where the root is expected
a = 0;
b = 2;
% Set the tolerance and maximum number of iterations
tolerance = 1e-4;
max_iterations = 10;

fa = f(a);
fb = f(b);
if sign(fa) >= sign(fb)
    error('Function must have opposite signs at interval endpoints.');
end
iteration = 0;
while abs(b - a) > tolerance && iteration < max_iterations
    c = (a + b) / 2;
    fc = f(c);
    if fc == 0
        % The exact root is found
        break;
    elseif sign(fa) * sign(fc) < 0
        % Root is in the left subinterval [a, c]
        b = c;
        fb = fc;
    else
        % Root is in the right subinterval [c, b]
        a = c;
        fa = fc;
    end
    iteration = iteration + 1;
end
root = (a + b) / 2;
fprintf('Approximate root: %f\n', root);
