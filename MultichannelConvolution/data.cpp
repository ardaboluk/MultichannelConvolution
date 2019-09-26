
#include "data.h"

namespace conv {
	
	template <class T>
	Data<T>::Data(T& data) {
		this->data = data;
	}

	template <class T>
	T& Data<T>::getData() {
		return this->data;
	}
}