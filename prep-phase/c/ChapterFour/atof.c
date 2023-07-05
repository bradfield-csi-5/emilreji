#include <stdio.h>
#include <ctype.h>

/* atof: convert string s to double */
double atof(char s[])
{
    double val, power;
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
    return sign * val / power;
}

int main()
{
    char s[10] = "190.564";
    // char s[10] = "1.564";
    double result = atof(s);
    printf("%lf\n", result);
}