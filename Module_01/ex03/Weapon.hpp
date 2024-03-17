#ifndef WEAPON_HPP
# define WEAPON_HPP

class Weapon {

public:

	~Weapon();
	Weapon(const std::string& type); 

	const std::string&	getType(void) const;
	void				setType(std::string type);

private:

	Weapon();
	std::string	_type;

};

#endif