coefficients = [1, -3, 2, 4]; % coefficients of the polynomial: x^3 - 3x^2 + 2x+4
x = 3; % the value at which to evaluate the polynomial

result = hornerMethod(coefficients, x);

disp(['Result: ' num2str(result)]);
