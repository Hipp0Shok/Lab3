#include "hashtable.h"

template<>
unsigned int hash<std::string>(std::string const &key)
{
    unsigned int i = 0;
    unsigned int answer = 0;
    while(key[i])
    {
        answer += static_cast<unsigned int>(key[i]);
        i++;
    }
    return(static_cast<unsigned int>(1024*fmod(answer*0.618033, 1)));
}
