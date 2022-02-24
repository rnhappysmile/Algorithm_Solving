import java.util.Stack;

/*
 * https://leetcode.com/problems/daily-temperatures/
 */

public class DailyTemperatures {
    public static void main(String[] args) {
        int[] testCase = {73,74,75,71,69,72,76,73};

        int[] result = dailyTemperatures(testCase);
        for(int i : result)
            System.out.println(i);
    }

    public static int[] dailyTemperatures(int[] temperatures) {
        int temperaturesResult[] = new int[temperatures.length];
        Stack<Integer> stack = new Stack<Integer>();

        for(int i = temperatures.length - 1; i >= 0; i--) {

            while(!stack.empty() && temperatures[i] >= temperatures[stack.peek()])
                stack.pop();

            if(!stack.isEmpty())
                temperaturesResult[i] = stack.peek() - i;

            stack.push(i);
        }

        return temperaturesResult;
    }
}
