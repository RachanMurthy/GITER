package calculator.scientific;

public class ScientificCalculator {
    public double squareRoot(double a) {
        if (a < 0) {
            throw new IllegalArgumentException("Cannot compute square root of a negative number");
        }
        return Math.sqrt(a);
    }

    public double power(double base, double exponent) {
        return Math.pow(base, exponent);
    }

    public double sin(double a) {
        return Math.sin(a);
    }

    public double cos(double a) {
        return Math.cos(a);
    }
}
