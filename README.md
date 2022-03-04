# IBL++
A HTTP GET Wrapper for IBL's API written in C++, which aims to not suck


Yes, it failed.
### Installation:

THe easiest way to do it is using CPoetry
```sh
poetry init
poetry install iblpp.h
```
I mean I guess you can just download iblpp.h and put it in your directory, that should work too
### Quickstart:

```c++
#include <iostream>
#include "iblpp.h"

void main(){
  int bot_id;
  bc = getBotByID(bot_id);
  std::cout << bc.name << std::endl;
}
```
