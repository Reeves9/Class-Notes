import numpy as np

def sigmoid(x):
  """Sigmoid activation function."""
  return 1 / (1 + np.exp(-x))

def forward_pass(weights, biases, inputs):
  """Performs a single forward pass through the network."""
  hidden_layer = sigmoid(np.dot(inputs, weights[0]) + biases[0])
  output = sigmoid(np.dot(hidden_layer, weights[1]) + biases[1])
  return hidden_layer, output

def backpropagation(weights, biases, inputs, target, learning_rate):
  """Calculates and updates weights and biases using backpropagation."""
  hidden_layer, output = forward_pass(weights, biases, inputs)

  # Calculate errors
  output_error = output - target
  hidden_error = np.dot(output_error, weights[1].T) * hidden_layer * (1 - hidden_layer)

  # Update weights and biases
  weights[1] -= learning_rate * np.dot(hidden_layer.T, output_error)
  biases[1] -= learning_rate * output_error.sum()

  weights[0] -= learning_rate * np.dot(inputs.T, hidden_error)
  biases[0] -= learning_rate * hidden_error.sum()

def full_adder(inputs, weights, biases, learning_rate, epochs):
  """Trains and uses the neural network for full addition."""
  for _ in range(epochs):
    for input, target in zip(inputs, targets):
      backpropagation(weights, biases, input, target, learning_rate)

  hidden_layer, output = forward_pass(weights, biases, inputs[-1])
  return output

# Initialize weights and biases with random values
np.random.seed(42)
weights = [np.random.rand(3, 4), np.random.rand(4, 2)]
biases = [np.random.rand(4), np.random.rand(2)]

# Define training data and target outputs
inputs = np.array([[0, 0, 0], [0, 1, 0], [1, 0, 0], [1, 1, 0],
                   [0, 0, 1], [0, 1, 1], [1, 0, 1], [1, 1, 1]])
targets = np.array([[0, 0], [1, 0], [1, 0], [0, 1],
                   [1, 0], [0, 1], [0, 1], [1, 1]])

# Train the network
full_adder(inputs, weights, biases, 0.01, 1000)

# Test the network
test_input = np.array([1, 1, 1])
prediction = full_adder(test_input, weights, biases, 0.01, 1)
print(f"Sum: {prediction[0]}, Carry: {prediction[1]}")
