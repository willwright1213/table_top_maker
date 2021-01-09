#include "headers/world.h"
#include "headers/era.h"

int main()
{
    World *test = new World("Test World");
    delete(test);
    return 0;
}
