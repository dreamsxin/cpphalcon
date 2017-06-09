#include "dispatcher.h"

namespace Phalcon {

	void Dispatcher::__construct()
	{
		Php::Value self(this);
		self["_actionSuffix"] = "Action";
	}

	void Dispatcher::setActionSuffix(Php::Parameters &params)
	{

	}

	void Dispatcher::setModuleName(Php::Parameters &params)
	{

	}

	Php::Value Dispatcher::getModuleName()
	{

		return nullptr;
	}

	void Dispatcher::setNamespaceName(Php::Parameters &params)
	{

	}

	Php::Value Dispatcher::getNamespaceName()
	{

		return nullptr;
	}

	void Dispatcher::setDefaultNamespace(Php::Parameters &params)
	{

	}

	Php::Value Dispatcher::getDefaultNamespace()
	{

		return nullptr;
	}

	void Dispatcher::setDefaultAction(Php::Parameters &params)
	{

	}

	Php::Value Dispatcher::getDefaultAction()
	{

		return nullptr;
	}

	void Dispatcher::setActionName(Php::Parameters &params)
	{

	}

	Php::Value Dispatcher::getActionName()
	{

		return nullptr;
	}

	void Dispatcher::setParams(Php::Parameters &params)
	{

	}

	Php::Value Dispatcher::getParams()
	{

		return nullptr;
	}

	void Dispatcher::setParam(Php::Parameters &params)
	{

	}

	Php::Value Dispatcher::getParam(Php::Parameters &params)
	{

		return nullptr;
	}

	Php::Value Dispatcher::getActiveMethod()
	{

		return nullptr;
	}

	Php::Value Dispatcher::isFinished()
	{

		return nullptr;
	}

	void Dispatcher::setReturnedValue(Php::Parameters &params)
	{

	}

	Php::Value Dispatcher::getReturnedValue()
	{

		return nullptr;
	}

	Php::Value Dispatcher::dispatch()
	{

		return nullptr;
	}

	void Dispatcher::forward(Php::Parameters &params)
	{

	}

	Php::Value Dispatcher::wasForwarded()
	{

		return nullptr;
	}

	Php::Value Dispatcher::getHandlerClass()
	{

		return nullptr;
	}

	void Dispatcher::_resolveEmptyProperties()
	{

	}
}

