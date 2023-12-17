% Define your matrix
A = [3, -1, 0;
     -1, 2, -1;
     0, -1, 1];

% Number of dominant eigenvalues/vectors to compute
k = 1;

% Compute dominant eigenvalues and eigenvectors using eigs
options = struct('isreal', 1, 'issym', 1);
[V, D] = eigs(A, k, 'LM', options);

% Extract the dominant eigenvector
dominant_eigenvector = V(:, 1);

% Display the dominant eigenvector
fprintf('Dominant Eigenvector:\n');
disp(dominant_eigenvector);
