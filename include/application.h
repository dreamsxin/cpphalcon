#ifndef PHALCON_APPLICATION_H
#define PHALCON_APPLICATION_H

#include <phpcpp.h>

namespace Phalcon {

	/**
	 * Phalcon\Application
	 *
	 * Base class
	 */
	class Application : public Php::Base {
	public:
		enum {APPLICATION_DUNNO, APPLICATION_DENY, APPLICATION_ALLOW};

	public:

		static void Init(Php::Class<Application> &application)
		{
			application.property("_defaultModule", nullptr, Php::Protected);
			application.property("_modules", nullptr, Php::Protected);

			application.method<&Application::registerModules>("registerModules", {
				Php::ByVal("modules", Php::Type::Array),
				Php::ByVal("merge", Php::Type::Bool, false),
			});
			application.method<&Application::getModules>("getModules");

			application.method<&Application::setDefaultModule>("setDefaultModule", {
				Php::ByVal("defaultModule", Php::Type::String),
			});
			application.method<&Application::getDefaultModule>("getDefaultModule");
			
			application.method("handle", Php::Abstract, {
				Php::ByVal("data", Php::Type::Null, false),
			});
		}

		/**
		 * Register an array of modules present in the application
		 *
		 * @param array $modules
		 * @param boolean $merge
		 * @param Phalcon\Application
		 */
		void registerModules(Php::Parameters &params);

		/**
		 * Return the modules registered in the application
		 *
		 * @return array
		 */
		Php::Value getModules();

		/**
		 * Sets the module name to be used if the router doesn't return a valid module
		 *
		 * @param string $defaultModule
		 * @return Phalcon\Application
		 */
		void setDefaultModule(Php::Parameters &params);

		/**
		 * Return the modules registered in the application
		 *
		 * @return array
		 */
		Php::Value getDefaultModule();
	};

} // namespace Phalcon

#endif /* PHALCON_APPLICATION_H */
