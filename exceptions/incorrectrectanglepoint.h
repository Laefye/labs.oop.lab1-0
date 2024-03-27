#ifndef INCORRECTRECTANGLEPOINT_H
#define INCORRECTRECTANGLEPOINT_H
#include "badparams.h"


class IncorrectRectanglePoint : public BadParams {
public:
    IncorrectRectanglePoint(const std::string& point);
};

#endif // INCORRECTRECTANGLEPOINT_H
