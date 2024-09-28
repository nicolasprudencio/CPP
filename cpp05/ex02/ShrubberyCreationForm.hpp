#ifndef SHRUBBERY_CREATION_FORM_HPP
# define SHRUBBERY_CREATION_FORM_HPP

# include "AForm.hpp"
# include <cmath>
# include <fstream>


#define REAL_SHRUBBERY "\
                    oOOO0Oo\n\
                   o000000oo\n\
                  00000000000o\n\
                 00000000000000\n\
              oooooo  00000000  o88o\n\
           ooOOOOOOOoo  ```''  888888\n\
         OOOOOOOOOOOO'.qQQQQq. `8888'\n\
        oOOOOOOOOOO'.QQQQQQQQQQ/.88'\n\
        OOOOOOOOOO'.QQQQQQQQQQ/ /q\n\
         OOOOOOOOO QQQQQQQQQQ/ /QQ\n\
           OOOOOOOOO `QQQQQQ/ /QQ'\n\
             OO:F_P:O `QQQQ/ /Q'\n\
                \\. \\\\  / // |\n\
                d\\ \\\\|_////\n\
                qP| \\ _' `|Ob\n\
                   \\  / \\  \\Op\n\
                   |  | O| |\n\
           _       /\\. \\_/ /\\\n\
            `---__/|_\\\\   //|  __\n\
                  `-  `-`--\n"

class Bureaucrat;

class ShrubberyCreationForm : public AForm
{
	private:
		std::string	_target;

	public:
		ShrubberyCreationForm();
		ShrubberyCreationForm(std::string const target);
		ShrubberyCreationForm(ShrubberyCreationForm const& other);
		~ShrubberyCreationForm();
		ShrubberyCreationForm& operator=(ShrubberyCreationForm const& other);

		void ShrubberyingFile() const;
		void execute(Bureaucrat const& executor) const
		throw(GradeTooLowException, GradeTooHighException, FormIsNotSignedException);
};
 
#endif