import numpy as np
import tensorflow as tf

# Prepare training data
inputs = np.array([[0, 0, 0], [0, 1, 0], [1, 0, 0], [1, 1, 0],
                   [0, 0, 1], [0, 1, 1], [1, 0, 1], [1, 1, 1]])
outputs = np.array([[0, 0], [1, 0], [1, 0], [0, 1],
                    [1, 0], [0, 1], [0, 1], [1, 1]])

# Create the neural network model
model = tf.keras.Sequential([
    tf.keras.layers.Dense(4, activation='relu', input_shape=(3,)),  # Hidden layer with 4 neurons
    tf.keras.layers.Dense(2, activation='sigmoid')  # Output layer with 2 neurons (Sum and Cout)
])

# Compile the model
model.compile(optimizer='adam', loss='binary_crossentropy', metrics=['accuracy'])

# Train the model
model.fit(inputs, outputs, epochs=1000, verbose=0)

# Test the model
test_inputs = np.array([[1, 1, 1]])  # Example test input
predictions = model.predict(test_inputs)
print(predictions)  # Should output [[0, 1]] for Sum=0 and Cout=1

# Use the trained model
def full_adder(a, b, cin):
  input_data = np.array([[a, b, cin]])
  prediction = model.predict(input_data)[0]
  return prediction[0], prediction[1]

# Example usage
sum, carry = full_adder(1, 1, 1)
print(f"Sum: {sum}, Carry: {carry}")
