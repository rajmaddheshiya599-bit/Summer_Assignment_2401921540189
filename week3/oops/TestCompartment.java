import java.util.Random;

abstract class Compartment {
    abstract String notice();
}

class FirstClass extends Compartment {
    String notice() {
        return "First Class Compartment";
    }
}

class Ladies extends Compartment {
    String notice() {
        return "Ladies Compartment";
    }
}

class General extends Compartment {
    String notice() {
        return "General Compartment";
    }
}

class Luggage extends Compartment {
    String notice() {
        return "Luggage Compartment";
    }
}

public class TestCompartment {

    static Compartment createCompartment(int n) {
        switch (n) {
            case 0:
                return new FirstClass();
            case 1:
                return new Ladies();
            case 2:
                return new General();
            default:
                return new Luggage();
        }
    }

    public static void main(String[] args) {
        Random r = new Random();

        for (int i = 0; i < 10; i++) {
            Compartment c = createCompartment(r.nextInt(4));
            System.out.println("Compartment " + (i + 1) + ": " + c.notice());
        }
    }
}