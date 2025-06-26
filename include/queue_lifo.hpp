#ifndef QUEUE_HPP
#define QUEUE_HPP

#include <vector>
#include <string>
#include <mutex>
#include <memory>
#include <queue_element.hpp>

namespace queue
{
    class queue_lifo
    {
        std::shared_ptr<queue_element> current_element;
        std::mutex mutex;
        
        public:
            queue_lifo(std::string path);
            std::string get_one();
            ~queue_lifo();
    };
}

#endif //QUEUE_HPP