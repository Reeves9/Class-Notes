% Parameters
Lx = 1;          % Length of the domain in x-direction
Ly = 1;          % Length of the domain in y-direction
Nx = 50;         % Number of grid points in x-direction
Ny = 50;         % Number of grid points in y-direction

% Discretization
dx = Lx / (Nx - 1);
dy = Ly / (Ny - 1);
x = linspace(0, Lx, Nx);
y = linspace(0, Ly, Ny);

% Initialize solution matrix
u = zeros(Ny, Nx);

% Boundary conditions
u(1, :) = 0;     % Bottom boundary
u(Ny, :) = 0;    % Top boundary
u(:, 1) = 0;     % Left boundary
u(:, Nx) = 1;    % Right boundary

% Iterative solver (Gauss-Seidel)
maxIter = 1000;   % Maximum number of iterations
tolerance = 1e-5;  % Convergence tolerance

for iter = 1:maxIter
    u_old = u;
    
    for i = 2:Ny-1
        for j = 2:Nx-1
            u(i, j) = 0.25 * (u(i-1, j) + u(i+1, j) + u(i, j-1) + u(i, j+1));
        end
    end
    
    % Check for convergence
    if max(max(abs(u - u_old))) < tolerance
        break;
    end
end

% Plot the solution
[X, Y] = meshgrid(x, y);
contourf(X, Y, u, 20, 'LineColor', 'none');
colorbar;
xlabel('x');
ylabel('y');
title('Solution of 2D Poisson Equation');
