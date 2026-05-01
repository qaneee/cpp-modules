#include "Weapon.hpp"

Weapon::~Weapon()
{
}

Weapon::Weapon()
{
	this->type = "";
}

Weapon::Weapon(const std::string& w)
{
	setType(w);
}

void Weapon::setType(std::string upd_type)
{
	this->type = upd_type;
}

const std::string &Weapon::getType(void) const
{
	return this->type;
}