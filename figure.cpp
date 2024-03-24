#include "figure.h"

Figure::Figure(const Params& params)
{
    params.get("name", this->name);
}
