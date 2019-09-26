#pragma once

namespace conv {
	template <class T>
	class Data {
	private:
		T& data;
	public:
		Data(T&);
		T& getData();
	};
}

#include "data.cpp"