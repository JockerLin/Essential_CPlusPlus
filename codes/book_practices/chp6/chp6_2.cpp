//
// Created by BlazarLin on 2020/8/28.
//

#ifndef CODES_CHP6_2_CPP
#define CODES_CHP6_2_CPP

#endif //CODES_CHP6_2_CPP
#include <iostream>
#include <fstream>
#include "chp6.h"

using namespace std;

void chp62Practices(){
    ofstream log( "../book_practices/chp6/log.txt" );
    if ( ! log )
    { cerr << "can't open log file!\n"; return; }
    MatrixPro<float> identity( 4, 4 );
    log << "identity: " << identity << endl;
    float ar[16]={ 1., 0., 0., 0., 0., 1., 0., 0.,
                   0., 0., 1., 0., 0., 0., 0., 1. };
    for ( int i = 0, k = 0; i < 4; ++i )
        for ( int j = 0; j < 4; ++j )
            identity( i, j ) = ar[ k++ ];
    log << "identity after set: " << identity << endl;
    MatrixPro<float> m( identity );
    log << "m: memberwise initialized: " << m << endl;
    MatrixPro<float> m2( 8, 12 );
    log << "m2: 8x12: " << m2 << endl;
    m2 = m;
    log << "m2 after memberwise assigned to m: "
        << m2 << endl;
    float ar2[16]={ 1.3, 0.4, 2.6, 8.2, 6.2, 1.7, 1.3, 8.3,
                    4.2, 7.4, 2.7, 1.9, 6.3, 8.1, 5.6, 6.6 };
    MatrixPro<float> m3( 4, 4 );
    for ( int ix = 0, kx = 0; ix < 4; ++ix )
        for ( int j = 0; j < 4; ++j )
            m3( ix, j ) = ar2[ kx++ ];
    log << "m3: assigned random values: " << m3 << endl;
    //MatrixPro<float> m4 = m3 * identity; log << m4 << endl;
    //MatrixPro<float> m5 = m3 + m4; log << m5 << endl;
    //m3 += m4; log << m3 << endl;
}
