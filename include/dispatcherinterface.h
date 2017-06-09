#ifndef PHALCON_DISPATCHERINTERFACE_H
#define PHALCON_DISPATCHERINTERFACE_H

#include <phpcpp.h>

namespace Phalcon {

	/**
	 * Phalcon\DispatcherInterface
	 *
	 * Interface for Phalcon\Dispatcher
	 */
	class DispatcherInterface : public Php::Interface {
	public:

		DispatcherInterface(const char *name) : Interface(name)
		{

			/**
			 * Sets the default action suffix
			 */
			method("setActionSuffix",{
				Php::ByVal("actionSuffix", Php::Type::String),
			});

			/**
			 * Sets the default namespace
			 */
			method("setDefaultNamespace",{
				Php::ByVal("namespace", Php::Type::String),
			});

			/**
			 * Sets the default action name
			 */
			method("setDefaultAction",{
				Php::ByVal("actionName", Php::Type::String),
			});

			/**
			 * Sets the namespace which the controller belongs to
			 */
			method("setNamespace",{
				Php::ByVal("namespace", Php::Type::String),
			});

			/**
			 * Sets the module name which the application belongs to
			 */
			method("setModuleName",{
				Php::ByVal("moduleName", Php::Type::String),
			});

			/**
			 * Sets the action name to be dispatched
			 */
			method("setActionName",{
				Php::ByVal("actionName", Php::Type::String),
			});

			/**
			 * Gets last dispatched action name
			 */
			method("getActionName");

			/**
			 * Sets action params to be dispatched
			 *
			 * @param array params
			 */
			method("setParams",{
				Php::ByVal("params", Php::Type::Array),
			});

			/**
			 * Gets action params
			 */
			method("getParams");

			/**
			 * Set a param by its name or numeric index
			 *
			 * @param  mixed param
			 * @param  mixed value
			 */
			method("setParam",{
				Php::ByVal("param", Php::Type::Null),
				Php::ByVal("value", Php::Type::Null),
			});

			/**
			 * Gets a param by its name or numeric index
			 *
			 * @param  mixed param
			 * @param  string|array filters
			 * @return mixed
			 */
			method("getParam");

			/**
			 * Checks if the dispatch loop is finished or has more pendent controllers/tasks to dispatch
			 */
			method("isFinished");

			/**
			 * Returns value returned by the lastest dispatched action
			 *
			 * @return mixed
			 */
			method("getReturnedValue");

			/**
			 * Dispatches a handle action taking into account the routing parameters
			 *
			 * @return object
			 */
			method("dispatch");

			/**
			 * Forwards the execution flow to another controller/action
			 *
			 * @param array forward
			 */
			method("forward",{
				Php::ByVal("forward", Php::Type::Array),
			});
		}
	};

} // namespace Phalcon

#endif /* PHALCON_DISPATCHERINTERFACE_H */
