#ifndef PHALCON_CONFIG_H
#define PHALCON_CONFIG_H

#include <phpcpp.h>

namespace Phalcon {

	/**
	 * Phalcon\Config
	 *
	 * Phalcon\Config is designed to simplify the access to, and the use of, configuration data within applications.
	 * It provides a nested object property based user interface for accessing this configuration data within
	 * application code.
	 */
	class Config : public Php::Base, public Php::ArrayAccess {
	public:

		static void Init(Php::Class<Config> &config)
		{
			config.method<&Config::__construct>("__construct");
			config.method<&Config::get>("get");
			config.method<&Config::merge>("merge");
			config.method<&Config::toArray>("toArray");
			config.method<&Config::count>("count");
		}

		/**
		 * Phalcon\Config constructor
		 * @param string $arrayConfig
		 *
		 */
		void __construct(Php::Parameters &params);

		/**
		 * Gets an attribute from the configuration, if the attribute isn't defined returns null
		 * If the value is exactly null or is not defined the default value will be used instead
		 *
		 *<code>
		 * echo $config->get('controllersDir', '../app/controllers/');
		 *</code>
		 */
		Php::Value get(Php::Parameters &params);

		/**
		 * Merges a configuration into the current one
		 *
		 *<code>
		 * $appConfig = new \Phalcon\Config(array('database' => array('host' => 'localhost')));
		 * $globalConfig->merge($config2);
		 *</code>
		 */
		Php::Value merge(Php::Parameters &params);

		/**
		 * Converts recursively the object to an array
		 *
		 *<code>
		 *	print_r($config->toArray());
		 *</code>
		 */
		Php::Value toArray();

		/**
		 * Returns the count of properties set in the config
		 *
		 *<code>
		 * print count($config);
		 *</code>
		 *
		 * or
		 *
		 *<code>
		 * print $config->count();
		 *</code>
		 */
		Php::Value count();

		bool offsetExists(const Php::Value &key);
		void offsetSet(const Php::Value &key, const Php::Value &value);
		Php::Value offsetGet(const Php::Value &key);
		void offsetUnset(const Php::Value &key);

	private:

	};

} // namespace Phalcon

#endif /* PHALCON_CONFIG_H */

