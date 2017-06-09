#ifndef PHALCON_DISPATCHER_H
#define PHALCON_DISPATCHER_H

#include <phpcpp.h>

namespace Phalcon {

	/**
	 * Phalcon\Dispatcher
	 *
	 * This is the base class for Phalcon\Mvc\Dispatcher and Phalcon\CLI\Dispatcher.
	 * This class can't be instantiated directly, you can use it to create your own dispatchers
	 */
	class Dispatcher : public Php::Base {
	public:

		enum EXCEPTION {
			EXCEPTION_NO_DI = 0,
			EXCEPTION_CYCLIC_ROUTING,
			EXCEPTION_HANDLER_NOT_FOUND,
			EXCEPTION_INVALID_HANDLER,
			EXCEPTION_INVALID_PARAMS,
			EXCEPTION_ACTION_NOT_FOUND,
		};

	public:

		Dispatcher() = default;

		virtual ~Dispatcher() = default;

		static void Init(Php::Class<Dispatcher> &dispatcher)
		{
			dispatcher.property("_activeHandler", nullptr, Php::Protected);
			dispatcher.property("_finished", nullptr, Php::Protected);
			dispatcher.property("_forwarded", false, Php::Protected);
			dispatcher.property("_moduleName", nullptr, Php::Protected);
			dispatcher.property("_namespaceName", nullptr, Php::Protected);
			dispatcher.property("_handlerName", nullptr, Php::Protected);
			dispatcher.property("_actionName", nullptr, Php::Protected);
			dispatcher.property("_params", nullptr, Php::Protected);
			dispatcher.property("_returnedValue", nullptr, Php::Protected);
			dispatcher.property("_lastHandler", nullptr, Php::Protected);
			dispatcher.property("_defaultNamespace", nullptr, Php::Protected);
			dispatcher.property("_defaultHandler", nullptr, Php::Protected);
			dispatcher.property("_defaultAction", nullptr, Php::Protected);
			dispatcher.property("_handlerSuffix", nullptr, Php::Protected);
			dispatcher.property("_actionSuffix", "Action", Php::Protected);
			dispatcher.property("_previousHandlerName", nullptr, Php::Protected);
			dispatcher.property("_previousActionName", nullptr, Php::Protected);

			dispatcher.property("EXCEPTION_NO_DI", Phalcon::Dispatcher::EXCEPTION_NO_DI, Php::Const);
			dispatcher.property("EXCEPTION_CYCLIC_ROUTING", Phalcon::Dispatcher::EXCEPTION_CYCLIC_ROUTING, Php::Const);
			dispatcher.property("EXCEPTION_HANDLER_NOT_FOUND", Phalcon::Dispatcher::EXCEPTION_HANDLER_NOT_FOUND, Php::Const);
			dispatcher.property("EXCEPTION_INVALID_HANDLER", Phalcon::Dispatcher::EXCEPTION_INVALID_HANDLER, Php::Const);
			dispatcher.property("EXCEPTION_INVALID_PARAMS", Phalcon::Dispatcher::EXCEPTION_INVALID_PARAMS, Php::Const);
			dispatcher.property("EXCEPTION_ACTION_NOT_FOUND", Phalcon::Dispatcher::EXCEPTION_ACTION_NOT_FOUND, Php::Const);

			dispatcher.method<&Phalcon::Dispatcher::__construct>("__construct");
		}

		/**
		 * Phalcon\Dispatcher constructor
		 *
		 */
		void __construct();

		/**
		 * Sets the default action suffix
		 */
		void setActionSuffix(Php::Parameters &params);

		/**
		 * Sets the module where the controller is (only informative)
		 */
		void setModuleName(Php::Parameters &params);

		/**
		 * Gets the module where the controller class is
		 */
		Php::Value getModuleName();

		/**
		 * Sets the namespace where the controller class is
		 */
		void setNamespaceName(Php::Parameters &params);

		/**
		 * Gets a namespace to be prepended to the current handler name
		 */
		Php::Value getNamespaceName();

		/**
		 * Sets the default namespace
		 */
		void setDefaultNamespace(Php::Parameters &params);

		/**
		 * Returns the default namespace
		 */
		Php::Value getDefaultNamespace();

		/**
		 * Sets the default action name
		 */
		void setDefaultAction(Php::Parameters &params);

		/**
		 * Returns the default action name
		 */
		Php::Value getDefaultAction();

		/**
		 * Sets the action name to be dispatched
		 */
		void setActionName(Php::Parameters &params);

		/**
		 * Gets the latest dispatched action name
		 */
		Php::Value getActionName();

		/**
		 * Sets action params to be dispatched
		 *
		 * @param array params
		 */
		void setParams(Php::Parameters &params);

		/**
		 * Gets action params
		 */
		Php::Value getParams();

		/**
		 * Set a param by its name or numeric index
		 *
		 * @param  mixed param
		 * @param  mixed value
		 */
		void setParam(Php::Parameters &params);

		/**
		 * Gets a param by its name or numeric index
		 *
		 * @param  mixed param
		 * @param  string|array filters
		 * @param  mixed defaultValue
		 * @return mixed
		 */
		Php::Value getParam(Php::Parameters &params);

		/**
		 * Returns the current method to be/executed in the dispatcher
		 */
		Php::Value getActiveMethod();

		/**
		 * Checks if the dispatch loop is finished or has more pendent controllers/tasks to dispatch
		 */
		Php::Value isFinished();

		/**
		 * Sets the latest returned value by an action manually
		 *
		 * @param mixed value
		 */
		void setReturnedValue(Php::Parameters &params);

		/**
		 * Returns value returned by the lastest dispatched action
		 *
		 * @return mixed
		 */
		Php::Value getReturnedValue();

		/**
		 * Dispatches a handle action taking into account the routing parameters
		 *
		 * @return object
		 */
		Php::Value dispatch();

		/**
		 * Forwards the execution flow to another controller/action
		 * Dispatchers are unique per module. Forwarding between modules is not allowed
		 *
		 *<code>
		 *  $this->dispatcher->forward(array("controller" => "posts", "action" => "index"));
		 *</code>
		 *
		 * @param array forward
		 */
		void forward(Php::Parameters &params);

		/**
		 * Check if the current executed action was forwarded by another one
		 */
		Php::Value wasForwarded();

		/**
		 * Possible class name that will be located to dispatch the request
		 */
		Php::Value getHandlerClass();

		/**
		 * Set empty properties to their defaults (where defaults are available)
		 */
		void _resolveEmptyProperties();

	private:

	};

} // namespace Phalcon

#endif /* PHALCON_DISPATCHER_H */

