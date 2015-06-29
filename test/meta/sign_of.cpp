//==================================================================================================
/*
  Copyright 2009 - 2011 LASMEA UMR 6602 CNRS/Univ. Clermont II
  Copyright 2009 - 2015 LRI UMR 8623 CNRS/Univ Paris Sud XI
  Copyright 2012 - 2015 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#include <boost/dispatch/meta/introspection/sign_of.hpp>
#include <cstdint>
#include <cstddef>

#include <nstest/unit.hpp>
#include <nstest/unit/tests/types.hpp>

struct foo {};
template<typename T> struct bar {};

NSTEST_CASE_TPL ( "sign_of of signed types is signed"
                , (float)(double)
                  (std::int8_t)(std::int16_t)(std::int32_t)(std::int64_t)(std::ptrdiff_t)
                )
{
  NSTEST_TYPE_IS( boost::dispatch::sign_of<bar<T>>   , signed );
  NSTEST_TYPE_IS( boost::dispatch::sign_of<T>        , signed );
  NSTEST_TYPE_IS( boost::dispatch::sign_of<T&>       , signed );
  NSTEST_TYPE_IS( boost::dispatch::sign_of<T&&>      , signed );
  NSTEST_TYPE_IS( boost::dispatch::sign_of<T const>  , signed );
  NSTEST_TYPE_IS( boost::dispatch::sign_of<T const&> , signed );
}

NSTEST_CASE_TPL ( "sign_of of unsigned types is unsigned"
                , (foo)(std::uint8_t)(std::uint16_t)(std::uint32_t)(std::uint64_t)(std::size_t)
                )
{
  NSTEST_TYPE_IS( boost::dispatch::sign_of<bar<T>>   , unsigned );
  NSTEST_TYPE_IS( boost::dispatch::sign_of<T>        , unsigned );
  NSTEST_TYPE_IS( boost::dispatch::sign_of<T&>       , unsigned );
  NSTEST_TYPE_IS( boost::dispatch::sign_of<T&&>      , unsigned );
  NSTEST_TYPE_IS( boost::dispatch::sign_of<T const>  , unsigned );
  NSTEST_TYPE_IS( boost::dispatch::sign_of<T const&> , unsigned );
}
