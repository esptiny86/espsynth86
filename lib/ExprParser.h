#ifndef EXPRPARSER_H
#define EXPRPARSER_H


const char * expressionToParse = "(1000*5&1000>7)|(1000*3&1000>10)";

char peek()
{
    return *expressionToParse;
}

char get()
{
    return *expressionToParse++;
}

int expression();

int number()
{
    int result = get() - '0';
    while (peek() >= '0' && peek() <= '9')
    {
        result = 10*result + get() - '0';
    }
    return result;
}

int factor()
{
    if (peek() >= '0' && peek() <= '9')
        return number();
    else if (peek() == '(')
    {
        get(); // '('
        int result = expression();
        get(); // ')'
        return result;
    }
    else if (peek() == '-')
    {
        get();
        return -factor();
    }
    return 0; // error
}

int term()
{
    int result = factor();
    while (peek() == '*' || peek() == '/' || peek() == '|')
    {
        char g = get();
        if (g == '*')
            result *= factor();
        else if (g == '|')
            result =  result | factor();
        else
            result /= factor();
    }

    return result;
}

int expression()
{
    int result = term();
    while (peek() == '+' || peek() == '-'  || peek() == '>'  || peek() == '<' || peek() == '&')
    {
        char g = get();
        if (g == '+')
            result += term();
        else if (g == '>')
            result =  result >> term();
        else if (g == '<')
            result =  result << term();
        else if (g == '&')
            result =  result & term();
        else
            result -= term();
    }


    return result;
}




#endif // EXPRPARSER_H
