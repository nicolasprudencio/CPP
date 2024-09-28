#ifndef INTERN_HPP
# define INTERN_HPP

# include <iostream>
# include "AForm.hpp"

class Intern
{
	public:
		Intern();
		Intern(Intern const& other);
		~Intern();
		Intern& operator=(Intern const& other);

		AForm* makeForm(std::string const& formName, std::string const& target);
};

#endif