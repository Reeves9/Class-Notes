clc;
clear all;

function root = bisection_method(f, a, b, tolerance, max_iterations)
    if f(a) * f(b) >= 0
        disp('The function may not have a root within the given interval.')
        root = NaN;
        return;
    end

    iteration = 1;
    while iteration <= max_iterations
        c = (a + b) / 2;
        if f(c) == 0 || abs(b - a) / 2 < tolerance
            root = c;
            return;
        end

        if f(c) * f(a) < 0
            b = c;
        else
            a = c;
        end

        iteration = iteration + 1;
    end

    disp('The method did not converge within the maximum number of iterations.');
    root = NaN;
end




