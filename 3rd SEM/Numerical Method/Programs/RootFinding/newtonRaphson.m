clc;
clear all;
close all;
f = @(x) x^3 - x - 1;
g = @(x) 3*x^2 - 1;

a = input('Please enter initial approximation a: ');
tol = 0.00005;

while true
    c = a - f(a) / g(a);
    disp(c);
    a = c;
    if abs(f(c)) < tol
        break;
    end
end

fprintf('The solution is %f\n', c);
