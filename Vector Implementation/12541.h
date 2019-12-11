#include <cstddef>

namespace std
{
	template<typename T> class vector {
		public:
			vector();
			void push_back(T x);
			void pop_back();
			T & operator [] (const int &x);
			const T & operator [] (const int &x) const;
			size_t size();
			size_t capacity();
			void reserve(size_t x);
			void clear();
		private:
			T *arr;
			size_t CAPACITY;
			size_t SIZE;
	};
}

template class std::vector<int>;
