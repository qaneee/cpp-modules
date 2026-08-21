#pragma once

#include <stdint.h>
#include <iostream>
#include <string>
#include "Data.hpp"

class Serializer
{
	public:
		static uintptr_t serialize(Data* ptr);
		static Data* deserialize(uintptr_t raw);
	
	private:
		Serializer();
		Serializer(const Serializer &);
		Serializer& operator=(const Serializer &);
		~Serializer();
};
