#ifndef PHALCON_ACL_H
#define PHALCON_ACL_H

#include <phpcpp.h>

namespace Phalcon {

	/**
	 * Phalcon\Acl
	 *
	 * This component allows to manage ACL lists. An access control list (ACL) is a list
	 * of permissions attached to an object. An ACL specifies which users or system processes
	 * are granted access to objects, as well as what operations are allowed on given objects.
	 */
	class Acl : public Php::Base {
	public:
		enum {ACL_DUNNO, ACL_DENY, ACL_ALLOW};

	public:

		static void Init(Php::Class<Acl> &acl)
		{
			acl.property("DUNNO", ACL_DUNNO, Php::Const);
			acl.property("DENY", ACL_DENY, Php::Const);
			acl.property("ALLOW", ACL_ALLOW, Php::Const);
		}

	private:

	};

} // namespace Phalcon

#endif /* PHALCON_ACL_H */
