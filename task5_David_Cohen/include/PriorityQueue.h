#pragma once

#include <iostream>
#include <list>
#include <exception>

/**
 * @brief A comparator struct for comparing elements in the PriorityQueue.
 *
 * This struct defines the comparison operation between two elements.
 * The operator() function should return a value indicating the comparison result.
 * In this example, it subtracts the second value from the first value.
 *
 * @tparam T The type of elements to be compared.
 */
template<typename T>
struct MyComparator
{
    /**
     * @brief Compares two elements.
     *
     * @param val1 The first element.
     * @param val2 The second element.
     * @return The result of the comparison.
     *         If val1 < val2, it returns a negative value.
     *         If val1 > val2, it returns a positive value.
     *         If val1 == val2, it returns 0.
     */
    T operator()(const T& val1, const T& val2) const
    {
        return val1 - val2;
    }
};

/**
 * @brief An exception class representing an empty PriorityQueue.
 */
class EmptyPriorityQueue : public std::exception
{
public:
    /**
     * @brief Returns the exception message.
     *
     * @return A pointer to the exception message.
     */
    const char* what() const noexcept override
    {
        return "PriorityQueue is empty!";
    }
};

/**
 * @brief A priority queue implementation.
 *
 * This class represents a priority queue, where elements are ordered according to their priority.
 * The priority is determined by the comparison function provided.
 * The push function inserts an element into the queue based on its priority,
 * and the poll function removes and returns the element with the highest priority.
 *
 * @tparam T The type of elements stored in the priority queue.
 */
template <typename T>
class PriorityQueue
{
public:
    /**
     * @brief Inserts an element into the priority queue.
     *
     * The element is inserted at the appropriate position based on its priority.
     *
     * @param t The element to be inserted.
     */
    void push(const T& t);

    /**
     * @brief Removes and returns the element with the highest priority.
     *
     * @return The element with the highest priority.
     * @throws EmptyPriorityQueue if the priority queue is empty.
     */
    T poll();

private:
    std::list<T> _data;
    MyComparator<T> _compare;
};

template<typename T>
void PriorityQueue<T>::push(const T& t)
{
    auto it = _data.begin();
    while (it != _data.end() && _compare(*it, t) < 0)
    {
        ++it;
    }
    _data.insert(it, t);
}

template<typename T>
T PriorityQueue<T>::poll()
{
    if (_data.empty())
        throw EmptyPriorityQueue();
    T element = _data.front();
    _data.pop_front();
    return element;
}
