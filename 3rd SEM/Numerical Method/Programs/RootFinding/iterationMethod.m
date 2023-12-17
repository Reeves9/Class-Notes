clc;
clear all;
close all;
%% Objective is to solve x^3-x-1=0
%%%%%%% sin x = 10(x-1)
g = @(x) nthroot(x + 1, 3);% try g = @(x) x^3-1;

a = input('Please enter initial approximation a: ');
tol = 0.00005;

while true
    c = g(a);
    disp(c);
    if abs(c - a) < tol
        break;
    end
    a = c;
end

fprintf('The solution is %f\n', c);
