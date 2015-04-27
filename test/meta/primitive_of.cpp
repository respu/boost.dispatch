//==================================================================================================
/*
  Copyright 2009 - 2011 LASMEA UMR 6602 CNRS/Univ. Clermont II
  Copyright 2009 - 2015 LRI UMR 8623 CNRS/Univ Paris Sud XI
  Copyright 2012 - 2015 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#include <boost/dispatch/meta/primitive_of.hpp>

#include <nstest/unit.hpp>
#include <nstest/unit/tests/types.hpp>

NSTEST_CASE( "primitive_of of basic types is type itself")
{
  NSTEST_TYPE_IS( boost::dispatch::meta::primitive_of<float>::type        , float         );
  NSTEST_TYPE_IS( boost::dispatch::meta::primitive_of<float&>::type       , float&        );
  NSTEST_TYPE_IS( boost::dispatch::meta::primitive_of<float&&>::type      , float&&       );
  NSTEST_TYPE_IS( boost::dispatch::meta::primitive_of<float const>::type  , float const   );
  NSTEST_TYPE_IS( boost::dispatch::meta::primitive_of<float const&>::type , float const&  );
}
