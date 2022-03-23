#pragma once

#include "quantum.h"

// Any changes to the layout names and/or definitions must also be made to info.json

#define LAYOUT_ortho( \
    K00, K01, K02, \
    K10, K11, K12  \
) { \
    { K00, K01, K02,}, \
    { K10, K11, K12,} \
}

