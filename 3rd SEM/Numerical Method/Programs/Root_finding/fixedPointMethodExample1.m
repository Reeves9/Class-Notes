g = @(x) sqrt(1 + 1/x);
x0 = 1;          % Initial guess
tol = 1e-6;      % Tolerance
maxIter = 15;   % Maximum number of iterations

root = fixedPointMethod(g, x0, tol, maxIter);

disp(['Root: ' num2str(root)]);

