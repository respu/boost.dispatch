//==================================================================================================
/*
  Copyright 2009 - 2015 LRI UMR 8623 CNRS/Univ Paris Sud XI
  Copyright 2012 - 2015 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)

*/
//==================================================================================================
#include <boost/dispatch/meta/transfer_qualifiers.hpp>

#include <nstest/unit.hpp>
#include <nstest/unit/tests/types.hpp>

NSTEST_CASE( "Check if nothing get transfered")
{
  NSTEST_TYPE_IS( (boost::dispatch::meta::transfer_qualifiers<int, float>::type)
                , int
                );
}
/*
NSTEST_CASE( "Check if 'const' get transfered")
{

}

NSTEST_CASE( "Check if 'const&' get transfered")
{

}

NSTEST_CASE( "Check if '&' get transfered")
{

}

NSTEST_CASE( "Check if '&&' get transfered")
{

}
*/
