#pragma once

namespace conv {
	template <class T>
	class Data {
	private:
		T* data;
	public:
		Data(T* p_data) : data(p_data) {}

		T* getData() const{
			return this->data;
		}
	};
}