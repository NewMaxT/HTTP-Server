#include <iostream>
#include <stdexcept>
#include "TCP_Server.h"


int main([[maybe_unused]] int argc, [[maybe_unused]] char *argv[]) {
    try {
        server::TCP srv;
        srv.Start();
        srv.Close();
    } catch(std::exception &Ex) {
      std::cout << Ex.what() << std::endl;
      return EXIT_FAILURE;
    }
}
