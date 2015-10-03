//==================================================================================================
/*
  Copyright 2009 - 2011 LASMEA UMR 6602 CNRS/Univ. Clermont II
  Copyright 2009 - 2015 LRI UMR 8623 CNRS/Univ Paris Sud XI
  Copyright 2012 - 2015 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#include <boost/dispatch/meta/introspection/primitive_of.hpp>

#include <stf.hpp>

using namespace boost::dispatch;

STF_CASE( "primitive_of of basic types is type itself")
{
  STF_TYPE_IS( primitive_of_t<float>        , float         );
  STF_TYPE_IS( primitive_of_t<float&>       , float&        );
  STF_TYPE_IS( primitive_of_t<float&&>      , float&&       );
  STF_TYPE_IS( primitive_of_t<float const>  , float const   );
  STF_TYPE_IS( primitive_of_t<float const&> , float const&  );
}
