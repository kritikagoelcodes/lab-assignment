
    import java.util.Scanner;

public class lab {
    static int[] arr = new int[100];
    static int n = 0; // current size

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int choice;
        do {
            System.out.println("\n--- MENU ---");
            System.out.println("1. CREATE");
            System.out.println("2. DISPLAY");
            System.out.println("3. INSERT");
            System.out.println("4. DELETE");
            System.out.println("5. LINEAR SEARCH");
            System.out.println("6. EXIT");
            System.out.print("Enter choice: ");
            choice = sc.nextInt();

            switch (choice) {
                case 1: create(sc); break;
                case 2: display(); break;
                case 3: insert(sc); break;
                case 4: delete(sc); break;
                case 5: linearSearch(sc); break;
                case 6: System.out.println("Exiting..."); break;
                default: System.out.println("Invalid choice!");
            }
        } while (choice != 6);
        sc.close();
    }

    static void create(Scanner sc) {
        System.out.print("Enter number of elements: ");
        n = sc.nextInt();
        System.out.println("Enter " + n + " elements:");
        for (int i = 0; i < n; i++) {
            arr[i] = sc.nextInt();
        }
    }

    static void display() {
        if (n == 0) {
            System.out.println("Array is empty!");
            return;
        }
        System.out.print("Array: ");
        for (int i = 0; i < n; i++) {
            System.out.print(arr[i] + " ");
        }
        System.out.println();
    }

    static void insert(Scanner sc) {
        if (n == arr.length) {
            System.out.println("Array is full!");
            return;
        }
        System.out.print("Enter position (1 to " + (n + 1) + "): ");
        int pos = sc.nextInt();
        if (pos < 1 || pos > n + 1) {
            System.out.println("Invalid position!");
            return;
        }
        System.out.print("Enter number to insert: ");
        int num = sc.nextInt();

        for (int i = n - 1; i >= pos - 1; i--) {
            arr[i + 1] = arr[i];
        }
        arr[pos - 1] = num;
        n++;
        System.out.println("Element inserted!");
    }

    static void delete(Scanner sc) {
        if (n == 0) {
            System.out.println("Array is empty!");
            return;
        }
        System.out.print("Enter position (1 to " + n + "): ");
        int pos = sc.nextInt();
        if (pos < 1 || pos > n) {
            System.out.println("Invalid position!");
            return;
        }
        System.out.println("Deleted element: " + arr[pos - 1]);
        for (int i = pos - 1; i < n - 1; i++) {
            arr[i] = arr[i + 1];
        }
        n--;
    }

    static void linearSearch(Scanner sc) {
        if (n == 0) {
            System.out.println("Array is empty!");
            return;
        }
        System.out.print("Enter element to search: ");
        int key = sc.nextInt();
        for (int i = 0; i < n; i++) {
            if (arr[i] == key) {
                System.out.println("Element found at position " + (i + 1));
                return;
            }
        }
        System.out.println("Element not found!");
    }
}

}
