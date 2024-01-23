// Define the number of data points
#define N 10

// Define the input and output data arrays
float x[N] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10}; // Input values
float y[N] = {2, 4, 5, 7, 9, 11, 12, 15, 16, 18}; // Output values

// Define the model parameters
float a = 0; // Slope of the line
float b = 0; // Intercept of the line

// Define the learning rate
float alpha = 0.01;

// Define the serial baud rate
#define BAUD_RATE 9600

// Initialize the serial communication
void setup() {
  Serial.begin(BAUD_RATE);
}

// Train the model
void train_model() {
  // Loop until the model converges
  while (true) {
    // Calculate the error for the current model
    float error = 0;
    for (int i = 0; i < N; i++) {
      error += pow(y[i] - (a * x[i] + b), 2);
    }
    error /= N;

    // Print the error and the model parameters
    Serial.print("Error: ");
    Serial.println(error);
    Serial.print("a: ");
    Serial.println(a);
    Serial.print("b: ");
    Serial.println(b);

    // Check if the error is small enough
    if (error < 0.01) {
      break;
    }

    // Update the model parameters using gradient descent
    float da = 0; // Partial derivative of error with respect to a
    float db = 0; // Partial derivative of error with respect to b
    for (int i = 0; i < N; i++) {
      da += -2 * x[i] * (y[i] - (a * x[i] + b));
      db += -2 * (y[i] - (a * x[i] + b));
    }
    da /= N;
    db /= N;

    a = a - alpha * da; // Update a
    b = b - alpha * db; // Update b
  }
}

// Predict the output for a new input
float predict(float x) {
  return a * x + b; // Use the line equation
}

// Main loop
void loop() {
  // Train the model once
  train_model();

  // Read a new input value from the serial monitor
  Serial.print("Enter a new input value: ");
  while (Serial.available() == 0) {
    // Wait for user input
  }
  float x_new = Serial.parseFloat(); // Parse the input value

  // Predict the output value for the new input
  float y_new = predict(x_new);

  // Print the prediction
  Serial.print("The predicted output value is: ");
  Serial.println(y_new);

  // Clear the serial buffer
  while (Serial.available() > 0) {
    Serial.read();
  }
}
