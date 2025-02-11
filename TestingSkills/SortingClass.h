#pragma once
#include <string>


using namespace std;



template<class T>
void mySwapFunc(T& first, T& second)
{
	T temp;
	temp = std::move(second);
	second = std::move(first);
	first = std::move(temp);
}

template <class T>
class SortingMethod {
protected:
    T* arr;
    int size;
public:
    virtual void sortArr() = 0;
    virtual void displayArr() const = 0;

    SortingMethod() : arr(nullptr), size(0) {}

    SortingMethod(T* arr, int size) {
        this->arr = new T[size];
        this->size = size;
        for (int i = 0; i < size; ++i) {
            this->arr[i] = arr[i];
        }
    }

    virtual ~SortingMethod() {
        delete[] arr;
    }

    SortingMethod(const SortingMethod& other) {
        this->arr = new T[other.size];
        this->size = other.size;
        for (int i = 0; i < this->size; ++i) {
            this->arr[i] = other.arr[i];
        }
    }

    SortingMethod& operator=(const SortingMethod& other) {
        if (this == &other) { return *this; }

        delete[] arr;
        this->arr = new T[other.size];
        this->size = other.size;

        for (int i = 0; i < this->size; ++i) {
            this->arr[i] = other.arr[i];
        }

        return *this;
    }

    SortingMethod(SortingMethod&& other) noexcept {
        this->arr = other.arr;
        this->size = other.size;
        other.arr = nullptr;
        other.size = 0;
    }

    SortingMethod& operator=(SortingMethod&& other) noexcept {
        if (this == &other) { return *this; }

        delete[] arr;
        this->arr = other.arr;
        this->size = other.size;

        other.arr = nullptr;
        other.size = 0;

        return *this;
    }
};

template <class T>
class BubbleSort : public SortingMethod<T> {
public:
    BubbleSort() : SortingMethod<T>() {}

    BubbleSort(T* arr, int size) : SortingMethod<T>(arr, size) {}

    void sortArr() override {
        for (int i = 0; i < this->size - 1; ++i) {
            bool flag = false;
            for (int j = 0; j < this->size - i - 1; ++j) {
                if (this->arr[j] > this->arr[j + 1]) {
                    mySwapFunc(this->arr[j], this->arr[j + 1]);
                    flag = true;
                }
            }
            if (!flag) {
                return;
            }
        }
    }


    void displayArr() const override
    {
        for (int i = 0; i < this->size; i++)
        {
            cout << *(this->arr + i) << ' ';
        }

        cout << endl;
    }
};