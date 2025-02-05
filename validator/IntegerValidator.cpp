#include "IntegerValidator.h"

bool IntegerValidator::validateInteger(const std::string &input)
{
    if (input.empty())
    {
        throw std::invalid_argument("Input string is empty.");
    }

    size_t start = 0;
    if (input[0] == '-' || input[0] == '+')
    { // Check for optional sign
        start = 1;
    }

    for (size_t i = start; i < input.length(); ++i)
    {
        if (!std::isdigit(input[i]))
        {
            throw std::invalid_argument("Input string is not a valid integer: " + input);
        }
    }

    return true;
}