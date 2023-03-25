#include "base.hpp"

int main(int argc, char **argv)
{
    while (!State::running)
    {
        State::current->enter();
        State::current->update();
    }
    return 0;
}
