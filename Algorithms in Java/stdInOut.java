import java.util.*;

public class stdInOut {

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        String myString = scanner.next();
        int myInt = scanner.nextInt();
        scanner.close();

        System.out.println("myString is: " + myString);
System.out.println("myInt is: " + myInt);
    }
}