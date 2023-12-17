% Define the system of first-order equations
f = @(x, u) [u(2); -2*u(2) - 2*u(1)];

% Define the initial conditions: y(0) = 1, y'(0) = 0
initial_conditions = [1; 0];

% Define the interval of integration
xspan = [0, 10];

% Solve the system of equations using ode45
[x, u] = ode45(f, xspan, initial_conditions);

% Extract the solutions y and y' from the solution vector u
y = u(:, 1);
y_prime = u(:, 2);

% Plot the solutions
figure;
subplot(2, 1, 1);
plot(x, y, 'b');
xlabel('x');
ylabel('y');
title('Solution of y(x)');
grid on;

subplot(2, 1, 2);
plot(x, y_prime, 'r');
xlabel('x');
ylabel("y'");
title("Solution of y'(x)");
grid on;
