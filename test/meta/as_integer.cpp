//==================================================================================================
/*
  Copyright 2009 - 2011 LASMEA UMR 6602 CNRS/Univ. Clermont II
  Copyright 2009 - 2015 LRI UMR 8623 CNRS/Univ Paris Sud XI
  Copyright 2012 - 2015 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#include <boost/dispatch/meta/generation/as_integer.hpp>
#include <boost/dispatch/meta/generation/make_integer.hpp>

#include <stf.hpp>

STF_CASE_TPL ( "Generate integer from integral types"
                , (std::uint8_t)(std::uint16_t)(std::uint32_t)(std::uint64_t)
                  (std::int8_t )(std::int16_t )(std::int32_t )(std::int64_t )
                )
{
  STF_TYPE_IS( (boost::dispatch::as_integer<T>)       , T );
  STF_TYPE_IS( (boost::dispatch::as_integer<T&>)      , T );
  STF_TYPE_IS( (boost::dispatch::as_integer<T&&>)     , T );
  STF_TYPE_IS( (boost::dispatch::as_integer<T const>) , T );
  STF_TYPE_IS( (boost::dispatch::as_integer<T const&>), T );
}

STF_CASE_TPL( "Generate integer from real types", (float)(double) )
{
  STF_TYPE_IS( (boost::dispatch::as_integer<T>)        ,(boost::dispatch::make_integer<sizeof(T),signed>) );
  STF_TYPE_IS( (boost::dispatch::as_integer<T&>)       ,(boost::dispatch::make_integer<sizeof(T),signed>) );
  STF_TYPE_IS( (boost::dispatch::as_integer<T&&>)      ,(boost::dispatch::make_integer<sizeof(T),signed>) );
  STF_TYPE_IS( (boost::dispatch::as_integer<T const>)  ,(boost::dispatch::make_integer<sizeof(T),signed>) );
  STF_TYPE_IS( (boost::dispatch::as_integer<T const&&>),(boost::dispatch::make_integer<sizeof(T),signed>) );
}

template<typename T> struct foo {};

STF_CASE_TPL ( "Generate integer from custom template types"
                , (std::uint8_t)(std::uint16_t)(std::uint32_t)(std::uint64_t)
                  (std::int8_t )(std::int16_t )(std::int32_t )(std::int64_t )
                  (float)(double)
                )
{
  STF_TYPE_IS( (boost::dispatch::as_integer<foo<foo<T>>>)        , foo<foo<boost::dispatch::as_integer<T>>>);
  STF_TYPE_IS( (boost::dispatch::as_integer<foo<foo<T>>&>)       , foo<foo<boost::dispatch::as_integer<T>>>);
  STF_TYPE_IS( (boost::dispatch::as_integer<foo<foo<T>>&&>)      , foo<foo<boost::dispatch::as_integer<T>>>);
  STF_TYPE_IS( (boost::dispatch::as_integer<foo<foo<T>> const>)  , foo<foo<boost::dispatch::as_integer<T>>>);
  STF_TYPE_IS( (boost::dispatch::as_integer<foo<foo<T>> const&&>), foo<foo<boost::dispatch::as_integer<T>>>);
}
