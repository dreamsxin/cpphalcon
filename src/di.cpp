#include "di.h"

#include <string>
#include <iostream>
#include <sstream>

namespace Phalcon {

	Di* Di::_default = nullptr;

	void Di::__construct()
	{
		if (!_default) {
			_default = this;
		}
	}

	void Di::setInternalEventsManager(Php::Parameters &params)
	{

	}

	Php::Value Di::getInternalEventsManager()
	{

		return nullptr;
	}

	Php::Value Di::set(Php::Parameters &params)
	{
		try {
			Php::Value name = params.at(0);
			Php::Value definition = params.at(1);
			Php::Value shared = params.size() > 2 ? params.at(2) : Php::Value(false);
		} catch (const std::out_of_range& e) {
			throw Php::Exception("Invalid number of parameters supplied");
		}

		return this;
	}

	Php::Value Di::setShared(Php::Parameters &params)
	{

		return nullptr;
	}

	void Di::remove(Php::Parameters &params)
	{

	}

	Php::Value Di::attempt(Php::Parameters &params)
	{

		return nullptr;
	}

	Php::Value Di::setRaw(Php::Parameters &params)
	{

		return nullptr;
	}

	Php::Value Di::getRaw(Php::Parameters &params)
	{

		return nullptr;
	}

	Php::Value Di::getService(Php::Parameters &params)
	{

		return nullptr;
	}

	Php::Value Di::get(Php::Parameters &params)
	{
		try {
			Php::Value name = params.at(0);
			Php::Value parameters = params.size() > 1 ? params.at(1) : Php::Value(nullptr);
		} catch (const std::out_of_range& e) {
			throw Php::Exception("Invalid number of parameters supplied");
		}

		return this;
	}

	Php::Value Di::getShared(Php::Parameters &params)
	{

		return nullptr;
	}

	Php::Value Di::has(Php::Parameters &params)
	{

		return nullptr;
	}

	Php::Value Di::wasFreshInstance()
	{

		return nullptr;
	}

	Php::Value Di::getServices()
	{

		return nullptr;
	}

	bool Di::offsetExists(const Php::Value &key)
	{

		return false;
	}

	void Di::offsetSet(const Php::Value &key, const Php::Value &value)
	{

	}

	Php::Value Di::offsetGet(const Php::Value &key)
	{

		return nullptr;
	}

	void Di::offsetUnset(const Php::Value &key)
	{

	}

	Php::Value Di::__call(const char *method, Php::Parameters &params) const
	{

		std::string message = "Call to undefined method or service '";
		message.append(method);
		message.append("'");

		throw Php::Exception(message);

		return nullptr;
	}

	void Di::setDefault(Php::Parameters &params)
	{
		try {
			Php::Value value = params.at(0);
			_default = (Di *) value.implementation();
		} catch (const std::out_of_range& e) {
			throw Php::Exception("Invalid number of parameters supplied");
		}
	}

	Php::Value Di::getDefault()
	{
		if (_default) {
			return _default;
		}
		return nullptr;
	}

	void Di::reset()
	{
		_default = nullptr;
	}
}
