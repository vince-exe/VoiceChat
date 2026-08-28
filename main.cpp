#include <boost/lambda/lambda.hpp>
#include <iostream>
#include <algorithm>

#include "configuration.hpp"

using VoiceChat::Configuration::App;

int main()
{
    App::get().loadConfiguration();
}