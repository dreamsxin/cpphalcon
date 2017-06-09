#include "di/service.h"

#include <string>
#include <iostream>
#include <sstream>

namespace Phalcon {

	void Di_Service::__construct(Php::Parameters &params)
	{
		try {
			this->_name = params.at(0);
			this->_definition = params.at(1);
			this->_shared = params.size() > 2 ? params.at(2) : Php::Value(false);
		} catch (const std::out_of_range& e) {
			throw Php::Exception("Invalid number of parameters supplied");
		}
	}

	Php::Value Di_Service::getName()
	{

		return this->_name;
	}

	void Di_Service::setShared(Php::Parameters &params)
	{
		this->_shared = params.at(0);
	}

	Php::Value Di_Service::isShared()
	{
		return this->_shared;
	}

	void Di_Service::setSharedInstance(Php::Parameters &params)
	{
		this->_sharedInstance = params.at(0);
	}

	void Di_Service::setDefinition(Php::Parameters &params)
	{
		this->_definition = params.at(0);
	}

	Php::Value Di_Service::getDefinition()
	{
		return this->_definition;
	}

	Php::Value Di_Service::resolve(Php::Parameters &params)
	{
		Php::Value parameters = params.size() > 0 ? params.at(0) : nullptr;
		Php::Value dependencyInjector = params.size() > 1 ? params.at(1) : nullptr;


		if (this->_shared && this->_sharedInstance) {
			return this->_sharedInstance;
		}

		Php::Object instance;

		if (this->_definition.isString()) {
			if (Php::call("class_exists", this->_definition)) {

				if (parameters.isArray()) {
					instance = Php::Object(this->_definition, parameters);
				} else {
					instance = Php::Object(this->_definition);
				}

				if (this->_shared) {
					this->_sharedInstance = instance;
				}

				this->_resolved = true;
				return instance;
			}
		} else if (this->_definition.isObject()) {

			if (this->_definition.instanceOf("Closure")) {
				if (parameters.isArray()) {
					instance = Php::call("call_user_func_array", this->_definition, parameters);
				} else {
					instance = Php::call("call_user_func", this->_definition);
				}
			} else {
				instance = this->_definition;
			}

			if (this->_shared) {
				this->_sharedInstance = instance;
			}

			this->_resolved = true;
			return instance;
		}

		return instance;
	}

	Php::Value Di_Service::setParameter(Php::Parameters &params)
	{
		Php::Value position = params.at(0);
		Php::Value parameter = params.at(1);

		if (!this->_definition.isArray()) {
			throw Php::Exception("Definition must be an array to update its parameters");
		}

		Php::Value arguments;
		if (this->_definition.contains("arguments")) {
			arguments = this->_definition.get("arguments");
		}

		arguments.set(position, parameter);

		this->_definition.set("arguments", arguments);

		return this;
	}

	Php::Value Di_Service::getParameter(Php::Parameters &params)
	{
		Php::Value position = params.at(0);

		if (!this->_definition.isArray()) {
			throw Php::Exception("Definition must be an array to update its parameters");
		}

		Php::Value arguments;
		if (this->_definition.contains("arguments")) {
			arguments = this->_definition.get("arguments");
			if (arguments.contains(position)) {
				return arguments.get(position);
			}
		}

		return nullptr;
	}

	Php::Value Di_Service::isResolved()
	{

		return this->_resolved;
	}
}
