import java.util.HashSet;
import java.util.Set;

public class ContainsDuplicate {

    public static boolean containsDuplicate(int[] nums) {

        Set<Integer> unique = new HashSet<Integer>();

        for (int i = 0; i < nums.length; i++) {
            unique.add(nums[i]);
        }

        if (unique.size() == nums.length)
            return false;
        return true;

    }

    public static void main(String args[]) {
        int numbers[] = { 1, 2, 2, 3 };

        if (containsDuplicate(numbers)) {
            System.out.println("Duplicates present");
        } else
            System.out.println("Duplicates not present");
    }

}
