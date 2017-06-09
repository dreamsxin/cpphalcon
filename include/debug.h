#ifndef PHALCON_DEBUG_H
#define PHALCON_DEBUG_H

#include <phpcpp.h>

namespace Phalcon {

	/**
	 * Phalcon\Debug
	 *
	 * Provides debug capabilities to Phalcon applications
	 */
	class Debug : public Php::Base {
	public:
		Debug() = default;
		virtual ~Debug() = default;

		static void Init(Php::Class<Debug> &debug)
		{
			debug.method<&Debug::enable>("enable");
			debug.method<&Debug::disable>("disable");
			/**
			 * Change the base URI for static resources
			 */
			debug.method<&Debug::setUri>("setUri", {
				Php::ByVal("uri", Php::Type::String)
			});
			debug.method<&Debug::setShowBackTrace>("setShowBackTrace", {
				Php::ByVal("showBackTrace", Php::Type::Bool),
			});
			debug.method<&Debug::setShowFiles>("setShowFiles", {
				Php::ByVal("showFiles", Php::Type::Bool),
			});
			debug.method<&Debug::setShowFileFragment>("setShowFileFragment", {
				Php::ByVal("showFileFragment", Php::Type::Bool),
			});
			debug.method<&Debug::listen>("listen", {
				Php::ByVal("exceptions", Php::Type::Bool),
				Php::ByVal("lowSeverity", Php::Type::Bool),
			});
			debug.method<&Debug::listenExceptions>("listenExceptions");
			debug.method<&Debug::listenLowSeverity>("listenLowSeverity");
			debug.method<&Debug::halt>("halt");
			debug.method<&Debug::debugVar>("debugVar", {
				Php::ByVal("varz"),
				Php::ByVal("key", Php::Type::String),
			});
			debug.method<&Debug::debugVar>("clearVars");
			debug.method<&Debug::getMajorVersion>("getMajorVersion");
			debug.method<&Debug::getVersion>("getVersion");
			debug.method<&Debug::getCssSources>("getCssSources");
			debug.method<&Debug::getJsSources>("getJsSources");
			debug.method<&Debug::showTraceItem>("showTraceItem", {
				Php::ByVal("n", Php::Type::Numeric),
				Php::ByVal("trace", Php::Type::Array),
			});
			debug.method<&Debug::onUncaughtLowSeverity>("onUncaughtLowSeverity", {
				Php::ByVal("severity", Php::Type::Numeric),
				Php::ByVal("message", Php::Type::String),
				Php::ByVal("file", Php::Type::String),
				Php::ByVal("line", Php::Type::Numeric),
			});
			debug.method<&Debug::onUncaughtException>("onUncaughtException", {
				Php::ByVal("exception", "Exception"),
			});
			debug.method<&Debug::onUncaughtException>("onUserDefinedError", {
				Php::ByVal("severity", Php::Type::Numeric),
				Php::ByVal("message", Php::Type::String),
				Php::ByVal("file", Php::Type::String),
				Php::ByVal("line", Php::Type::Numeric),
				Php::ByVal("context", Php::Type::Array),
			});
		}

		/**
		 * Enable simple debug mode
		 *
		 * @return Phalcon\Debug
		 */
		Php::Value enable();

		/**
		 * Disbale simple debug mode
		 *
		 * @return Phalcon\Debug
		 */
		Php::Value disable();

		/**
		 * Change the base URI for static resources
		 *
		 * @param string $uri
		 * @return Phalcon\Debug
		 */
		Php::Value setUri(Php::Parameters &params);

		/**
		 * Sets if files the exception's backtrace must be showed
		 *
		 * @param boolean $showBackTrace
		 * @return Phalcon\Debug
		 */
		Php::Value setShowBackTrace(Php::Parameters &params);

		/**
		 * Set if files part of the backtrace must be shown in the output
		 *
		 * @param boolean $showFiles
		 * @return Phalcon\Debug
		 */
		Php::Value setShowFiles(Php::Parameters &params);

		/**
		 * Sets if files must be completely opened and showed in the output
		 * or just the fragment related to the exception
		 *
		 * @param boolean $showFileFragment
		 * @return Phalcon\Debug
		 */
		Php::Value setShowFileFragment(Php::Parameters &params);

		/**
		 * Listen for uncaught exceptions and unsilent notices or warnings
		 *
		 * @param boolean $exceptions
		 * @param boolean $lowSeverity
		 * @return Phalcon\Debug
		 */
		Php::Value listen(Php::Parameters &params);

		/**
		 * Listen for uncaught exceptions
		 *
		 * @return Phalcon\Debug
		 */
		Php::Value listenExceptions();

		/**
		 * Listen for unsilent notices or warnings or user-defined error
		 *
		 * @return Phalcon\Debug
		 */
		Php::Value listenLowSeverity();

		/**
		 * Halts the request showing a backtrace
		 */
		void halt();

		/**
		 * Adds a variable to the debug output
		 *
		 * @param mixed $var
		 * @param string $key
		 * @return Phalcon\Debug
		 */
		Php::Value debugVar(Php::Parameters &params);

		/**
		 * Clears are variables added previously
		 *
		 * @return Phalcon\Debug
		 */
		Php::Value clearVars();

		/**
		 * Returns the major framework's version
		 *
		 * @return string
		 */
		Php::Value getMajorVersion();

		/**
		 * Generates a link to the current version documentation
		 *
		 * @return string
		 */
		Php::Value getVersion();

		/**
		 * Returns the css sources
		 *
		 * @return string
		 */
		Php::Value getCssSources();

		/**
		 * Returns the javascript sources
		 *
		 * @return string
		 */
		Php::Value getJsSources();

		/**
		 * Shows a backtrace item
		 *
		 * @param int $n
		 * @param array $trace
		 */
		Php::Value showTraceItem(Php::Parameters &params);

		/**
		 * Throws an exception when a notice or warning is raised
		 *
		 * @param int $severity
		 * @param string $message
		 * @param string $file
		 * @param string $line
		 * @return boolean
		 */
		void onUncaughtLowSeverity(Php::Parameters &params);

		/**
		 * Handles uncaught exceptions
		 *
		 * @param \Exception $exception
		 * @return boolean
		 */
		Php::Value onUncaughtException(Php::Parameters &params);

		/**
		 * Handles user-defined error
		 *
		 * @param int $severity
		 * @param string $message
		 * @param string $file
		 * @param string $line
		 * @param array $context
		 * @return boolean
		 */
		Php::Value onUserDefinedError(Php::Parameters &params);

		/**
		 * Handles user-defined error
		 *
		 * @return boolean
		 */
		Php::Value onShutdown();

		/**
		 * Returns the character set used to display the HTML
		 *
		 * @brief string \Phalcon\Debug::getCharset(void)
		 * @return string
		 */
		Php::Value getCharset();

		/**
		 * Sets the character set used to display the HTML
		 *
		 * @brief \Phalcon\Debug \Phalcon\Debug::setCharset(string $charset)
		 * @param string $charset
		 * @return \Phalcon\Debug
		 */
		Php::Value setCharset();

		/**
		 * Returns the number of lines deplayed before the error line
		 *
		 * @brief int \Phalcon\Debug::getLinesBeforeContext(void)
		 * @return int
		 */
		Php::Value getLinesBeforeContext();

		/**
		 * Sets the number of lines deplayed before the error line
		 *
		 * @brief \Phalcon\Debug \Phalcon\Debug::setLinesBeforeContext(int $lines)
		 * @param int $lines
		 * @return \Phalcon\Debug
		 */
		Php::Value setLinesBeforeContext(Php::Parameters &params);

		/**
		 * Returns the number of lines deplayed after the error line
		 *
		 * @brief int \Phalcon\Debug::getLinesAfterContext(void)
		 * @return int
		 */
		Php::Value getLinesAfterContext();

		/**
		 * Sets the number of lines deplayed after the error line
		 *
		 * @brief \Phalcon\Debug \Phalcon\Debug::setLinesAfterContext(int $lines)
		 * @param int $lines
		 * @return \Phalcon\Debug
		 */
		Php::Value setLinesAfterContext(Php::Parameters &params);
	protected:
	private:
	};

} // namespace Phalcon

#endif // PHALCON_DEBUG_H
