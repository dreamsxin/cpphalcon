#include "injectable.h"

#include <string>
#include <iostream>
#include <sstream>

namespace Phalcon {

	/**
	 * Sets the dependency injector
	 */
	void Injectable::setDI(Php::Parameters &params)
	{
		this->_dependencyInjector = params[0];
	}

	Php::Value Injectable::getDI()
	{

		return this->_dependencyInjector;
	}

	/**
	 * Sets the event manager
	 */
	void Injectable::setEventsManager(Php::Parameters &params)
	{
		this->_eventsManager = params[0];
	}

	Php::Value Injectable::getEventsManager()
	{

		return this->_eventsManager;
	}

	/**
	 * Sets the internal event manager
	 */
	void Injectable::setInternalEventsManager(Php::Parameters &params)
	{
		this->_eventsManager = params[0];
	}

	/**
	 * Returns the internal event manager
	 */
	Php::Value Injectable::getInternalEventsManager()
	{
		return this->_eventsManager;
	}
}
