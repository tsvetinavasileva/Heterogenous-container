//
// Created by Tsvetina on 12.1.2018 г..
//

#ifndef PROJECT_CONDITION_H
#define PROJECT_CONDITION_H

template <typename T>
using Condition = bool (*) (T const&);

#endif //PROJECT_CONDITION_H
