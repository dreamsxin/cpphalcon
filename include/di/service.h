#ifndef PHALCON_DI_SERVICE_H
#define PHALCON_DI_SERVICE_H

#include <phpcpp.h>

namespace Phalcon {

	/**
	 * Phalcon\Di\Service
	 *
	 * Represents individually a service in the services container
	 *
	 *<code>
	 * $service = new Phalcon\Di\Service('request', 'Phalcon\Http\Request');
	 * $request = $service->resolve();
	 *<code>
	 *
	 */
	class Di_Service : public Php::Base {
	protected:
		Php::Value _name;
		Php::Value _definition;
		Php::Value _shared = false;
		Php::Value _resolved = false;
		Php::Value _sharedInstance;

	public:

		Di_Service() = default;

		virtual ~Di_Service() = default;

		static void Init(Php::Class<Di_Service> &di_service)
		{
			di_service.method<&Di_Service::__construct>("__construct", {
				Php::ByVal("name", Php::Type::String),
				Php::ByVal("definition", Php::Type::Null),
				Php::ByVal("shared", Php::Type::Bool, false),
			});
			di_service.method<&Di_Service::setShared>("setShared",{
				Php::ByVal("shared", Php::Type::Bool),
			});
			di_service.method<&Di_Service::isShared>("isShared");
			di_service.method<&Di_Service::setSharedInstance>("setSharedInstance",{
				Php::ByVal("sharedInstance", Php::Type::Null),
			});
			di_service.method<&Di_Service::setDefinition>("setDefinition", {
				Php::ByVal("definition", Php::Type::Null),
			});
			di_service.method<&Di_Service::getDefinition>("getDefinition");
			di_service.method<&Di_Service::resolve>("resolve",{
				Php::ByVal("parameters", Php::Type::Array, false),
				Php::ByVal("dependencyInjector", "Phalcon\\DiInterface", false),
			});
			di_service.method<&Di_Service::isResolved>("isResolved");
			di_service.method<&Di_Service::setParameter>("setParameter",{
				Php::ByVal("position", Php::Type::Numeric),
				Php::ByVal("parameter", Php::Type::Array),
			});
			di_service.method<&Di_Service::getParameter>("getParameter",{
				Php::ByVal("position", Php::Type::Numeric),
			});	
		}

		/**
		 * Phalcon\Di\Service
		 *
		 * @param string $name
		 * @param mixed $definition
		 * @param boolean $shared
		 */
		void __construct(Php::Parameters &params);

		/**
		 * Returns the service's name
		 */
		Php::Value getName();

		/**
		 * Sets if the service is shared or not
		 *
		 * @param bollean shared
		 */
		void setShared(Php::Parameters &params);

		/**
		 * Check whether the service is shared or not
		 */
		Php::Value isShared();


		/**
		 * Sets/Resets the shared instance related to the service
		 *
		 * @param mixed sharedInstance
		 */
		void setSharedInstance(Php::Parameters &params);

		/**
		 * Set the service definition
		 *
		 * @param mixed definition
		 */
		void setDefinition(Php::Parameters &params);

		/**
		 * Returns the service definition
		 *
		 * @return mixed
		 */
		Php::Value getDefinition();

		/**
		 * Resolves the service
		 *
		 * @param array parameters
		 * @param Phalcon\DiInterface dependencyInjector
		 * @return mixed
		 */
		Php::Value resolve(Php::Parameters &params);

		/**
		 * Changes a parameter in the definition without resolve the service
		 */
		Php::Value setParameter(Php::Parameters &params);

		/**
		 * Returns a parameter in a specific position
		 *
		 * @param int position
		 * @return array
		 */
		Php::Value getParameter(Php::Parameters &params);

		/**
		 * Returns true if the service was resolved
		 */
		Php::Value isResolved();
	};

} // namespace Phalcon

#endif
