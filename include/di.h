#ifndef PHALCON_DI_H
#define PHALCON_DI_H

#include <phpcpp.h>

namespace Phalcon {

	/**
	 * Phalcon\Di
	 *
	 * Phalcon\Di is a component that implements Dependency Injection/Service Location
	 * of services and it's itself a container for them.
	 *
	 *<code>
	 * $di = new Phalcon\Di();
	 *
	 * //Using a string definition
	 * $di->set('request', 'Phalcon\Http\Request', true);
	 *
	 * //Using an anonymous function
	 * $di->set('request', function(){
	 *	  return new Phalcon\Http\Request();
	 * }, true);
	 *
	 * $request = $di->getRequest();
	 *
	 *</code>
	 */
	class Di : public Php::Base, public Php::ArrayAccess {
	protected:
		Php::Value _services;
		Php::Value _sharedInstances;
		Php::Value _freshInstance;
		Php::Value _eventsManager;
	public:
		static Di* _default;

	public:
		/**
		 *  c++ constructor
		 */
		Di() = default;

		/**
		 *  c++ destructor
		 */
		virtual ~Di() = default;

		static void Init(Php::Class<Di> &di)
		{
			di.method<&Phalcon::Di::__construct>("__construct");
			di.method<&Phalcon::Di::setDefault>("setDefault", {
				Php::ByVal("dependencyInjector", "Phalcon\\DiInterface"),
			});
			di.method<&Phalcon::Di::getDefault>("getDefault");
			di.method<&Phalcon::Di::set>("set", {
				Php::ByVal("name", Php::Type::String, true),
				Php::ByVal("definition", Php::Type::Null, true),
				Php::ByVal("shared", Php::Type::Bool, false),
			});
			di.method<&Phalcon::Di::set>("get", {
				Php::ByVal("name", Php::Type::String, true),
				Php::ByVal("parameters", Php::Type::Array, false),
			});
		}

		/**
		 * Phalcon\Di constructor
		 *
		 */
		void __construct();

		/**
		 * Sets the internal event manager
		 */
		void setInternalEventsManager(Php::Parameters &params);

		/**
		 * Returns the internal event manager
		 */
		Php::Value getInternalEventsManager();

		/**
		 * Registers a service in the services container
		 *
		 * @param string $name
		 * @param mixed $definition
		 * @param boolean $shared
		 * @return Phalcon\Di\ServiceInterface
		 */
		Php::Value set(Php::Parameters &params);

		/**
		 * Registers an "always shared" service in the services container
		 */
		Php::Value setShared(Php::Parameters &params);

		/**
		 * Removes a service in the services container
		 */
		void remove(Php::Parameters &params);

		/**
		 * Attempts to register a service in the services container
		 * Only is successful if a service hasn"t been registered previously
		 * with the same name
		 */
		Php::Value attempt(Php::Parameters &params);

		/**
		 * Sets a service using a raw Phalcon\Di\Service definition
		 */
		Php::Value setRaw(Php::Parameters &params);

		/**
		 * Returns a service definition without resolving
		 */
		Php::Value getRaw(Php::Parameters &params);

		/**
		 * Returns a Phalcon\Di\Service instance
		 */
		Php::Value getService(Php::Parameters &params);

		/**
		 * Resolves the service based on its configuration
		 */
		Php::Value get(Php::Parameters &params);

		/**
		 * Resolves a service, the resolved service is stored in the Di, subsequent requests for this service will return the same instance
		 *
		 * @param string name
		 * @param array parameters
		 * @return mixed
		 */
		Php::Value getShared(Php::Parameters &params);

		/**
		 * Check whether the Di contains a service by a name
		 */
		Php::Value has(Php::Parameters &params);

		/**
		 * Check whether the last service obtained via getShared produced a fresh instance or an existing one
		 */
		Php::Value wasFreshInstance();

		/**
		 * Return the services registered in the Di
		 */
		Php::Value getServices();

		bool offsetExists(const Php::Value &key);
		void offsetSet(const Php::Value &key, const Php::Value &value);
		Php::Value offsetGet(const Php::Value &key);
		void offsetUnset(const Php::Value &key);

		Php::Value __call(const char *method, Php::Parameters &params) const;

		/**
		 * Set a default dependency injection container to be obtained into static methods
		 *
		 * @param Phalcon\DiInterface $dependencyInjector
		 */
		static void setDefault(Php::Parameters &params);

		/**
		 * Return the lastest Di created
		 *
		 * @return Phalcon\DiInterface
		 */
		static Php::Value getDefault();

		/**
		 * Resets the internal default Di
		 */
		void static reset();
	};

} // namespace Phalcon

#endif
