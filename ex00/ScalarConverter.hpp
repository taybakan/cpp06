#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

# include <iostream>
# include <string>

class ScalarConverter
{
	private	:
		ScalarConverter(void);
		ScalarConverter(ScalarConverter const &src);
		~ScalarConverter(void);
		ScalarConverter &operator=(ScalarConverter const &rhs);
		static void convertChar(std::string str);
		static void convertInt(std::string str);
		static void convertFloat(std::string str);
		static void convertDouble(std::string str);

	public	:
		static bool convert(std::string str);
};



#endif