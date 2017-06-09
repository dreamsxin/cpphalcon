#ifndef PHALCON_INJECTABLE_H
#define PHALCON_INJECTABLE_H

#include <phpcpp.h>

namespace Phalcon {

	/**
	 * Phalcon\Injectable
	 *
	 * This class allows to access services in the services container by just only accessing a public property
	 * with the same name of a registered service
	 */
	class Injectable : public Php::Base {
	protected:
		Php::Value _dependencyInjector;
		Php::Value _eventsManager;

	public:
		/**
		 *  c++ constructor
		 */
		Injectable() = default;

		/**
		 *  c++ destructor
		 */
		virtual ~Injectable() = default;

		static void Init(Php::Class<Injectable> &injectable)
		{
			injectable.property("_dependencyInjector", nullptr, Php::Protected);
			injectable.property("_eventsManager", nullptr, Php::Protected);
			injectable.property("_eventCallbacks", nullptr, Php::Protected);

			injectable.method<&Injectable::setDI>("setDI", {
				Php::ByVal("dependencyInjector", "Phalcon\\DIInterface"),
			});
			injectable.method<&Injectable::getDI>("getDI");

			injectable.method<&Injectable::setEventsManager>("setEventsManager", {
				Php::ByVal("eventsManager", "Phalcon\\Events\\ManagerInterface"),
			});
			injectable.method<&Injectable::getEventsManager>("getEventsManager");

			injectable.method<&Injectable::setInternalEventsManager>("setInternalEventsManager", {
				Php::ByVal("eventsManager", "Phalcon\\Events\\ManagerInterface"),
			});
			injectable.method<&Injectable::getInternalEventsManager>("getInternalEventsManager");
		}

		/**
		 * Sets the dependency injector
		 */
		void setDI(Php::Parameters &params);

		Php::Value getDI();

		/**
		 * Sets the event manager
		 */
		void setEventsManager(Php::Parameters &params);

		Php::Value getEventsManager();

		/**
		 * Sets the internal event manager
		 */
		void setInternalEventsManager(Php::Parameters &params);

		/**
		 * Returns the internal event manager
		 */
		Php::Value getInternalEventsManager();
	};

} // namespace Phalcon

#endif /* PHALCON_INJECTABLE_H */

