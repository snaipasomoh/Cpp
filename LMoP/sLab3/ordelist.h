#include "delist.h"

namespace lab{
	class ordelist : public delist{
	public:
		ordelist (){};
		ordelist (delist const &other);
		void ordadd (dObj const &data);
	};
}
