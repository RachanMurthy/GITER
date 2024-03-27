package calculator;

import calculator.basic.BasicCalculator;
import calculator.scientific.ScientificCalculator;

public class Main {
    public static void main(String[] args) {
        BasicCalculator basicCalculator = new BasicCalculator();
        System.out.println("2 + 3 = " + basicCalculator.add(2, 3));

        ScientificCalculator scientificCalculator = new ScientificCalculator();
        System.out.println("Square root of 16 = " + scientificCalculator.squareRoot(16));

    }
}
