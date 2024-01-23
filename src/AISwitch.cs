using System;

class Program {
    const int N = 10;
    static float[] x = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    static float[] y = {2, 4, 5, 7, 9, 11, 12, 15, 16, 18};
    static float a = 0;
    static float b = 0;
    static float alpha = 0.01f;

    static void train_model() {
        while (true) {
            float error = 0;
            for (int i = 0; i < N; i++) {
                error += (float)Math.Pow(y[i] - (a * x[i] + b), 2);
            }
            error /= N;
            Console.WriteLine("Generating Output ... " + b);
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

    static float predict(float x) {
        return a * x + b;
    }

    static void Main(string[] args) {
        train_model();
        Console.Write("Input: ");
        float x_new = float.Parse(Console.ReadLine());
        float y_new = predict(x_new);
        Console.WriteLine("Output: " + y_new);
    }
}
