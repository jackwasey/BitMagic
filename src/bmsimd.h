#ifndef BMSIMD__H__INCLUDED__
#define BMSIMD__H__INCLUDED__
/*
Copyright(c) 2018 Anatoliy Kuznetsov(anatoliy_kuznetsov at yahoo.com)

Permission is hereby granted, free of charge, to any person
obtaining a copy of this software and associated documentation
files (the "Software"), to deal in the Software without restriction,
including without limitation the rights to use, copy, modify, merge,
publish, distribute, sublicense, and/or sell copies of the Software,
and to permit persons to whom the Software is furnished to do so,
subject to the following conditions:

The above copyright notice and this permission notice shall be included
in all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES
OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.
IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM,
DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE,
ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR
OTHER DEALINGS IN THE SOFTWARE.

You have to explicitly mention BitMagic project in any derivative product,
its WEB Site, published materials, articles or any other work derived from this
project or based on our code or know-how.

For more information please visit:  http://bitmagic.io

*/


#ifdef BMAVX2OPT
# undef BMSSE42OPT
# undef BMSSE2OPT
# define BMVECTOPT
# include "bmavx2.h"
#endif


#ifdef BMSSE42OPT
# define BMVECTOPT
# include "bmsse4.h"
#endif

#ifdef BMSSE2OPT
# undef BM64OPT
# define BMVECTOPT
# include "bmsse2.h"
#endif

namespace bm
{

/**
    @brief return SIMD optimization used for building BitMagic
    @return SIMD code
*/
inline int simd_version()
{
#ifdef BMAVX2OPT
    return bm::simd_avx2;
#endif
#ifdef BMSSE42OPT
    return bm::simd_sse42;
#endif
#ifdef BMSSE2OPT
    return bm::simd_sse2;
#else
    return bm::simd_none;
#endif
}


} // namespace

#endif