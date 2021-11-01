
#include <stdexcept>

using namespace std;

class null_ptr_exception : public exception {
public:
	null_ptr_exception(const char* c) : exception(c) {
	}
private:

};
template <typename T>
class smart_ptr {
public:
	smart_ptr() noexcept {
		ptr_ = nullptr;
		ref_ = new int{ 0 };
	}
	// Create a smart_ptr that is initialized to NULL. The reference count
	// should be zero.

	explicit smart_ptr(T* raw_ptr) {
		ptr_ = raw_ptr;
		ref_ = new int{ 1 }; // this can throw
	}
	// Create a smart_ptr that is initialized to raw_ptr. The reference count
	// should be one.       

	smart_ptr(const smart_ptr& rhs) noexcept {
		ptr_ = rhs.ptr_;
		ref_ = rhs.ref_;
		if (ref_ != nullptr) {
			(*ref_)++;
		}
	}
	// Copy construct a pointer from rhs. The reference count should be
	// incremented by one.

	smart_ptr(smart_ptr&& rhs) noexcept {
		ptr_ = rhs.ptr_;
		ref_ = rhs.ref_;
		rhs.ref_ = nullptr;
		rhs.ptr_ = nullptr;

	}
	// Move construct a pointer from rhs.

	smart_ptr& operator=(const smart_ptr& rhs) noexcept {
		if (rhs.ref_ == nullptr || *(rhs.ref_) == 0) {
			ptr_ = nullptr;
			(*ref_)--;
			ref_ = new int{ 0 };
			return *this;
		}
		ptr_ = rhs.ptr_;
		ref_ = rhs.ref_;
		(*ref_)++;
		return *this;
	}
	// This assignment should make a shallow copy of the right-hand side's
	// pointer data. The reference count should be incremented as appropriate.
	smart_ptr& operator=(smart_ptr&& rhs) noexcept {
		delete ptr_;
		delete ref_;
		ptr_ = rhs.ptr_;
		ref_ = rhs.ref_;
		rhs.ref_ = nullptr;
		rhs.ptr_ = nullptr;
		return *this;
	}

	// This move assignment should steal the right-hand side's pointer data.

	bool clone() {
		if (ref_ == nullptr || ptr_ == nullptr || ref_count() < 2) {
			return false;
		}
		(*ref_)--;
		T* deepCopy = new T{ *ptr_ }; //this can throw
		ptr_ = deepCopy;
		ref_ = new int{ 1 }; //this can throw
		return true;
	}
	// If the smart_ptr is either NULL or has a reference count of one, this
	// function will do nothing and return false. Otherwise, the referred to
	// object's reference count will be decreased and a new deep copy of the
	// object will be created. This new copy will be the object that this
	// smart_ptr points and its reference count will be one.

	int ref_count() const noexcept {
		if (ref_ == nullptr)return 0;
		return (*ref_);
	}
	// Returns the reference count of the pointed to data.

	T& operator*() {
		if (ptr_ == nullptr) {
			throw null_ptr_exception("invalid access"); //this is a throw
		}
		return *ptr_;
	}
	// The dereference operator shall return a reference to the referred object.
	// Throws null_ptr_exception on invalid access.

	T* operator->() {
		if (ptr_ == nullptr) {
			throw null_ptr_exception("invalid access"); //this is a throw
		}
		return ptr_;
	}
	// The arrow operator shall return the pointer ptr_. Throws null_ptr_exception
	// on invalid access.

	~smart_ptr() noexcept {
		if (ref_ && *ref_ > 1) {
			(*ref_)--;
			ref_ = nullptr;
			ptr_ = nullptr;
		}
		if (ref_) {
			delete ref_;
		}
		if (ptr_) {
			delete ptr_;
		}
	}

	// deallocate all dynamic memory

private:
	T* ptr_;               // pointer to the referred object
	int* ref_;             // pointer to a reference count
};