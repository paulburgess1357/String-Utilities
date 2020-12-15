#pragma once
#include <string>


class ILoadString{
	
public:
	virtual ~ILoadString() = default;
	virtual std::string load() const = 0;
	
};
