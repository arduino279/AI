#define N 10
float x[N] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
float y[N] = {2, 4, 5, 7, 9, 11, 12, 15, 16, 18};
float a = 0;
float b = 0;
float alpha = 0.01;

void setup() {
  Serial.begin(9600);
}

void train_model() {
  while (true) {
    float error = 0;
    for (int i = 0; i < N; i++) {
      error += pow(y[i] - (a * x[i] + b), 2);
    }
    error /= N;
    Serial.print("Generating Output ... ");
    Serial.println(b);
    if (error < 0.01) {
      break;
    }
    float da = 0;
    float db = 0;
    for (int i = 0; i < N; i++) {
      da += -2 * x[i] * (y[i] - (a * x[i] + b));
      db += -2 * (y[i] - (a * x[i] + b));
    }
    da /= N;
    db /= N;
    a = a - alpha * da;
    b = b - alpha * db;
  }
}

float predict(float x) {
  return a * x + b;
}

void loop() {
  train_model();
  Serial.print("Input: ");
  while (Serial.available() == 0) {
    
  }
  float x_new = Serial.parseFloat();
  float y_new = predict(x_new);
  Serial.print("Output: ");
  Serial.println(y_new);
  while (Serial.available() > 0) {
    Serial.read();
  }
}
