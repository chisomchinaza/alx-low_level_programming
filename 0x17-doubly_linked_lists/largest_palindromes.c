#include <stdio.h>
#include <stdlib.h>

/**
 * is_palindrome - Check if a number is a palindrome.
 * @num: The number to check.
 *
 * Return: 1 if num is a palindrome, 0 otherwise.
 */
int is_palindrome(int num)
{
    int original = num;
    int reversed = 0;
    int remainder;

    while (num != 0)
    {
        remainder = num % 10;
        reversed = reversed * 10 + remainder;
        num /= 10;
    }
    return (original == reversed);
}

/**
 * find_largest_palindrome - Find the largest palindrome product of two 3-digit numbers.
 *
 * Return: The largest palindrome product.
 */
int find_largest_palindrome(void)
{
    int i, j;
    int max_palindrome = 0;
    int product;

    for (i = 100; i < 1000; i++)
    {
        for (j = i; j < 1000; j++)
        {
            product = i * j;
            if (is_palindrome(product) && product > max_palindrome)
            {
                max_palindrome = product;
            }
        }
    }
    return max_palindrome;
}

/**
 * write_result - Write the result to a file named "102-result".
 * @result: The result to write to the file.
 */
void write_result(int result)
{
    FILE *file;

    file = fopen("102-result", "w");
    if (file == NULL)
    {
        perror("Error opening file");
        exit(EXIT_FAILURE);
    }
    fprintf(file, "%d", result);
    fclose(file);
}

/**
 * main - Entry point of the program.
 *
 * Return: Always 0 (Success).
 */
int main(void)
{
    int largest_palindrome;

    largest_palindrome = find_largest_palindrome();
    write_result(largest_palindrome);

    return 0;
}

