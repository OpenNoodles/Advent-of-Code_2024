#pragma once


#include "datastructures/Lines.h"
#include "datastructures/LMatrix.h"

#include "datastructures/VMatrix.h"
template<> class VMatrix<char>;

#include "datastructures/Walker.h"
template<> class Walker<Lines>;
template<> class Walker<VMatrix<char>>;
