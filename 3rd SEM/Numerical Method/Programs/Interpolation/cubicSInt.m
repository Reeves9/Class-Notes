% Main script
n = input('Enter the number of data points: ');
x = zeros(1, n);
y = zeros(1, n);

disp('Enter the x and y values:');
for i = 1:n
    inputValues = input('','s');
    values = sscanf(inputValues, '%f %f');
    x(i) = values(1);
    y(i) = values(2);
end

% Call the cubicSplineInterpolation function to get coefficients
coefficients = cubicSplineInterpolation(x, y);

xValue = input('Enter the x value for interpolation: ');

% Interpolate using the cubic polynomials
interpolatedValue = zeros(1, n-1);
for i = 1:n-1
    if x(i) <= xValue && xValue <= x(i+1)
        dx = xValue - x(i);
        interpolatedValue = coefficients(i, 1) * dx^3 + coefficients(i, 2) * dx^2 + coefficients(i, 3) * dx + coefficients(i, 4);
        break;
    end
end

fprintf('Interpolated value at x = %.2f is %.4f\n', xValue, interpolatedValue);