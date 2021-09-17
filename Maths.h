//
// Created by Vladimir on 17.09.2021.
//

#ifndef NUMERICSERIES_MATHS_H
#define NUMERICSERIES_MATHS_H


namespace Maths{

    const double pi = 3.14159265358979323846;

    template <typename T> T fact(T x) {
        if (x == 0 || x == 1)
            return 1;
        else
            return x * fact(x - 1);
    };

}


#endif //NUMERICSERIES_MATHS_H
