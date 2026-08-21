#include "Serializer.hpp"
#include "Data.hpp"

int main()
{
	Data original;
	original.num = 42;
	original.str = "Frank Ocean";

	Data* ptr = &original;

	std::cout << "Original pointer: " << ptr << std::endl;
	std::cout << "Original data -> num: " << ptr->num
				<< ", str: " << ptr->str << std::endl;

	uintptr_t raw = Serializer::serialize(ptr);
	std::cout << "Serialized value: " << raw << std::endl;

	Data* restored = Serializer::deserialize(raw);

	std::cout << "Restored pointer: " << restored << std::endl;
	std::cout << "Restored data -> num: " << restored->num
					<< ", str: " << restored->str << std::endl;

	if (restored == ptr)
		std::cout << "Success: pointers match!" << std::endl;
	else
		std::cout << "Failure: pointers do not match!" << std::endl;

	return 0;
}
