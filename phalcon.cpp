#include <phpcpp.h>

#include "injectable.h"
#include "version.h"
#include "debug.h"
#include "acl.h"
#include "application.h"
#include "arr.h"
#include "config.h"
#include "loader.h"
#include "dispatcherinterface.h"
#include "dispatcher.h"
#include "diinterface.h"
#include "di.h"
#include "di/serviceinterface.h"
#include "di/service.h"
#include "db.h"

extern "C" {

	PHPCPP_EXPORT void *get_module()
	{

		static Php::Extension extension("Phalcon++", "0.0.1");

		Php::Ini ini("phalcon.debug.enable_debug", false);
		extension.add(std::move(ini));

		/**
		 * Define Phalcon namespace
		 */
		Php::Namespace phalconNamespace("Phalcon");

		/* Class Phalcon\Di\Injectable */
		Php::Class<Phalcon::Injectable> injectable("Injectable", Php::Abstract);
		phalconNamespace.add(injectable);

		/* Class Phalcon\Version */
		Php::Class<Phalcon::Version> version("Version");
		phalconNamespace.add(std::move(version));

		/* Class Phalcon\Debug */
		Php::Class<Phalcon::Debug> debug("Debug");
		phalconNamespace.add(std::move(debug));

		/* Class Phalcon\Acl */
		Php::Class<Phalcon::Acl> acl("Acl", Php::Abstract);
		phalconNamespace.add(std::move(acl));

		/* Class Phalcon\Application */
		Php::Class<Phalcon::Application> application("Application", Php::Abstract);
		phalconNamespace.add(std::move(application));

		/* Class Phalcon\Arr */
		Php::Class<Phalcon::Arr> arr("Arr");
		phalconNamespace.add(std::move(arr));

		/* Class Phalcon\Config */
		Php::Class<Phalcon::Config> config("Config");
		phalconNamespace.add(std::move(config));

		/* Class Phalcon\Loader */
		Php::Class<Phalcon::Loader> loader("Loader", injectable);
		phalconNamespace.add(std::move(loader));

		/* Interface Phalcon\DiInterface */
		Phalcon::DiInterface diInterface("DiInterface");
		phalconNamespace.add(std::move(diInterface));

		/* Class Phalcon\Di */
		Php::Class<Phalcon::Di> di("Di", diInterface);
		phalconNamespace.add(std::move(di));

		/* Interface Phalcon\DiInterface */
		Phalcon::DispatcherInterface dispatcherInterface("DispatcherInterface");
		phalconNamespace.add(std::move(dispatcherInterface));

		/* Class Phalcon\Dispatcher */
		Php::Class<Phalcon::Dispatcher> dispatcher("Dispatcher", dispatcherInterface);
		phalconNamespace.add(std::move(dispatcher));

		/* Class Phalcon\Db */
		Php::Class<Phalcon::Db> db("Db");

		phalconNamespace.add(std::move(db));

		/**
		 * Define Di namespace
		 */
		Php::Namespace diNamespace("Di");

		/* Interface Phalcon\Di\ServiceInterface */
		Phalcon::Di_ServiceInterface diServiceInterface("ServiceInterface");
		diNamespace.add(std::move(diServiceInterface));

		/* Class Phalcon\Di\Service */
		Php::Class<Phalcon::Di_Service> di_service("Service", diServiceInterface);
		diNamespace.add(std::move(di_service));

		phalconNamespace.add(std::move(diNamespace));
		extension.add(std::move(phalconNamespace));
		return extension;
	}
}
