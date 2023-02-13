#include "tests.h"
#include "vector.h"
#include <stdexcept>

class Testi
{
	public:
		Testi(void) {
			std::cout << "Default constructor\n";
		}
		Testi(const Testi& test) {
			std::cout << "Copy constructor\n";
		}
		~Testi(void) {
			std::cout << "Destructor\n";
		}
		const Testi&	operator=(const Testi& test) {
			std::cout << "Copy assignmenet operator\n";
			return *this;
		}
};

void	test_vector(void)
{
	ft::vector<Testi>* v1 = new ft::vector<Testi>(5);
	delete v1;

	assert(false);
}

