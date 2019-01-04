import java.util.Stack;

public class CalculateExpression{
    public static void main(String[] args) {
        Stack<Character> stack = new Stack<Character>();
        Stack<Character> expStack = stack;
        Stack <Double> operandStack = new Stack<Double>();
        
        String Expression = args[0];

        for(int i=0;i<Expression.length();i++){
            if(Expression.charAt(i) == '+') expStack.push('+');
            else if (Expression.charAt(i) == '*') expStack.push('*');
            else if(Expression.charAt(i) == '-') expStack.push('-');
            else if(Expression.charAt(i) == '/') expStack.push('/');
            else if(Expression.charAt(i) == ')'){
                double val1 = operandStack.pop();
                double val2 = operandStack.pop();
                char op = expStack.pop();
                if(op == '+') operandStack.push(val1+val2);
                else if(op == '*') operandStack.push(val1*val2);
                else if(op == '/') operandStack.push(val2/val1);
                else if(op == '-') operandStack.push(val2-val1);
            }
            else if(Expression.charAt(i)!= ' ') operandStack.push(Double.valueOf(Expression.charAt((i))));

        }

        System.out.println("Result = " + operandStack.pop().toString());
    }
}