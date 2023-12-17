% Define parameters
L = 1;          % Length of the spatial domain
T = 0.5;        % Total simulation time
Nx = 100;       % Number of spatial grid points
Nt = 500;       % Number of time steps
alpha = 0.01;   % Thermal diffusivity

dx = L / (Nx - 1);
dt = T / Nt;

x = linspace(0, L, Nx);
u = sin(pi * x);  % Initial condition

% Time-stepping loop
for n = 1:Nt
    unew = u;
    for i = 2:Nx-1
        unew(i) = u(i) + alpha * dt / dx^2 * (u(i-1) - 2 * u(i) + u(i+1));
    end
    u = unew;
end

% Plot the solution
plot(x, u);
xlabel('Position (x)');
ylabel('Temperature (u)');
title('Solution of 1D Heat Equation using FTCS');
