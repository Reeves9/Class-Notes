clc;
clear all;
close all;
f = @(x) x^3 - x - 1;
a = input('Please enter first approximation a: ');
b = input('Please enter second approximation b: ');
tol = 0.00005;
if f(a)*f(b) > 0
    fprintf("Initial approximation doesn't bracket the root\n");
    return;
else
    while true
        c = (a*f(b) - b*f(a))/(f(b) - f(a));
        fprintf("%f \t %f \t %f \n",a, b, c);
        a = b;
        b = c;
        if abs(f(c)) < tol %abs(a-b) < tol
            break;
        end
    end
end
fprintf("The solution is %f\n", c);
