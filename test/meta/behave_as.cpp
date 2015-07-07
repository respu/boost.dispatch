//==================================================================================================
/*
  Copyright 2009 - 2011 LASMEA UMR 6602 CNRS/Univ. Clermont II
  Copyright 2009 - 2015 LRI UMR 8623 CNRS/Univ Paris Sud XI
  Copyright 2012 - 2015 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#include <boost/dispatch/meta/introspection/behave_as.hpp>
#include <boost/dispatch/detail/brigand/types/bool.hpp>
#include <type_traits>

#include <nstest/unit.hpp>
#include <nstest/unit/tests/types.hpp>

template<typename T> using is_fp = typename std::is_floating_point<T>::type;

NSTEST_CASE( "behave_as of basic types is same as direct meta-function call")
{
  NSTEST_TYPE_IS( (boost::dispatch::behave_as<float,is_fp>) , brigand::true_  );
  NSTEST_TYPE_IS( (boost::dispatch::behave_as<double,is_fp>), brigand::true_  );
  NSTEST_TYPE_IS( (boost::dispatch::behave_as<char,is_fp>)  , brigand::false_ );
  NSTEST_TYPE_IS( (boost::dispatch::behave_as<void*,is_fp>) , brigand::false_ );
}

template<typename T> struct foo {};
template<typename T> struct bar {};

NSTEST_CASE( "behave_as go through template layers")
{
  NSTEST_TYPE_IS( (boost::dispatch::behave_as<foo<float>,is_fp>)         , brigand::true_  );
  NSTEST_TYPE_IS( (boost::dispatch::behave_as<foo<bar<double>>,is_fp>)   , brigand::true_  );
  NSTEST_TYPE_IS( (boost::dispatch::behave_as<foo<bar<foo<void>>>,is_fp>), brigand::false_ );
}
