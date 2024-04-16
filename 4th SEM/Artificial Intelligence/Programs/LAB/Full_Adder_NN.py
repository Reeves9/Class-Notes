import numpy as np

def sigmoid(x):
    return 1 / (1 + np.exp(-x))

def sigmoid_derivative(x):
    return x * (1 - x)

class NeuralNetwork:
    def __init__(self):
        np.random.seed(1)
        self.synaptic_weights = 2 * np.random.random((2, 2)) - 1

    def train(self, training_inputs, training_outputs, iterations):
        for iteration in range(iterations):
            output = self.think(training_inputs)
            error = training_outputs - output
            adjustment = np.dot(training_inputs.T, error * sigmoid_derivative(output))
            self.synaptic_weights += adjustment

    def think(self, inputs):
        return sigmoid(np.dot(inputs, self.synaptic_weights))

training_inputs = np.array([[0, 0],
                            [0, 1],
                            [1, 0],
                            [1, 1]])

training_outputs = np.array([[0, 0],
                             [0, 1],
                             [0, 1],
                             [1, 0]])

neural_network = NeuralNetwork()
neural_network.train(training_inputs, training_outputs, iterations=10000)

print("Synaptic weights after training:")
print(neural_network.synaptic_weights)

print("New situation:")
new_input = np.array([1, 0])
print("Input:", new_input)
print("Output:", neural_network.think(new_input))
