#include "SuperHero.h"

bool isCorrectSymbols(const MyString& str)
{
	for (int i = 0; i < str.length(); i++)
		if (str[i] == '-' || str[i] == '\"' || str[i] == '\'')
			return false;
	return true;
}

const char* getPowerString(const Power& power)
{
	switch (power)
	{
	case Power::Earth: return "Earth"; break;
	case Power::Fire: return "Fire"; break;	
	case Power::Water: return "Water"; break;
	case Power::Air: return "Air"; break;
	case Power::Cosmic: return "Cosmic"; break;
	case Power::Unknown: return "Unknown"; break;
	default: return "Unknown"; break;
	}
}
const char* getStateString(const State& state)
{
	switch (state)
	{
	case State::Attack: return "Attack"; break;
	case State::Deff: return "Deff"; break;
	case State::InShop: return "InShop"; break;
	case State::nonDefined: return "nonDefined"; break;
	case State::deleted: return "Deleted"; break;
	default: return "nonDefined"; break;
	}
}

SuperHero::SuperHero() 
{
	_firstName = "Unknown";
	_lastName = "Unknown";
	_heroName = "Unknown";
	_power = Power::Unknown;
	_state = State::nonDefined;
	_playerId = 0;
	_damage = 0;
	_price = 0;
	_level = 1;
};

SuperHero::SuperHero(const MyString& firstName, const MyString& lastName,
	const MyString& heroName, size_t damage, size_t price,
	size_t playerId, const MyString& power, const MyString& state)
{
	setFirstName(firstName);
	setLastName(lastName);
	setHeroName(heroName);
	setDamage(damage);
	setPrice(price);
	setPlayerId(playerId);
	setPower(power);
	setState(state);
}

void SuperHero::setFirstName(const MyString& firstName)
{
	if (!isCorrectSymbols(firstName))
		throw std::invalid_argument("Not awolled using \'-\',\'\'\',\'\"\'!\n");


	if (firstName.length() < 16)
		_firstName = firstName;
	else
		throw std::length_error("Too long first name!");
}
void SuperHero::setLastName(const MyString& lastName)
{
	if (!isCorrectSymbols(lastName))
		throw std::invalid_argument("Not awolled using \'-\',\'\'\',\'\"\'!\n");


	if (lastName.length() < 16)
		_lastName = lastName;
	else
		throw std::length_error("Too long last name!");
}
void SuperHero::setHeroName(const MyString& heroName)
{
	if (!isCorrectSymbols(heroName))
		throw std::invalid_argument("Not awolled using \'-\',\'\'\',\'\"\'!\n");

	if (heroName.length() == 0)
		throw std::out_of_range("");

	if (heroName.length() < 16)
		_heroName = heroName;
	else
		throw std::length_error("Too long hero name!");
}
void SuperHero::setDamage(size_t damage)
{
	_damage = damage;
}
void SuperHero::setPrice(size_t price)
{
	_price = price;
}
void SuperHero::setPlayerId(size_t playerId)
{
	if (_state == State::InShop || _state == State::deleted)
		_playerId = 0;
	else
		_playerId = playerId;
}
void SuperHero::setLevel(size_t level)
{
	if (level > 5 || level == 0)
		level = 1;
	_level = level;
}
void SuperHero::setPower(const MyString& power)
{
	if (power == "Fire")
		_power = Power::Fire;
	else if (power == "Water")
		_power = Power::Water;
	else if (power == "Earth")
		_power = Power::Earth;
	else if (power == "Air")
		_power = Power::Air;
	else if (power == "Cosmic")
		_power = Power::Cosmic;
	else
		_power = Power::Unknown;
}
void SuperHero::setState(const MyString& state)
{
	if (_playerId > 0 && state == "InShop")
		throw std::bad_alloc();
	if (state == "InShop")
		_state = State::InShop;
	else if (state == "Attack")
		_state = State::Attack;
	else if (state == "Deff")
		_state = State::Deff;
	else if (state == "Deleted")
		_state = State::deleted;
	else
		_state = State::nonDefined;
		
}
void SuperHero::setPower(const Power& power)
{
	_power = power;
}
void SuperHero::setState(const State& state)
{
	if (_playerId > 0 && state == State::InShop)
		throw std::bad_alloc();

	_state = state;
}


const MyString& SuperHero::getFirstName() const
{
	return _firstName;
}
const MyString& SuperHero::getLastName() const
{
	return _lastName;
}
const MyString& SuperHero::getHeroName() const
{
	return _heroName;
}
size_t SuperHero::getDamage() const
{
	return _damage;
}
size_t SuperHero::getPrice() const
{
	return _price;
}
size_t SuperHero::getPlayerId() const
{
	return _playerId;
}
size_t SuperHero::getLevel() const
{
	return _level;
}
const Power& SuperHero::getPower() const
{
	return _power;
}
const State& SuperHero::getState() const
{
	return _state;
}
const char* SuperHero::getPowerStr() const
{
	return getPowerString(_power);
}
const char* SuperHero::getStateStr() const
{
	return getStateString(_state);
}
const char* SuperHero::getHeroNameStr() const
{
	return _heroName.c_str();
}

void SuperHero::saveHeroInDB(std::ofstream& superHeroDB) const
{
	superHeroDB << "\n------------\n";
	superHeroDB << _firstName << "-";
	superHeroDB << _lastName << "-";
	superHeroDB << _heroName << "-";
	superHeroDB << _damage << "-";
	superHeroDB << _price << "-";
	superHeroDB << getPowerString(_power) << "-";   
	superHeroDB << getStateString(_state) << "-";   
	superHeroDB << _level << "-";
	superHeroDB << _playerId;
}





