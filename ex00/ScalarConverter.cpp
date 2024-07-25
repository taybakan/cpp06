#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter(void) {}

ScalarConverter::ScalarConverter(ScalarConverter const &src)
{
	*this = src;
}

ScalarConverter::~ScalarConverter(void) {}

ScalarConverter &ScalarConverter::operator=(ScalarConverter const &rhs)
{
	(void)rhs;
	return *this;
}

void ScalarConverter::convertChar(std::string str)
{
	std::cout << "char: \'" << str[0] << "\'" << std::endl;
	std::cout << "int: " << static_cast<int>(str[0]) << std::endl;
	std::cout << "float: " << static_cast<float>(str[0]) << ".0f" << std::endl;
	std::cout << "double: " << static_cast<double>(str[0]) << ".0" << std::endl;
}

void ScalarConverter::convertInt(std::string str)
{
	int	i = std::stoi(str);
	if (i >= 32 && i < 127)
		std::cout << "char: \'" << static_cast<char>(i) << "\'" << std::endl;
	else
		std::cout << "char: " << "impossible" << std::endl;
	std::cout << "int: " << i << std::endl;
	std::cout << "float: " << static_cast<float>(i) << ".0f" << std::endl;
	std::cout << "double: " << static_cast<double>(i) << ".0" << std::endl;
}

void ScalarConverter::convertFloat(std::string str)
{
	float	i = std::stof(str);
	if (i >= 32 && i < 127)
		std::cout << "char: \'" << static_cast<char>(i) << "\'" << std::endl;
	else
		std::cout << "char: " << "impossible" << std::endl;
	std::cout << "int: " << static_cast<int>(i) << std::endl;
	std::cout << "float: " << i << "f" << std::endl;
	std::cout << "double: " << static_cast<double>(i) << std::endl;
}

void ScalarConverter::convertDouble(std::string str)
{
	double	i = std::stof(str);
	if (i >= 32 && i < 127)
		std::cout << "char: \'" << static_cast<char>(i) << "\'" << std::endl;
	else
		std::cout << "char: " << "impossible" << std::endl;
	std::cout << "int: " << static_cast<int>(i) << std::endl;
	std::cout << "float: " << static_cast<float>(i) << "f" << std::endl;
	std::cout << "double: " << i << std::endl;
}

std::string trim(std::string str)
{
    size_t start = 0;
    size_t end = str.length();

    while (start < end && std::isspace(str[start]))
        start++;
    while (end > start && std::isspace(str[end - 1]))
        end--;
    return (str.substr(start, end - start));
}

bool ScalarConverter::convert(std::string av)
{
	std::string	str = trim(av);
	int 		isdot = 0;
	
	if (str.length() == 0)
		return 0;
	if (str.length() == 1 && !isdigit(str[0])
		return 0 + convertChar(str);
	for (size_t i = 0; i < str.length(); i++)
	{
		if (i == 0 && (str[i] == '-' || str[i] == '+'))
			continue;
		if (str[i] == '.')
			isdot++;
		if (i + 1 == str.length() && isdot == 0 && isdigit(str[i]))
		{
			convertInt(str);
			return 1;
		}
		if (str[i] == 'f' && i + 1 == str.length() && isdot == 1)
		{
			convertFloat(str);
			return 1;
		}
		if (i + 1 == str.length() && isdot == 1)
		{
			convertDouble(str);
			return 1;
		}
		if (str[i] == '.')
			continue;
		if (!isdigit(str[i]))
			break;
	}
	if (!(str.compare("+inf") && str.compare("-inf") && str.compare("nan")))
	{
		double d = std::stod(str);
		std::cout << "char: " << "impossible" << std::endl;
		std::cout << "int: " << "impossible" << std::endl;
		std::cout << "float: " << static_cast<float>(d) << "f" << std::endl;
		std::cout << "double: " << d << std::endl;
		return 1;
	}
	if (!(str.compare("+inff") && str.compare("-inff") && str.compare("nanf")))
	{
		float f = std::stof(str);
		std::cout << "char: " << "impossible" << std::endl;
		std::cout << "int: " << "impossible" << std::endl;
		std::cout << "float: " << f << std::endl;
		std::cout << "double: " << f << std::endl;
		return 1;
	}
	std::cerr << "error!" << std:endl;
	return 1;
}
