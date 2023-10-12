#include <iostream>

class Warlock
{
	private:
		std::string	_name;
		std::string	_title;

	public:
		Warlock();
		Warlock(std::string name, std::string title);
		~Warlock();
		std::string&	getName(const std::string name);
		std::string&	getTitle(const std::string name);
		void			setTitles(const std::string title);
		void			introduce();
};