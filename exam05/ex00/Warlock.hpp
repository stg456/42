#pragma once
#include <iostream>

class Warlock
{
    private:
<<<<<<< HEAD
        std::string _name;
        std::string _title;

        Warlock();
        Warlock& operator=(Warlock const &rhs);
        Warlock(Warlock const &src);

    public:
        Warlock(std::string name, std::string title);
        ~Warlock();

        std::string const & getName() const;
        std::string const & getTitle() const;
        void setTitle(std::string const &str);
        void introduce() const;
};
=======
        Warlock & operator = (Warlock const & rhs);
        Warlock(Warlock const &obj);
        Warlock();
        std::string _name;
        std::string _title;

    public:
        Warlock(std::string name, std::string title);
        ~Warlock();
        std::string const & getName() const;
        std::string const & getTitle()const;
        void setTitle(std::string const & str);
        void introduce() const;
}
>>>>>>> a33c94c461bc0e42ae186abf3f786592899d6c81
