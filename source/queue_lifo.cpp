#include <iostream>
#include <boost/filesystem.hpp>

#include <queue_lifo.hpp>
#include <queue_element.hpp>

queue::queue_lifo::queue_lifo(std::string path)
{
    std::lock_guard<std::mutex> lock(this->mutex);

    bool is_first_element = true;

    namespace fs = boost::filesystem;
    for (fs::recursive_directory_iterator it(path), end; it != end; ++it)
    {
        current_element = std::make_unique<queue_element>(is_first_element? nullptr : current_element, (*it).path().string());
        is_first_element = false;
    }
}

std::string queue::queue_lifo::get_one()
{
    std::lock_guard<std::mutex> lock(this->mutex);

    if (current_element != nullptr)
    {
        std::string result(current_element->get_path());
        current_element = current_element->get_previous_element();
        return result;
    }

    return "";
}

queue::queue_lifo::~queue_lifo()
{
   
}