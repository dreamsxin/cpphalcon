#include "version.h"

#include <string>
#include <iostream>
#include <sstream>

namespace Phalcon {

	Php::Value Version::get()
	{

		std::stringstream ss;
		ss << _major << "." << _medium << "." << _minor << " ";

		switch (_special) {
		case Version::TYPE_ALPHA:
			ss << "ALPHA " << _special_number;
			break;
		case Version::TYPE_BETA:
			ss << "BETA " << _special_number;
			break;
		case Version::TYPE_RC:
			ss << "RC " << _special_number;
			break;
		case Version::TYPE_STABLE:
			ss << "STABLE " << _special_number;
			break;
		}

		return ss.str();
	}

	Php::Value Version::getId()
	{
		std::stringstream ss;
		ss << _major;

		ss.fill('0');
		ss.width(2);
		ss << _medium;
		ss << _minor;
		ss << _special;
		ss << _special_number;

		return ss.str();
	}
}
