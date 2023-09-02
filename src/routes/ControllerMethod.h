#pragma once
#include "string"
#include "../requests/Request.h"
#include "map"
#include "functional"

using namespace Requests;

template <typename T>
using ControllerMethod = string (T::*)(Request);