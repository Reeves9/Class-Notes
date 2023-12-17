f = @(x) x^3-x-1;
x0 = 1;          % Initial guess 1
x1 = 2;          % Initial guess 2
tol = 1e-4;      % Tolerance
maxIter = 15;   % Maximum number of iterations

root = secantMethod(f, x0, x1, tol, maxIter);

disp(['Root: ' num2str(root)]);
