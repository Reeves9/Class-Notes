% Main function
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

xValue = input('Enter the x value for interpolation: ');
interpolatedValue = forwardDifference(x, y, n, xValue);
fprintf('Interpolated value at x = %.2f is %.4f\n', xValue, interpolatedValue);