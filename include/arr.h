#ifndef PHALCON_ARR_H
#define PHALCON_ARR_H

#include <phpcpp.h>

namespace Phalcon {

	/**
	 * Phalcon\Arr
	 *
	 * Base class
	 */
	class Arr : public Php::Base {
	public:
		enum {ARR_DUNNO, ARR_DENY, ARR_ALLOW};

	public:

		static void Init(Php::Class<Arr> &arr)
		{
			arr.method<&Arr::is_assoc>("is_assoc", {
				Php::ByVal("array", Php::Type::Array),
			});
			arr.method<&Arr::is_assoc>("is_array", {
				Php::ByVal("var", Php::Type::Null),
			});
			arr.method<&Arr::path>("path", {
				Php::ByVal("array", Php::Type::Array),
				Php::ByVal("path", Php::Type::Null),
				Php::ByVal("defaultValue", Php::Type::Null, false),
				Php::ByVal("delimiter", Php::Type::String, false),
			});

			arr.method<&Arr::set_path>("set_path", {
				Php::ByVal("array", Php::Type::Array),
				Php::ByVal("path", Php::Type::Null),
				Php::ByVal("value", Php::Type::Null),
				Php::ByVal("delimiter", Php::Type::String, false),
			});

			arr.method<&Arr::range>("range", {
				Php::ByVal("step", Php::Type::Numeric),
				Php::ByVal("max", Php::Type::Numeric),
			});

			arr.method<&Arr::get>("get", {
				Php::ByVal("array", Php::Type::Array),
				Php::ByVal("keys", Php::Type::Null),
				Php::ByVal("defaultValue", Php::Type::Null, false),
			});

			arr.method<&Arr::first>("first", {
				Php::ByVal("array", Php::Type::Array),
				Php::ByVal("keys", Php::Type::Null),
				Php::ByVal("defaultValue", Php::Type::Null, false),
			});

			arr.method<&Arr::choice>("choice", {
				Php::ByVal("array", Php::Type::Array),
				Php::ByVal("key", Php::Type::String),
				Php::ByVal("trueValue", Php::Type::Null),
				Php::ByVal("falseValue", Php::Type::Null, false),
			});

			arr.method<&Arr::extract>("extract", {
				Php::ByVal("array", Php::Type::Array),
				Php::ByVal("paths", Php::Type::Array),
				Php::ByVal("defaultValue", Php::Type::Null, false),
			});

			arr.method<&Arr::pluck>("pluck", {
				Php::ByVal("array", Php::Type::Array),
				Php::ByVal("key", Php::Type::String),
			});

			arr.method<&Arr::unshift>("unshift", {
				Php::ByVal("array", Php::Type::Array),
				Php::ByVal("key", Php::Type::String),
				Php::ByVal("value", Php::Type::Null),
			});

			arr.method<&Arr::map>("map", {
				Php::ByVal("array", Php::Type::Array),
				Php::ByVal("callback", Php::Type::Callable),
			});

			arr.method<&Arr::merge>("merge", {
				Php::ByVal("array1", Php::Type::Array),
				Php::ByVal("array2", Php::Type::Array),
			});

			arr.method<&Arr::overwrite>("overwrite", {
				Php::ByVal("array1", Php::Type::Array),
				Php::ByVal("array2", Php::Type::Array),
			});

			arr.method<&Arr::flatten>("flatten", {
				Php::ByVal("array", Php::Type::Array),
			});

			arr.method<&Arr::filter>("filter", {
				Php::ByVal("array", Php::Type::Array),
				Php::ByVal("filters", Php::Type::Array),
			});

			arr.method<&Arr::sum>("sum", {
				Php::ByVal("array", Php::Type::Array),
				Php::ByVal("path", Php::Type::Null),
				Php::ByVal("defaultValue", Php::Type::Null, false),
				Php::ByVal("delimiter", Php::Type::String, false),
			});

			arr.method<&Arr::toArray>("toArray", {
				Php::ByVal("val", Php::Type::Null),
			});
		}

		/**
		 * Tests if an array is associative or not.
		 *
		 * @param array $array
		 * @return boolean
		 */
		static Php::Value is_assoc(Php::Parameters &params);

		/**
		 * Test if a value is an array with an additional check for array-like objects.
		 *
		 * @param mixed $value
		 * @return boolean
		 */
		static Php::Value is_array(Php::Parameters &params);

		/**
		 * Gets a value from an array using a dot separated path.
		 *
		 * @param array $array
		 * @param mixed $path
		 * @param mixed $default
		 * @param string $delimiter
		 * @return mixed
		 */
		static Php::Value path(Php::Parameters &params);

		/**
		 * Set a value on an array by path.
		 *
		 * Using a wildcard "*" will search intermediate arrays and return an array.
		 *
		 * @param array $array
		 * @param string $path
		 * @param mixed $value
		 * @param string $delimiter
		 */
		static void set_path(Php::Parameters &params);

		/**
		 * Fill an array with a range of numbers.
		 *
		 * @param integer $step
		 * @param integer $max
		 * @return array
		 */
		static Php::Value range(Php::Parameters &params);

		/**
		 * Retrieve a single key from an array. If the key does not exist in the
		 * array, the default value will be returned instead.
		 *
		 * @param array $array
		 * @param string|array|\Closure $key
		 * @param mixed $default_value
		 * @return mixed
		 */
		static Php::Value get(Php::Parameters &params);

		/**
		 * Retrieve a single key from an array, if value an array return the first element.
		 *
		 * @param array $array
		 * @param string|array|\Closure $key
		 * @param mixed $default_value
		 * @return mixed
		 */
		static Php::Value first(Php::Parameters &params);

		/**
		 * Choice one value, If the key does not exist in the array, the value2 will be returned instead.
		 *
		 * @param array $array
		 * @param string $key
		 * @param string $value1
		 * @param string $value2
		 * @return mixed
		 */
		static Php::Value choice(Php::Parameters &params);

		/**
		 * Retrieves multiple paths from an array. If the path does not exist in the
		 * array, the default value will be added instead.
		 *
		 * @param array $array
		 * @param array $paths
		 * @param mixed $default_value
		 * @return array
		 */
		static Php::Value extract(Php::Parameters &params);

		/**
		 * Retrieves muliple single-key values from a list of arrays.
		 *
		 * @param array $array
		 * @param string $key
		 * @return array
		 */
		static Php::Value pluck(Php::Parameters &params);

		/**
		 * Adds a value to the beginning of an associative array.
		 *
		 * @param array $array
		 * @param string $key
		 * @param mixed $val
		 * @return array
		 */
		static Php::Value unshift(Php::Parameters &params);

		/**
		 * Recursive version of [array_map](http://php.net/array_map), applies one or more
		 * callbacks to all elements in an array, including sub-arrays.
		 *
		 * @param array $array
		 * @param mixed $callbacks
		 * @return array
		 */
		static Php::Value map(Php::Parameters &params);

		/**
		 * Recursively merge two arrays. Values in an associative array
		 * overwrite previous values with the same key. Values in an indexed array
		 * are appended, but only when they do not already exist in the result.
		 *
		 * @param array $array1
		 * @param array $array2
		 * @return array
		 */
		static Php::Value merge(Php::Parameters &params);

		/**
		 * Overwrites an array with values from input arrays.
		 * Keys that do not exist in the first array will not be added!
		 *
		 * @param array $array1
		 * @param array $array2
		 * @return array
		 */
		static Php::Value overwrite(Php::Parameters &params);

		/**
		 * Convert a multi-dimensional array into a single-dimensional array.
		 *
		 * @param array $array
		 * @return array
		 */
		static Php::Value flatten(Php::Parameters &params);

		/**
		 * Filters elements of an array using a the filter
		 *
		 * @param array $array
		 * @param array $filters
		 * @return array
		 */
		static Php::Value filter(Php::Parameters &params);

		/**
		 * Return the sum of all the values in the array using a dot separated path
		 *
		 * @param array $array
		 * @param mixed $path
		 * @param mixed $default
		 * @param string $delimiter
		 * @return number
		 */
		static Php::Value sum(Php::Parameters &params);

		/**
		 * Converts an object or an array of objects into an array
		 *
		 * @param object|array|string $object
		 * @param array $properties
		 * @param bool $recursive
		 * @return array
		 */
		static Php::Value toArray(Php::Parameters &params);
	};

} // namespace Phalcon

#endif /* PHALCON_ARR_H */
