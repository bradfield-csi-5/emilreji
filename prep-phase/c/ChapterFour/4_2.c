#include <stdio.h>
#include <ctype.h>
// #include <math.h>

/* atof: convert string s to double */
double atof(char s[])
{
    double val, power, result;
    int i, sign;
    for (i = 0; isspace(s[i]); i++) /* skip white space */
        ;
    sign = (s[i] == '-') ? -1 : 1;
    if (s[i] == '+' || s[i] == '-')
        i++;
    for (val = 0.0; isdigit(s[i]); i++)
    {
        printf("%lf\n", val);
        val = 10.0 * val + (s[i] - '0');
        printf("%lf\n\n", val);
    }
    if (s[i] == '.')
        i++;
    for (power = 1.0; isdigit(s[i]); i++)
    {
        printf("%lf\n", val);
        val = 10.0 * val + (s[i] - '0');
        power *= 10;
        printf("%lf\n\n", val);
    }
    // printf("break: %d   %c\n",  i, s[i]);

    result = sign * val / power;

    if (s[i] == 'e' || s[i] == 'E')
    {
        i++;
    }
    else
    {
        return result;
    }
    printf("result: %lf\n", result);

    int expsign = (s[i] == '-') ? -1 : 1;
    if (s[i] == '+' || s[i] == '-')
        i++;

    int expval;
    for (expval = 0; isdigit(s[i]); i++)
    {
        expval = 10 * expval + (s[i] - '0');
    }
    if (expsign == -1)
    {
        while (expval-- > 0)
        {
            printf("result exponent: %lf\n", result);
            result = result / 10.0;
        }
    }
    else
    {
        while (expval-- > 0)
        {
            result = result * 10.0;
        }
    }

    // result = result * pow(expval, expsign); // failed

    return result;
}

int main()
{
    // char s[10] = "190.564";
    // char s[10] = "1.564";
    char s[20] = "190.564e-16";
    double result = atof(s);
    printf("%.20f\n", result);
}