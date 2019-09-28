#pragma once

namespace conv {
	template <class T>
	class DataWrapper {
	private:
		T* data;
	public:
		DataWrapper(T* p_data) : data(p_data) {}

		T* getData() const{
			return this->data;
		}
	};
}