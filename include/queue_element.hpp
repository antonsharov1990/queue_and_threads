#ifndef QUEUE_ELEMENT_HPP
#define QUEUE_ELEMENT_HPP
#include <vector>
#include <string>
#include <mutex>
#include <memory>

namespace queue
{
    class queue_element
    {
        std::string path;
        std::shared_ptr<queue_element> previous_element;
        std::mutex mutex;
        
        public:
            queue_element(std::shared_ptr<queue_element> previous_element, std::string path);
            std::string get_path();
            std::shared_ptr<queue_element> get_previous_element();
            ~queue_element();
    };
}

#endif //QUEUE_ELEMENT_HPP