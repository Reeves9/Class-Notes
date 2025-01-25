% Main script
n = input('Enter the number of data points: ');
x = zeros(1, n);
y = zeros(1, n);

disp('Enter the x and y values:');%fprintf
for i = 1:n
    inputValues = input('','s');
    values = sscanf(inputValues, '%f %f');
    %% The format specifier '%f %f' indicates that the input should be parsed 
    %% as two floating-point numbers separated by a space
    x(i) = values(1);
    y(i) = values(2);
end

xValue = input('Enter the x value for interpolation: ');
interpolatedValue = backwardDifference(x, y, n, xValue);
fprintf('Interpolated value at x = %.2f is %.4f\n', xValue, interpolatedValue);
