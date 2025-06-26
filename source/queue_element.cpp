#include <iostream>
#include <queue_element.hpp>
#include <memory>

queue::queue_element::queue_element(std::shared_ptr<queue_element> previous_element, std::string path)
{
    std::lock_guard<std::mutex> lock(this->mutex);
    this->previous_element = previous_element;
    this->path = path;
}

std::string queue::queue_element::get_path()
{
    std::lock_guard<std::mutex> lock(this->mutex);
    return this->path;
}

std::shared_ptr<queue::queue_element> queue::queue_element::get_previous_element()
{
    std::lock_guard<std::mutex> lock(this->mutex);
    return this->previous_element;
}

queue::queue_element::~queue_element()
{

}