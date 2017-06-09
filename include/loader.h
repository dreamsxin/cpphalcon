#ifndef PHALCON_LOADER_H
#define PHALCON_LOADER_H

#include <phpcpp.h>

namespace Phalcon {

	/**
	 * Phalcon\Loader
	 *
	 * This component helps to load your project classes automatically based on some conventions
	 *
	 *<code>
	 * //Creates the autoloader
	 * $loader = new Loader();
	 *
	 * //Register some namespaces
	 * $loader->registerNamespaces(array(
	 *   'Example\Base' => 'vendor/example/base/',
	 *   'Example\Adapter' => 'vendor/example/adapter/',
	 *   'Example' => 'vendor/example/'
	 * ));
	 *
	 * //register autoloader
	 * $loader->register();
	 *
	 * //Requiring this class will automatically include file vendor/example/adapter/Some.php
	 * $adapter = Example\Adapter\Some();
	 *</code>
	 */
	class Loader : public Php::Base {
	protected:
		Php::Value _foundPath;
		Php::Value _extensions;
		Php::Value _checkedPath;
		Php::Value _prefixes;
		Php::Value _classes;
		Php::Value _namespaces;
		Php::Value _directories;
		Php::Value _registered;

	public:

		Loader() = default;

		virtual ~Loader() = default;

		static void Init(Php::Class<Loader> &loader)
		{
			loader.method<&Phalcon::Loader::__construct>("__construct");
			loader.method<&Phalcon::Loader::_register>("register");
			loader.method<&Phalcon::Loader::unregister>("unregister");
		}

		/**
		 * Phalcon\Loader constructor
		 *
		 */
		void __construct();

		/**
		 * Sets an array of file extensions that the loader must try in each attempt to locate the file
		 */
		Php::Value setExtensions(Php::Parameters &params);

		/**
		 * Returns the file extensions registered in the loader
		 */
		Php::Value getExtensions();

		/**
		 * Register namespaces and their related directories
		 */
		Php::Value registerNamespaces(Php::Parameters &params);

		/**
		 * Returns the namespaces currently registered in the autoloader
		 */
		Php::Value getNamespaces();

		/**
		 * Register directories in which "not found" classes could be found
		 */
		Php::Value registerPrefixes(Php::Parameters &params);

		/**
		 * Returns the prefixes currently registered in the autoloader
		 */
		Php::Value getPrefixes();

		/**
		 * Register directories in which "not found" classes could be found
		 */
		Php::Value registerDirs(Php::Parameters &params);

		/**
		 * Returns the directories currently registered in the autoloader
		 */
		Php::Value getDirs();

		/**
		 * Register classes and their locations
		 */
		Php::Value registerClasses(Php::Parameters &params);

		/**
		 * Returns the class-map currently registered in the autoloader
		 */
		Php::Value getClasses();

		/**
		 * Register the autoload method
		 */
		Php::Value _register();

		/**
		 * Unregister the autoload method
		 */
		Php::Value unregister();

		/**
		 * Autoloads the registered classes
		 */
		Php::Value autoLoad(Php::Parameters &params);

		/**
		 * Get the path when a class was found
		 */
		Php::Value getFoundPath();

		/**
		 * Get the path the loader is checking for a path
		 */
		Php::Value getCheckedPath();

	private:

	};

} // namespace Phalcon

#endif /* PHALCON_LOADER_H */

