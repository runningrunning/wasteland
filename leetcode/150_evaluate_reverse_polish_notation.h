int evalRPN(char** tokens, int tokensSize)
{
    int stack_c = 0;
    int stack_n = 256;
    int* stack = malloc(sizeof(int) * stack_n);

    for(int i = 0; i < tokensSize; i ++)
    {
        char* t = tokens[i];
        char c = t[0];

        if (t[1] == '\0' && (c == '+' || c == '-' || c == '*' || c == '/'))
        {
            if (stack_c < 2)
                return 0;

            int a = stack[stack_c - 2];
            int b = stack[stack_c - 1];
            switch(c)
            {
            case '+':
                stack[stack_c - 2] = a + b;
                break;
            case '-':
                stack[stack_c - 2] = a - b;
                break;
            case '*':
                stack[stack_c - 2] = a * b;
                break;
            case '/':
                stack[stack_c - 2] = a / b;
                break;
            }
            stack_c -= 1;
        }
        else
        {
            if (stack_c >= stack_n)
            {
                stack_n += 256;
                stack = realloc(stack, sizeof(int) * stack_n);
            }
            stack[stack_c ++] = atol(t);
        }
    }
    return stack[0];
}
