#include <iostream>
#include <boost/filesystem.hpp>
#include <vector>
#include <string>
#include <queue_lifo.hpp>

int main(int argc, char** argv)
{
    if (argc < 2) {
        std::cout << "Application run without arguments." << std::endl;
        std::cout << "Please insert working path:" << std::endl;
        std::cout << "queue /home/user/test_dir" << std::endl;
        std::cout << "queue \"/path with spaces/test_dir\"" << std::endl;
        return 0;
    }

    if (argc > 2) {
        std::cout << "Please insert only path to target dirrectory:" << std::endl;
        std::cout << "queue \"/path with spaces/test_dir\"" << std::endl;
        return 0;
    }

    std::cout << "List of arguments:" << std::endl;
    for(int i = 1; i < argc; i++)
    {
        std::cout << argv[i] << std::endl;
    }

    std::string path(argv[1]);
    queue::queue_lifo q(path);

    std::string message = "Files:";
    do
    {
        std::cout << message << std::endl;
        message = q.get_one();
    }
    while (!message.empty());
    std::cout << "end." << std::endl;

    return 0;
}