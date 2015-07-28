//==================================================================================================
/*
  Copyright 2009 - 2011 LASMEA UMR 6602 CNRS/Univ. Clermont II
  Copyright 2009 - 2015 LRI UMR 8623 CNRS/Univ Paris Sud XI
  Copyright 2012 - 2015 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#include <boost/dispatch/meta/introspection/factory_of.hpp>

#include <nstest.hpp>

NSTEST_CASE( "factory_of of basic types is meta-identity")
{
  NSTEST_TYPE_IS( boost::dispatch::factory_of<float>::apply<int>       , int );
  NSTEST_TYPE_IS( boost::dispatch::factory_of<float&>::apply<int>      , int );
  NSTEST_TYPE_IS( boost::dispatch::factory_of<float&&>::apply<int>     , int );
  NSTEST_TYPE_IS( boost::dispatch::factory_of<float const>::apply<int> , int );
  NSTEST_TYPE_IS( boost::dispatch::factory_of<float const&>::apply<int>, int );
}
