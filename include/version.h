#ifndef PHALCON_VERSION_H
#define PHALCON_VERSION_H

#include <phpcpp.h>

namespace Phalcon {

	/**
	 *  Forward declarations
	 */
	template <class T> class Class;

	/**
	 * Phalcon\Version
	 *
	 * This class allows to get the installed version of the framework
	 */
	class Version : public Php::Base {
	public:

		enum TYPE {
			TYPE_ALPHA = 1,
			TYPE_BETA = 2,
			TYPE_RC = 3,
			TYPE_STABLE = 4,
		};

	private:
		static const int _major = 0;
		static const int _medium = 0;
		static const int _minor = 1;
		static const int _special = 1;
		static const int _special_number = 0;

	public:

		Version() = default;

		virtual ~Version() = default;

		static void Init(Php::Class<Version> &version)
		{
			version.property("TYPE_ALPHA", Version::TYPE_ALPHA, Php::Const);
			version.property("TYPE_BETA", Version::TYPE_BETA, Php::Const);
			version.property("TYPE_RC", Version::TYPE_RC, Php::Const);
			version.property("TYPE_STABLE", Version::TYPE_STABLE, Php::Const);

			version.method<&Version::get>("get");
			version.method<&Version::getId>("getId");
		}

		/**
		 * Returns the active version (string)
		 *
		 * <code>
		 * echo Phalcon\Version::get();
		 * </code>
		 *
		 * @return string
		 */
		static Php::Value get();

		/**
		 * Returns the active version (string)
		 *
		 * <code>
		 * echo Phalcon\Version::getId();
		 * </code>
		 *
		 * @return string
		 */
		static Php::Value getId();
	};

} // namespace Phalcon

#endif
