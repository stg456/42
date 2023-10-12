#include <iostream>

class Warlock
{
	private:
		std::string	_name;
		std::string	_title;
		Warlock();
		Warlock(Warlock const &src);
		Warlock & operator = (Warlock const & rhs);

	public:
		Warlock();
		Warlock(std::string name, std::string title);
		~Warlock();
		std::string	const	getName();
		std::string	const	getTitle();
		void			setTitles(const std::string const & title);
		void			introduce() const;
};