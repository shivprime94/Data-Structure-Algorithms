import java.util.*;

class nextPermutation {
  public static void swap(int[] arr, int i, int j) {
    int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
  }

  public static void reverse(int[] arr, int i, int j) {
    while (i < j) {
      swap(arr, i, j);
      i++;
      j--;
    }
  }

  public static void nextPermutation(int[] nums) {
    if (nums == null || nums.length <= 1)
      return;
    int i = nums.length - 2;
    while (i >= 0 && nums[i] >= nums[i + 1])
      i--;
    if (i >= 0) {
      int j = nums.length - 1;
      while (nums[j] <= nums[i])
        j--;
      swap(nums, i, j);
    }
    reverse(nums, i + 1, nums.length - 1);
  }

  public static void main(String[] args) {
    Scanner sc = new Scanner(System.in);
    int n = sc.nextInt();
    int[] arr = new int[n];
    for (int i = 0; i < n; i++) {
      arr[i] = sc.nextInt();
    }
    nextPermutation(arr);
    for (int i = 0; i < n; i++) {
      System.out.print(arr[i]);
    }
  }
}