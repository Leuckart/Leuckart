import java.util.*;

/**************************************************
 * @File Name: InputTest.java
 * @Author: Leuckart
 * @Time: 2020-05-28 15:40
 **************************************************/

public class InputTest {
	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);

		// get first input
		System.out.print("What is your name? ");
		String name = in.nextLine();

		// get second input
		System.out.print("How old are you? ");
		int age = in.nextInt();

		// display output on console
		System.out.println("Hello, " + name + ". Next year, you'll be " + (age + 1));
	}
}
