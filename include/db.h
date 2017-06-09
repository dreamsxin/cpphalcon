#ifndef PHALCON_DB_H
#define PHALCON_DB_H

#include <phpcpp.h>

namespace Phalcon {

	/**
	 * Phalcon\Db
	 *
	 * Phalcon\Db and its related classes provide a simple SQL database interface for Phalcon Framework.
	 * The Phalcon\Db is the basic class you use to connect your PHP application to an RDBMS.
	 * There is a different adapter class for each brand of RDBMS.
	 *
	 * This component is intended to lower level database operations. If you want to interact with databases using
	 * higher level of abstraction use Phalcon\Mvc\Model.
	 *
	 * Phalcon\Db is an abstract class. You only can use it with a database adapter like Phalcon\Db\Adapter\Pdo
	 */
	class Db : public Php::Base {
	public:

		static void Init(Php::Class<Db> &db)
		{
			db.property("FETCH_USE_DEFAULT", Php::constant("PDO::FETCH_USE_DEFAULT").numericValue(), Php::Const);
			db.property("FETCH_LAZY", Php::constant("PDO::FETCH_LAZY").numericValue(), Php::Const);
			db.property("FETCH_ASSOC", Php::constant("PDO::FETCH_ASSOC").numericValue(), Php::Const);
			db.property("FETCH_NUM", Php::constant("PDO::FETCH_NUM").numericValue(), Php::Const);
			db.property("FETCH_BOTH", Php::constant("PDO::FETCH_BOTH").numericValue(), Php::Const);
			db.property("FETCH_OBJ", Php::constant("PDO::FETCH_OBJ").numericValue(), Php::Const);
			db.property("FETCH_BOUND", Php::constant("PDO::FETCH_BOUND").numericValue(), Php::Const);
			db.property("FETCH_COLUMN", Php::constant("PDO::FETCH_COLUMN").numericValue(), Php::Const);
			db.property("FETCH_CLASS", Php::constant("PDO::FETCH_CLASS").numericValue(), Php::Const);
			db.property("FETCH_INTO", Php::constant("PDO::FETCH_INTO").numericValue(), Php::Const);
			db.property("FETCH_FUNC", Php::constant("PDO::FETCH_FUNC").numericValue(), Php::Const);
			db.property("FETCH_NAMED", Php::constant("PDO::FETCH_NAMED").numericValue(), Php::Const);
			db.property("FETCH_KEY_PAIR", Php::constant("PDO::FETCH_KEY_PAIR").numericValue(), Php::Const);
			db.property("FETCH_GROUP", Php::constant("PDO::FETCH_GROUP").numericValue(), Php::Const);
			db.property("FETCH_UNIQUE", Php::constant("PDO::FETCH_UNIQUE").numericValue(), Php::Const);
			db.property("FETCH_CLASSTYPE", Php::constant("PDO::FETCH_CLASSTYPE").numericValue(), Php::Const);
			db.property("FETCH_SERIALIZE", Php::constant("PDO::FETCH_SERIALIZE").numericValue(), Php::Const);
			db.property("FETCH_PROPS_LATE", Php::constant("PDO::FETCH_PROPS_LATE").numericValue(), Php::Const);

			db.method<&Db::setup>("setup");
		}

		/**
		 * Enables/disables options in the Database component
		 */
		static void setup(Php::Parameters &params);

	private:

	};

} // namespace Phalcon

#endif /* PHALCON_DB_H */

